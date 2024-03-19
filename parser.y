%{
    #include <bits/stdc++.h>
    #include "node.h"
    #include "symbol_table.cpp"
    using namespace std;
    int yylex();    
    int yyerror(const char *s);
    extern int yylineno;
    extern stack<int> indent_stack;
    NODE *start_node;
	fstream fout;
	extern FILE *yyin;
    int is_param=0;
    //symbol table
    sym_table * global_sym_table = new sym_table();    
    stack<sym_table*> curr_sym_tbl;
    vector<st_node> parameter_vec;
    #define __CLASS__ 2
    #define __FUNC__ 1
    #define __DOT__ 1
    #define __TDOT__ 2
    int is_dot_name=0;
    string after_dot_name = "";
    int tempCount=1;
    int instCount=0;
    string newTemp();
    void create_ins(int type, string optype, string addr1, string addr2, string addr3);
    vector<vector<string>> instructions;

%}

%union {
    NODE *elem;
}

%token <elem> KEYWORD NEWLINE  NAME YIELD FROM ELIF AWAIT ASYNC TRUE FALSE NONE IMPORT PASS BREAK EXCEPT RAISE CLASS FINALLY RETURN CONTINUE FOR LAMBDA TRY AS DEF NONLOCAL WHILE ASSERT DEL GLOBAL WITH
%token <elem> INTEGER FLOAT STRING
%token <elem> POW FLOOR_DIV DIV MUL ADD SUB MOD EQUAL
%token <elem> SHIFT_LEFT SHIFT_RIGHT BITWISE_AND BITWISE_XOR BITWISE_OR TILDE  
%token <elem> AT COMMA WAL_OP COLON SEMI_COLON SMALL_OPEN SMALL_CLOSE BOX_OPEN BOX_CLOSE CURLY_OPEN CURLY_CLOSE  DOT ARROW
%token <elem> DOUBLE_EQUAL NE LT GT LE GE
%token <elem> IN IS IF ELSE 
%token <elem> AND OR NOT
%token <elem> TYPE_HINT FUNC_TYPE_HINT 
%token <elem> ADD_EQUAL SUB_EQUAL MUL_EQUAL  AT_EQUAL  DIV_EQUAL MOD_EQUAL BITWISE_AND_EQUAL  BITWISE_OR_EQUAL  BITWISE_XOR_EQUAL SHIFT_LEFT_EQUAL  SHIFT_RIGHT_EQUAL  POW_EQUAL  FLOOR_DIV_EQUAL 
%token INDENT DEDENT
%type <elem> start file_input stmt compound_stmt async_stmt if_stmt if_stmt_deviation elif_namedexpr_test_colon_suite_star while_stmt while_stmt_deviation for_stmt   funcdef funcdef_title func_type_hint_optional parameters typedlist_argument typedlist_arguments comma_option_argument_star typedarglist tfpdef func_body_suite suite stmt_plus simple_stmt semi_colon_small_stmt_star small_stmt flow_stmt break_stmt continue_stmt return_stmt raise_stmt global_stmt nonlocal_stmt comma_name_star assert_stmt expr_stmt testlist symbol_test_star expr_stmt_option1_plus annassign testlist_star_expr testlist_star_expr_option1_star augassign expr  symbol_xor_expr_star xor_expr symbol_and_expr_star and_expr symbol_shift_expr_star shift_expr shift_arith_expr_star arith_expr symbol_term_star term symbol_factor_star symbol_factor factor power atom_expr trailer_star trailer classdef bracket_arglist_optional arglist argument_list subscriptlist subscript_list subscript argument comp_iter sync_comp_for comp_for comp_if test_nocond or_test or_and_test_star and_test and_not_test_star not_test comparison comp_op_expr_plus comp_op exprlist expr_star_expr_option namedexpr_test_star_expr_option_list namedexpr_test_star_expr_option expr_star_expr_option_list   testlist_comp   namedexpr_test test atom number string_plus  else_colon_suite_optional 

%%
    


start : file_input {$$ = create_node(2,"START", $1); start_node=$$;}
    ;

file_input: NEWLINE file_input {$$ = $2;}
    | stmt file_input {$$ = create_node(3,"File Input",$1,$2);}
    | {$$ = NULL;}	
    ;


stmt: simple_stmt  {$$ = $1;}
    |compound_stmt {$$ = $1;}
    ;

compound_stmt: if_stmt { $$ = $1;}
    |  while_stmt { $$ = $1;}
    | for_stmt { $$ = $1;}
    /* | try_stmt { $$ = $1;} */
    | funcdef  {  $$ = $1;}
    | classdef { $$ = $1;}
    | async_stmt { $$ = $1;}
    ;
    
async_stmt: ASYNC funcdef { $$ = create_node(3,"Async_stmt",$1,$2);}
    | ASYNC for_stmt { $$ = create_node(3,"Async_stmt",$1,$2);}
    ;

/* if_stmt: IF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star ELSE COLON suite { $$ = create_node(9,"If_stmt",$1,$2,$3,$4,$5,$6,$7,$8);}
    | IF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star { $$ = create_node(6,"If_stmt",$1,$2,$3,$4,$5);} */

if_stmt: IF {           
            sym_table * new_table = new sym_table();
            new_table->return_type=curr_sym_tbl.top()->return_type;
            create_entry(curr_sym_tbl.top(),"if_block" , "If_stmt" ,yylineno,1,new_table );
            curr_sym_tbl.push(new_table);

            }  
            namedexpr_test COLON suite {
                                    if(curr_sym_tbl.size()>1)
                                    curr_sym_tbl.pop();} 
            if_stmt_deviation {
                $$ = create_node(6,"If_stmt",$1,$3,$4,$5,$7);
                
            };

if_stmt_deviation: elif_namedexpr_test_colon_suite_star ELSE COLON {
        sym_table * new_table = new sym_table();
        new_table->return_type=curr_sym_tbl.top()->return_type;
        create_entry(curr_sym_tbl.top(),"elif_block" , "Elif_stmt" ,yylineno,0,new_table );
        curr_sym_tbl.push(new_table);
        } 
        suite { 
            $$ = create_node(5,"elif_stmt",$1,$2,$3,$5);if(curr_sym_tbl.size()>1) curr_sym_tbl.pop();
        }
        |elif_namedexpr_test_colon_suite_star {$$ = $1;};
                                                

elif_namedexpr_test_colon_suite_star: ELIF {
        sym_table * new_table = new sym_table();
        new_table->return_type=curr_sym_tbl.top()->return_type;
        create_entry(curr_sym_tbl.top(),"else_block" , "Else_stmt" ,yylineno,0,new_table );
        curr_sym_tbl.push(new_table);
        } 
        namedexpr_test COLON suite {
            if(curr_sym_tbl.size()>1) curr_sym_tbl.pop();
        } 
        elif_namedexpr_test_colon_suite_star {$$ = create_node(6,"Elif_block",$1,$3,$4,$5,$7);}
    | { $$ = NULL;}
    ;

