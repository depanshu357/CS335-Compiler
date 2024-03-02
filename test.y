%{
    #include <bits/stdc++.h>
    #include "data.h"
    using namespace std;
    int yylex();    
    int yyerror(const char *s);
    extern int yylineno;
    extern stack<int> indent_stack;
    NODE *start_node;
	fstream fout;
	extern FILE *yyin;

    

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
%type <elem> start file_input stmt compound_stmt async_stmt if_stmt elif_namedexpr_test_colon_suite_star while_stmt for_stmt try_stmt except_clause_colon_suite try_stmt_options except_clause test_as_name_optional funcdef parameters typedlist_argument typedlist_arguments comma_option_argument_star typedarglist tfpdef func_body_suite suite stmt_plus simple_stmt semi_colon_small_stmt_star small_stmt flow_stmt break_stmt continue_stmt return_stmt raise_stmt global_stmt nonlocal_stmt comma_name_star assert_stmt expr_stmt testlist symbol_test_star expr_stmt_option1_plus annassign testlist_star_expr testlist_star_expr_option1_star augassign expr star_expr symbol_xor_expr_star xor_expr symbol_and_expr_star and_expr symbol_shift_expr_star shift_expr shift_arith_expr_star arith_expr symbol_term_star term symbol_factor_star symbol_factor factor power atom_expr trailer_star trailer classdef bracket_arglist_optional arglist argument_list subscriptlist subscript_list subscript argument optional_test comp_iter sync_comp_for comp_for comp_if test_nocond or_test or_and_test_star and_test and_not_test_star not_test comparison comp_op_expr_plus comp_op exprlist expr_star_expr_option expr_star_expr_option_list testlist_comp namedexpr_test_star_expr_option_list namedexpr_test_star_expr_option namedexpr_test test atom number string_plus  

%%



start : file_input {$$ = create_node(2,"START", $1); start_node=$$;}
    ;

file_input: NEWLINE file_input {$$ = $2;}
    | stmt file_input {$$ = create_node(3,"file_input",$1,$2);}
    | { /* action */}	
    ;


stmt: simple_stmt  {$$ = $1;}
    |compound_stmt {$$ = $1;}
    ;

compound_stmt: if_stmt { $$ = $1;}
    |  while_stmt { $$ = $1;}
    | for_stmt { $$ = $1;}
    | try_stmt { $$ = $1;}
    | funcdef  {  $$ = $1;}
    | classdef { $$ = $1;}
    | async_stmt { $$ = $1;}
    ;
    
async_stmt: ASYNC funcdef { $$ = create_node(3,"async_stmt",$1,$2);}
    | ASYNC for_stmt { $$ = create_node(3,"async_stmt",$1,$2);}
    ;

if_stmt: IF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star ELSE COLON suite { $$ = create_node(9,"if_stmt",$1,$2,$3,$4,$5,$6,$7,$8);}
    | IF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star { $$ = create_node(6,"if_stmt",$1,$2,$3,$4,$5);}
    ;

elif_namedexpr_test_colon_suite_star: ELIF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star {$$ = create_node(5,"elif_namedexpr",$1,$2,$3,$4);}
    | { $$ = NULL;}
    ;

while_stmt: WHILE namedexpr_test COLON suite ELSE COLON suite { $$ = create_node(8,"while_stmt",$1,$2,$3,$4,$5,$6,$7);}
    | WHILE namedexpr_test COLON suite {$$ = create_node(5,"while_stmt",$1,$2,$3,$4);}
    ;

for_stmt:  FOR exprlist IN testlist COLON suite ELSE COLON suite { $$ = create_node(10,"for_stmt",$1,$2,$3,$4,$5,$6,$7,$8,$9);}
    | FOR exprlist IN testlist COLON suite {$$ = create_node(7,"for_stmt",$1,$2,$3,$4,$5,$6);}
    ; 

try_stmt: TRY COLON suite FINALLY COLON suite {$$ = create_node(7,"try_stmt",$1,$2,$3,$4,$5,$6);}
    | TRY COLON suite except_clause_colon_suite try_stmt_options { $$ = create_node(6,"try_stmt",$1,$2,$3,$4,$5);}
    ;

except_clause_colon_suite: except_clause COLON suite except_clause_colon_suite {$$ = create_node(5,"except_clause_colon_suite",$1,$2,$3,$4);}
    | except_clause COLON suite { $$ = create_node(4,"except_clause_colon_suite",$1,$2,$3);}
    ;

try_stmt_options: ELSE COLON suite FINALLY COLON suite { $$ = create_node(7,"try_stmt_options",$1,$2,$3,$4,$5,$6);}
    | ELSE COLON suite {$$ = create_node(4,"try_stmt_options",$1,$2,$3);}
    | FINALLY COLON suite { $$ = create_node(4,"try_stmt_options",$1,$2,$3);}
    | { $$ = NULL;{}}
    ;

except_clause: EXCEPT test_as_name_optional {$$ = create_node(3,"except_clause",$1,$2);}

test_as_name_optional: test {$$=$1;}
    | test AS NAME {$$ = create_node(4,"test_as_name",$1,$2,$3);}
    | {$$ = NULL;}
    ;

/*using this notation instead of below one*/
funcdef:  DEF NAME parameters  FUNC_TYPE_HINT COLON  func_body_suite { $$ = create_node(7,"funcdef",$1,$2,$3,$4,$5,$6);}
    | DEF NAME parameters  COLON  func_body_suite { $$ = create_node(6,"funcdef",$1,$2,$3,$4,$5);}
    ;

// Written only to run START ye dono document se dekhna hai
parameters: SMALL_OPEN typedarglist SMALL_CLOSE {$$ = create_node(4,"parameters",$1,$2,$3);}
    |SMALL_OPEN SMALL_CLOSE {$$ = create_node(3,"parameters",$1,$2);}
    ;


typedlist_argument: tfpdef  { $$ = $1;}
    // |  tfpdef TYPE_HINT
    // |  tfpdef TYPE_HINT EQUAL test {cout << "yes";}
    |  tfpdef  EQUAL test { $$ = create_node(4,"typedlist_argument",$1,$2,$3);}
    ;
    
typedlist_arguments: typedlist_argument comma_option_argument_star {$$ = create_node(3,"typedlist_arguments",$1,$2);};

comma_option_argument_star: comma_option_argument_star COMMA typedlist_argument {$$ = create_node(4,"comma_option_argument_star",$1,$2,$3);}
    | { $$ = NULL;}
    ;

typedarglist:
    typedlist_arguments {$$ = $1;}
    ;

tfpdef: NAME { $$ = $1;}
    | NAME TYPE_HINT { $$ = create_node(3,"tfpdef",$1,$2); }
    | NAME COLON test {$$ = create_node(4,"tfpdef",$1,$2,$3);}
    ;

func_body_suite: simple_stmt {$$ = $1;}
    | NEWLINE INDENT stmt_plus DEDENT { $$ = $3;}

suite: simple_stmt {$$ = $1;}
    | NEWLINE INDENT stmt_plus DEDENT { $$ = $3;}
    ;

stmt_plus: stmt stmt_plus {$$ = create_node(3,"stmt_plus",$1,$2);}
    | stmt {$$ = $1;}
    ;

simple_stmt: small_stmt semi_colon_small_stmt_star NEWLINE {$$ = create_node(3,"simple_stmt",$1,$2);}
    ;

semi_colon_small_stmt_star: SEMI_COLON small_stmt semi_colon_small_stmt_star {$$ = create_node(4,"semi_colon_small_stmt_star",$1,$2,$3);}
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

return_stmt: RETURN testlist_star_expr {$$ = create_node(3,"return_stmt",$1,$2);}
    | RETURN {$$ = $1;}
    ;

raise_stmt: RAISE {$$ = $1;}
    | RAISE test {$$ = create_node(3,"raise_stmt",$1,$2);}
    | RAISE test FROM test {$$ = create_node(5,"raise_stmt",$1,$2,$3,$4);}
    ;

global_stmt: GLOBAL NAME comma_name_star {$$ = create_node(4,"global_stmt",$1,$2,$3);};

nonlocal_stmt: NONLOCAL NAME comma_name_star {$$ = create_node(4,"nonlocal_stmt",$1,$2,$3);};

comma_name_star: COMMA NAME comma_name_star {$$ = create_node(4,"comma_name_star",$1,$2,$3);}
    | { $$ = NULL;}
    ;

assert_stmt: ASSERT test COMMA test {$$ = create_node(5,"assert_stmt",$1,$2,$3,$4);}
    | ASSERT test {$$ = create_node(3,"assert_stmt",$1,$2);}
    ;

expr_stmt: testlist_star_expr annassign {$$ = create_node(3,"expr_stmt",$1,$2);}
    | testlist_star_expr augassign testlist {$$ = create_node(4,"expr_stmt",$1,$2,$3);}
    |testlist_star_expr  {$$ = $1;}
    |testlist_star_expr expr_stmt_option1_plus  {$$ = create_node(3,"expr_stmt",$1,$2);}
    ;

testlist:  test symbol_test_star  {$$ = create_node(3,"testlist",$1,$2);}  ;

symbol_test_star: COMMA test symbol_test_star {$$ = create_node(4,"symbol_test",$1,$2,$3);}
    | COMMA {$$ = $1;}
    |{$$=NULL;} 
    ;


    
expr_stmt_option1_plus:EQUAL testlist_star_expr expr_stmt_option1_plus {$$ = create_node(4,"expr_stmt",$1,$2,$3);}
    // |TYPE_HINT EQUAL testlist_star_expr
    | EQUAL testlist_star_expr {$$ = create_node(3,"expr_stmt",$1,$2);}
    ;

annassign: COLON test {$$ = create_node(3,"annassign",$1,$2);}
    | COLON test EQUAL testlist_star_expr {$$ = create_node(5,"annassign",$1,$2,$3,$4);}
    ;

testlist_star_expr: test testlist_star_expr_option1_star {$$ = create_node(3,"testlist_expr",$1,$2);}
    | star_expr testlist_star_expr_option1_star {$$ = create_node(3,"testlist_expr",$1,$2);}
    ;

testlist_star_expr_option1_star: COMMA test testlist_star_expr_option1_star {$$ = create_node(4,"testlist_expr",$1,$2,$3);}
    | COMMA star_expr testlist_star_expr_option1_star {$$ = create_node(4,"testlist_expr",$1,$2,$3);}
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

expr: xor_expr symbol_xor_expr_star {$$ = create_node(3,"expr",$1,$2);}

star_expr: MUL expr {$$ = create_node(3,"star_expr",$1,$2);};

symbol_xor_expr_star: BITWISE_OR xor_expr symbol_xor_expr_star {$$ = create_node(4,"symbol_xor_expr",$1,$2,$3);}
    | /*empty*/ {$$=NULL;}
    ;

xor_expr: and_expr symbol_and_expr_star {$$ = create_node(3,"xor_expr",$1,$2);};

symbol_and_expr_star: BITWISE_XOR and_expr symbol_and_expr_star {$$ = create_node(4,"symbol_and_expr",$1,$2,$3);}
    | /*empty*/ {$$=NULL;}
    ;

and_expr: shift_expr symbol_shift_expr_star {$$ = create_node(3,"and_expr",$1,$2);};

symbol_shift_expr_star: BITWISE_AND shift_expr symbol_shift_expr_star {$$ = create_node(4,"symbol_shift_expr",$1,$2,$3);}
    | /*empty*/ {$$=NULL;}
    ;

shift_expr: arith_expr shift_arith_expr_star {$$ = create_node(3,"shift_expr",$1,$2);};

shift_arith_expr_star: /*empty*/ {$$=NULL;}
    | SHIFT_LEFT arith_expr shift_arith_expr_star {$$ = create_node(4,"shift_arith_expr",$1,$2,$3);}
    | SHIFT_RIGHT arith_expr shift_arith_expr_star {$$ = create_node(4,"shift_arith_expr",$1,$2,$3);}
    ;

arith_expr: term symbol_term_star  {$$ = create_node(3,"arith_expr",$1,$2);} ;

symbol_term_star: /*empty*/ {$$=NULL;}
    | ADD term symbol_term_star {$$ = create_node(4,"symbol_term",$1,$2,$3);}
    | SUB term symbol_term_star {$$ = create_node(4,"symbol_term",$1,$2,$3);}
    ;

term: factor symbol_factor_star {$$ = create_node(3,"term",$1,$2);};

symbol_factor_star: /*empty*/ {$$=NULL;}
    | symbol_factor symbol_factor_star {$$ = create_node(3,"symbol_factor",$1,$2);}
    ;

symbol_factor: MUL factor {$$ = create_node(3,"symbol_factor",$1,$2);}
    | AT factor {$$ = create_node(3,"symbol_factor",$1,$2);}
    | DIV factor {$$ = create_node(3,"symbol_factor",$1,$2);}
    | FLOOR_DIV factor {$$ = create_node(3,"symbol_factor",$1,$2);}
    | MOD factor {$$ = create_node(3,"symbol_factor",$1,$2);}
    ;

factor: ADD factor {$$ = create_node(3,"Factor",$1,$2);}
    | SUB factor {$$ = create_node(3,"Factor",$1,$2);}
    | TILDE factor {$$ = create_node(3,"Factor",$1,$2);}
    | power {$$ = $1;}
    ;
    
power: atom_expr {$$ = $1;}
    | atom_expr POW factor {
        $$ = create_node(4,"Power",$1,$2,$3);
    }
    ;

atom_expr: AWAIT atom trailer_star {$$=create_node(4,"atom_expr",$1,$2,$3);}
    | atom trailer_star{$$=create_node(3,"atom_expr", $1,$2);}
    ;

trailer_star:  trailer trailer_star  {$$ = create_node(3,"trailer_star",$1,$2);}
    | /*empty*/{$$=NULL;}
    ;


trailer: SMALL_OPEN arglist SMALL_CLOSE  {$$ = create_node(4,"trailer",$1,$2,$3);}
    |SMALL_OPEN SMALL_CLOSE { $$ = create_node(3,"trailer",$1,$2);}
    |BOX_OPEN subscriptlist BOX_CLOSE {$$ = create_node(4,"trailer",$1,$2,$3);}
    |DOT NAME TYPE_HINT {$$ = create_node(4,"trailer",$1,$2,$3);}
    |DOT NAME { $$ = create_node(3,"trailer",$1,$2);}
    ;


classdef: CLASS NAME bracket_arglist_optional COLON suite {$$=create_node(6,"classdef",$1,$2,$3,$4,$5);};

bracket_arglist_optional: SMALL_OPEN SMALL_CLOSE {$$=create_node(3,"bracket_arglist_optional",$1,$2);}
    | SMALL_OPEN arglist SMALL_CLOSE {$$=create_node(4,"bracket_arglist_optional",$1,$2,$3);}
    | {$$=NULL;}
    ;

arglist: argument_list COMMA {$$=create_node(3,"arglist",$1,$2);}
    | argument_list {$$=$1;}
    ;

argument_list: argument_list COMMA argument { $$=create_node(4,"argument_list",$1,$2,$3);}
    | argument { $$=$1;}
    ;

subscriptlist: subscript_list COMMA {$$=create_node(3,"subscriptlist",$1,$2);}
    | subscript_list { $$=$1;}
    ;

subscript_list: subscript_list COMMA subscript { $$=create_node(4,"subscript_list",$1,$2,$3);}
    | subscript { $$=$1;}
    ;


subscript: test {$$=$1;}
    | optional_test COLON optional_test{ $$=create_node(4,"subscript",$1,$2,$3);}
    ;


argument: test { $$ = $1;}
    | test comp_for {$$=create_node(3,"argument",$1,$2);}
    | test EQUAL test  {$$=create_node(4,"argument",$1,$2,$3);}
    | POW test {$$=create_node(3,"argument",$1,$2);}
    | MUL test {$$=create_node(3,"argument",$1,$2);}
    ;

optional_test: test {$$=$1;}
    | /*empty*/ {$$=NULL;}
    ; 

comp_iter: comp_for {$$=$1;}
    | comp_if {$$=$1;}
    ;

sync_comp_for: FOR exprlist IN or_test {$$=create_node(5,"sync_comp_for",$1,$2,$3,$4);}
    | FOR exprlist IN or_test comp_iter {$$=create_node(6,"sync_comp_for",$1,$2,$3,$4,$5);}
    ;


comp_for:  sync_comp_for {$$=$1;}
    | ASYNC sync_comp_for {$$=create_node(3,"comp_for",$1,$2);}
    ;

comp_if: IF test_nocond {$$=create_node(3,"comp_if",$1,$2);}
    | IF test_nocond comp_iter {$$ = create_node(4,"comp_if",$1,$2,$3);}
    ;

test_nocond: or_test {$$=$1;};

or_test: and_test or_and_test_star{$$=create_node(3,"or_test",$1,$2);};

or_and_test_star:OR and_test or_and_test_star {$$=create_node(4,"or_and_test_star",$1,$2,$3);}
    | { $$ = NULL;}
    ;
    
and_test: not_test and_not_test_star {$$=create_node(3,"and_test",$1,$2);};

and_not_test_star: AND not_test and_not_test_star {$$=create_node(4,"and_not_test_star",$1,$2,$3);}
    | { $$ = NULL;}
    ;

not_test: NOT not_test {$$=create_node(3,"not_test",$1,$2);}
    | comparison {$$=$1;}
    ;
    
/* still not implemented comp_op_expr_star properly but currently forms valid grammar*/    
comparison: expr comp_op_expr_plus {$$=create_node(3,"comparison",$1,$2);}
    |expr {$$=$1;}
   ;

comp_op_expr_plus: comp_op expr comp_op_expr_plus {$$=create_node(3,"comp_op_expr_plus",$1,$2);}
    | comp_op expr {$$=create_node(3,"comp_op_expr_plus",$1,$2);}
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
    | star_expr {$$=$1;}
    ;

expr_star_expr_option_list: expr_star_expr_option COMMA expr_star_expr_option_list {$$=create_node(4,"expr_star_expr_option_list",$1,$2,$3);}
    | expr_star_expr_option COMMA {$$=create_node(3,"expr_star_expr_option",$1,$2);}
    | expr_star_expr_option {$$=$1;}
    ;

testlist_comp: namedexpr_test_star_expr_option comp_for {$$=create_node(3,"testlist_comp",$1,$2);} 
    | namedexpr_test_star_expr_option_list  {$$=$1;}
    ; 


namedexpr_test_star_expr_option_list: namedexpr_test_star_expr_option COMMA namedexpr_test_star_expr_option_list {$$=create_node(4,"namedexpr_test_star_expr_option_list",$1,$2,$3);}
    | namedexpr_test_star_expr_option COMMA {$$=create_node(3,"namedexpr_test_star_expr_option",$1,$2);}
    | namedexpr_test_star_expr_option {$$=$1;}
    ;

namedexpr_test_star_expr_option: namedexpr_test {$$=$1;}
    | star_expr {$$=$1;}
    ;

namedexpr_test: test {$$=$1;};

test: or_test {$$=$1;}
    |or_test IF or_test ELSE test {$$=create_node(6,"test",$1,$2,$3,$4,$5);};

atom: SMALL_OPEN testlist_comp SMALL_CLOSE {$$=create_node(4,"Atom",$1,$2,$3);}
    | SMALL_OPEN SMALL_CLOSE {$$=create_node(3,"Atom",$1,$2);}
    | BOX_OPEN testlist_comp BOX_CLOSE {$$=create_node(4,"Atom",$1,$2,$3);}
    | BOX_OPEN BOX_CLOSE {$$=create_node(3,"Atom",$1,$2);}
    | CURLY_OPEN CURLY_CLOSE {$$=create_node(3,"Atom",$1,$2);}
    | NAME {$$=$1;}
    | NAME TYPE_HINT {$$=create_node(3,"Atom", $1, $2);}
    | number {$$=$1;}
    | string_plus {$$=$1;}
    | TRUE {$$=$1;}
    | FALSE {$$=$1;}
    | NONE {$$=$1;}
    ;
// dictionary , setliterals are to be ignored

number: INTEGER {$$ = $1;}
    | FLOAT {$$ = $1;}
    ;

string_plus: STRING string_plus {$$=create_node(3,"string", $1, $2);}
    | STRING {$$=$1;}
    ;




%%
void MakeDOTFile(NODE*cell)
{
    if(!cell)
        return;
    
    string value = string(cell->val);
    if(value.length()>2 && value[0]=='"' && value[value.length()-1]=='"')
    {
        value = value.substr(1,value.length()-2);
        value="\\\""+value+"\\\"";
    }
    fout << "\t" << cell->id << "\t\t[ style = solid label = \"" + value + "\"  ];" << endl;

    for(int i=0;i<cell->children.size();i++)
    {
        if(!cell->children[i])
            continue;
        
        fout << "\t" << cell->id << " -> " << cell->children[i]->id << endl;
        MakeDOTFile(cell->children[i]);
    }
}

int main(){
    indent_stack.push(0);
    /* yylex(); */
    
    yyparse();
 
    // Open the output file
    string output_file = "";
    output_file = "output.dot";
	fout.open(output_file.c_str());

    // clear any text in this file
    fout.clear();
    

    fout<<"digraph G{"<<endl;
    fout << endl;
    fout<<"label     = \"AST\""<<endl;
    fout<<"fontname  = \"Cascadia code\""<<endl;
    fout<<"fontsize  = 30"<<endl;
    fout<<"labelloc  = t"<<endl;
    fout << endl;
    fout<<"node   [ fontname=\"Cascadia code\" ]"<<endl;
    
    MakeDOTFile(start_node);
    fout<<"}";
    fout.close();

    return 0;
}


int yyerror(const char *s){
    cout << "Error: " << s << ",line: "<< yylineno << endl;
    return 0;
}