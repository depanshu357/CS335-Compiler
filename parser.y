%{
    #include <bits/stdc++.h>
    #include "node.h"
    #include "symbol_table.cpp"
    #include <typeinfo>
    // #include "x_86.cpp"
    using namespace std;
    int yylex();    
    int yyerror(const char *s);
    extern int yylineno;
    // extern create_x86_code();
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
    int labelCount = 1;
    int instCount=0;
    string dot_is_spl_type;
    int is_class_arg=0;
    string newTemp();
    vector<string> label_st;
    vector<string>loop_stack;
    string newLabel();
    vector<string> arr_elements;
    int arr_active = 0;
    int box_active = 0;
    int box_value = -1; 
    int func_par_offset = 0;
    int func_call_active = 0;
    int brack_open = 0;
    int class_active = 0;
    int class_func_call_active = 0;
    string constructor_reg = ""; 
    vector<vector<string>> func_arguments;
    vector<string> x86_file;
    void create_ins(int type, string optype, string addr1, string addr2, string addr3);
    void print_x86_ins(vector<string> & ins, sym_table * symbol_table, int ins_no);
    vector<vector<string>>instructions;
    vector<string>range_arg;
    string prev_var_name="";
    string prev_dot_var="";
    int is_constructor=0;
    int len_func_call_active=0;
    int len_arg_pushed=0;
    int print_func_call_active=0;
    vector<vector<string>>parameter_ins;
    vector<vector<string>> len_func_arguments;
    vector<vector<string>> print_func_arguments;
    map<string, string> offset_vec;
    string last_offset = "0";
    int class_par_offset = 0, prev_self = 0;
    vector<sym_table*>sym_tbl_info;
    int p_prev_range=0;
    int strCount = 0;
    string get_str_name();
    map<string,string> str_map;
    string last_string = "";
    int str_count = 0;
    set<int> str_cmp_ins_no;
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
%token <elem> __NAME__ __MAIN__
%token <elem> ADD_EQUAL SUB_EQUAL MUL_EQUAL  AT_EQUAL  DIV_EQUAL MOD_EQUAL BITWISE_AND_EQUAL  BITWISE_OR_EQUAL  BITWISE_XOR_EQUAL SHIFT_LEFT_EQUAL  SHIFT_RIGHT_EQUAL  POW_EQUAL  FLOOR_DIV_EQUAL 
%token INDENT DEDENT
%type <elem> start file_input stmt compound_stmt async_stmt if_stmt if_stmt_deviation elif_namedexpr_test_colon_suite_star while_stmt while_stmt_deviation for_stmt   funcdef funcdef_title func_type_hint_optional parameters typedlist_argument typedlist_arguments comma_option_argument_star typedarglist tfpdef func_body_suite suite stmt_plus simple_stmt semi_colon_small_stmt_star small_stmt flow_stmt break_stmt continue_stmt return_stmt raise_stmt global_stmt nonlocal_stmt comma_name_star assert_stmt expr_stmt testlist symbol_test_star expr_stmt_option1_plus annassign testlist_star_expr testlist_star_expr_option1_star augassign expr  symbol_xor_expr_star xor_expr symbol_and_expr_star and_expr symbol_shift_expr_star shift_expr  arith_expr  term  factor power atom_expr trailer_star trailer classdef bracket_arglist_optional arglist argument_list subscriptlist subscript_list subscript argument comp_iter sync_comp_for comp_for comp_if test_nocond or_test  and_test  not_test comparison comp_op_expr_plus comp_op exprlist expr_star_expr_option namedexpr_test_star_expr_option_list namedexpr_test_star_expr_option expr_star_expr_option_list   testlist_comp   namedexpr_test test atom number string_plus  else_colon_suite_optional 

%%
    


start : file_input {$$ = create_node(2,"START", $1); start_node=$$;}
    ;

file_input: NEWLINE file_input {$$ = $2;}
    | stmt file_input {$$ = create_node(3,"File Input",$1,$2);
    }
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

if_stmt: IF namedexpr_test {
        newLabel();
        string temp=newLabel();
        create_ins(0,"if_false",$2->addr,"goto",temp);
    } COLON suite {
        string prevLabel=label_st.back();
        label_st.pop_back();
        if(!label_st.empty())
            create_ins(0,"goto",label_st.back(),"","");
        create_ins(0,prevLabel+":","","","");
    } if_stmt_deviation {
        $$ = create_node(6,"If_stmt",$1,$2,$4,$5,$7);
        if(!label_st.empty())
            create_ins(0,label_st.back()+":","","","");
        label_st.pop_back();
        
        
    };

if_stmt_deviation: elif_namedexpr_test_colon_suite_star ELSE COLON suite { 
            $$ = create_node(5,"elif_stmt",$1,$2,$3,$4);
        }
        |elif_namedexpr_test_colon_suite_star {$$ = $1;};
                                                

elif_namedexpr_test_colon_suite_star: ELIF  namedexpr_test {
        string temp=newLabel();
        create_ins(0,"if_false",$2->addr,"goto",temp);
    } COLON suite {
        string prevLabel=label_st.back();
        label_st.pop_back();
        if(!label_st.empty())
            create_ins(0,"goto",label_st.back(),"","");
        create_ins(0,prevLabel+":","","","");
    } elif_namedexpr_test_colon_suite_star {$$ = create_node(6,"Elif_block",$1,$2,$4,$5,$7);}
    | { $$ = NULL;}
    ;

/* while_stmt: WHILE namedexpr_test COLON suite ELSE COLON suite { $$ = create_node(8,"While_stmt",$1,$2,$3,$4,$5,$6,$7);}
    | WHILE namedexpr_test COLON suite {$$ = create_node(5,"While_stmt",$1,$2,$3,$4);}
    ; */

while_stmt: WHILE {
        string temp=newLabel();
        create_ins(0,temp+":","","","");
    }namedexpr_test {
        // newLabel();
        string temp=newLabel();
        create_ins(0,"if_false",$3->addr,"goto",temp);
    
    } COLON suite {
        string prevLabel=label_st.back();
        label_st.pop_back();
        if(!label_st.empty())
            create_ins(0,"goto",label_st.back(),"","");
        create_ins(0,prevLabel+":","","","");
        label_st.pop_back();
    } while_stmt_deviation { 
        $$ = create_node(6,"While_stmt",$1,$3,$5,$6,$8);
        // if(!label_st.empty())
        //     create_ins(0,label_st.back()+":","","","");
    }
    ;

while_stmt_deviation: ELSE COLON suite { 
    $$ = create_node(4,"Else_block",$1,$2,$3);
    }
    | { $$ = NULL;}
    ;

for_stmt: FOR exprlist IN testlist COLON {
        if("list["+string($2->type_of_node)+"]"!=string($4->type_of_node)){
            if(string($2->type_of_node)=="int" && string($4->type_of_node)=="list[float]"){
                //continue;
            }
            else if(string($2->type_of_node)=="float" && string($4->type_of_node)=="list[int]")
            {
                //continue;
            }
            else if(string($2->type_of_node)=="int" && string($4->type_of_node)=="list[bool]")
            {
                //continue;
            }
            else if(string($2->type_of_node)=="bool" && string($4->type_of_node)=="list[int]"){
                //continue;
            }
            else{
                cout<<"Error type is not iterable at line " <<yylineno <<". \n";   
                return 0;
            }
        }
        if(prev_var_name!="range"){
            int offset=get_type_size(string($4->type_of_node.substr(5,$4->type_of_node.size()-6)));
            int max_size=get_size_from_tbl(curr_sym_tbl.top(),$4->addr);
            string label2=newLabel(); //after FOR label
            string temp1=newTemp();
            string sizetemp2=newTemp();
            create_ins(2,"=",temp1,"-8","");
            create_ins(2,"=",sizetemp2,$4->addr+"["+temp1+"]","");
            create_ins(3,"*",sizetemp2,sizetemp2,"8");
            string label1=newLabel(); //label for FOR
            loop_stack.push_back(label1); // for break stmt
            create_ins(0,label1+":","","","");
            string temp2=newTemp();
            create_ins(3,"+",temp1,temp1,to_string(offset));
            create_ins(3,"<",temp2,temp1,sizetemp2);
            create_ins(0,"if_false",temp2, "goto",label2);
            create_ins(2,"=",$2->addr,$4->addr+"["+temp1+"]","");
        }
        else{
            string low,high;
            if(range_arg.size()>2 || range_arg.size()<1){
                cout<<"Error invalid range arguments at line " <<yylineno <<". \n";
                return 0;
            }else if(range_arg.size()==1){
                string reg = newTemp();
                create_ins(2,"=",reg,"-1","");
                low=reg;
                high=range_arg[0];
            }
            else{
                low=range_arg[0];
                high=range_arg[1];
                create_ins(3,"-",low,low,"1");
            }
            // cout<<low<<" "<<high<<endl;
            range_arg.clear();
            string temp1=newTemp();
            string label2=newLabel(); //after FOR label
            create_ins(2,"=",temp1,low,"");
            string label1=newLabel(); //label for FOR
            loop_stack.push_back(label1); // for break stmt
            create_ins(0,label1+":","","","");
            string temp2=newTemp();
            create_ins(3,"+",temp1,temp1,"1");
            create_ins(3,"<",temp2,temp1,high);
            create_ins(0,"if_false",temp2, "goto",label2);
            create_ins(2,"=", $2->addr,temp1,"");
            // create_ins(0,$2->addr,"=",temp1,"");
            
            prev_var_name="aryan";


        }
    } suite {
        
        if(!label_st.empty())
        {
            create_ins(0,"goto",label_st.back(),"","");
            label_st.pop_back();
        }
        if(!loop_stack.empty()){
            loop_stack.pop_back();
        }
        if(!label_st.empty())
        {
            create_ins(0,label_st.back()+":","","","");
            label_st.pop_back();
        }
        

    } else_colon_suite_optional{
        $$ = create_node(8,"For_stmt",$1,$2,$3,$4,$5,$7,$9);
        //check if testlist is a list or range
        if(($4->type_of_node.size()<6 || $4->type_of_node.substr(0,4)!="list") ){
            cout<<"Error type is not iterable at line " <<yylineno <<". \n";
            return 0;
        }
        //check if the exprlist is same type as testlsit list [*]
        if(($4->type_of_node.substr(0,4)=="list") && $2->type_of_node!=$4->type_of_node.substr(5,$4->type_of_node.size()-6)){
            cout<<"Error type is not same as iterable at line " <<yylineno <<". \n";
            return 0;
        }
        // cout<<$2->type_of_node<<" ompho "<<$4->type_of_node<<endl;

    }
    ; 

else_colon_suite_optional : ELSE COLON  suite { 
        $$ = create_node(4,"Else_block",$1,$2,$3);
    }
    | { $$ = NULL;}
    ;

/*using this notation instead of below one*/
funcdef:  DEF funcdef_title  func_body_suite { 
        $$ = create_node(4,"Func_def",$1,$2,$3);
        // cout << $2->lexeme << "TESSSSS"<< endl;
        if(string($2->lexeme)=="__init__"){
            create_ins(0,"ret","","","");
        }
        if(curr_sym_tbl.top()->return_type=="None"  && curr_sym_tbl.top()->name!="main"){
            create_ins(0,"ret","","","");
        }

        if(curr_sym_tbl.size()>1 && string($2->lexeme)!="__init__")
        {
                // cout<<"poping "<<curr_sym_tbl.top()->name<<endl; 
                curr_sym_tbl.pop(); 
        } 
        // create_ins(0,"move8","%rbp","%rsp","");
        // create_ins(0,"move8","-8(%rbp)","%rbp","");
        // create_ins(0,"addq", "%rsp","$"+to_string(func_par_offset*2),"");
        func_par_offset = 0;
        prev_self = 0;
    }
     /* | DEF NAME {parameter_vec.clear(); is_param=1;} parameters  COLON  func_body_suite { $$ = create_node(6,"Func_def",$1,$2,$3,$4,$5);}  */
    ;


funcdef_title: NAME {
        parameter_vec.clear(); 
        is_param=1;
        // if(curr_sym_tbl.top()->name!="global"){
        //     create_ins(0,curr_sym_tbl.top()->name+"@"+$1->lexeme+":","","","");
        // }
        // else
        //     create_ins(0,string($1->lexeme)+":","","","");

        // create_ins(0,"move8", "%rbp","-8(%rsp)","");
        // create_ins(2,"=", "%rbp","%rsp","");
    } 
    parameters func_type_hint_optional COLON { 
        $$ = create_node(5,"Func_def",$1,$3,$4,$5);
        $$->lexeme=$1->lexeme;
        // cout << $1->lexeme << "TESSSSS"<< endl;
        int check_flag=0;
        if(curr_sym_tbl.top()->name!="global"){
            check_flag=1;
        }
        if(string($1->lexeme)=="__init__"){
            //continue;
            add_parameters(curr_sym_tbl.top(), parameter_vec);
            is_param=0;
            // cout<<endl<<"here ginf"<<endl;

            // create_ins(0,"."+$1->lexeme+"":","","","");
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

            for(auto it:parameter_vec){
                curr_sym_tbl.top()->x86_offset-=8;
                offset_vec[curr_sym_tbl.top()->name+it.name] = to_string(curr_sym_tbl.top()->x86_offset);
            }

        }

        if(check_flag){
            if(string($1->lexeme)!="__init__")
                create_ins(0,curr_sym_tbl.top()->prev_sym_table->name+"_"+$1->lexeme+":","","","");
            else 
                {
                    create_ins(0,curr_sym_tbl.top()->name+"_"+$1->lexeme+":","","","");
                    curr_sym_tbl.top()->x86_offset-=8;
                    offset_vec[curr_sym_tbl.top()->name+"self"] = to_string(curr_sym_tbl.top()->x86_offset);    
                }
        }
        else
            create_ins(0,string($1->lexeme)+":","","","");
        for(auto it:parameter_ins){
            create_ins(stoi(it[0]),it[1],it[2],it[3],it[4]);
        }
        parameter_ins.clear();
}
;

func_type_hint_optional: FUNC_TYPE_HINT {$$ = $1; $$->type_of_node= $1->val;}
    | { $$ = NULL;}
    ;

// Written only to run START ye dono document se dekhna hai
parameters: SMALL_OPEN typedarglist SMALL_CLOSE {
        $$ = create_node(4,"Arguments",$1,$2,$3);
        // cout<<"parameters"<<endl;
    }
    |SMALL_OPEN SMALL_CLOSE {$$ = create_node(3,"Parantheses",$1,$2);}
    ;

typedarglist:
    typedlist_arguments {$$ = $1;}
    ;

typedlist_arguments: typedlist_argument comma_option_argument_star {$$ = create_node(3,"Arguments",$1,$2);};

typedlist_argument: tfpdef  { $$ = $1;}
    |  tfpdef EQUAL test { 
        $$ = create_node(4,"Assign_expr",$1,$2,$3);
        
        if(
            $1->type_of_node!=$3->type_of_node && 
            (($1->type_of_node!="int" && $1->type_of_node!="float") || ( $3->type_of_node!="int" && $3->type_of_node!="float")) &&
            (($1->type_of_node!="int" && $1->type_of_node!="bool") || ( $3->type_of_node!="int" && $3->type_of_node!="bool"))
        ){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
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
            cout<<"Variable "<<$1->lexeme<<" not declared at line "<<yylineno<<endl;
            return 0;
            // cout<<"this is running in if"<<endl;
            // give error as type hint not found
        }
        if(is_param) {
            add_to_vector(parameter_vec, $1->lexeme, $1->lexeme,yylineno);
            int size_of_var=8;
            // create_ins(0,"move"+to_string(size_of_var),to_string(func_par_offset)+"(%rbp)",$1->lexeme,"");
            
            parameter_ins.push_back({"0","move8",to_string(func_par_offset +16)+"(%rbp)",$1->lexeme,""});
            // cout << $1->lexeme << " line 448" << endl;

            func_par_offset+=size_of_var; //size of self pointer
            
        }
        $$->type_of_node= search_type_in_sym_table(curr_sym_tbl.top(),$1->lexeme);
        }
    | NAME TYPE_HINT { $$ = create_node(3,"Identifier",$1,$2); 
        if(is_param) {
            add_to_vector(parameter_vec, $1->lexeme, $2->lexeme,yylineno);
            int size_of_var=get_type_size($2->lexeme);
            // create_ins(0,"move"+to_string(size_of_var),to_string(func_par_offset)+"(%rbp)",$1->lexeme,"");
            parameter_ins.push_back({"0","move8",to_string(func_par_offset +16)+"(%rbp)",$1->lexeme,""});
            // cout<<$1->lexeme<<" line 460"<<endl;
            func_par_offset += size_of_var;
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

func_body_suite: simple_stmt {
        $$ = $1; 
    }
    | NEWLINE INDENT stmt_plus DEDENT { 
        $$ = $3;
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
    | IF __NAME__ DOUBLE_EQUAL __MAIN__ COLON {
        create_ins(0,"programStart:", "","","");
    } suite {
        $$ = create_node(3,"Simple_stmts",$1,$2,$3,$4,$5,$7);
    }
    ;

semi_colon_small_stmt_star: SEMI_COLON small_stmt semi_colon_small_stmt_star {
        $$ = create_node(4,"Small_stmts",$1,$2,$3);
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
    
break_stmt: BREAK {$$  = $1;
        for(int i=0;i<label_st.size();i++){
            if(!loop_stack.empty() &&label_st[i]==loop_stack.back() && i>0){
                create_ins(0,"goto",label_st[i-1],"","");
                
                break;
            }
        }
    };

continue_stmt: CONTINUE {$$ = $1;
        create_ins(0,"goto",loop_stack.back(),"","");
    };

return_stmt: RETURN testlist_star_expr {
        $$ = create_node(3,"Return_stmt",$1,$2);
        if($2->type_of_node=="float" && curr_sym_tbl.top()->return_type=="int"){
            //continue; change float val to int
        }
        else if($2->type_of_node=="int" && curr_sym_tbl.top()->return_type=="float"){
          //continue; change int val to float
        }
        else if($2->type_of_node!=curr_sym_tbl.top()->return_type){
            // cout<<$2->type_of_node<<" "<<curr_sym_tbl.top()->name<<" hehe"<<endl;
            cout<<"Error invalid return type at line " <<yylineno <<endl;
            return 0;
        }

        create_ins(0,"move8",$2->addr,"%rax","");
        create_ins(0,"ret","","","");
        
    }
    | RETURN {
        $$ = $1;
        if(curr_sym_tbl.top()->return_type!="None"){
            cout<<"Error invalid return type at line " <<yylineno <<endl;
            return 0;
        }
        create_ins(0,"ret","","","");

    }
    ;

raise_stmt: RAISE {$$ = $1;}
    | RAISE test {$$ = create_node(3,"Raise_stmt",$1,$2);}
    | RAISE test FROM test {$$ = create_node(5,"Raise_stmt",$1,$2,$3,$4);}
    ;

global_stmt: GLOBAL NAME comma_name_star {
    $$ = create_node(4,"Global_stmt",$1,$2,$3);
    if(!search_sym_table(global_sym_table,$2->lexeme,0)){
        cout<<"Variable is not already global at line "<<yylineno<<endl;
            return 0;
    }
    curr_sym_tbl.top()->global_vars.push_back($2->lexeme);
};

nonlocal_stmt: NONLOCAL NAME comma_name_star {$$ = create_node(4,"Nonlocal_stmt",$1,$2,$3);};

comma_name_star: COMMA NAME comma_name_star {
    $$ = create_node(4,"Identifiers",$1,$2,$3);
     if(!search_sym_table(global_sym_table,$2->lexeme,0)){
        cout<<"Variable is not already global at line "<<yylineno<<endl;
            return 0;
    }
    curr_sym_tbl.top()->global_vars.push_back($2->lexeme);
    }
    | { $$ = NULL;}
    ;

assert_stmt: ASSERT test COMMA test {$$ = create_node(5,"Assert_stmt",$1,$2,$3,$4);}
    | ASSERT test {$$ = create_node(3,"Assert_stmt",$1,$2);}
    ;

expr_stmt: testlist_star_expr annassign {$$ = create_node(3,"Expr_stmt",$1,$2);
    //didnt get this production to use in the code so didnt implement the type_of_node
    }
    | testlist_star_expr augassign testlist {
        // cout<<"line 323\n";
        // cout<<$2->lexeme<<endl;
    $$ = create_node(4,"Expr_stmt",$1,$2,$3);
    if((string($2->lexeme)=="&=" || string($2->lexeme)=="|=" || string($2->lexeme)=="^=" || string($2->lexeme)=="<<=" || string($2->lexeme)==">>=") && ($1->type_of_node!="int" || $3->type_of_node!="int")){
        if($1->type_of_node!="int" || $3->type_of_node!="int"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        
    }
    else if(($1->type_of_node!="int" && $1->type_of_node!="float") || ($3->type_of_node!="int" && $3->type_of_node!="float")){
        // cout<<"line 323 "<<$1->type_of_node<<" "<<$3->type_of_node<<endl;
        cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
    }else{
            // cout<<$1->type_of_node<<" "<<$3->type_of_node<<" "<<$2->lexeme<<endl;
            string operation = string($2->lexeme).substr(0,string($2->lexeme).size()-1);
            // string reg = newTemp();
            // cout<<operation<<endl;
            // cout<<$1->addr<<" "<<operation<<$1->addr<<"+"<<$3->addr<<endl;
            string reg = newTemp();
            create_ins(3,operation,reg,$1->addr,$3->addr);
            create_ins(2,"=", $1->addr,reg,"");
            $$->addr = $1->addr;
        }
        $$->type_of_node= $1->type_of_node;

    }
    |testlist_star_expr  {$$ = $1;}
    |testlist_star_expr expr_stmt_option1_plus  {
        $$ = create_node(3,"Expr_stmt",$1,$2);
        if(($1->type_of_node=="int" && $2->type_of_node=="bool") || ($1->type_of_node=="bool" && $2->type_of_node=="int")){

        }
        else if($1->type_of_node!=$2->type_of_node && (($1->type_of_node!="int" && $1->type_of_node!="float") || ( $2->type_of_node!="int" && $2->type_of_node!="float"))){
            cout<<"Error invalid assignment type at line " <<yylineno <<endl;
            cout<<$1->type_of_node<<" "<<$2->type_of_node<<endl;
            return 0;
            // cout<<$1->type_of_node<<" "<<$2->type_of_node<<endl;
            
        }
        $$->type_of_node= $1->type_of_node;
        if(is_constructor){
            create_ins(2,"=",$1->addr,constructor_reg,"");
            is_constructor=0;
            func_call_active = 0;
        }
        else if(func_call_active==-1){
            create_ins(0,"move8","%rax",$1->addr,"");
            func_call_active = 0;   
        }
        else if(class_func_call_active==-1){
            create_ins(0,"move8","%rax",$1->addr,"");
            class_func_call_active = 0;
            class_active = 0;
        }
        else if(prev_self==1){
            create_ins(0,"move8",$2->addr,$1->addr+"[0]","");
            prev_self=0;
        }else if(prev_self==2){
            create_ins(0,"move8",$2->addr+"[0]",$1->addr,"");
            prev_self = 0;
        }
        else{
            create_ins(2,$2->residual_ins, $1->addr,$2->addr, "");
        }

    }
    ;
    

testlist:  test symbol_test_star  {
    $$ = create_node(3,"Expressions",$1,$2);
    $$->type_of_node = $1->type_of_node;
    $$->addr=$1->addr;
    }
    
symbol_test_star: COMMA test symbol_test_star {
    $$ = create_node(4,"Expressions",$1,$2,$3);}
    | COMMA {$$ = $1;}
    |{$$=NULL;} 
    ;

expr_stmt_option1_plus:EQUAL testlist_star_expr expr_stmt_option1_plus {
        $$ = create_node(4,"Expr_stmt",$1,$2,$3);
        if($3!=NULL && $3->type_of_node!=$2->type_of_node){
            cout<<"Error invalid assignment type at line " <<yylineno <<endl;
            cout<<"line 620\n";
            return 0;
        }
        create_ins(2,$3->residual_ins, $2->addr,$3->addr, "");
        $$->addr=$2->addr;
        $$->residual_ins=$1->lexeme;

        $$->type_of_node= $2->type_of_node;


    }
    | EQUAL testlist_star_expr {$$ = create_node(3,"Expr_stmt",$1,$2);
        $$->type_of_node= $2->type_of_node;
        
        $$->addr=$2->addr;
        $$->residual_ins=$1->lexeme;

    }
    ;

annassign: COLON test {$$ = create_node(3,"Identifiers",$1,$2); 
    //didnt get this production to use in the code so didnt implement the type_of_node
    // cout<<"Annassign1"<<endl;
    }
    | COLON test EQUAL testlist_star_expr {$$ = create_node(5,"Identifiers",$1,$2,$3,$4);
    //didnt get this production to use in the code so didnt implement the type_of_node
    // cout<<"Annassign2"<<endl;
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

        if($2==NULL || $2->type_of_node=="undefined"){
            $$->addr= $1->addr;
            $$->residual_ins= $1->residual_ins;
            $$->type_of_node= $1->type_of_node;
        }
        $$->addr=$1->addr;
    }
    ;

testlist_star_expr_option1_star: COMMA test testlist_star_expr_option1_star {
        $$ = create_node(4,"Expressions",$1,$2,$3);
        // cout << "testlist_star_expr_option1_star" << endl;
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
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node= $1->type_of_node;
    }

    if($2==NULL){
        $$->addr= $1->addr;
        $$->residual_ins= $1->residual_ins;
    }else {
        string reg = newTemp();
        create_ins(3,$2->residual_ins,reg,$1->addr,$2->addr);
        $$->addr = reg;
        $$->residual_ins = $1->residual_ins;
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
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node= $2->type_of_node;
            // cout<<"hua kya"<<endl;
        if($3==NULL){
            $$->residual_ins = $1->lexeme;
            $$->addr = $2->addr;
        }else{
            string reg = newTemp();
            create_ins(3,$3->residual_ins,reg,$2->addr,$3->addr);
            $$->addr = reg;
            $$->residual_ins = $1->lexeme;
        }
        // cout<<"line 527 "<<$$->addr<<endl;
    }
    | /*empty*/ {$$=NULL;}
    ;

xor_expr: and_expr symbol_and_expr_star {
    $$ = create_node(3,"Expressions",$1,$2);
    if($2==NULL){
        $$->type_of_node= $1->type_of_node;
    }else{
        if($2->type_of_node!="int" || $1->type_of_node!="int"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node= $2->type_of_node;
    }
    
    if($2==NULL){
        $$->addr= $1->addr;
        $$->residual_ins= $1->residual_ins;
    }else{
        string reg = newTemp();
        create_ins(3,$2->residual_ins,reg,$1->addr,$2->addr);
        $$->addr = reg;
        $$->residual_ins = $1->residual_ins; // this line not needed but added to avoid any error if any
    }
    // cout<<"line 552 "<<$$->addr<<endl;
};

symbol_and_expr_star: BITWISE_XOR and_expr symbol_and_expr_star {
        $$ = create_node(4,"Xor_exprs",$1,$2,$3);
        if($2->type_of_node!="int" ){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node = $2->type_of_node;
        if($3==NULL){
            $$->residual_ins = $1->lexeme;
            $$->addr = $2->addr;
        }else{
            string reg = newTemp();
            create_ins(3,$3->residual_ins,reg,$2->addr,$3->addr);
            $$->residual_ins = $1->lexeme;
            $$->addr = reg;
        }
    }
    | /*empty*/ {$$=NULL;}
    ;

and_expr: shift_expr symbol_shift_expr_star {
    $$ = create_node(3,"Expressions",$1,$2);
    if($2==NULL || $2->type_of_node=="undefined"){
        $$->type_of_node= $1->type_of_node;
    }else{
        if($2->type_of_node!="int"|| $1->type_of_node!="int" ){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node= $2->type_of_node;
    }
    
    if($2==NULL){
        $$->addr= $1->addr;
        $$->residual_ins= $1->residual_ins;
    }
    else{
        string reg = newTemp();
        create_ins(3,$2->residual_ins,reg,$1->addr,$2->addr);
        $$->addr = reg;
        $$->residual_ins = $1->residual_ins;
    
    }
};

symbol_shift_expr_star: BITWISE_AND shift_expr symbol_shift_expr_star {
        $$ = create_node(4,"And_exprs",$1,$2,$3);
        if($2->type_of_node!="int" ){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node = $2->type_of_node;
        if($3==NULL){
            $$->residual_ins = $1->lexeme;
            $$->addr = $2->addr;
        }else{
            string reg = newTemp();
            create_ins(3,$3->residual_ins,reg,$2->addr,$3->addr);
            $$->residual_ins = $1->lexeme;
            $$->addr = reg;
        }
        // karna hai 3ac code
    }
    | /*empty*/ {$$=NULL;}
    ;
shift_expr:shift_expr SHIFT_LEFT arith_expr {
     $$ = create_node(4,"Shift_expr",$1,$2,$3);
       if($1->type_of_node!="int" && $3->type_of_node!="int"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node="int";
        if($1!=NULL){
            string reg=newTemp();
            create_ins(3,"<<", reg,$1->addr, $3->addr);
            $$->addr=reg;
            $$->residual_ins=$1->residual_ins;
        }
        else{
            $$->addr=$3->addr;
            $$->residual_ins="<<";
        }
    }
    |shift_expr SHIFT_RIGHT arith_expr {
        $$ = create_node(4,"Shift_expr",$1,$2,$3);
       if($1->type_of_node!="int" && $3->type_of_node!="int"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node="int";
        if($1!=NULL){
            string reg=newTemp();
            create_ins(3,">>", reg,$1->addr, $3->addr);
            $$->addr=reg;
            $$->residual_ins=$1->residual_ins;
        }
        else{
            $$->addr=$3->addr;
            $$->residual_ins=">>";
        }
    
    }
    |arith_expr {
        $$ = $1;
    };


// shift_expr: arith_expr shift_arith_expr_star {
//     $$ = create_node(3,"Expressions",$1,$2);
//     if($2==NULL || $2->type_of_node=="undefined"){
//         $$->type_of_node= $1->type_of_node;
//     }else{
//         if(($2->type_of_node!="int" && $2->type_of_node!="bool") || ($1->type_of_node!="int" && $1->type_of_node!="bool")){
//             cout<<"Error invalid operand type at line " <<yylineno <<endl;
//             return 0;
//         }
//         $$->type_of_node= "int";
//     }
    
//     if($2==NULL){
//         $$->addr= $1->addr;
//         $$->residual_ins= $1->residual_ins;
//     }
//     else{
//         string reg = newTemp();
//         create_ins(3,$2->residual_ins,reg,$1->addr,$2->addr);
//         $$->addr = reg;
//         $$->residual_ins = $1->residual_ins;
//     }
//     // cout<<"line 616 "<<$$->addr<<endl;

// };

// shift_arith_expr_star: /*empty*/ {$$=NULL;}
//     | SHIFT_LEFT arith_expr shift_arith_expr_star {
//         $$ = create_node(4,"Shift_left_expr",$1,$2,$3);
//         if($2->type_of_node!="int" && $2->type_of_node!="bool"){
//             cout<<"Error invalid operand type at line " <<yylineno <<endl;
//             return 0;
//         }
//         $$->type_of_node = $2->type_of_node;
//         if($3!=NULL){
//             string reg=newTemp();
//             create_ins(3,$3->residual_ins, reg,$2->addr, $3->addr);
//             $$->addr=reg;
//             $$->residual_ins=$1->lexeme;
//         }
//         else{
//             $$->addr=$2->addr;
//             $$->residual_ins=$1->lexeme;

//         }
        
//     }
//     | SHIFT_RIGHT arith_expr shift_arith_expr_star {
//         $$ = create_node(4,"Shift_right_expr",$1,$2,$3);
//         if($2->type_of_node!="int" && $2->type_of_node!="bool"){
//             cout<<"Error invalid operand type at line " <<yylineno <<endl;
//             return 0;
//         }
//         $$->type_of_node = $2->type_of_node;
//         if($3!=NULL){
//             string reg=newTemp();
//             create_ins(3,$3->residual_ins, reg,$1->addr, $3->addr);
//             $$->addr=reg;
//             $$->residual_ins=$1->lexeme;
//         }
//         else{
//             $$->addr=$2->addr;
//             $$->residual_ins=$1->lexeme;
//         }
//     }
//     ;
arith_expr:arith_expr ADD term {
        $$ = create_node(4,"Operator_expr",$1,$2,$3);
        if($3->type_of_node!="int" && $3->type_of_node!="float" && $3->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        if($1==NULL || $1->type_of_node=="undefined"){
            $$->type_of_node= $3->type_of_node;
        }else if($1->type_of_node!="int" && $1->type_of_node!="float" && $1->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }else if($3->type_of_node=="float" || $1->type_of_node=="float"){
            $$->type_of_node= "float";
        }else{
            $$->type_of_node= "int";
        }
        if($1!=NULL){
            string reg=newTemp();
            create_ins(3,"+", reg,$1->addr, $3->addr);
            $$->addr=reg;
            $$->residual_ins=$1->residual_ins;
        }
        else{
            $$->addr=$3->addr;
            $$->residual_ins="+";
        }
    }
    | arith_expr SUB term {
        $$ = create_node(4,"Operator_expr",$1,$2,$3);
        if($3->type_of_node!="int" && $3->type_of_node!="float" && $3->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        if($1==NULL || $1->type_of_node=="undefined"){
            $$->type_of_node= $3->type_of_node;
        }else if($1->type_of_node!="int" && $1->type_of_node!="float" && $1->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }else if($3->type_of_node=="float" || $1->type_of_node=="float"){
            $$->type_of_node= "float";
        }else{
            $$->type_of_node= "int";
        }
        if($1!=NULL){
            string reg=newTemp();
            create_ins(3,"-", reg,$1->addr, $3->addr);
            $$->addr=reg;
            $$->residual_ins=$1->residual_ins;
        }
        else{
            $$->addr=$3->addr;
            $$->residual_ins="+";
        }
    }
    | term {$$=$1;}
    ;


term:term MUL factor {
    $$ = create_node(4,"Operator_expr",$1,$2,$3);
        if($3->type_of_node!="int" && $3->type_of_node!="float" && $3->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        if($1==NULL || $1->type_of_node=="undefined"){
            $$->type_of_node= $3->type_of_node;
        }else if($1->type_of_node!="int" && $1->type_of_node!="float" && $1->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }else if($3->type_of_node=="float" || $1->type_of_node=="float"){
            $$->type_of_node= "float";
        }else{
            $$->type_of_node= "int";
        }
        if($1!=NULL){
            string reg=newTemp();
            create_ins(3,"*", reg,$1->addr, $3->addr);
            $$->addr=reg;
            $$->residual_ins=$1->residual_ins;
        }
        else{
            $$->addr=$3->addr;
            $$->residual_ins="*";
        }
    }
    |term DIV factor {
        $$ = create_node(4,"Operator_expr",$1,$2,$3);
        if($3->type_of_node!="int" && $3->type_of_node!="float" && $3->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        if($1==NULL || $1->type_of_node=="undefined"){
            $$->type_of_node= $3->type_of_node;
        }else if($1->type_of_node!="int" && $1->type_of_node!="float" && $1->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }else if($3->type_of_node=="float" || $1->type_of_node=="float"){
            $$->type_of_node= "float";
        }else{
            $$->type_of_node= "int";
        }
        if($1!=NULL){
            string reg=newTemp();
            create_ins(3,"/", reg,$1->addr, $3->addr);
            $$->addr=reg;
            $$->residual_ins=$1->residual_ins;
        }
        else{
            $$->addr=$3->addr;
            $$->residual_ins="/";
        }
    }
    |term FLOOR_DIV factor {
        $$ = create_node(4,"Operator_expr",$1,$2,$3);
        if($3->type_of_node!="int" && $3->type_of_node!="float" && $3->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        if($1==NULL || $1->type_of_node=="undefined"){
            $$->type_of_node= $3->type_of_node;
        }else if($1->type_of_node!="int" && $1->type_of_node!="float" && $1->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }else if($3->type_of_node=="float" || $1->type_of_node=="float"){
            $$->type_of_node= "float";
        }else{
            $$->type_of_node= "int";
        }
        if($1!=NULL){
            string reg=newTemp();
            create_ins(3,"//", reg,$1->addr, $3->addr);
            $$->addr=reg;
            $$->residual_ins=$1->residual_ins;
        }
        else{
            $$->addr=$3->addr;
            $$->residual_ins="//";
        }
    }
    |term MOD factor {
        $$ = create_node(4,"Operator_expr",$1,$2,$3);
        if($3->type_of_node!="int" && $3->type_of_node!="float" && $3->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        if($1==NULL || $1->type_of_node=="undefined"){
            $$->type_of_node= $3->type_of_node;
        }else if($1->type_of_node!="int" && $1->type_of_node!="float" && $1->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }else if($3->type_of_node=="float" || $1->type_of_node=="float"){
            $$->type_of_node= "float";
        }else{
            $$->type_of_node= "int";
        }
        if($1!=NULL){
            string reg=newTemp();
            create_ins(3,"%", reg,$1->addr, $3->addr);
            $$->addr=reg;
            $$->residual_ins=$1->residual_ins;
        }
        else{
            $$->addr=$3->addr;
            $$->residual_ins="%";
        }
    }
    |factor {$$=$1;}
    ;


// symbol_factor_star: /*empty*/ {$$=NULL;}
//     | symbol_factor symbol_factor_star {$$ = create_node(3,"Terms",$1,$2);
//     if($1->type_of_node!="int" && $1->type_of_node!="float" && $1->type_of_node!="bool"){
//         cout<<"Error invalid operand type at line " <<yylineno <<endl;
//             return 0;
//     }
//     if($2!=NULL && $2->type_of_node!="int" && $2->type_of_node!="float" && $2->type_of_node!="bool"){
//         cout<<"Error invalid operand type at line " <<yylineno <<endl;
//             return 0;
//     }

//     if($1->type_of_node=="float" || ($2!=NULL && $2->type_of_node=="float"))
//         $$->type_of_node= "float";
//     else
//         $$->type_of_node= "int";
    
//     if($2!=NULL ){
//         string reg=newTemp();
//         create_ins(3,$2->residual_ins, reg,$1->addr, $2->addr);
//         $$->addr=reg;
//         $$->residual_ins= $1->residual_ins;
//     }
//     else {
//         $$->addr=$1->addr;
//         $$->residual_ins=$1->residual_ins;
//     }
//     };

// symbol_factor: MUL factor {
//         $$ = create_node(3,"Mul_term",$1,$2);
//         if($2->type_of_node!="int" && $2->type_of_node!="float" && $2->type_of_node!="bool"){
//             cout<<"Error invalid operand type at line " <<yylineno <<endl;
//             return 0;
//         }
//         $$->type_of_node = $2->type_of_node;
//         $$->addr=$2->addr;
//         $$->residual_ins="*";
//     }
//     // | AT factor {$$ = create_node(3,"At_term",$1,$2);}
//     | DIV factor {
//         $$ = create_node(3,"Div_term",$1,$2);
//         if($2->type_of_node!="int" && $2->type_of_node!="float" && $2->type_of_node!="bool"){
//             cout<<"Error invalid operand type at line " <<yylineno <<endl;
//             return 0;
//         }
//         $$->type_of_node = "float";
//         // $$->type_of_node = $2->type_of_node;
//         $$->addr=$2->addr;
//         $$->residual_ins="/";
//     }
//     | FLOOR_DIV factor {
//         $$ = create_node(3,"Div_term",$1,$2);
//         if($2->type_of_node!="int" && $2->type_of_node!="float" && $2->type_of_node!="bool"){
//             cout<<"Error invalid operand type at line " <<yylineno <<endl;
//             return 0;
//         }
//         $$->type_of_node = $2->type_of_node;
//         $$->addr=$2->addr;
//         $$->residual_ins="//";
//     }
//     | MOD factor {
//         $$ = create_node(3,"Mod_term",$1,$2);
//         if($2->type_of_node!="int" && $2->type_of_node!="float" && $2->type_of_node!="bool"){
//             cout<<"Error invalid operand type at line " <<yylineno <<endl;
//             return 0;
//         }
//         $$->type_of_node = $2->type_of_node;
//         $$->addr=$2->addr;
//         $$->residual_ins="%";
//     }
//     ;

factor: ADD factor {
        $$ = create_node(3,"Add_term",$1,$2);
        if($2->type_of_node!="int" && $2->type_of_node!="float" && $2->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node = $2->type_of_node;
        $$->addr=$2->addr;
    }
    | SUB factor {
        $$ = create_node(3,"Sub_term",$1,$2);
        if($2->type_of_node!="int" && $2->type_of_node!="float" &&  $2->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node = $2->type_of_node;
        string reg=newTemp();
        create_ins(3,"*", reg,$2->addr, "-1");
        $$->addr=reg;
    }
    | TILDE factor {
        $$ = create_node(3,"Tilde_term",$1,$2);
        if($2->type_of_node!="int" && $2->type_of_node!="float" && $2->type_of_node!="bool"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node = $2->type_of_node;
        string reg=newTemp();
        create_ins(2,"~", reg,$2->addr,"");
        $$->addr=reg;
    }
    | power {$$ = $1;}
    ;
    
power: atom_expr {$$ = $1;}
    | atom_expr POW factor {$$ = create_node(4,"Power_term",$1,$2,$3);
        if(!($3->type_of_node=="int" || $3->type_of_node=="float" || $3->type_of_node=="bool")){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }else if(!($1->type_of_node=="int" || $1->type_of_node=="float" || $1->type_of_node=="bool")){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }else{
            if($1->type_of_node=="float" || $3->type_of_node=="float")
                $$->type_of_node= "float";
            else
                $$->type_of_node= "int";
        }

        string reg=newTemp();
        create_ins(3,"**", reg,$1->addr, $3->addr);
        $$->addr=reg;         
    }
    ;

atom_expr: AWAIT atom trailer_star {$$=create_node(4,"Await_stmt",$1,$2,$3);}
    | atom trailer_star{
        $$=create_node(3,"Terms", $1,$2);
        if(is_dot_name == __TDOT__ && $2!=NULL){
            string full_name=string($1->lexeme)+after_dot_name;
            delete_sym_table(curr_sym_tbl.top(),full_name);
            create_entry(curr_sym_tbl.top(),full_name,$2->type_of_node,yylineno,0,NULL );
            
            
            string reg=newTemp();
            create_ins(3, "+", reg, "self", to_string(curr_sym_tbl.top()->class_self_offset));
            class_par_offset+=get_type_size($2->type_of_node);
                $$->addr = reg;
            if(string($1->lexeme)=="self")
            {
                curr_sym_tbl.top()->self_offset_map[full_name]=curr_sym_tbl.top()->class_self_offset;
                curr_sym_tbl.top()->class_self_offset+=8;
                prev_self=1;
                // cout<<full_name<<" "<<curr_sym_tbl.top()->name<<" "<<curr_sym_tbl.top()->class_self_offset<<endl;
            }

            // $$->type_of_node = $3->lexeme;
            is_dot_name=0;
        }
        else if( is_dot_name== __DOT__ && $2!=NULL){
            string full_name=string($1->lexeme)+after_dot_name;
            if(dot_is_spl_type.size()>0){
                if(dot_is_spl_type.substr(0,3)=="Box"){
                    if(search_type_in_sym_table(curr_sym_tbl.top(),full_name).substr(0,4) !="list"){
                        cout<<"Error invalid dereferencing of a type at line no "<<yylineno<<endl;
                        return 0;
                    }
                }
                else if(dot_is_spl_type.size()>=5 && dot_is_spl_type.substr(0,5)=="Small"){
                    int func_exist=search_class_func(global_sym_table,search_type_in_sym_table(curr_sym_tbl.top(),$1->lexeme),after_dot_name.substr(1,after_dot_name.size()-1));
                    if(!func_exist){
                        // cout<<$1->lexeme<<" "<<after_dot_name<<" this is full name"<<endl;
                        cout<<"Error invalid function call at line no "<<yylineno<<endl;
                        return 0;
                    }
                }
            }

            is_dot_name=0;

            int curr_offset=get_offset_from_tbl(curr_sym_tbl.top(),full_name);
            if (string($1->lexeme) == "self")
                prev_self = 2;
            if(!brack_open){
                if(curr_offset==-1 && dot_is_spl_type.size()==0){
                    cout<<"Error invalid variable at line no "<<yylineno<<endl;
                    return 0;
                }
                string reg=newTemp();
                $$->addr=reg;
                if(class_active==0 && dot_is_spl_type.size()==0)
                {
                    create_ins(3, "+", reg, "self", to_string(curr_sym_tbl.top()->self_offset_map[full_name]));
                    $$->addr = reg + "[0]";
                    prev_self=0;
                }

            }
            
            if(print_func_call_active==1){
                string reg = newTemp();
                
                create_ins(3, "+", reg, "self", to_string(curr_sym_tbl.top()->self_offset_map[full_name]));
                
                $$->addr = reg+"[0]";
            }

            if(class_func_call_active==1){
                vector<st_node>sym_tbl_func_param=get_class_func_parameters(global_sym_table,$1->type_of_node,func_arguments[0][0]);
                // cout<<sym_tbl_func_param.size()<<" "<<func_arguments.size()<<endl;
                if(sym_tbl_func_param.size()!=func_arguments.size()){
                    cout<<"Error invalid number of arguments at line " <<yylineno <<". Expected "<<sym_tbl_func_param.size()<<" arguments\n";
                    return 0;
                }else {
                    create_ins(0,"#callnew","","","");
                    for(int i=sym_tbl_func_param.size()-1;i>=1;i--){
                        if(sym_tbl_func_param[i].type!=func_arguments[i][1] ){
                            if(sym_tbl_func_param[i].type=="int" && func_arguments[i][1]=="float"){

                            }else if(sym_tbl_func_param[i].type=="float" && func_arguments[i][1]=="int"){

                            }else if(sym_tbl_func_param[i].type=="int" && func_arguments[i][1]=="bool"){

                            }else if(sym_tbl_func_param[i].type=="bool" && func_arguments[i][1]=="int"){

                            }else{
                                cout<<"Error type of arguments not matching at line " <<yylineno <<endl;
                                return 0;
                            }
                        }
                        create_ins(0,"push",func_arguments[i][0],"","");
                    }
                    create_ins(0,"push",$1->lexeme,"","");
                    string get_name=get_full_name(global_sym_table,$1->type_of_node,func_arguments[0][0]);

                    // create_ins(0,"call,",string($1->type_of_node)+"_"+func_arguments[0][0],"","");
                    create_ins(0,"call,",get_name,"","");
                }
        
                class_func_call_active=-1;
                class_active=0;
                func_arguments.clear();
            }
        }


        if($2 && $2->type_of_node.substr(0,3)=="Box" && $2->type_of_node!="Box;int"){
            cout<<"Error invalid dereferencing type at line " <<yylineno <<". Expected int\n";
            return 0;
        }
        if($2==NULL ){
            string temp_type = $1->type_of_node;
            $$->type_of_node= $1->type_of_node;
        }else{
            if($2->type_of_node.substr(0,3)=="Box" ){
                if($1->type_of_node.size()<6 || $1->type_of_node.substr(0,4)!="list"){
                    cout<<"Error invalid dereferencing of a type at line no "<<yylineno<<endl;
                    return 0;
                }
                if($1->type_of_node.size()>=6){
                    string temp_type = $1->type_of_node.substr(5,$1->type_of_node.size()-6);
                    $$->type_of_node= temp_type;                
                }
            }
            else if($2->type_of_node.size()>=5 && $2->type_of_node.substr(0,5)=="Small"){
                $$->type_of_node= $1->type_of_node;
                
                if(func_call_active==1 && prev_var_name!="range" && prev_var_name!="len" && prev_var_name!="print")
                {
                    string reg=newTemp();
                    create_ins(0,"move8","%rax",reg,"");
                
                    $$->addr=reg;
                    // $$->addr=$2->addr;
                    func_call_active=0;
                }

            }
            else{
                string full_name=string($1->lexeme)+after_dot_name;
                // cout<<full_name<<" line 1347 "<<after_dot_name.substr(1)<<endl;
                
                $$->type_of_node = search_type_in_sym_table(curr_sym_tbl.top(),full_name);
                if(string($$->type_of_node)=="NULL" && after_dot_name.size()>1){
                    $$->type_of_node = search_in_global_scope(global_sym_table,after_dot_name.substr(1));
                    // cout<<"Inside  --------"<<endl;
                }
                // cout<<"line 1349 type= "<<$$->type_of_node<<endl;
            }
        }
        class_active=0;
        if($2==NULL ){
            $$->addr=$1->addr;
            $$->residual_ins=$1->residual_ins;
        }
        else{
            if($2->type_of_node.size()>=3 && $2->type_of_node.substr(0,3)=="Box"){
                string reg=newTemp();
                string arr_type=search_type_in_sym_table(curr_sym_tbl.top(),$1->lexeme);
                int offset=get_type_size(arr_type.substr(5,arr_type.size()-6));
                int arr_max_size=get_size_from_tbl(curr_sym_tbl.top(),$1->lexeme);
                // if(box_value*offset>=arr_max_size){
                //     cout<<"Error --atom_expr-- array index out of bound error "<<yylineno<<endl;
                // }
                string reg2 = newTemp();
                create_ins(3,"*",reg2,$2->addr,to_string(offset));
                string result=string($1->lexeme)+"["+reg2+"]";
                $2->addr=result;
                $$->addr=result;
            }
            
        }
        //  if($1->lexeme && string($1->lexeme)=="print"){ 
        //     create_ins(0,"print,", $2->addr,"","");
        //     // cout<<func_call_active<<" 1242"<<endl;
        //     // prev_var_name="";
        // }
 if($1->lexeme && string($1->lexeme)=="print"){ 
            $$->addr=$2->addr;
             if(p_prev_range==1){
                p_prev_range=0;
                prev_var_name="range";
            }else{
                prev_var_name="aryan";
            }
            // prev_var_name="";
        }



        if($1->lexeme && string($1->lexeme)=="len"){ 
            $$->addr=$2->addr;
             if(p_prev_range==1){
                p_prev_range=0;
                prev_var_name="range";
            }else{
                prev_var_name="aryan";
            }
            // prev_var_name="";
        }

        // if($1->lexeme && string($1->lexeme)== "len" ){
        //     if(p_prev_range==1){
        //         p_prev_range=0;
        //         prev_var_name="range";
        //     }else{
        //         prev_var_name="aryan";
        //     }
        //     // cout<<" 1273 at line " << yylineno<<endl;
        //     if($2==NULL){
        //         cout<<"Error --atom_expr-- invalid len usage at line " <<yylineno <<endl;
        //     }
        //     else{
        //         if($2->type_of_node.size()>=9 && $2->type_of_node.substr(0,9)!="Smalllist"){
        //             cout<<"Error --atom_expr-- invalid len arg type at line " <<yylineno <<endl;
        //         }
        //         // cout<<$2->type_of_node<<"  1277 "<<yylineno<<endl;
        //         string temp=newTemp();
        //         string reg=newTemp();
        //         create_ins(0,temp,"=","-4","");
        //         create_ins(2,"=",reg,$2->addr+"["+temp+"]","");
        //         // len_func=-1;
        //         $$->addr=reg;
        //         $$->type_of_node="int";
        //         if(func_call_active==1){
        //             func_arguments.push_back({reg,"int"});
        //         }
        //         // func_arguments.clear();
        //     }

        // }
    }
    ;

trailer_star:  trailer trailer_star  {
        $$ = create_node(3,"Stmts",$1,$2);
        $$->type_of_node=$1->type_of_node;
        $$->addr=$1->addr;
        if($2!=NULL){
            //check if first 3 substring is  Box
            if($1->type_of_node.substr(0,3)=="Box" || ($1->type_of_node.size()>=5 && $1->type_of_node.substr(0,5)=="Small")){
                    cout<<"Error invalid sequence of dereferencing at line no "<<yylineno<<endl;
                    return 0;
            }
            if($2->type_of_node.size()>=5 && ($2->type_of_node.substr(0,3)=="Box" ||  $2->type_of_node.substr(0,5)=="Small")){
                    dot_is_spl_type=$2->type_of_node;
            }else{
                dot_is_spl_type="";
            }
        }
        else{
            dot_is_spl_type="";
        }
    }
    | /*empty*/{$$=NULL;}
    ;


trailer: SMALL_OPEN { 
        brack_open = 1;
    } 
    arglist SMALL_CLOSE  {
        $$ = create_node(4,"Arguments",$1,$3,$4);
        $$->type_of_node = "Small"+$3->type_of_node;
        $$->addr=$3->addr;
        brack_open = 0;
        // if(func_call_active){
        //     for(auto t:func_arguments){
        //         for(auto t2:t) cout<<t2<<" ";
        //         cout<<endl;
        //     }   
        // }
        if(func_call_active==1 && len_func_call_active==0 && print_func_call_active==0){

            if(is_constructor){
                vector<st_node>sym_tbl_func_param=get_self_param(global_sym_table,func_arguments[0][0]);
                // cout<<"reaching 1289"<<func_arguments[0][0]<<sym_tbl_func_param.size()<<endl;
                if(sym_tbl_func_param.size()!=func_arguments.size()){
                    cout<<"Error invalid number of arguments at line " <<yylineno <<". Expected "<<sym_tbl_func_param.size()<<" arguments\n";
                    return 0;
                }
                else{
                    int total_size=0;
                    create_ins(0,"#callnew","","","");
                    for(int i=sym_tbl_func_param.size()-1;i>=1;i--){
                        total_size+=sym_tbl_func_param[i].size;
                        if(sym_tbl_func_param[i].type!=func_arguments[i][1] ){
                            if(sym_tbl_func_param[i].type=="int" && func_arguments[i][1]=="float"){

                            }else if(sym_tbl_func_param[i].type=="float" && func_arguments[i][1]=="int"){

                            }else if(sym_tbl_func_param[i].type=="int" && func_arguments[i][1]=="bool"){

                            }else if(sym_tbl_func_param[i].type=="bool" && func_arguments[i][1]=="int"){

                            }else{
                                cout<<"Error type of arguments not matching at line " <<yylineno <<endl;
                                return 0;
                            }
                        }
                        create_ins(0,"push",func_arguments[i][0],"","");
                    }
                    string reg=func_arguments[0][2];
                    int self_mem=get_ctr_self_size(global_sym_table,func_arguments[0][0]);
                    create_ins(0,reg,"=","alloc_mem("+to_string(self_mem)+")","");
                    create_ins(0,"push",reg,"","");
                    create_ins(0,"call,",func_arguments[0][0]+"___init__","","");
                    // create_ins(0,"call,",curr_sym_tbl.top()->name+"___init__","","");
                    $$->addr=reg;
                }
                // is_constructor=0;
                func_call_active=0;
                // cout<<" line 1341 "<<endl;
            }
            else{
                vector<st_node>sym_tbl_func_param=get_parameters(curr_sym_tbl.top(),func_arguments[0][0]);
                if(sym_tbl_func_param.size()+1!=func_arguments.size()){
                    cout<<"Error invalid number of arguments at line " <<yylineno <<endl;
                    return 0;

                }else {
                    create_ins(0,"#callnew","","","");
                    for(int i=sym_tbl_func_param.size()-1;i>=0;i--){
                        if(sym_tbl_func_param[i].type!=func_arguments[i+1][1] ){
                            if(sym_tbl_func_param[i].type=="int" && func_arguments[i+1][1]=="float"){

                            }else if(sym_tbl_func_param[i].type=="float" && func_arguments[i+1][1]=="int"){

                            }else if(sym_tbl_func_param[i].type=="int" && func_arguments[i+1][1]=="bool"){

                            }else if(sym_tbl_func_param[i].type=="bool" && func_arguments[i+1][1]=="int"){

                            }else{
                                cout<<"Error type of arguments not matching at line " <<yylineno <<endl;
                                return 0;
                            }
                        }
                        create_ins(0,"push",func_arguments[i+1][0],"","");
                    }
                    create_ins(0,"call,",func_arguments[0][0],"","");
                    // func_call_active=0;
                    // if(prev_var_name!="range" && prev_var_name!="len" && prev_var_name!="print")
                    // {
                    //     string reg=newTemp();
                    //     create_ins(0,"move8","%rax",reg,"");
                    //     // cout<<prev_var_name<<endl;
                    //     $$->addr=reg;
                    //     // func_call_active=0;
                    // }
                }
                // cout<<"found "<<endl;
                // for(auto it:func_arguments){
                //     for(auto it2:it){
                //         cout<<it2<<" ";
                //     }
                //     cout<<endl;
                // }
                // cout<<"enddd"<<endl;
            }
            func_arguments.clear();
            // cout<<"line 1354 "<<endl;
            // func_call_active=-1;
        }
        else if(len_func_call_active==1){
            len_func_call_active=0;
            string temp=newTemp();
            string reg=newTemp();
            create_ins(2,"=",temp,"-8","");
            // create_ins(0,temp,"=","-4","");
            create_ins(2,"=",reg,len_func_arguments[0][0]+"["+temp+"]","");
            // len_func=-1;
            $$->addr=reg;

            len_func_arguments.clear();
            $$->type_of_node="int";
            // if(func_call_active==1){
            //     func_arguments.push_back({reg,"int"});
            //     len_arg_pushed=1;
            // }
            // cout<<"at time after len"<<endl;
            // for(auto it:func_arguments){
            //     for(auto it2:it){
            //         cout<<it2<<" ";
            //     }
            //     cout<<endl;
            // }

        }
         else if(print_func_call_active==1){
            print_func_call_active=0;
            create_ins(0,"print,",print_func_arguments[0][0],print_func_arguments[0][1],"");
            print_func_arguments.clear();
            // len_func=-1;
            $$->addr=$3->addr;
            $$->type_of_node=$3->type_of_node;
        }
        class_active = 0;
    }
    |SMALL_OPEN SMALL_CLOSE { 
        $$ = create_node(3,"Parantheses",$1,$2);
        $$->type_of_node = "Small";
        if(func_call_active==1 && len_func_call_active==0){

         if(is_constructor){
                // cout<<"is_contructor"<<" "<<yylineno<<endl;
                vector<st_node>sym_tbl_func_param=get_self_param(global_sym_table,func_arguments[0][0]);
                if(sym_tbl_func_param.size()!=func_arguments.size()){
                    cout<<"Error invalid number of arguments at line " <<yylineno <<endl;
                    return 0;
                }
                else{
                    int total_size=0;
                    create_ins(0,"#callnew","","","");
                    for(int i=sym_tbl_func_param.size()-1;i>=1;i--){
                        total_size+=sym_tbl_func_param[i].size;
                        if(sym_tbl_func_param[i].type!=func_arguments[i-1][1] ){
                            if(sym_tbl_func_param[i].type=="int" && func_arguments[i-1][1]=="float"){

                            }else if(sym_tbl_func_param[i].type=="float" && func_arguments[i-1][1]=="int"){

                            }else if(sym_tbl_func_param[i].type=="int" && func_arguments[i-1][1]=="bool"){

                            }else if(sym_tbl_func_param[i].type=="bool" && func_arguments[i-1][1]=="int"){

                            }else{
                                cout<<"Error type of arguments not matching at line " <<yylineno <<endl;
                                return 0;
                            }
                        }
                        create_ins(0,"push",func_arguments[i][0],"","");
                    }
                    string reg=func_arguments[0][2];
                    int self_mem=get_ctr_self_size(global_sym_table,func_arguments[0][0]);
                    create_ins(0,reg,"=","alloc_mem("+to_string(self_mem)+")","");
                    create_ins(0,"push",reg,"","");
                    create_ins(0,"call,",func_arguments[0][0]+"___init__","","");
                    // create_ins(0,"call,",curr_sym_tbl.top()->name+"___init__","","");
                    $$->addr=reg;
                }
                // is_constructor=0;
                func_call_active=-1;
            }
            else{
                vector<st_node>sym_tbl_func_param=get_parameters(curr_sym_tbl.top(),func_arguments[0][0]);
                if(sym_tbl_func_param.size()+1!=func_arguments.size()){
                     cout<<"Error invalid number of arguments at line " <<yylineno <<endl;
                    return 0;
                }else 
                    create_ins(0,"#callnew","","","");
                    for(int i=sym_tbl_func_param.size()-1;i>=0;i--){
                        if(sym_tbl_func_param[i].type!=func_arguments[i][1] ){
                            if(sym_tbl_func_param[i].type=="int" && func_arguments[i+1][1]=="float"){

                            }else if(sym_tbl_func_param[i].type=="float" && func_arguments[i+1][1]=="int"){

                            }else if(sym_tbl_func_param[i].type=="int" && func_arguments[i+1][1]=="bool"){

                            }else if(sym_tbl_func_param[i].type=="bool" && func_arguments[i+1][1]=="int"){

                            }else{
                                cout<<"Error type of arguments not matching at line " <<yylineno <<endl;
                                return 0;
                            }
                        }
                        create_ins(0,"push",func_arguments[i+1][0],"","");
                    }
                create_ins(0,"call,",func_arguments[0][0],"","");
                // func_call_active=-1;
                // cout<<"hello"<<endl;
            }
            // func_arguments.clear();      

            class_active = 0;
            func_arguments.clear();
            // cout<<"line 1428 "<<endl;
        }
    }
    |BOX_OPEN {box_active = 1;} subscriptlist BOX_CLOSE {
        $$ = create_node(4,"Square_bracket",$1,$3,$4);
        $$->type_of_node = "Box;"+$3->type_of_node;
        $$->addr = $3->addr;
        box_active = 0;
        // cout<<"box_value "<<box_value<<endl;   
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
        $$->type_of_node = search_type_in_sym_table(curr_sym_tbl.top(),$2->lexeme);
        // $$->type_of_node = search_type_in_sym_table(curr_sym_tbl.top(),$2->lexeme);
        // if(!search_sym_table(curr_sym_tbl.top(),$2->lexeme,0)){
        //     cout<<"Sym_tbl_error: Variable "<<$2->lexeme<<" not declared at line "<<yylineno<<endl;
        //     cout<<curr_sym_tbl.top()->prev_sym_table->name<<" this also"<<endl;
        //     // give error as type hint not found
        // }
        // $$->type_of_node = search_type_in_sym_table(curr_sym_tbl.top(),$2->lexeme);

        if(class_active==1){
            class_func_call_active=1;
            func_arguments.clear();

            func_arguments.push_back({$2->lexeme, $2->type_of_node});
        }
    }
    ;


classdef: CLASS NAME {
            parameter_vec.clear(); is_param=1;
            is_class_arg=1;
        }
        bracket_arglist_optional COLON {
        is_class_arg=0;
        sym_table * new_table = new sym_table();
        create_entry(curr_sym_tbl.top(),$2->lexeme , $2->lexeme ,yylineno,__CLASS__,new_table );
        curr_sym_tbl.push(new_table);
        add_parameters(curr_sym_tbl.top(), parameter_vec);
        if($4!=NULL)
            add_parent_class(global_sym_table,curr_sym_tbl.top(), $4->type_of_node);
        is_param=0;
        }
        suite {
            $$=create_node(6,"Class_def",$1,$2,$4,$5,$7);
            if(curr_sym_tbl.size()>1)
                curr_sym_tbl.pop();
            // pop off the parameters
        };

bracket_arglist_optional: SMALL_OPEN SMALL_CLOSE {$$=create_node(3,"Parantheses",$1,$2);}
    | SMALL_OPEN arglist SMALL_CLOSE {
        $$=create_node(4,"Arguments",$1,$2,$3);
        $$->type_of_node=$2->type_of_node;
    }
    | {$$=NULL;}
    ;

arglist: argument_list COMMA {
        $$=create_node(3,"Arguments",$1,$2);
    }
    | argument_list {$$=$1;}
    ;

argument_list: argument_list COMMA argument { $$=create_node(4,"Arguments",$1,$2,$3);
        $$->type_of_node=$3->type_of_node;
        $$->addr=$3->addr;
        if(prev_var_name=="range"){
            if($3->type_of_node!="int"){
                cout<<"Error invalid argument type at line " <<yylineno <<endl;
                return 0;
            }
            range_arg.push_back($3->addr);
        }    
        if(func_call_active==1 && len_func_call_active==0 && print_func_call_active==0){
            if(len_arg_pushed==1){
                len_arg_pushed=0;
            }
            else{
                func_arguments.push_back({$3->addr, $3->type_of_node});
            }
        }
        if(class_func_call_active==1){
            func_arguments.push_back({$3->addr, $3->type_of_node});
        }
        if(len_func_call_active==1){
            len_func_arguments.push_back({$3->addr, $3->type_of_node});
        }
        if(print_func_call_active==1){
            print_func_arguments.push_back({$3->addr, $3->type_of_node});
        }
    }
    | argument { 
        $$=$1;
        if(prev_var_name=="range"){
            if($1->type_of_node!="int"){
                cout<<"Error invalid argument type at line " <<yylineno <<endl;
                return 0;
            }
            range_arg.push_back($1->addr);
        }
        if(func_call_active==1 && len_func_call_active==0 && print_func_call_active==0){
             if(len_arg_pushed==1){
                len_arg_pushed=0;
            }
            else{
                func_arguments.push_back({$1->addr, $1->type_of_node});
            }
            // cout<<$1->addr<<" "<<yylineno<<endl;
        }
        if(class_func_call_active==1){
            func_arguments.push_back({$1->addr, $1->type_of_node});
        }
        if(len_func_call_active==1){
            len_func_arguments.push_back({$1->addr, $1->type_of_node});
        }
        if(print_func_call_active==1){
            print_func_arguments.push_back({$1->addr, $1->type_of_node});
        }
    }
    ;

subscriptlist: subscript_list COMMA {$$=create_node(3,"Terms",$1,$2);
        $$->type_of_node=$1->type_of_node;
        $$->addr = $1->addr;
    }
    | subscript_list { $$=$1;$$->addr = $1->addr;}
    ;

subscript_list: subscript_list COMMA subscript { $$=create_node(4,"Terms",$1,$2,$3);
        $$->type_of_node=$3->type_of_node;
    }
    | subscript { $$=$1;$$->addr = $1->addr; }
    ;


subscript: test {$$=$1;$$->addr = $1->addr;}
   // |   optional_test COLON optional_test{ $$=create_node(4,"Terms",$1,$2,$3);}
    ;


argument: test { $$ = $1;}
    | test comp_for {$$=create_node(3,"Terms",$1,$2);}
    | test EQUAL test  {$$=create_node(4,"Assign_term",$1,$2,$3);
        if(
            $1->type_of_node!=$3->type_of_node && 
            (($1->type_of_node!="int" && $1->type_of_node!="float") || ( $3->type_of_node!="int" && $3->type_of_node!="float")) && 
            (($1->type_of_node!="bool" && $1->type_of_node!="int") || ($3->type_of_node!="bool" && $3->type_of_node!="int"))
        ){
            cout<<"Error invalid type assign at line " <<yylineno <<endl;
            return 0;
        }
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


or_test:or_test OR and_test {
    $$ = create_node(4,"OR_expr",$1,$2,$3);
       if($1->type_of_node!="int" && $3->type_of_node!="int"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node="int";
        if($1!=NULL){
            string reg=newTemp();
            create_ins(3,"or", reg,$1->addr, $3->addr);
            $$->addr=reg;
            $$->residual_ins=$1->residual_ins;
        }
        else{
            $$->addr=$3->addr;
            $$->residual_ins="or";
        }
    }
    | and_test {$$=$1;}; 

// or_test: and_test or_and_test_star{
//         $$=create_node(3,"Expressions",$1,$2);
//         if($2==NULL)
//             $$->type_of_node=$1->type_of_node;
//         else{
//             $$->type_of_node="int";
//             }
        
//         if($2==NULL ){
//             $$->addr=$1->addr;
//             $$->residual_ins=$1->residual_ins;
//         }else{
//             string reg = newTemp();
//             create_ins(3,$2->residual_ins,reg,$1->addr,$2->addr);
//             $$->addr = reg;
//             // cout<<$2->residual_ins<<endl;
//             $$->residual_ins = $1->residual_ins;
//         }
//     };

// or_and_test_star:OR and_test or_and_test_star {
//         $$=create_node(4,"OR_term",$1,$2,$3);
//         if($3==NULL)
//         {
//             $$->residual_ins = $1->lexeme;
//             $$->addr = $2->addr;
//             // cout<<$1->lexeme<<" "<<$$->addr<<endl;
//         }
//         else{
//             string reg = newTemp();
//             create_ins(2,$3->residual_ins, reg,$2->addr,$3->addr);
//             $$->residual_ins = $1->lexeme;
//             $$->addr = reg;
//         }
//     }
//     | { $$ = NULL;}
//     ;

and_test:and_test AND not_test {
    $$ = create_node(4,"AND_expr",$1,$2,$3);
       if($1->type_of_node!="int" && $3->type_of_node!="int"){
            cout<<"Error invalid operand type at line " <<yylineno <<endl;
            return 0;
        }
        $$->type_of_node="int";
        if($1!=NULL){
            string reg=newTemp();
            create_ins(3,"and", reg,$1->addr, $3->addr);
            $$->addr=reg;
            $$->residual_ins=$1->residual_ins;
        }
        else{
            $$->addr=$3->addr;
            $$->residual_ins="and";
        }
    }
    | not_test {$$=$1;}; 

// and_test: not_test and_not_test_star {
//     $$=create_node(3,"Expressions",$1,$2);
//     if($2==NULL)
//         $$->type_of_node=$1->type_of_node;
//     else{
//         // karna hai
//         $$->type_of_node="int";
//         }
//     if($2==NULL ){
//         $$->addr=$1->addr;
//         $$->residual_ins=$1->residual_ins;
//         // cout<<"yeh kyu when line "<<yylineno<<endl;
//     }else{
//         // cout<<"line 1128 "<<$2->addr<<" "<<yylineno<<endl;
//         string reg = newTemp();
//         create_ins(3,$2->residual_ins,reg,$1->addr,$2->addr);
//         $$->addr = reg;
//         // cout<<$2->residual_ins<<endl;
//         $$->residual_ins = $1->residual_ins;
//     }
// };

// and_not_test_star: AND not_test and_not_test_star {
//         $$=create_node(4,"And_term",$1,$2,$3);
//         $$->type_of_node="int";
//         if($3==NULL)
//         {
//             $$->residual_ins = $1->lexeme;
//             $$->addr = $2->addr;
//         }
//         else{
//             string reg = newTemp();
//             create_ins(2,$3->residual_ins, reg,$2->addr,$3->addr);
//             $$->residual_ins = $1->lexeme;
//             $$->addr = reg;
//         }
//     }
//     | { $$ = NULL;}
//     ;

not_test: NOT not_test {
        $$=create_node(3,"Not_term",$1,$2);
        $$->type_of_node=$2->type_of_node;
        string reg = newTemp();
        $$->residual_ins=$1->lexeme;
        create_ins(2,$1->lexeme, reg,$2->addr,"");
        $$->addr = reg;

    }
    | comparison {$$=$1;};
    
comparison: expr comp_op_expr_plus {
        $$=create_node(3,"Expressions",$1,$2);
        if($2==NULL){
            $$->type_of_node=$1->type_of_node;
            $$->addr=$1->addr;
        }
        else{
            // karna hai
            if($1->type_of_node!=$2->type_of_node){
                if($1->type_of_node=="int" && $2->type_of_node=="float" || $1->type_of_node=="float" && $2->type_of_node=="int"){
                    //continue
                }
                else if($1->type_of_node=="int" && $2->type_of_node=="bool" || $1->type_of_node=="bool" && $2->type_of_node=="int"){
                    //continue
                }
                else{
                    cout<<"Error invalid operand type at line " <<yylineno <<endl;
                    return 0;
                }
            }
            $$->type_of_node="int";

            // if($1->type_of_node!=$2->type_of_node 
            // && (($1->type_of_node!="int" || $1->type_of_node!="bool") && ($2->type_of_node!="int" || $2->type_of_node!="bool"))){
            //     cout<<"Error --comparison-- invalid type assign at line " <<yylineno <<".";
            // }
            }
        string reg = newTemp();
        create_ins(3,$2->residual_ins, reg,$1->addr, $2->addr);
        // cout<<$1->type_of_node<<endl;
        if($1->type_of_node == "str" && $2->type_of_node == "str") {
            str_cmp_ins_no.insert(instructions.size()-1);
        }
        $$->residual_ins = $1->residual_ins;
        $$->addr = reg;
       
    }
    |expr {
        $$=$1 ;
    }

comp_op_expr_plus: comp_op expr comp_op_expr_plus {
        $$=create_node(3,"Expresions",$1,$2);
        string reg = newTemp();
        create_ins(3,$3->residual_ins, reg,$2->addr, $3->addr);
        $$->residual_ins=$1->lexeme;
        $$->addr = reg;
        if($2->type_of_node!=$3->type_of_node){
                if($3->type_of_node=="int" && $2->type_of_node=="float" || $3->type_of_node=="float" && $2->type_of_node=="int"){
                    //continue
                }
                else if($3->type_of_node=="int" && $2->type_of_node=="bool" || $3->type_of_node=="bool" && $2->type_of_node=="int"){
                    //continue
                }
                else{
                    cout<<"Error invalid operand type at line " <<yylineno <<endl;
                    return 0;
                }
            }
        $$->type_of_node="int";
        
    }
    | comp_op expr {
        $$=create_node(3,"Expressions",$1,$2);
        $$->residual_ins=$1->lexeme;
        $$->addr=$2->addr;
        $$->type_of_node=$2->type_of_node;
    }
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

namedexpr_test: test {
    $$=$1;
    if(arr_active) 
        arr_elements.push_back($1->addr);
    };

test: or_test {
        $$=$1;
        $$->addr=$1->addr;
        $$->residual_ins=$1->residual_ins;
        // cout<<$$->addr<<" 1613 "<<yylineno<<endl;
    }
    |or_test IF or_test ELSE test {$$=create_node(6,"Expressions",$1,$2,$3,$4,$5);
    if($1->type_of_node!=$5->type_of_node){
        cout<<"Error invalid type  at line " <<yylineno <<".";
        return 0;
    }
    $$->type_of_node=$1->type_of_node;
    // cout<<$$->type_of_node<<"hello"<<endl;

    };

atom: SMALL_OPEN testlist_comp SMALL_CLOSE {
        
        $$=create_node(4,"Arguments",$1,$2,$3);
        $$->type_of_node = $2->type_of_node;
        $$->addr=$2->addr;
    }
    | SMALL_OPEN SMALL_CLOSE {$$=create_node(3,"Parantheses",$1,$2);}
    | BOX_OPEN {
            arr_active=1;
        } testlist_comp BOX_CLOSE {$$=create_node(4,"Square_bracket",$1,$3,$4);
        $$->type_of_node="list["+$3->type_of_node+"]";
        // cout<<"box "<<$2->type_of_node<<endl;
        // for(auto t: arr_elements) cout<<t<<" ";
        arr_active=0;
        string reg=newTemp();
        string array_size=to_string(get_type_size($3->type_of_node)*arr_elements.size()+8);
        create_ins(0,reg, "=","alloc_mem("+array_size+")","");
        $$->addr=reg;
        
        string temp=newTemp();
        create_ins(2,"=",temp,"0","");
        // create_ins(0,temp, "=","0","");

        //store the size of array in the first field
        create_ins(2,"=",$$->addr+"["+temp+"]",to_string(arr_elements.size()),"");
        create_ins(3,"+",temp,temp,"8");

        for(auto it: arr_elements){
            create_ins(2,"=",$$->addr+"["+temp+"]",it,"");
            create_ins(3,"+",temp,temp,to_string(get_type_size($3->type_of_node)));
        }
        
        create_ins(3,"+",reg,reg,"8"); // increase the pointer to move ahead of the size field

        // $$->size = get_type_size($3->type_of_node)*arr_elements.size();
        update_size_entry(curr_sym_tbl.top(),prev_var_name, get_type_size($3->type_of_node)*arr_elements.size());
        arr_elements.clear();

    }
    | BOX_OPEN BOX_CLOSE {$$=create_node(3,"Square_bracket",$1,$2);}
    | CURLY_OPEN CURLY_CLOSE {$$=create_node(3,"Curly_bracket",$1,$2);}
    | NAME {
        string curr_type = search_type_in_sym_table(curr_sym_tbl.top(),$1->lexeme);
        $1->type_of_node = curr_type; 
        $$=$1;
        $$->lexeme=$1->lexeme;
        $$->addr=$1->lexeme;
        if((string($1->lexeme)!="print" && string($1->lexeme)!="range"&& string($1->lexeme)!="len"&& string($1->lexeme)!="main") &&  !search_sym_table(curr_sym_tbl.top(),$1->lexeme,0)){
            cout<<"Variable "<<$1->lexeme<<" not declared at line "<<yylineno<<endl;
            return 0;
            // give error as type hint not found
        }
        $$->type_of_node=curr_type;
         if(string($1->lexeme)=="print" ){
             if(prev_var_name=="range"){
                p_prev_range=1;
            }
            print_func_call_active=1;
            
            prev_var_name=string($1->lexeme);
        }
        else if(string($1->lexeme)=="range"){
            prev_var_name=string($1->lexeme);
        }
        else if(string($1->lexeme)=="len"){

            if(prev_var_name=="range"){
                p_prev_range=1;
            }
            len_func_call_active=1;
            
            prev_var_name=string($1->lexeme);

        }
        else if(search_for_func(global_sym_table,$1->lexeme)){
            func_call_active=1;
            func_arguments.push_back({$1->addr, $1->type_of_node});
            
        }else if(search_for_class(global_sym_table,$1->lexeme)){
            func_call_active=1;
            is_constructor=1;
            func_arguments.clear();

            string reg=newTemp();
            $$->addr=reg;
            constructor_reg=reg;
            // cout<<"line 1792"<<endl;
            func_arguments.push_back({$1->lexeme, $1->type_of_node,reg});
        }
        else if(search_for_class(global_sym_table,$1->type_of_node)){
            class_active = 1;
            // cout<<"heeh"<<$1->type_of_node<<endl;
            // cout<<" line 1744 "<<yylineno<<endl;
        }
    }
    | NAME TYPE_HINT {
        $$=create_node(3,"Identifier", $1, $2); 
        $$->addr=$1->lexeme;
        $$->type_of_node = $2->lexeme;
        if(check_is_in_global(curr_sym_tbl.top(),$1->lexeme)){
            cout<<"Error global variable redefined at line " <<yylineno <<endl;
            return 0;
        }
        if(is_param) {
            add_to_vector(parameter_vec, $1->lexeme, $2->lexeme,yylineno);
        }
        else{
            // delete_sym_table(curr_sym_tbl.top(),$1->lexeme);
            int is_var=search_in_curr_scope(curr_sym_tbl.top(),$1->lexeme,0);
            if(is_var){
                cout<<"Error variable redefined  at line "<<yylineno<<endl;
                return 0;
                // delete_sym_table(curr_sym_tbl.top(),$1->lexeme);
            }
            create_entry(curr_sym_tbl.top(),  $1->lexeme,$2->lexeme,yylineno,0,NULL );
        }
        if(string($1->lexeme)=="print" || string($1->lexeme)=="range" )
            prev_var_name=string($1->lexeme);


    }
    | number {$$=$1;
        string reg=newTemp();
        create_ins(2,"=", reg,$1->lexeme,"");
        $$->addr=reg;
        if(box_active) box_value = stoi($1->lexeme);
        // if(prev_var_name=="print"){
        //     create_ins(0,"print(", $1->addr,")","");
        //     prev_var_name="";
        // }
    }
    | string_plus {$$=$1;
        string reg=newTemp();
        create_ins(2,"=", reg,$1->addr,"");
        $$->addr=reg;

        // if(prev_var_name=="print"){
        //     create_ins(0,"print(", $1->addr,")","");
        //     prev_var_name="";
        // }
    }
    | TRUE {$$=$1;
        $$->type_of_node="bool";
         string reg=newTemp();
        create_ins(2,"=", reg,$1->lexeme,"");
        $$->addr=reg;
        // if(prev_var_name=="print"){
        //     create_ins(0,"print(", $1->addr,")","");
        //     prev_var_name="";
        // }
    }
    | FALSE {
        $$=$1;
        $$->type_of_node="bool";
        string reg=newTemp();
        create_ins(2,"=", reg,$1->lexeme,"");
        $$->addr=reg;
        // if(prev_var_name=="print"){
        //     create_ins(0,"print(", $1->addr,")","");
        //     prev_var_name="";
        // }
    }
    | NONE {
        $$=$1;
        $$->type_of_node="None";
        string reg=newTemp();
        create_ins(2,"=", reg,$1->lexeme,"");
        $$->addr=reg;
        
        // if(prev_var_name=="print"){
        //     create_ins(0,"print(", $1->addr,")","");
        //     prev_var_name="";
        // }
    }
    ;
// dictionary , setliterals are to be ignored

number: INTEGER {$$ = $1;
       $$->addr=$$->lexeme;
       $$->type_of_node="int";
    }
    | FLOAT {$$ = $1;
        $$->addr=$$->lexeme;
        $$->type_of_node="float";
    }
    ;

string_plus: STRING string_plus {
    $$=create_node(3,"Strings", $1, $2);
    
    //ignore the last quote of the first string and the first quote of the second string
    $$->addr=string($1->lexeme).substr(0,string($1->lexeme).size()-1)+$2->addr.substr(1,$2->addr.size()-1);
    $$->type_of_node="str";
    }
    | STRING {$$=$1;
        $$->addr=$$->lexeme;
        $$->type_of_node="str";
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
    // cout<<value<<endl;
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
    // string temp = ".t" + to_string(tempCount);
    
    string temp = ".t" + to_string(tempCount);
    tempCount++;
    return temp;
}
string newLabel(){
    // string temp = ".label" + to_string(labelCount);
    string temp = ".label" + to_string(labelCount);
    label_st.push_back(temp);
    labelCount++;
    return temp;
}

string get_str_name(){
    string temp = ".str" + to_string(strCount);
    strCount++;
    return temp;
}

void create_ins(int type, string optype, string addr1,string addr2, string addr3 ){
    vector<string> instruct{to_string(type), optype, addr1, addr2, addr3};
    // int flag=0;
    if((type==2 || type==3) && offset_vec.find(curr_sym_tbl.top()->name+addr1)==offset_vec.end())
    {
        curr_sym_tbl.top()->x86_offset-=8;
        offset_vec[curr_sym_tbl.top()->name+addr1] = to_string(curr_sym_tbl.top()->x86_offset);
        // flag=1;
        // x86_file.push_back("subq $8, %rsp");
        // cout<<"subq $8, %rsp"<<endl;
    }
    if(type==0 && optype=="move8" && addr2[0]=='.'&& offset_vec.find(curr_sym_tbl.top()->name+addr2)==offset_vec.end())
    {
        curr_sym_tbl.top()->x86_offset-=8;
        offset_vec[curr_sym_tbl.top()->name+addr2] = to_string(curr_sym_tbl.top()->x86_offset);
        // flag=1;
        // x86_file.push_back("subq $8, %rsp");
        // cout<<"subq $8, %rsp"<<endl;
    }
    if(type==0 && optype=="move8" && addr1[0]=='.'&& offset_vec.find(curr_sym_tbl.top()->name+addr1)==offset_vec.end())
    {
        curr_sym_tbl.top()->x86_offset-=8;
        offset_vec[curr_sym_tbl.top()->name+addr1] = to_string(curr_sym_tbl.top()->x86_offset);
        // flag=1;
        // x86_file.push_back("subq $8, %rsp");
        // cout<<"subq $8, %rsp"<<endl;
    }
    if(type==0 && optype=="move8" &&  offset_vec.find(curr_sym_tbl.top()->name+addr1)==offset_vec.end())
    {
        curr_sym_tbl.top()->x86_offset-=8;
        offset_vec[curr_sym_tbl.top()->name+addr1] = to_string(curr_sym_tbl.top()->x86_offset);
        // flag=1;
        // x86_file.push_back("subq $8, %rsp");
        // cout<<"subq $8, %rsp"<<endl;
    }
    if (type == 0 && optype == "move8" && offset_vec.find(curr_sym_tbl.top()->name + addr2) == offset_vec.end())
    {
        curr_sym_tbl.top()->x86_offset -= 8;
        offset_vec[curr_sym_tbl.top()->name + addr2] = to_string(curr_sym_tbl.top()->x86_offset);
        // flag=1;
        // x86_file.push_back("subq $8, %rsp");
        // cout<<"subq $8, %rsp"<<endl;
    }

    if(type==0 && addr2.substr(0,9)=="alloc_mem" &&  optype[0]=='.' && offset_vec.find(curr_sym_tbl.top()->name+optype)==offset_vec.end()){
        curr_sym_tbl.top()->x86_offset-=8;
        offset_vec[curr_sym_tbl.top()->name+optype] = to_string(curr_sym_tbl.top()->x86_offset);
        
    }
    instructions.push_back(instruct);
    sym_tbl_info.push_back(curr_sym_tbl.top());
    instCount++;
    // print_x86_ins(instruct,curr_sym_tbl.top());



    // if(flag){
    //     x86_file.push_back("subq $8, %rsp");
    //     flag=0;
    // }

}

void print_instructions(string filename){
    ofstream fout;
    string filePath = "./output/"+filename+".txt";
    fout.open(filePath);
    for(auto ins: instructions){
        if(ins[0]=="3"){
            fout << ins[2] << " = " << ins[3] << " " << ins[1] << " " << ins[4] << endl; 
        }
        else if(ins[0]=="2"){
            if(ins[1] == "="){
                fout << ins[2] << " = " << ins[3] << endl;
            }
            else{
                fout << ins[2] << " = " << ins[1] << " " <<ins[3] << endl;
            }
        }else if(ins[0]=="0"){
            fout<<ins[1]<<" "<<ins[2]<<" "<<ins[3]<<" "<<ins[4]<<endl;
        }
    }
    fout.close();
}




// 3AC functions below----------------------





int get_offset(string temp, sym_table *symbol_table, string &reg)
{
    if (temp[0] == '.')
    {
        /* int offset=stoi(temp.substr(2));
        reg="-"+to_string((offset-1)*8)+"(%r15)";
        return offset; */
        reg = offset_vec[symbol_table->name+temp] + "(%rbp)";
        // last_offset = offset_vec[symbol_table->name+temp].substr(1);
        string offset_temp = offset_vec[symbol_table->name+temp];
        if(offset_temp.size())
            last_offset = offset_vec[symbol_table->name+temp].substr(1);
        else last_offset = "0";
        return 0;
    }
    else if (temp[0] == '-' || temp[0] <= '9' && temp[0] >= '0')
    {
        //check if string contains % or not
        if (temp.find("%") != string::npos)
        {
            reg = temp;
        }
        else
        {
            reg = "$" + temp;
        }
        return 0;
    }
    else if(temp[0]=='%'){
        reg=temp;
        last_offset = "0";
        return 0;
    }
    else{
        int offset= get_offset_from_tbl(symbol_table, temp);
        /* reg="-"+to_string(offset)+"(%rbp)"; */
        reg=offset_vec[symbol_table->name+temp]+"(%rbp)";
        // last_offset = offset_vec[symbol_table->name+temp].substr(1);
        string offset_temp = offset_vec[symbol_table->name+temp];
        if(offset_temp.size())
            last_offset = offset_vec[symbol_table->name+temp].substr(1);
        else last_offset = "0";
        return 0;
    }
}

string get_last_offset(string temp){
    if(temp.size()>6){
        return temp.substr(1,temp.size()-7);
    }else return "0";
}

void callnew(sym_table * symbol_table){
    x86_file.push_back("movq %rsp, "+to_string((symbol_table->x86_offset-8))+"(%rbp)");
    x86_file.push_back("shr $4, %rsp");   // Shift right by 4 bits
    x86_file.push_back("sub $1, %rsp");   // Add 1
    x86_file.push_back("shl $4, %rsp"); 
    return;
}

void print_x86_ins(vector<string> &ins,  sym_table *symbol_table,int ins_no)
{
    /* if(ins[2]=="i"){
        cout<<ins[0]<<"heheheehe"<<endl;
    } */
    string res_ins;
     if(ins[0]=="3"){
            res_ins=ins[2] + " = " + ins[3] + " " + ins[1] + " " + ins[4] ; 
    }
    else if(ins[0]=="2"){
        if(ins[1] == "="){
            res_ins=ins[2] + " = " + ins[3] ;
        }
        else{
            res_ins= ins[2] + " = " + ins[1] +" " +ins[3] ;
        }
    }else if(ins[0]=="0"){
        res_ins=ins[1]+" "+ins[2]+" "+ins[3]+" "+ins[4];
    }
    x86_file.push_back("\n#"+res_ins);
    if(str_cmp_ins_no.count(ins_no)){
        x86_file.push_back("# comparison of strings");
    }
    // cout<<ins[3]
    char firstLetter = ins[3][0];
    int is_string = 0;
    if(firstLetter>='0' && firstLetter<='9'){
        // cout<<"it is a number : "<<ins[3]<<endl;
    }else if(firstLetter=='"'){
        // cout<<"it is a string : "<<ins[3]<<endl;
        last_string = ins[3];
        str_count++;
        is_string = 1;
    }
        // cout<<last_offset<<endl;
    

    // string strx = typeid(ins[3]).name();
    // cout<<strx<<endl;


    if (ins[0] == "3"){
        string reg1,reg2,reg3;
        string offset_1,offset_2,offset_3;
        if(ins[2].back() == ']'){
            string reg4,reg5;
            string s1 = ins[2].substr(0, ins[3].find('['));
            string s2 = ins[2].substr(ins[3].find('[') + 1, ins[2].find(']') - ins[2].find('[') - 1);
            
            int temp1=get_offset(s1,symbol_table,reg4);
            int temp2=get_offset(s2,symbol_table,reg5);
            
            x86_file.push_back("movq "+ reg4 + ", %r8");
            x86_file.push_back("movq "+ reg5 + ", %r9");
            reg1 = "( %r8, %r9 )";
        }
        else{
            int temp1 = get_offset(ins[2], symbol_table,reg1);
            offset_1 = get_last_offset(reg1);
        }
        if(ins[3].back()==']'){
            string reg4,reg5;
            string s1 = ins[3].substr(0, ins[3].find('['));
            string s2 = ins[3].substr(ins[3].find('[') + 1, ins[3].find(']') - ins[3].find('[') - 1);
            
            int temp1=get_offset(s1,symbol_table,reg4);
            int temp2=get_offset(s2,symbol_table,reg5);
            
            x86_file.push_back("movq "+ reg4 + ", %r10");
            x86_file.push_back("movq "+ reg5 + ", %r11");
            reg2 = "( %r10, %r11 )";
        }
        else{
            int temp2 = get_offset(ins[3], symbol_table,reg2);
            offset_2 = get_last_offset(reg2);
        }
        if(ins[4].back()==']'){
            string reg4,reg5;
            string s1 = ins[4].substr(0, ins[4].find('['));
            string s2 = ins[4].substr(ins[4].find('[') + 1, ins[4].find(']') - ins[4].find('[') - 1);
            
            int temp1=get_offset(s1,symbol_table,reg4);
            int temp2=get_offset(s2,symbol_table,reg5);
            
            x86_file.push_back("movq "+ reg4 + ", %r12");
            x86_file.push_back("movq "+ reg5 + ", %r15");
            reg3 = "( %r12, %r15 )";
        }
        else{
            int temp3 = get_offset(ins[4], symbol_table,reg3);
            offset_3 = get_last_offset(reg3);
        }
        // cout<<offset_1<<" "<<offset_2<<" "<<offset_3<<endl;

        
        if (ins[1] == "+")
        {
            x86_file.push_back("movq "+reg2+", %r13");
            x86_file.push_back("movq "+reg3+", %r14");
            x86_file.push_back("addq %r13, %r14");
            x86_file.push_back("movq %r14, "+reg1);
            // x86_file.push_back("movq 0(%r1) %r2\n");
            // x86_file.push_back("movq 8(%r1) %r3\n");
            // x86_file.push_back("movq %r3 16(%r1)\n");
            // x86_file.push_back("movq %r3 16(%r1)\n");
        }
        else if (ins[1] == "-")
        {
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");
            x86_file.push_back("subq %r14, %r13");
            x86_file.push_back("movq %r13, " + reg1);
        }
        else if(ins[1] == "*")
        {
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");
            x86_file.push_back("imulq %r13, %r14");
            x86_file.push_back("movq %r14, " + reg1);
        }else if(ins[1]=="/"){
            x86_file.push_back("movq "+reg2+", %rax"); // $rdx for higher order, %rax for lower order
            x86_file.push_back("movq "+reg3+", %r14");
            x86_file.push_back("cqto");
            x86_file.push_back("idivq %r14");
            x86_file.push_back("movq %rax, " + reg1);
        }else if(ins[1]=="//"){
            x86_file.push_back("movq "+reg2+", %rax"); // $rdx for higher order, %rax for lower order
            x86_file.push_back("movq "+reg3+", %r14");
            x86_file.push_back("cqto");
            x86_file.push_back("idivq %r14");
            x86_file.push_back("movq %rax, " + reg1);
        }else if(ins[1]=="%"){
            x86_file.push_back("movq "+reg2+", %rax"); // $rdx for higher order, %rax for lower order
            x86_file.push_back("movq "+reg3+", %r14");
            x86_file.push_back("cqto");
            x86_file.push_back("idivq %r14");
            x86_file.push_back("movq %rdx, " + reg1);
        }
        else if(ins[1]==">"){
            if(str_cmp_ins_no.count(ins_no)){
                x86_file.push_back("movq " + reg2 + ", %rdi");
                x86_file.push_back("movq " + reg3 + ", %rsi");
                x86_file.push_back("call strcmp@PLT");
                x86_file.push_back("cmp $1, %eax");
                x86_file.push_back("sete %al");             
                x86_file.push_back("movzbq %al, %r14");     // Move the result into %r14, zero-extending it to 64 bits
                x86_file.push_back("movq %r14, "+reg1);
            }else{

                x86_file.push_back("movq " + reg2 + ", %r13");
                x86_file.push_back("movq " + reg3 + ", %r14");     // Move the value of 'a' into %rax
                x86_file.push_back("cmpq %r14, %r13");      // Compare 'a' with 'b'
                x86_file.push_back("setg %al");             // Set %al to 1 if 'a' is greater than 'b', otherwise set to 0
                x86_file.push_back("movzbq %al, %r14");     // Move the result into %r14, zero-extending it to 64 bits
                x86_file.push_back("movq %r14, "+reg1);
            }
        }
        else if(ins[1]=="<"){
            if(str_cmp_ins_no.count(ins_no)){
                x86_file.push_back("movq " + reg2 + ", %rdi");    // Move address of string a into %rdi
                x86_file.push_back("movq " + reg3 + ", %rsi");    // Move address of string b into %rsi
                x86_file.push_back("call strcmp@PLT");            // Call strcmp to compare the strings
                x86_file.push_back("test %eax, %eax");            // Test if result is zero
                x86_file.push_back("setl %al");                   // Set AL to 1 if string a < b (result < 0)
                x86_file.push_back("movzbq %al, %r14");           // Zero-extend AL to 64 bits and store in %r14
                x86_file.push_back("movq %r14, "+reg1);           // Move the result into reg1

                // x86_file.push_back("movq " + reg2 + ", %rdi");
                // x86_file.push_back("movq " + reg3 + ", %rsi");
                // x86_file.push_back("call strcmp@PLT");
                // x86_file.push_back("cmp $1, %eax");
                // x86_file.push_back("setne %al");             
                // x86_file.push_back("movzbq %al, %r14");     // Move the result into %r14, zero-extending it to 64 bits
                // x86_file.push_back("movq %r14, "+reg1);
            }else{
                x86_file.push_back("movq " + reg2 + ", %r13");
                x86_file.push_back("movq " + reg3 + ", %r14");     // Move the value of 'a' into %rax
                x86_file.push_back("cmpq %r13, %r14");      // Compare 'b' with 'a'
                x86_file.push_back("setg %al");             // Set %al to 1 if 'b' is greater than 'a', otherwise set to 0
                x86_file.push_back("movzbq %al, %r14");     // Move the result into %r14, zero-extending it to 64 bits
                x86_file.push_back("movq %r14, "+reg1);
            }
        }
        else if(ins[1]==">="){
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");     // Move the value of 'a' into %rax
            x86_file.push_back("cmpq %r14, %r13");      // Compare 'a' with 'b'
            x86_file.push_back("setge %al");             // Set %al to 1 if 'a' is greater than or equal to 'b', otherwise set to 0
            x86_file.push_back("movzbq %al, %r14");     // Move the result into %r14, zero-extending it to 64 bits
            x86_file.push_back("movq %r14, "+reg1);
        }
        else if(ins[1]=="<="){
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");     // Move the value of 'a' into %rax
            x86_file.push_back("cmpq %r13, %r14");      // Compare 'b' with 'a'
            x86_file.push_back("setge %al");             // Set %al to 1 if 'b' is greater than or equal to 'a', otherwise set to 0
            x86_file.push_back("movzbq %al, %r14");     // Move the result into %r14, zero-extending it to 64 bits
            x86_file.push_back("movq %r14, "+reg1);
        }
        else if(ins[1]=="=="){
            if(str_cmp_ins_no.count(ins_no)){
                x86_file.push_back("movq " + reg2 + ", %rdi");
                x86_file.push_back("movq " + reg3 + ", %rsi");
                x86_file.push_back("call strcmp@PLT");
                x86_file.push_back("cmpq $0, %rax");
                x86_file.push_back("sete %al");             
                x86_file.push_back("movzbq %al, %r14");     // Move the result into %r14, zero-extending it to 64 bits
                x86_file.push_back("movq %r14, "+reg1);
            }else{
                x86_file.push_back("movq " + reg2 + ", %r13");
                x86_file.push_back("movq " + reg3 + ", %r14");     // Move the value of 'a' into %rax
                x86_file.push_back("cmpq %r13, %r14");      // Compare 'b' with 'a'
                x86_file.push_back("sete %al");             // Set %al to 1 if 'b' is  equal to 'a', otherwise set to 0
                x86_file.push_back("movzbq %al, %r14");     // Move the result into %r14, zero-extending it to 64 bits
                x86_file.push_back("movq %r14, "+reg1);
            }
        }
        else if (ins[1] == "&")
        {
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");
            x86_file.push_back("andq %r13, %r14");
            x86_file.push_back("movq %r14, " + reg1);
        }
        else if(ins[1]=="!="){
            if(str_cmp_ins_no.count(ins_no)){
                x86_file.push_back("movq " + reg2 + ", %rdi");
                x86_file.push_back("movq " + reg3 + ", %rsi");
                x86_file.push_back("call strcmp@PLT");
                x86_file.push_back("cmpq $0, %rax");
                x86_file.push_back("setne %al");             
                x86_file.push_back("movzbq %al, %r14");     // Move the result into %r14, zero-extending it to 64 bits
                x86_file.push_back("movq %r14, "+reg1);
            }else{
                x86_file.push_back("movq " + reg2 + ", %r13");
                x86_file.push_back("movq " + reg3 + ", %r14");
                x86_file.push_back("cmpq %r13, %r14");
                x86_file.push_back("setne %al");
                x86_file.push_back("movzbq %al, %r13");
                x86_file.push_back("movq %r13, " + reg1);
            }
        }
        else if (ins[1] == "|")
        {
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");
            x86_file.push_back("orq %r13, %r14");
            x86_file.push_back("movq %r14, " + reg1);
        }else if(ins[1]=="and"){
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");
            x86_file.push_back("cmpq $0, %r13");
            x86_file.push_back("setne %al");
            x86_file.push_back("movzbq %al, %r13");
            x86_file.push_back("cmpq $0, %r14");
            x86_file.push_back("setne %al");
            x86_file.push_back("movzbq %al, %r14");
            x86_file.push_back("andq %r13, %r14");
            x86_file.push_back("movq %r14, " + reg1);
        }else if(ins[1]=="or"){
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");
            x86_file.push_back("cmpq $0, %r13");
            x86_file.push_back("setne %al");
            x86_file.push_back("movzbq %al, %r13");
            x86_file.push_back("cmpq $0, %r14");
            x86_file.push_back("setne %al");
            x86_file.push_back("movzbq %al, %r14");
            x86_file.push_back("orq %r13, %r14");
            x86_file.push_back("movq %r14, " + reg1);
        }else if(ins[1]=="**"){
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");
            x86_file.push_back("movq %r13, %rax");
            x86_file.push_back("movq %r14, %rcx");
            x86_file.push_back("xor %rdx, %rdx");
            x86_file.push_back("movq $1, %rdx");
            x86_file.push_back("cmpq $0, %rcx");
            x86_file.push_back("je .label" + to_string(labelCount));
            x86_file.push_back(".label" + to_string(labelCount) + ":");
            x86_file.push_back("imul %rax, %rdx");
            x86_file.push_back("dec %rcx");
            x86_file.push_back("cmpq $0, %rcx");
            x86_file.push_back("jne .label" + to_string(labelCount));
            x86_file.push_back("movq %rdx, " + reg1);
            labelCount++;
        }
        else if(ins[1]=="<<"){
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");
            x86_file.push_back("movq %r13, %rax");
            x86_file.push_back("movq %r14, %rcx");
            x86_file.push_back("shl %cl, %al");
            x86_file.push_back("movq %rax, " + reg1);
            
        }
        else if(ins[1]==">>"){
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");
            x86_file.push_back("movq %r13, %rax");
            x86_file.push_back("movq %r14, %rcx");
            x86_file.push_back("shr %cl, %al");
            x86_file.push_back("movq %rax, " + reg1);
        }
        else if(ins[1]=="in"){
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");
        }else if(ins[1]=="^"){
            x86_file.push_back("movq " + reg2 + ", %r13");
            x86_file.push_back("movq " + reg3 + ", %r14");
            x86_file.push_back("xorq %r13, %r14");
            x86_file.push_back("movq %r14, " + reg1);
        }
        
    }
    else if(ins[0]=="2"){
        string reg1, reg2;
        string offset_1, offset_2;
        if(ins[2].back() == ']'){
            string reg4,reg5;
            string s1 = ins[2].substr(0, ins[2].find('['));
            string s2 = ins[2].substr(ins[2].find('[') + 1, ins[2].find(']') - ins[2].find('[') - 1);
            
            int temp1=get_offset(s1,symbol_table,reg4);
            int temp2=get_offset(s2,symbol_table,reg5);
            
            x86_file.push_back("movq "+ reg4 + ", %r8");
            x86_file.push_back("movq "+ reg5 + ", %r9");
            reg1 = "( %r8, %r9 )";
        }
        else{
            int temp1 = get_offset(ins[2], symbol_table, reg1);
            offset_1 = get_last_offset(reg1);
        }
        if(ins[3].back()==']'){
            string reg4,reg5;
            string s1 = ins[3].substr(0, ins[3].find('['));
            string s2 = ins[3].substr(ins[3].find('[') + 1, ins[3].find(']') - ins[3].find('[') - 1);
            
            int temp1=get_offset(s1,symbol_table,reg4);
            int temp2=get_offset(s2,symbol_table,reg5);
            
            x86_file.push_back("movq "+ reg4 + ", %r10");
            x86_file.push_back("movq "+ reg5 + ", %r11");
            reg2 = "( %r10, %r11 )";
        }
        else{
            int temp2 = get_offset(ins[3], symbol_table, reg2);
            offset_2 = get_last_offset(reg2);
        }
        // cout<<offset_1<<" "<<offset_2<<endl;
        /* if(ins[2]=="i"){
            cout<<ins[1]<<" hehehe "<<reg1<<" "<<reg2<<endl;        } */
        if(ins[1]=="="){
            if(last_string.size()>2 && is_string){
                str_map[to_string(str_count)] = last_string.substr(1,last_string.size()-2)+"\\n";
                /* str_map[o] = last_string.substr(1,last_string.size()-2)+"\\n"; */

            }else{
                /* str_map[offset_1] = "\\n";
                str_map[offset_2] = "\\n"; */
            }
            if(ins[3].back()==']' && ins[2].back()==']'){
                x86_file.push_back("movq "+reg2+", %r13");
                x86_file.push_back("movq %r13, "+reg1);
            }
            else if(ins[3][0]>= '0' && ins[3][0]<='9'){
                x86_file.push_back("movq "+reg2+", "+reg1);
            }
            else{
                if(is_string){
                    x86_file.push_back("movq $.str" + to_string(str_count) + ", %r13");
                }else{
                     x86_file.push_back("movq " + reg2 + ", %r13");
                }
                    x86_file.push_back("movq %r13, " +  reg1);
            }
            // cout<<ins[2]<<" "<<temp1<<endl;
            // cout<<ins[3]<<" "<<temp2<<endl;
        }
        else if(ins[1]=="~"){
            x86_file.push_back("movq " + reg2 + ", %r14");
            x86_file.push_back("notq %r14");
            x86_file.push_back("movq %r14, " + reg1);
        }else if(ins[1]=="not"){
            x86_file.push_back("movq " + reg2 + ", %r14");
            x86_file.push_back("cmpq $0, %r14");
            x86_file.push_back("sete %al");
            x86_file.push_back("movzbq %al, %r14");
            x86_file.push_back("movq %r14, " + reg1);

        }
    }else if(ins[0]=="0"){
        if(ins[1]=="print,"){
            string reg;
            string offset_1;
            if(ins[2].back()==']'){
                string reg4,reg5;
                string s1 = ins[2].substr(0, ins[2].find('['));
                string s2 = ins[2].substr(ins[2].find('[') + 1, ins[2].find(']') - ins[2].find('[') - 1);
                
                int temp1=get_offset(s1,symbol_table,reg4);
                int temp2=get_offset(s2,symbol_table,reg5);
                
                x86_file.push_back("movq "+ reg4 + ", %r8");
                x86_file.push_back("movq "+ reg5 + ", %r9");
                reg = "( %r8, %r9 )";
            }
            else{
                int temp1 = get_offset(ins[2], symbol_table, reg);
                offset_1 = get_last_offset(reg);
            }
            // cout<<offset_1<<endl;
            // x86_file.push_back("push %rbx");
            x86_file.push_back("mov "+reg+", %rax");
            x86_file.push_back("mov %rax, %rsi");
            if(ins[3]=="str"){
                string str_name=get_str_name();
                /* x86_file.push_back("leaq .str"+offset_1+"(%rip), %rax"); */
                x86_file.push_back("movq "+reg+", %rdi");
            }else{
                x86_file.push_back("lea .note0(%rip), %rax");
            }
            x86_file.push_back("mov %rax, %rdi");
            x86_file.push_back("xor %rax, %rax");
            // x86_file.push_back("subq $"+to_string(curr_sym_tbl.top()->x86_offset *(-1))+", %rsp");
            callnew(symbol_table);
            x86_file.push_back("call printf@plt");
            x86_file.push_back("movq "+to_string((symbol_table->x86_offset-8))+"(%rbp), %rsp");
            // x86_file.push_back("pop %rsp");
        }
        else if(ins[1]=="goto"){
            // cout<<"jumppp "<<ins[2]<<endl;
            x86_file.push_back("jmp "+ins[2]);
        }
        else if(ins[1].back()==':'){
            // cout<<"reaching : "<<ins[1]<<endl;
            x86_file.push_back(ins[1]);
                // cout<<symbol_table->name<<" reaching "<<ins[1]<<endl;
            if(ins[1]=="main:"){
                x86_file.push_back("pushq %rbp");
                x86_file.push_back("movq %rsp, %rbp");
                x86_file.push_back("subq $"+to_string(symbol_table->x86_offset*(-1) + 8)+", %rsp");
            }
            if(ins[1]!="main:"&& ((symbol_table->name+":" ==ins[1])||(symbol_table->name+"___init__:"==ins[1])||(symbol_table->prev_sym_table->name+"_"+symbol_table->name+":"==ins[1]))){
                x86_file.push_back("pushq %rbp");
                x86_file.push_back("movq %rsp, %rbp");
                x86_file.push_back("subq $"+to_string(symbol_table->x86_offset*(-1))+", %rsp");
                x86_file.push_back("pushq %rbx");
                x86_file.push_back("pushq %rdi");
                x86_file.push_back("pushq %rsi");
                x86_file.push_back("pushq %r12");
                x86_file.push_back("pushq %r13");
                x86_file.push_back("pushq %r14");
                x86_file.push_back("pushq %r15");

            }
        }
        else if(ins[1] == "if_false"){
            string reg;
            int offset=get_offset(ins[2],symbol_table,reg);
            x86_file.push_back("mov "+reg+", %rax");
            x86_file.push_back("cmp $0, %rax");
            x86_file.push_back("je "+ins[4]);
        }
        else if(ins[1]== "call,"){
        //    callnew(symbol_table); //handled in antoher if condition #callnew
            x86_file.push_back("call "+ins[2]);
            x86_file.push_back("addq %r13, %rsp"); //restoring the space allocated for pushing the arguments
            x86_file.push_back("movq "+to_string((symbol_table->x86_offset-8))+"(%rbp), %rsp");
            // x86_file.push_back("pop %rsp"); //restoring the prev rsp before callnew

        }else if(ins[1]=="move8"){
            string reg1,reg2;
            if(ins[2].back()==']'){
                string reg4,reg5;
                string s1 = ins[2].substr(0, ins[2].find('['));
                string s2 = ins[2].substr(ins[2].find('[') + 1, ins[2].find(']') - ins[2].find('[') - 1);
                
                int temp1=get_offset(s1,symbol_table,reg4);
                int temp2=get_offset(s2,symbol_table,reg5);
                
                x86_file.push_back("movq "+ reg4 + ", %r8");
                x86_file.push_back("movq "+ reg5 + ", %r9");
                reg1 = "( %r8, %r9 )";
            }
            else{
                int temp1 = get_offset(ins[2], symbol_table, reg1);
            }
            if(ins[3].back()==']'){
                string reg4,reg5;
                string s1 = ins[3].substr(0, ins[3].find('['));
                string s2 = ins[3].substr(ins[3].find('[') + 1, ins[3].find(']') - ins[3].find('[') - 1);
                
                int temp1=get_offset(s1,symbol_table,reg4);
                int temp2=get_offset(s2,symbol_table,reg5);
                
                x86_file.push_back("movq "+ reg4 + ", %r10");
                x86_file.push_back("movq "+ reg5 + ", %r11");
                reg2 = "( %r10, %r11 )";
            }
            else{
                int temp2 = get_offset(ins[3], symbol_table, reg2);
            }
            /* int temp1=get_offset(ins[2],symbol_table,reg1);
            int temp2=get_offset(ins[3],symbol_table,reg2); */
            /* if((reg1[0]=='-'|| (reg1[0]<='9'&& reg1[0]>='0')) && (reg2[0]=='-'|| (reg2[0]<='9'&& reg2[0]>='0')))
            { */
                x86_file.push_back("movq "+reg1+", %r13");
                x86_file.push_back("movq %r13, "+reg2);
            /* }
            else{
                x86_file.push_back("movq "+reg1+", "+reg2);
            } */
        }else if(ins[1]=="ret"){
            x86_file.push_back("popq %r15");
            x86_file.push_back("popq %r14");
            x86_file.push_back("popq %r13");
            x86_file.push_back("popq %r12");
            x86_file.push_back("popq %rsi");
            x86_file.push_back("popq %rdi");
            x86_file.push_back("popq %rbx");
            x86_file.push_back("addq $"+to_string(symbol_table->x86_offset*(-1))+", %rsp");
            x86_file.push_back("popq %rbp");
            x86_file.push_back("movq $"+to_string(symbol_table->parameter_count*8)+", %r13");
            x86_file.push_back("ret");
        }
        else if(ins[1]=="push"){
            string reg;
            if(ins[2].back()==']'){
                string reg4,reg5;
                string s1 = ins[2].substr(0, ins[2].find('['));
                string s2 = ins[2].substr(ins[2].find('[') + 1, ins[2].find(']') - ins[2].find('[') - 1);
                
                int temp1=get_offset(s1,symbol_table,reg4);
                int temp2=get_offset(s2,symbol_table,reg5);
                
                x86_file.push_back("movq "+ reg4 + ", %r8");
                x86_file.push_back("movq "+ reg5 + ", %r9");
                reg = "( %r8, %r9 )";
            }
            else{
                int temp1 = get_offset(ins[2], symbol_table, reg);
            }
            x86_file.push_back("pushq "+reg);
        }
        else if(ins[3].substr(0,9)=="alloc_mem"){
            string size = ins[3].substr(10, ins[3].size()-11);
            callnew(symbol_table);
            x86_file.push_back("movq $"+ size +", %rdi");
            x86_file.push_back("call malloc@plt");
            x86_file.push_back("movq "+to_string((symbol_table->x86_offset-8))+"(%rbp), %rsp");
            // x86_file.push_back("pop %rsp"); //restoring the prev rsp before callnew
            //got the pointer to array in %rax
            string reg;
            int temp=get_offset(ins[1],symbol_table,reg);
            x86_file.push_back("movq %rax, " + reg);
        }
        else if(ins[1].back()==']'){
            string reg1,reg2,reg3;
            string s1 = ins[1].substr(0, ins[1].find('['));
            string s2 = ins[1].substr(ins[1].find('[') + 1, ins[1].find(']') - ins[1].find('[') - 1);
            int temp1=get_offset(s1,symbol_table,reg1);
            int temp2=get_offset(s2,symbol_table,reg2);
            int temp3=get_offset(ins[3],symbol_table,reg3);
            
            x86_file.push_back("movq "+ reg1 + ", %r13");
            x86_file.push_back("movq "+ reg2 + ", %r14");
            x86_file.push_back("movq "+ reg3 + ", %r15");
            x86_file.push_back("movq %r15, (%r13, %r14)"); // Store the value 4 at memory location a + offset

        }
        else if(ins[1]=="#callnew"){
            callnew(symbol_table);
        }
    }
    is_string = 0;
}

void create_x86_file(string filename){
    ofstream fout;
    string filePath = "./output/"+filename+".s";
    fout.open(filePath);
    fout<<".section .data\n";
    fout<<".section .text\n";
    fout<<".section .rodata\n";
    fout<<".note0:"<<endl;
    fout<<"        .string \"%ld\\n\""<<endl;
    fout<<"        .text"<<endl;
    for(auto it: str_map){
        fout<<".str"+it.first+":"<<endl;
        fout<<"        .string \""+it.second+"\""<<endl;
        fout<<"        .text"<<endl;
    }
    fout<<".global main\n";
    // fout<<"main:\n";
    // fout << "push %rbp\n";
    // fout << "movq %rsp, %rbp\n";
    for(auto ins: x86_file){
        
        fout<<ins<<endl;
    }
    fout<<"\n";
    // fout<<"ret"<<endl;
    fout<<"pop %rbx"<<endl;
    fout<< "mov $60, %rax       # System call number for exit\n";
    fout<<"xor %rdi, %rdi      # Exit code is 0\n";
    fout<<"syscall\n";
    fout.close();
}

void generate_x86_ins(){
    for(int i=0;i<instructions.size();i++){
        if(instructions[i][1]=="programStart:"){
            return;
        }
        print_x86_ins(instructions[i],sym_tbl_info[i],i);
    }
}

int main(int argc, char* argv[]){
    indent_stack.push(0);
    /* yylex(); */
    global_sym_table->total_offset=0;
    global_sym_table->return_type = "undefined";
    global_sym_table->name= "global";
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

    remove("output");
    std::string folderName = "output";
    std::filesystem::create_directory(folderName);


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
	fout.open(("./output/"+output_file+".dot").c_str() , ios::out | ios::trunc);
    

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
    //  print_sym_table(global_sym_table); 
    printToCSV(global_sym_table,0,global_sym_table->name);

    fout<<"}";
    fout.close();
    print_instructions(output_file);

    generate_x86_ins();

    create_x86_file(output_file);
    // create_x86_code(instructions,global_sym_table);

    return 0;
}


int yyerror(const char *s){
    cout << "Error: " << s << ",line: "<< yylineno << endl;
    return 0;
}