/* while_stmt: WHILE namedexpr_test COLON suite ELSE COLON suite { $$ = create_node(8,"While_stmt",$1,$2,$3,$4,$5,$6,$7);}
    | WHILE namedexpr_test COLON suite {$$ = create_node(5,"While_stmt",$1,$2,$3,$4);}
    ; */

while_stmt: WHILE {
        sym_table * new_table = new sym_table();
        new_table->return_type=curr_sym_tbl.top()->return_type;
        create_entry(curr_sym_tbl.top(),"while_block" , "While_stmt" ,yylineno,0,new_table );
        curr_sym_tbl.push(new_table);
    }  
    namedexpr_test COLON suite while_stmt_deviation { 
        $$ = create_node(4,"While_stmt",$1,$3,$4);
    }
    ;

while_stmt_deviation: ELSE COLON {
        sym_table * new_table = new sym_table();
        new_table->return_type=curr_sym_tbl.top()->return_type;
        create_entry(curr_sym_tbl.top(),"else_while_block" , "Else_while_stmt" ,yylineno,0,new_table );
        curr_sym_tbl.push(new_table);
    } suite { $$ = create_node(4,"Else_block",$1,$2,$4);
    if(curr_sym_tbl.size()>1)
        curr_sym_tbl.pop();
    }
    | { $$ = NULL;}
    ;

for_stmt: FOR {
    sym_table * new_table = new sym_table();
    new_table->return_type=curr_sym_tbl.top()->return_type;
    create_entry(curr_sym_tbl.top(),"Block" , "For_block" ,yylineno,0,new_table );
    curr_sym_tbl.push(new_table);
    } 
    exprlist IN testlist COLON suite {
        if(curr_sym_tbl.size()>1)
            curr_sym_tbl.pop();
    } else_colon_suite_optional{
        $$ = create_node(8,"For_stmt",$1,$3,$4,$5,$6,$7,$9);
        //check if testlist is a list or range
        // cout<<$5->val<<endl;
        if(($5->type_of_node.size()<6 || $5->type_of_node.substr(0,4)!="list") ){
            cout<<"Error type is not iterable at line " <<yylineno <<". \n";
            // cout << $5->type_of_node.size()<<endl;
            // cout<<$5->type_of_node<<endl;

        }
        //check if the exprlist is same type as testlsit list [*]
        if(($5->type_of_node.substr(0,4)=="list") && $3->type_of_node!=$5->type_of_node.substr(5,$5->type_of_node.size()-6)){
            cout<<"Error  type is not same as iterable at line " <<yylineno <<". \n";
        }
        // cout<<$5->type_of_node<<endl;
    }
    ; 

else_colon_suite_optional : ELSE COLON {
    sym_table * new_table = new sym_table();
    new_table->return_type=curr_sym_tbl.top()->return_type;
    create_entry(curr_sym_tbl.top(),"Block" , "Else_block" ,yylineno,0,new_table );
    curr_sym_tbl.push(new_table);
    } suite { 
        $$ = create_node(4,"Else_block",$1,$2,$4);
        if(curr_sym_tbl.size()>1) curr_sym_tbl.pop();
    }
    | { $$ = NULL;}
    ;

/*using this notation instead of below one*/
funcdef:  DEF funcdef_title  func_body_suite { 
    $$ = create_node(4,"Func_def",$1,$2,$3);
    // cout << $2->lexeme << "TESSSSS"<< endl;
    if(curr_sym_tbl.size()>1 && string($2->lexeme)!="__init__")
    {
            // cout<<"poping "<<curr_sym_tbl.top()->name<<endl; 
            curr_sym_tbl.pop(); 
    } 
}
     /* | DEF NAME {parameter_vec.clear(); is_param=1;} parameters  COLON  func_body_suite { $$ = create_node(6,"Func_def",$1,$2,$3,$4,$5);}  */
    ;


funcdef_title: NAME {
    parameter_vec.clear(); is_param=1;} parameters func_type_hint_optional COLON { 
    $$ = create_node(5,"Func_def",$1,$3,$4,$5);
    $$->lexeme=$1->lexeme;
    // cout << $1->lexeme << "TESSSSS"<< endl;
    if(string($1->lexeme)=="__init__"){
        //continue;
        add_parameters(curr_sym_tbl.top(), parameter_vec);
        is_param=0;
        // cout<<endl<<"here ginf"<<endl;

    }
    else{
        sym_table * new_table = new sym_table();
        string func_type="func";
        if($4!=NULL){
            func_type=$4->lexeme;
            
        }
        else
            func_type="None";
        create_entry(curr_sym_tbl.top(),  $1->lexeme,func_type,yylineno,__FUNC__,new_table );
        curr_sym_tbl.push(new_table);
        add_parameters(curr_sym_tbl.top(), parameter_vec);
        is_param=0;
        $$->type_of_node= func_type;
        curr_sym_tbl.top()->return_type= func_type;
    }
}
;

func_type_hint_optional: FUNC_TYPE_HINT {$$ = $1; $$->type_of_node= $1->val;}
    | { $$ = NULL;}
    ;

// Written only to run START ye dono document se dekhna hai
parameters: SMALL_OPEN typedarglist SMALL_CLOSE {$$ = create_node(4,"Arguments",$1,$2,$3);}
    |SMALL_OPEN SMALL_CLOSE {$$ = create_node(3,"Parantheses",$1,$2);}
    ;

typedarglist:
    typedlist_arguments {$$ = $1;}
    ;

typedlist_arguments: typedlist_argument comma_option_argument_star {$$ = create_node(3,"Arguments",$1,$2);};

typedlist_argument: tfpdef  { $$ = $1;}
    |  tfpdef EQUAL test { 
        $$ = create_node(4,"Assign_expr",$1,$2,$3);
        
        if($1->type_of_node!=$3->type_of_node && (($1->type_of_node!="int" && $1->type_of_node!="float") || ( $3->type_of_node!="int" && $3->type_of_node!="float"))){
            cout<<"Error --typedlist_argument-- invalid type at line " <<yylineno <<endl;
        }
        $$->type_of_node= $1->type_of_node;
    }
    ;
// x:int = 24
comma_option_argument_star: comma_option_argument_star COMMA typedlist_argument {$$ = create_node(4,"Arguments",$1,$2,$3);}
    | { $$ = NULL;}
    ;


tfpdef: NAME { $$ = $1; 
        // cout<<"this is running";
        if((string($1->lexeme)!="print" && string($1->lexeme)!="range"&& string($1->lexeme)!="len") &&  !search_sym_table(curr_sym_tbl.top(),$1->lexeme,0)){
            cout<<"Sym_tbl_error: Variable "<<$1->lexeme<<" not declared at line "<<yylineno<<endl;
            // cout<<"this is running in if"<<endl;
            // give error as type hint not found
        }
        $$->type_of_node= search_type_in_sym_table(curr_sym_tbl.top(),$1->lexeme);
        }
    | NAME TYPE_HINT { $$ = create_node(3,"Identifier",$1,$2); 
        if(is_param) {
            add_to_vector(parameter_vec, $1->lexeme, $2->lexeme,yylineno);
        }
        else{
        delete_sym_table(curr_sym_tbl.top(),$1->lexeme);
        create_entry(curr_sym_tbl.top(),  $1->lexeme,$2->lexeme,yylineno,0,NULL );
        }
        $$->type_of_node= $2->lexeme;

    }
    | NAME COLON test {
        //ignore this production
        $$ = create_node(4,"Identifier",$1,$2,$3);
        $$->type_of_node= search_type_in_sym_table(curr_sym_tbl.top(),$1->lexeme);


    }
    ;

func_body_suite: simple_stmt {$$ = $1; 
        // if(curr_sym_tbl.size()>1)
        //     curr_sym_tbl.pop();    
    }
    | NEWLINE INDENT stmt_plus DEDENT { $$ = $3;
    // if(curr_sym_tbl.size()>1)
    //     curr_sym_tbl.pop();
    }

suite: simple_stmt {$$ = $1;}
    | NEWLINE INDENT stmt_plus DEDENT { $$ = $3;}
    ;

stmt_plus: stmt stmt_plus {$$ = create_node(3,"Stmts",$1,$2);
    }
    | stmt {$$ = $1;}
    ;

simple_stmt: small_stmt semi_colon_small_stmt_star NEWLINE {
        $$ = create_node(3,"Simple_stmts",$1,$2);
       
        
    }
    ;

semi_colon_small_stmt_star: SEMI_COLON small_stmt semi_colon_small_stmt_star {$$ = create_node(4,"Small_stmts",$1,$2,$3);
        // if($3 && $3->type_of_node!="undefined")
        //     $$->type_of_node= $3->type_of_node;
        // else 
        //     $$->type_of_node= $2->type_of_node;
       
    }
    | SEMI_COLON {$$ = $1;}
    | { $$ = NULL;}
    ;

small_stmt: expr_stmt {$$ = $1;}
    | flow_stmt {$$ = $1;}
    | global_stmt {$$ = $1;}
    | nonlocal_stmt {$$ = $1;}
    | assert_stmt {$$ = $1;}
    ;

flow_stmt: break_stmt {$$ = $1;}
    | continue_stmt {$$ = $1;}
    | return_stmt {$$ = $1;}
    | raise_stmt {$$ = $1;}
    ;
    
break_stmt: BREAK {$$  = $1;};

continue_stmt: CONTINUE {$$ = $1;};

return_stmt: RETURN testlist_star_expr {
        $$ = create_node(3,"Return_stmt",$1,$2);
        if($2->type_of_node=="float" && curr_sym_tbl.top()->return_type=="int"){
            //continue; change float val to int
        }
        else if($2->type_of_node=="int" && curr_sym_tbl.top()->return_type=="float"){
          //continue; change int val to float
        }
        else if($2->type_of_node!=curr_sym_tbl.top()->return_type){
            cout<<$2->type_of_node<<" "<<curr_sym_tbl.top()->name<<" hehe"<<endl;
            cout<<"Error --return_stmt-- invalid return type at line " <<yylineno <<". Expected "<<curr_sym_tbl.top()->return_type<<endl;
        }
        
    }
    | RETURN {
        $$ = $1;
        if(curr_sym_tbl.top()->return_type!="None"){
            cout<<"Error --return_stmt-- invalid return type at line " <<yylineno <<". Expected "<<curr_sym_tbl.top()->return_type<<endl;
        }
    }
    ;

raise_stmt: RAISE {$$ = $1;}
    | RAISE test {$$ = create_node(3,"Raise_stmt",$1,$2);}
    | RAISE test FROM test {$$ = create_node(5,"Raise_stmt",$1,$2,$3,$4);}
    ;

global_stmt: GLOBAL NAME comma_name_star {$$ = create_node(4,"Global_stmt",$1,$2,$3);};

nonlocal_stmt: NONLOCAL NAME comma_name_star {$$ = create_node(4,"Nonlocal_stmt",$1,$2,$3);};

comma_name_star: COMMA NAME comma_name_star {$$ = create_node(4,"Identifiers",$1,$2,$3);}
    | { $$ = NULL;}
    ;

assert_stmt: ASSERT test COMMA test {$$ = create_node(5,"Assert_stmt",$1,$2,$3,$4);}
    | ASSERT test {$$ = create_node(3,"Assert_stmt",$1,$2);}
    ;

expr_stmt: testlist_star_expr annassign {$$ = create_node(3,"Expr_stmt",$1,$2);
    //didnt get this production to use in the code so didnt implement the type_of_node
    }
    | testlist_star_expr augassign testlist {
    $$ = create_node(4,"Expr_stmt",$1,$2,$3);
    if(string($2->lexeme)=="&=" || string($2->lexeme)=="|=" || string($2->lexeme)=="^=" || string($2->lexeme)=="<<=" || string($2->lexeme)==">>="){
        if($1->type_of_node!="int" || $3->type_of_node!="int"){
            cout<<"Error --expr_stmt2-- invalid type at line " <<yylineno <<". Expected int\n";
        }
        
    }
    else if(($1->type_of_node!="int" && $1->type_of_node!="float") || ($3->type_of_node!="int" && $3->type_of_node!="float")){
        cout<<"line 323 "<<$1->type_of_node<<" "<<$3->type_of_node<<endl;
        cout<<"-Error --expr_stmt3-- invalid type at line " <<yylineno <<". Expected int or float\n";
    }
    $$->type_of_node= $1->type_of_node;

    }
    |testlist_star_expr  {$$ = $1;}
    |testlist_star_expr expr_stmt_option1_plus  {
        $$ = create_node(3,"Expr_stmt",$1,$2);
        if($1->type_of_node!=$2->type_of_node && (($1->type_of_node!="int" && $1->type_of_node!="float") || ( $2->type_of_node!="int" && $2->type_of_node!="float"))){
            cout<<"Error --expr_stmt4-- invalid type at line " <<yylineno <<". Expected "<<$1->type_of_node<<endl;
            cout<<$1->type_of_node<<" "<<$2->type_of_node<<endl;
            
        }
        $$->type_of_node= $1->type_of_node;
    }
    ;
    

testlist:  test symbol_test_star  {$$ = create_node(3,"Expressions",$1,$2);
    $$->type_of_node = $1->type_of_node;
    }
    
symbol_test_star: COMMA test symbol_test_star {$$ = create_node(4,"Expressions",$1,$2,$3);}
    | COMMA {$$ = $1;}
    |{$$=NULL;} 
    ;

expr_stmt_option1_plus:EQUAL testlist_star_expr expr_stmt_option1_plus {
    $$ = create_node(4,"Expr_stmt",$1,$2,$3);
    if($3!=NULL && $3->type_of_node!=$2->type_of_node){
        cout<<"Error --expr_stmt_option1_plus-- invalid type at line " <<yylineno <<". Expected "<<$2->type_of_node<<endl;
    }
    $$->type_of_node= $2->type_of_node;
}
    // |TYPE_HINT EQUAL testlist_star_expr
    | EQUAL testlist_star_expr {$$ = create_node(3,"Expr_stmt",$1,$2);
        $$->type_of_node= $2->type_of_node;
    }
    ;

annassign: COLON test {$$ = create_node(3,"Identifiers",$1,$2); 
    //didnt get this production to use in the code so didnt implement the type_of_node
    cout<<"Annassign1"<<endl;
    }
    | COLON test EQUAL testlist_star_expr {$$ = create_node(5,"Identifiers",$1,$2,$3,$4);
    //didnt get this production to use in the code so didnt implement the type_of_node
    cout<<"Annassign2"<<endl;
    }
    ;

testlist_star_expr: test testlist_star_expr_option1_star {
        $$ = create_node(3,"Expressions",$1,$2);
        // if($2==NULL || $2->type_of_node=="undefined"){
        //     $$->type_of_node= $1->type_of_node;
        // }else{
        //     $$->type_of_node= $1->type_of_node;
        // }
        $$->type_of_node= $1->type_of_node;
        if($2 && $2->type_of_node!="undefined"){
            $$->type_of_node= $2->type_of_node;
        }
        // cout<<$$->type_of_node<<" in line 4444"<<endl;
    }
    ;

testlist_star_expr_option1_star: COMMA test testlist_star_expr_option1_star {
        $$ = create_node(4,"Expressions",$1,$2,$3);
        cout << "testlist_star_expr_option1_star" << endl;
        // if($3 || $3->type_of_node=="undefined"){
        //     // continue;
        //     cout <<"if is running" << endl;
        // }
        // else if($2->type_of_node!=$3->type_of_node){
        //     cout<<"Error --testlist_star_expr_option1_star-- invalid type at line " <<yylineno <<". Expected "<<$2->type_of_node<<endl;
        // }
        // else{
        //     $$->type_of_node= $2->type_of_node;
        // }
    }
    | COMMA {$$ = $1;}
    |{$$=NULL;}
    ;

augassign: ADD_EQUAL {$$ = $1;} 
    | SUB_EQUAL {$$ = $1;} 
    | MUL_EQUAL {$$ = $1;} 
    | AT_EQUAL {$$ = $1;}
    | DIV_EQUAL {$$ = $1;}
    | MOD_EQUAL {$$ = $1;} 
    | BITWISE_AND_EQUAL {$$ = $1;} 
    | BITWISE_OR_EQUAL {$$ = $1;} 
    | BITWISE_XOR_EQUAL {$$ = $1;}
    | SHIFT_LEFT_EQUAL {$$ = $1;} 
    | SHIFT_RIGHT_EQUAL {$$ = $1;} 
    | POW_EQUAL {$$ = $1;} 
    | FLOOR_DIV_EQUAL {$$ = $1;} 
    ;

expr: xor_expr symbol_xor_expr_star {
    $$ = create_node(3,"Expressions",$1,$2);
     if($2==NULL || $2->type_of_node=="undefined"){
        $$->type_of_node= $1->type_of_node;
    }else{
        if($2->type_of_node!="int" || $1->type_of_node!="int"){
            cout<<"Error --expr-- invalid type at line " <<yylineno <<". Expected int\n";
        }
        $$->type_of_node= $1->type_of_node;
    }
}

/* star_expr: MUL expr {
        $$ = create_node(3,"Expressions",$1,$2);
        //check if expr is of type list
        if($2->type_of_node.size()<6 || $2->type_of_node.substr(0,4)!="list"){
            cout<<"Error invalid type at line " <<yylineno <<". Expected list\n";
        }
        
    }; */

symbol_xor_expr_star: BITWISE_OR xor_expr symbol_xor_expr_star {
        $$ = create_node(4,"Or_exprs",$1,$2,$3);
        if($2->type_of_node!="int" ){
            cout<<"Error --symbol_xor_expr_star-- invalid type at line " <<yylineno <<". Expected int\n";
        }
        $$->type_of_node= $2->type_of_node;
    }
    | /*empty*/ {$$=NULL;}
    ;

xor_expr: and_expr symbol_and_expr_star {
    $$ = create_node(3,"Expressions",$1,$2);
    if($2==NULL || $2->type_of_node=="undefined"){
        $$->type_of_node= $1->type_of_node;
    }else{
        if($2->type_of_node!="int" || $1->type_of_node!="int"){
            cout<<"Error --xor_expr-- invalid type at line " <<yylineno <<". Expected int\n";
        }
        $$->type_of_node= $2->type_of_node;
    }
};

symbol_and_expr_star: BITWISE_XOR and_expr symbol_and_expr_star {
        $$ = create_node(4,"Xor_exprs",$1,$2,$3);
        if($2->type_of_node!="int" ){
            cout<<"Error --symbol_and_expr_star-- invalid type at line " <<yylineno <<". Expected int\n";
        }
        $$->type_of_node = $2->type_of_node;
    }
    | /*empty*/ {$$=NULL;}
    ;

and_expr: shift_expr symbol_shift_expr_star {
    $$ = create_node(3,"Expressions",$1,$2);
    if($2==NULL || $2->type_of_node=="undefined"){
        $$->type_of_node= $1->type_of_node;
    }else{
        if($2->type_of_node!="int"|| $1->type_of_node!="int" ){
            cout<<"Error --and_expr-- invalid type at line " <<yylineno <<". Expected int\n";
        }
        $$->type_of_node= $2->type_of_node;
    }
};

symbol_shift_expr_star: BITWISE_AND shift_expr symbol_shift_expr_star {
        $$ = create_node(4,"And_exprs",$1,$2,$3);
        if($2->type_of_node!="int" ){
            cout<<"Error --symbol_shift_expr_star-- invalid type at line " <<yylineno <<". Expected int\n";
        }
        $$->type_of_node = $2->type_of_node;
    }
    | /*empty*/ {$$=NULL;}
    ;

shift_expr: arith_expr shift_arith_expr_star {
    $$ = create_node(3,"Expressions",$1,$2);
    if($2==NULL || $2->type_of_node=="undefined"){
        $$->type_of_node= $1->type_of_node;
    }else{
        if($2->type_of_node!="int" || $1->type_of_node!="int"){
            cout<<"Error --shift_expr-- invalid type at line " <<yylineno <<". Expected int\n";
        }
        $$->type_of_node= $2->type_of_node;
    }
};

shift_arith_expr_star: /*empty*/ {$$=NULL;}
    | SHIFT_LEFT arith_expr shift_arith_expr_star {
        $$ = create_node(4,"Shift_left_expr",$1,$2,$3);
        if($2->type_of_node!="int" ){
            cout<<"Error --shift_arith_expr_star-- invalid type at line " <<yylineno <<". Expected int\n";
        }
        $$->type_of_node = $2->type_of_node;
    }
    | SHIFT_RIGHT arith_expr shift_arith_expr_star {
        $$ = create_node(4,"Shift_right_expr",$1,$2,$3);
        if($2->type_of_node!="int" ){
            cout<<"Error --shift_arith_expr_star-- invalid type at line " <<yylineno <<". Expected int\n";
        }
        $$->type_of_node = $2->type_of_node;
    }
    ;

arith_expr: term symbol_term_star  {
    $$ = create_node(3,"Expressions",$1,$2);
    if($2==NULL || $2->type_of_node=="undefined"){
        $$->type_of_node= $1->type_of_node;
    }else if($2->type_of_node!="int" && $2->type_of_node!="float"){
        cout<<"Error --arith_expr-- invalid type at line " <<yylineno <<". Expected int or float\n";
    }else if($1->type_of_node=="float" || $2->type_of_node=="float"){
        $$->type_of_node= "float";
    }else{
        $$->type_of_node= "int";
    }
    if($2!=NULL && $2->type_of_node!="undefined"){
        string reg=newTemp();
        $1->addr="t45";
        $2->addr="t41";
        create_ins(3,$2->residual_ins, reg,$1->addr, $2->addr);
        $$->addr=reg;
    }
} ;

symbol_term_star: /*empty*/ {$$=NULL;}
    | ADD term symbol_term_star {
        $$ = create_node(4,"Operator_expr",$1,$2,$3);
        if($2->type_of_node!="int" && $2->type_of_node!="float"){
            cout<<"Error --symbol_term_star-- invalid type at line " <<yylineno <<". Expected int or float\n";
        }
        if($3==NULL || $3->type_of_node=="undefined"){
            $$->type_of_node= $2->type_of_node;
        }else if($3->type_of_node!="int" && $3->type_of_node!="float"){
            cout<<"Error --symbol_term_star-- invalid type at line " <<yylineno <<". Expected int or float\n";
        }else if($2->type_of_node=="float" || $3->type_of_node=="float"){
            $$->type_of_node= "float";
        }else{
            $$->type_of_node= "int";
        }
        if($3!=NULL && $3->type_of_node!="undefined"){
        string reg=newTemp();
        $2->addr="t45";
        $3->addr="t45";
        $1->addr="t34";
        create_ins(3,$3->residual_ins, reg,$2->addr, $3->addr);
        $$->addr=reg;
        $$->residual_ins="+";
        }
    }
    | SUB term symbol_term_star {
        $$ = create_node(4,"Operator_expr",$1,$2,$3);
        if($2->type_of_node!="int" && $2->type_of_node!="float"){
            cout<<"Error --symbol_term_star-- invalid type at line " <<yylineno <<". Expected int or float\n";
        }
        if($3==NULL || $3->type_of_node=="undefined"){
            $$->type_of_node= $2->type_of_node;
        }else if($3->type_of_node!="int" && $3->type_of_node!="float"){
            cout<<"Error -- invalid type at line " <<yylineno <<". Expected int or float\n";
        }else if($2->type_of_node=="float" || $3->type_of_node=="float"){
            $$->type_of_node= "float";
        }else{
            $$->type_of_node= "int";
        
        }
        if($3!=NULL && $3->type_of_node!="undefined"){
        string reg=newTemp();
        // create_ins(3,$3->residual_ins, reg,$2->addr, $3->addr);
        // $$->addr=reg;
        // $$->residual_ins="+";
        }
    }
    ;

term: factor symbol_factor_star {
    $$ = create_node(3,"Terms",$1,$2);
    if($2==NULL){
        $$->type_of_node= $1->type_of_node;
    }else if($2->type_of_node!="int" && $2->type_of_node!="float"){
        cout<<"line 495 ";
        cout<<"Error --term-- invalid type at line " <<yylineno <<". Expected int or float\n";
        
    }else if($1->type_of_node!="float" && $1->type_of_node!="int"){
        cout<<"Error --term-- invalid type at line " <<yylineno <<". Expected int or float\n";
    }
    else {
        if($1->type_of_node=="float" || $2->type_of_node=="float")
            $$->type_of_node= "float";
        else
            $$->type_of_node= "int";
    }
    };
    


symbol_factor_star: /*empty*/ {$$=NULL;}
    | symbol_factor symbol_factor_star {$$ = create_node(3,"Terms",$1,$2);
    if($1->type_of_node!="int" && $1->type_of_node!="float"){
        cout<<"Error --symbol_factor_star-- invalid type at line " <<yylineno <<". Expected int or float\n";
    }
    if($2!=NULL && $2->type_of_node!="int" && $2->type_of_node!="float"){
        cout<<"Error --symbol_factor_star-- invalid type at line " <<yylineno <<". Expected int or float\n";
    }

    if($1->type_of_node=="float" || ($2!=NULL && $2->type_of_node=="float"))
        $$->type_of_node= "float";
    else
        $$->type_of_node= "int";
    
    };

symbol_factor: MUL factor {
        $$ = create_node(3,"Mul_term",$1,$2);
        if($2->type_of_node!="int" && $2->type_of_node!="float"){
            cout<<"Error --symbol_factor-- invalid type at line " <<yylineno <<". Expected int or float\n";
        }
        $$->type_of_node = $2->type_of_node;
    }
    // | AT factor {$$ = create_node(3,"At_term",$1,$2);}
    | DIV factor {
        $$ = create_node(3,"Div_term",$1,$2);
        if($2->type_of_node!="int" && $2->type_of_node!="float"){
            cout<<"Error --symbol_factor-- invalid type at line " <<yylineno <<". Expected int or float\n";
        }
        $$->type_of_node = "float";
        // $$->type_of_node = $2->type_of_node;
    }
    | FLOOR_DIV factor {
        $$ = create_node(3,"Div_term",$1,$2);
        if($2->type_of_node!="int" && $2->type_of_node!="float"){
            cout<<"Error --symbol_factor-- invalid type at line " <<yylineno <<". Expected int or float\n";
        }
        $$->type_of_node = $2->type_of_node;
    }
    | MOD factor {
        $$ = create_node(3,"Mod_term",$1,$2);
        if($2->type_of_node!="int" && $2->type_of_node!="float"){
            cout<<"Error --symbol_factor-- invalid type at line " <<yylineno <<". Expected int or float\n";
        }
        $$->type_of_node = $2->type_of_node;
    }
    ;

factor: ADD factor {
        $$ = create_node(3,"Add_term",$1,$2);
        if($2->type_of_node!="int" && $2->type_of_node!="float"){
            cout<<"Error --factor-- invalid type at line " <<yylineno <<". Expected int or float\n";
        }
        $$->type_of_node = $2->type_of_node;
    }
    | SUB factor {
        $$ = create_node(3,"Sub_term",$1,$2);
        if($2->type_of_node!="int" && $2->type_of_node!="float"){
            cout<<"Error --factor-- invalid type at line " <<yylineno <<". Expected int or float\n";
        }
        $$->type_of_node = $2->type_of_node;
    }
    | TILDE factor {
        $$ = create_node(3,"Tilde_term",$1,$2);
        if($2->type_of_node!="int" && $2->type_of_node!="float"){
            cout<<"Error --factor-tilde-- invalid type at line " <<yylineno <<". Expected int or float\n";
        }
        $$->type_of_node = $2->type_of_node;
    }
    | power {$$ = $1;}
    ;
    
power: atom_expr {$$ = $1;}
    | atom_expr POW factor {$$ = create_node(4,"Power_term",$1,$2,$3);
        if(!($3->type_of_node=="int" || $3->type_of_node=="float")){
            cout<<"Error --power-- invalid power type at line " <<yylineno <<". Expected int or float.\n";
        }else if(!($1->type_of_node=="int" || $1->type_of_node=="float")){
            cout<<"Error --power2-- invalid power type at line " <<yylineno <<". Expected int or float\n";
        }else{
            if($1->type_of_node=="float" || $3->type_of_node=="float")
                $$->type_of_node= "float";
            else
                $$->type_of_node= "int";
        }
    }
    ;

atom_expr: AWAIT atom trailer_star {$$=create_node(4,"Await_stmt",$1,$2,$3);}
    | atom trailer_star{
        
        if(is_dot_name == __TDOT__){
            string full_name=string($1->lexeme)+after_dot_name;
            delete_sym_table(curr_sym_tbl.top(),full_name);
            create_entry(curr_sym_tbl.top(),full_name,$2->type_of_node,yylineno,0,NULL );
            // $$->type_of_node = $3->lexeme;
            is_dot_name=0;
        }
        else if( is_dot_name== __DOT__){
            string full_name=string($1->lexeme)+after_dot_name;
            // cout<<$$->type_of_node<<" this is type"<<endl;
            // cout<<full_name<<" this is full name"<<endl;
            is_dot_name=0;
        }

        $$=create_node(3,"Terms", $1,$2);
        if($2 && $2->type_of_node.substr(0,3)=="Box" && $2->type_of_node!="Box;int"){
            cout<<"Error --atom_expr--- invalid type at line " <<yylineno <<". Expected int\n";
        }
        // if($2)
        //     cout<<$2->type_of_node<<" Thissss"<<endl;
        if($2==NULL ){
            string temp_type = $1->type_of_node;
            $$->type_of_node= $1->type_of_node;
            // cout<<$$->type_of_node<<endl;
        }else{
            // $$->type_of_node= $1->type_of_node+";"+$2->type_of_node;
            if($2->type_of_node.substr(0,3)=="Box" ){
                if($1->type_of_node.size()<6 || $1->type_of_node.substr(0,4)!="list"){
                    cout<<"Error --atom_expr-- invalid dereferencing of a type at line no "<<yylineno<<endl;
                }
                if($1->type_of_node.size()>=6){
                    string temp_type = $1->type_of_node.substr(5,$1->type_of_node.size()-6);
                    $$->type_of_node= temp_type;                
                }
            }
            else if($2->type_of_node.size()>=5 && $2->type_of_node.substr(0,5)=="Small"){
                $$->type_of_node= $1->type_of_node;
            }
            else{
                string full_name=string($1->lexeme)+after_dot_name;
                $$->type_of_node = search_type_in_sym_table(curr_sym_tbl.top(),full_name);

            }
        }
    }
    ;

trailer_star:  trailer trailer_star  {
        $$ = create_node(3,"Stmts",$1,$2);
        $$->type_of_node=$1->type_of_node;
        if($2!=NULL){
            //check if first 3 substring is  Box
            if($1->type_of_node.substr(0,3)=="Box" || ($1->type_of_node.size()>=5 && $1->type_of_node.substr(0,5)=="Small")){
                    cout<<"Error --trailer_star-- invalid sequence of dereferencing at line no "<<yylineno<<endl;
            }
            
        }
    }
    | /*empty*/{$$=NULL;}
    ;


trailer: SMALL_OPEN arglist SMALL_CLOSE  {
        $$ = create_node(4,"Arguments",$1,$2,$3);
        $$->type_of_node = "Small";
    }
    |SMALL_OPEN SMALL_CLOSE { 
        $$ = create_node(3,"Parantheses",$1,$2);
        $$->type_of_node = "Small";
    }
    |BOX_OPEN subscriptlist BOX_CLOSE {$$ = create_node(4,"Square_bracket",$1,$2,$3);
        $$->type_of_node = "Box;"+$2->type_of_node;
        // cout<<"trailer"<<endl;
    }
    |DOT NAME TYPE_HINT {
        is_dot_name=__TDOT__;
        $$ = create_node(4,"Identifier",$1,$2,$3);
        $$->type_of_node = $3->lexeme;
        after_dot_name="."+ string($2->lexeme);

        // delete_sym_table(curr_sym_tbl.top(),$2->lexeme);
        // create_entry(curr_sym_tbl.top(),  $2->lexeme,$3->lexeme,yylineno,0,NULL );
        // $$->type_of_node = $3->lexeme;
    }
    |DOT NAME { 
        $$ = create_node(3,"Identifier",$1,$2);
        is_dot_name=__DOT__;
        after_dot_name="."+ string($2->lexeme);
        // $$->type_of_node = search_type_in_sym_table(curr_sym_tbl.top(),$2->lexeme);
        // if(!search_sym_table(curr_sym_tbl.top(),$2->lexeme,0)){
        //     cout<<"Sym_tbl_error: Variable "<<$2->lexeme<<" not declared at line "<<yylineno<<endl;
        //     cout<<curr_sym_tbl.top()->prev_sym_table->name<<" this also"<<endl;
        //     // give error as type hint not found
        // }
        // $$->type_of_node = search_type_in_sym_table(curr_sym_tbl.top(),$2->lexeme);

    }
    ;


classdef: CLASS NAME {
            parameter_vec.clear(); is_param=1;
        }
        bracket_arglist_optional COLON {
        sym_table * new_table = new sym_table();
        create_entry(curr_sym_tbl.top(),$2->lexeme , $2->lexeme ,yylineno,__CLASS__,new_table );
        curr_sym_tbl.push(new_table);
        add_parameters(curr_sym_tbl.top(), parameter_vec);
        is_param=0;
        }
        suite {
            $$=create_node(6,"Class_def",$1,$2,$4,$5,$7);
            if(curr_sym_tbl.size()>1)
                curr_sym_tbl.pop();
        };

/* classdef: CLASS NAME bracket_arglist_optional COLON suite {
    $$=create_node(6,"Class_def",$1,$2,$3,$4,$5);
    // sym_table * new_table = new sym_table();
    // create_entry(curr_sym_tbl.top(),  $2->val,"class",yylineno,0,4,0,new_table );
    // curr_sym_tbl.push(new_table);

}; */

bracket_arglist_optional: SMALL_OPEN SMALL_CLOSE {$$=create_node(3,"Parantheses",$1,$2);}
    | SMALL_OPEN arglist SMALL_CLOSE {$$=create_node(4,"Arguments",$1,$2,$3);
    }
    | {$$=NULL;}
    ;

arglist: argument_list COMMA {
        $$=create_node(3,"Arguments",$1,$2);
    }
    | argument_list {$$=$1;}
    ;

argument_list: argument_list COMMA argument { $$=create_node(4,"Arguments",$1,$2,$3);}
    | argument { $$=$1;}
    ;

subscriptlist: subscript_list COMMA {$$=create_node(3,"Terms",$1,$2);
        $$->type_of_node=$1->type_of_node;
    }
    | subscript_list { $$=$1;}
    ;

subscript_list: subscript_list COMMA subscript { $$=create_node(4,"Terms",$1,$2,$3);
        $$->type_of_node=$3->type_of_node;
    }
    | subscript { $$=$1; }
    ;


subscript: test {$$=$1;}
   // |   optional_test COLON optional_test{ $$=create_node(4,"Terms",$1,$2,$3);}
    ;


argument: test { $$ = $1;}
    | test comp_for {$$=create_node(3,"Terms",$1,$2);}
    | test EQUAL test  {$$=create_node(4,"Assign_term",$1,$2,$3);
        if($1->type_of_node!=$3->type_of_node && (($1->type_of_node!="int" && $1->type_of_node!="float") || ( $3->type_of_node!="int" && $3->type_of_node!="float"))){
            cout<<"Error --argument-- invalid type assign at line " <<yylineno <<".";
        }
        cout<<"arg working"<<endl;
        // $$->type_of_node=$1->type_of_node;
    }
    | POW test {$$=create_node(3,"Power_term",$1,$2);}
    | MUL test {$$=create_node(3,"Mul_term",$1,$2);}
    ;



comp_iter: comp_for {$$=$1;}
    | comp_if {$$=$1;}
    ;

sync_comp_for: FOR exprlist IN or_test {$$=create_node(5,"For_stmt",$1,$2,$3,$4);}
    | FOR exprlist IN or_test comp_iter {$$=create_node(6,"For_stmt",$1,$2,$3,$4,$5);}
    ;


comp_for:  sync_comp_for {$$=$1;}
    | ASYNC sync_comp_for {$$=create_node(3,"Async_stmt",$1,$2);}
    ;

comp_if: IF test_nocond {$$=create_node(3,"IF_stmt",$1,$2);}
    | IF test_nocond comp_iter {$$ = create_node(4,"IF_stmt",$1,$2,$3);}
    ;

test_nocond: or_test {$$=$1;};

or_test: and_test or_and_test_star{$$=create_node(3,"Expressions",$1,$2);
    if($2==NULL)
        $$->type_of_node=$1->type_of_node;
    else{
        // karna hai
        }
    };

or_and_test_star:OR and_test or_and_test_star {$$=create_node(4,"OR_term",$1,$2,$3);}
    | { $$ = NULL;}
    ;
    
and_test: not_test and_not_test_star {$$=create_node(3,"Expressions",$1,$2);
    if($2==NULL)
        $$->type_of_node=$1->type_of_node;
    else{
        // karna hai
        }
};

and_not_test_star: AND not_test and_not_test_star {$$=create_node(4,"And_term",$1,$2,$3);}
    | { $$ = NULL;}
    ;

not_test: NOT not_test {$$=create_node(3,"Not_term",$1,$2);}
    | comparison {$$=$1;
    $$->type_of_node=$1->type_of_node;
    }
    ;
    
comparison: expr comp_op_expr_plus {$$=create_node(3,"Expressions",$1,$2);
    if($2==NULL)
        $$->type_of_node=$1->type_of_node;
    else{
        // karna hai
        }
    }
    |expr {$$=$1;
    $$->type_of_node=$1->type_of_node;
    }
   ;

comp_op_expr_plus: comp_op expr comp_op_expr_plus {$$=create_node(3,"Expresions",$1,$2);}
    | comp_op expr {$$=create_node(3,"Expressions",$1,$2);}
    ;


comp_op: LT {$$=$1;}
    |GT {$$=$1;}
    |DOUBLE_EQUAL {$$=$1;}
    |GE {$$=$1;}
    |LE {$$=$1;}
    |NE {$$=$1;}
    |IN {$$=$1;}
    |NOT IN  {$$=create_node(3, "Not In", $1,$2);}
    |IS {$$=$1;}
    |IS NOT {$$=create_node(3, "Is Not", $1,$2);}
    ;



exprlist: 
     expr_star_expr_option_list {$$=$1;}
    ;

expr_star_expr_option: expr {$$=$1;}
    ;

expr_star_expr_option_list: expr_star_expr_option COMMA expr_star_expr_option_list {$$=create_node(4,"Expressions",$1,$2,$3);}
    | expr_star_expr_option COMMA {$$=create_node(3,"Expressions",$1,$2);}
    | expr_star_expr_option {$$=$1;}
    ;

testlist_comp: namedexpr_test_star_expr_option comp_for {$$=create_node(3,"Expressions",$1,$2);} 
    | namedexpr_test_star_expr_option_list  {$$=$1;}
    ; 


namedexpr_test_star_expr_option_list: namedexpr_test_star_expr_option COMMA namedexpr_test_star_expr_option_list {$$=create_node(4,"Expressions",$1,$2,$3); $$->type_of_node=$1->type_of_node;}
    | namedexpr_test_star_expr_option COMMA {$$=create_node(3,"Expressions",$1,$2); $$->type_of_node=$1->type_of_node;}
    | namedexpr_test_star_expr_option {$$=$1; }
    ;

namedexpr_test_star_expr_option: namedexpr_test {$$=$1;}
    ;

namedexpr_test: test {$$=$1;};

test: or_test {$$=$1;}
    |or_test IF or_test ELSE test {$$=create_node(6,"Expressions",$1,$2,$3,$4,$5);
    if($1->type_of_node!=$5->type_of_node){
        cout<<"Error --test-- invalid type assign at line " <<yylineno <<".";
    }
    $$->type_of_node=$1->type_of_node;
    cout<<$$->type_of_node<<"hello"<<endl;
    };

atom: SMALL_OPEN testlist_comp SMALL_CLOSE {
        $$=create_node(4,"Arguments",$1,$2,$3);
        $$->type_of_node = $2->type_of_node;
    }
    | SMALL_OPEN SMALL_CLOSE {$$=create_node(3,"Parantheses",$1,$2);}
    | BOX_OPEN testlist_comp BOX_CLOSE {$$=create_node(4,"Square_bracket",$1,$2,$3);$$->type_of_node="list["+$2->type_of_node+"]";}
    | BOX_OPEN BOX_CLOSE {$$=create_node(3,"Square_bracket",$1,$2);}
    | CURLY_OPEN CURLY_CLOSE {$$=create_node(3,"Curly_bracket",$1,$2);}
    | NAME {
        string curr_type = search_type_in_sym_table(curr_sym_tbl.top(),$1->lexeme);
        $1->type_of_node = curr_type; 
        $$=$1;
        $$->addr=$1->lexeme;
        if((string($1->lexeme)!="print" && string($1->lexeme)!="range"&& string($1->lexeme)!="len"&& string($1->lexeme)!="main") &&  !search_sym_table(curr_sym_tbl.top(),$1->lexeme,0)){
            cout<<"Sym_tbl_error: Variable "<<$1->lexeme<<" not declared at line "<<yylineno<<endl;
            // give error as type hint not found
        }
        $$->type_of_node=curr_type;
    }
    | NAME TYPE_HINT {
        $$=create_node(3,"Identifier", $1, $2); 
        $$->addr=$1->lexeme;
        $$->type_of_node = $2->lexeme;
    if(is_param) {
        add_to_vector(parameter_vec, $1->lexeme, $2->lexeme,yylineno);
    }
    else{
        delete_sym_table(curr_sym_tbl.top(),$1->lexeme);
        create_entry(curr_sym_tbl.top(),  $1->lexeme,$2->lexeme,yylineno,0,NULL );
    }
    }
    | number {$$=$1;}
    | string_plus {$$=$1;}
    | TRUE {$$=$1;$$->type_of_node="int";}
    | FALSE {$$=$1;$$->type_of_node="int";}
    | NONE {$$=$1;$$->type_of_node="None";}
    ;
// dictionary , setliterals are to be ignored

number: INTEGER {$$ = $1;
        $$->addr=$$->lexeme;
    }
    | FLOAT {$$ = $1;
        $$->addr=$$->lexeme;
    }
    ;

string_plus: STRING string_plus {$$=create_node(3,"Strings", $1, $2);}
    | STRING {$$=$1;
        $$->addr=$$->lexeme;
    }
    ;



%%

NODE* convertParseTreeToAST(NODE* parseTree) {
    if (parseTree == nullptr) {
        return nullptr;
    }

    // If the node is a non-terminal, then skip this node and directly return the AST of the child.
    if (parseTree != start_node){
        NODE* temp = NULL;
        int temp_count = 0;
        for(int i=0;i<parseTree->children.size();i++)
        {
            if(parseTree->children[i]!=NULL){
                temp = parseTree->children[i];
                temp_count++;
            }
        }
        if(temp_count==1){
            //delete the current node and return the child node
            parseTree = NULL;
            return convertParseTreeToAST(temp);
        }
    }

    NODE* astNode = new NODE;
    astNode->id = parseTree->id;
    astNode->lexeme=parseTree->lexeme;
    astNode->val = parseTree->val;
    astNode->is_terminal = parseTree->is_terminal;

    for (NODE* child : parseTree->children) {
        NODE* astChild = convertParseTreeToAST(child);
        astNode->children.push_back(astChild);

    }

    return astNode;
}


void MakeDOTFile(NODE*cell) {
    if(!cell)
        return;
    
    string value = string(cell->val);
    if(value.length()>2 && value[0]=='"' && value[value.length()-1]=='"')
    {
        value = value.substr(1,value.length()-2);
        value="\\\""+value+"\\\"";
    }
    
    if(cell->is_terminal){
        fout << "\t" << cell->id << "\t\t[ style = solid label = \"" + value + "\" color = red shape = rectangle ];" << endl;
    }
    else
        fout << "\t" << cell->id << "\t\t[ style = solid label = \"" + value + "\"  ];" << endl;

    for(int i=0;i<cell->children.size();i++)
    {
        if(!cell->children[i])
            continue;
        
        fout << "\t" << cell->id << " -> " << cell->children[i]->id << endl;
        MakeDOTFile(cell->children[i]);
    }
} 

string newTemp(){
    string temp = "t" + to_string(tempCount);
    tempCount++;
    return temp;

}

void create_ins(int type, string optype, string addr1,string addr2, string addr3 ){
    vector<string> instruct{to_string(type), optype, addr1, addr2, addr3};
    instructions.push_back(instruct);
    instCount++;

}

void print_instructions(){
    for(int i=0;i<instructions.size();i++){
        for(int j=0;j<instructions[i].size();j++){
            cout<<instructions[i][j]<<" ";
        }
    }
}

int main(int argc, char* argv[]){
    indent_stack.push(0);
    /* yylex(); */
    global_sym_table->total_offset=0;
    global_sym_table->return_type = "undefined";
    create_entry(global_sym_table, "print", "print", 0, 1, NULL);
    create_entry(global_sym_table, "range", "list[int]", 0, 1, NULL);
    create_entry(global_sym_table, "len", "int", 0, 1, NULL);
    create_entry(global_sym_table, "self", "self", 0, 1, NULL);
    create_entry(global_sym_table, "__name__", "__name__", 0, 1, NULL);
    curr_sym_tbl.push(global_sym_table);
	string output_file = "";
    string input_file = "input.txt";

    if(argc < 2 || argc > 4) {
		cout << "Usage: ./main <input file> <output file> <debug>" << endl;
		cout << "Example: ./main --input=input.py --output=output.dot --verbose" << endl;
		cout<<endl;
		cout << "For more help, run ./main --help" << endl;
		return 0;
	}

	yydebug = 0;
	bool debug = false;
	bool noInputFile = true;

	for(int i=1;i<argc;i++){
		string arg = argv[i];
		if(arg == "--help"){
			cout << "--input : Add this flag for specifying a input file to the parser. This is a required flag." << endl;
			cout << "Example: ./main --input=input.py" << endl;
			cout<<endl;
			cout << "--output Add this flag for specifying a output file to the parser which would contain the output i.e a AST in graphical form. This flag is optional. Default value is output.dot" << endl;
			cout << "Example: ./main --input=input.py --output=result.dot" << endl;
			cout<<endl;
			cout << "--verbose Add this flag for switching on the debug mode in the parser. This flag is optional." << endl;
			cout << "Example: ./main --input=input.py --output=result.dot --verbose" << endl;
			return 0;
		}
		else if(arg.substr(0,8) == "--input="){
			input_file = arg.substr(8);
			noInputFile = false;
		}
		else if(arg.substr(0,9) == "--output="){
			output_file = arg.substr(9);
		}
		else if(arg == "--verbose"){
			debug = true;
		}

		else{
			cout << "Invalid argument: " << arg << endl;
			return 0;
		}
	}

	if(input_file == "" || noInputFile){
		cout << "Please specify an input file." << endl;
		return 0;
	}
	if(output_file == ""){
		output_file = "output.dot";
	}
	if(debug){
		cout << "Input file: " << input_file << endl;
		cout << "Output file: " << output_file << endl;
		cout << "Debug: " << debug << endl;
		yydebug = 1;
	}

    //  Open the input file
	FILE* fp = fopen(("./" + input_file).c_str(), "r");

	if(!fp){
		cout << "Error opening file: " << input_file << endl;
		return 0;
	}
	yyin = fp;
    
    yyparse();
 
    // Close the input file
	fclose(fp);
    
    // Open the output file
    // output_file = "output.dot";
	fout.open(output_file.c_str() , ios::out | ios::trunc);
    

    fout<<"digraph G{"<<endl;
    fout << endl;
    fout<<"label     = \"AST\""<<endl;
    fout<<"fontname  = \"Cascadia code\""<<endl;
    fout<<"fontsize  = 30"<<endl;
    fout<<"labelloc  = t"<<endl;
    fout << endl;
    fout<<"node   [ fontname=\"Cascadia code\" ]"<<endl;
    
    NODE* ast = convertParseTreeToAST(start_node);

    MakeDOTFile(ast);

    /* MakeDOTFile(start_node); */
    /* print_sym_table(global_sym_table); */
    print_instructions();


    fout<<"}";
    fout.close();

    return 0;
}


int yyerror(const char *s){
    cout << "Error: " << s << ",line: "<< yylineno << endl;
    return 0;
}