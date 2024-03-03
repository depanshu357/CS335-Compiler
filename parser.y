%{
    #include <bits/stdc++.h>
    #include "node.h"
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
    | stmt file_input {$$ = create_node(3,"File Input",$1,$2);}
    | {$$ = NULL;}	
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
    
async_stmt: ASYNC funcdef { $$ = create_node(3,"Async_stmt",$1,$2);}
    | ASYNC for_stmt { $$ = create_node(3,"Async_stmt",$1,$2);}
    ;

if_stmt: IF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star ELSE COLON suite { $$ = create_node(9,"If_stmt",$1,$2,$3,$4,$5,$6,$7,$8);}
    | IF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star { $$ = create_node(6,"If_stmt",$1,$2,$3,$4,$5);}
    ;

elif_namedexpr_test_colon_suite_star: ELIF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star {$$ = create_node(5,"Elif_block",$1,$2,$3,$4);}
    | { $$ = NULL;}
    ;

while_stmt: WHILE namedexpr_test COLON suite ELSE COLON suite { $$ = create_node(8,"While_stmt",$1,$2,$3,$4,$5,$6,$7);}
    | WHILE namedexpr_test COLON suite {$$ = create_node(5,"While_stmt",$1,$2,$3,$4);}
    ;

for_stmt:  FOR exprlist IN testlist COLON suite ELSE COLON suite { $$ = create_node(10,"For_stmt",$1,$2,$3,$4,$5,$6,$7,$8,$9);}
    | FOR exprlist IN testlist COLON suite {$$ = create_node(7,"For_stmt",$1,$2,$3,$4,$5,$6);}
    ; 

try_stmt: TRY COLON suite FINALLY COLON suite {$$ = create_node(7,"Try_stmt",$1,$2,$3,$4,$5,$6);}
    | TRY COLON suite except_clause_colon_suite try_stmt_options { $$ = create_node(6,"Try_stmt",$1,$2,$3,$4,$5);}
    ;

except_clause_colon_suite: except_clause COLON suite except_clause_colon_suite {$$ = create_node(5,"Except_block",$1,$2,$3,$4);}
    | except_clause COLON suite { $$ = create_node(4,"Except_block",$1,$2,$3);}
    ;

try_stmt_options: ELSE COLON suite FINALLY COLON suite { $$ = create_node(7,"Else_finally_block",$1,$2,$3,$4,$5,$6);}
    | ELSE COLON suite {$$ = create_node(4,"Else_block",$1,$2,$3);}
    | FINALLY COLON suite { $$ = create_node(4,"Finally_block",$1,$2,$3);}
    | { $$ = NULL;{}}
    ;

except_clause: EXCEPT test_as_name_optional {$$ = create_node(3,"Except_block",$1,$2);}

test_as_name_optional: test {$$=$1;}
    | test AS NAME {$$ = create_node(4,"Expressions_block",$1,$2,$3);}
    | {$$ = NULL;}
    ;

/*using this notation instead of below one*/
funcdef:  DEF NAME parameters  FUNC_TYPE_HINT COLON  func_body_suite { $$ = create_node(7,"Func_def",$1,$2,$3,$4,$5,$6);}
    | DEF NAME parameters  COLON  func_body_suite { $$ = create_node(6,"Func_def",$1,$2,$3,$4,$5);}
    ;

// Written only to run START ye dono document se dekhna hai
parameters: SMALL_OPEN typedarglist SMALL_CLOSE {$$ = create_node(4,"Arguments",$1,$2,$3);}
    |SMALL_OPEN SMALL_CLOSE {$$ = create_node(3,"Parantheses",$1,$2);}
    ;


typedlist_argument: tfpdef  { $$ = $1;}
    |  tfpdef EQUAL test { $$ = create_node(4,"Assign_expr",$1,$2,$3);}
    ;
    
typedlist_arguments: typedlist_argument comma_option_argument_star {$$ = create_node(3,"Arguments",$1,$2);};

comma_option_argument_star: comma_option_argument_star COMMA typedlist_argument {$$ = create_node(4,"Arguments",$1,$2,$3);}
    | { $$ = NULL;}
    ;

typedarglist:
    typedlist_arguments {$$ = $1;}
    ;

tfpdef: NAME { $$ = $1;}
    | NAME TYPE_HINT { $$ = create_node(3,"Identifier",$1,$2); }
    | NAME COLON test {$$ = create_node(4,"Identifier",$1,$2,$3);}
    ;

func_body_suite: simple_stmt {$$ = $1;}
    | NEWLINE INDENT stmt_plus DEDENT { $$ = $3;}

suite: simple_stmt {$$ = $1;}
    | NEWLINE INDENT stmt_plus DEDENT { $$ = $3;}
    ;

stmt_plus: stmt stmt_plus {$$ = create_node(3,"Stmts",$1,$2);}
    | stmt {$$ = $1;}
    ;

simple_stmt: small_stmt semi_colon_small_stmt_star NEWLINE {$$ = create_node(3,"Simple_stmts",$1,$2);}
    ;

semi_colon_small_stmt_star: SEMI_COLON small_stmt semi_colon_small_stmt_star {$$ = create_node(4,"Small_stmts",$1,$2,$3);}
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

return_stmt: RETURN testlist_star_expr {$$ = create_node(3,"Return_stmt",$1,$2);}
    | RETURN {$$ = $1;}
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

expr_stmt: testlist_star_expr annassign {$$ = create_node(3,"Expr_stmt",$1,$2);}
    | testlist_star_expr augassign testlist {$$ = create_node(4,"Expr_stmt",$1,$2,$3);}
    |testlist_star_expr  {$$ = $1;}
    |testlist_star_expr expr_stmt_option1_plus  {$$ = create_node(3,"Expr_stmt",$1,$2);}
    ;

testlist:  test symbol_test_star  {$$ = create_node(3,"Expressions",$1,$2);}  ;

symbol_test_star: COMMA test symbol_test_star {$$ = create_node(4,"Expressions",$1,$2,$3);}
    | COMMA {$$ = $1;}
    |{$$=NULL;} 
    ;


    
expr_stmt_option1_plus:EQUAL testlist_star_expr expr_stmt_option1_plus {$$ = create_node(4,"Expr_stmt",$1,$2,$3);}
    // |TYPE_HINT EQUAL testlist_star_expr
    | EQUAL testlist_star_expr {$$ = create_node(3,"Expr_stmt",$1,$2);}
    ;

annassign: COLON test {$$ = create_node(3,"Identifiers",$1,$2);}
    | COLON test EQUAL testlist_star_expr {$$ = create_node(5,"Identifiers",$1,$2,$3,$4);}
    ;

testlist_star_expr: test testlist_star_expr_option1_star {$$ = create_node(3,"Expressions",$1,$2);}
    | star_expr testlist_star_expr_option1_star {$$ = create_node(3,"Expressions",$1,$2);}
    ;

testlist_star_expr_option1_star: COMMA test testlist_star_expr_option1_star {$$ = create_node(4,"Expressions",$1,$2,$3);}
    | COMMA star_expr testlist_star_expr_option1_star {$$ = create_node(4,"Expressions",$1,$2,$3);}
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

expr: xor_expr symbol_xor_expr_star {$$ = create_node(3,"Expressions",$1,$2);}

star_expr: MUL expr {$$ = create_node(3,"Expressions",$1,$2);};

symbol_xor_expr_star: BITWISE_OR xor_expr symbol_xor_expr_star {$$ = create_node(4,"Or_exprs",$1,$2,$3);}
    | /*empty*/ {$$=NULL;}
    ;

xor_expr: and_expr symbol_and_expr_star {$$ = create_node(3,"Expressions",$1,$2);};

symbol_and_expr_star: BITWISE_XOR and_expr symbol_and_expr_star {$$ = create_node(4,"Xor_exprs",$1,$2,$3);}
    | /*empty*/ {$$=NULL;}
    ;

and_expr: shift_expr symbol_shift_expr_star {$$ = create_node(3,"Expressions",$1,$2);};

symbol_shift_expr_star: BITWISE_AND shift_expr symbol_shift_expr_star {$$ = create_node(4,"And_exprs",$1,$2,$3);}
    | /*empty*/ {$$=NULL;}
    ;

shift_expr: arith_expr shift_arith_expr_star {$$ = create_node(3,"Expressions",$1,$2);};

shift_arith_expr_star: /*empty*/ {$$=NULL;}
    | SHIFT_LEFT arith_expr shift_arith_expr_star {$$ = create_node(4,"Shift_left_expr",$1,$2,$3);}
    | SHIFT_RIGHT arith_expr shift_arith_expr_star {$$ = create_node(4,"Shift_right_expr",$1,$2,$3);}
    ;

arith_expr: term symbol_term_star  {$$ = create_node(3,"Expressions",$1,$2);} ;

symbol_term_star: /*empty*/ {$$=NULL;}
    | ADD term symbol_term_star {$$ = create_node(4,"Operator_expr",$1,$2,$3);}
    | SUB term symbol_term_star {$$ = create_node(4,"Operator_expr",$1,$2,$3);}
    ;

term: factor symbol_factor_star {$$ = create_node(3,"Terms",$1,$2);};

symbol_factor_star: /*empty*/ {$$=NULL;}
    | symbol_factor symbol_factor_star {$$ = create_node(3,"Terms",$1,$2);}
    ;

symbol_factor: MUL factor {$$ = create_node(3,"Mul_term",$1,$2);}
    | AT factor {$$ = create_node(3,"At_term",$1,$2);}
    | DIV factor {$$ = create_node(3,"Div_term",$1,$2);}
    | FLOOR_DIV factor {$$ = create_node(3,"Div_term",$1,$2);}
    | MOD factor {$$ = create_node(3,"Mod_term",$1,$2);}
    ;

factor: ADD factor {$$ = create_node(3,"Add_term",$1,$2);}
    | SUB factor {$$ = create_node(3,"Sub_term",$1,$2);}
    | TILDE factor {$$ = create_node(3,"Tilde_term",$1,$2);}
    | power {$$ = $1;}
    ;
    
power: atom_expr {$$ = $1;}
    | atom_expr POW factor {$$ = create_node(4,"Power_term",$1,$2,$3);}
    ;

atom_expr: AWAIT atom trailer_star {$$=create_node(4,"Await_stmt",$1,$2,$3);}
    | atom trailer_star{$$=create_node(3,"Terms", $1,$2);}
    ;

trailer_star:  trailer trailer_star  {$$ = create_node(3,"Stmts",$1,$2);}
    | /*empty*/{$$=NULL;}
    ;


trailer: SMALL_OPEN arglist SMALL_CLOSE  {$$ = create_node(4,"Arguments",$1,$2,$3);}
    |SMALL_OPEN SMALL_CLOSE { $$ = create_node(3,"Parantheses",$1,$2);}
    |BOX_OPEN subscriptlist BOX_CLOSE {$$ = create_node(4,"Square_bracket",$1,$2,$3);}
    |DOT NAME TYPE_HINT {$$ = create_node(4,"Identifier",$1,$2,$3);}
    |DOT NAME { $$ = create_node(3,"Identifier",$1,$2);}
    ;


classdef: CLASS NAME bracket_arglist_optional COLON suite {$$=create_node(6,"Class_def",$1,$2,$3,$4,$5);};

bracket_arglist_optional: SMALL_OPEN SMALL_CLOSE {$$=create_node(3,"Parantheses",$1,$2);}
    | SMALL_OPEN arglist SMALL_CLOSE {$$=create_node(4,"Arguments",$1,$2,$3);}
    | {$$=NULL;}
    ;

arglist: argument_list COMMA {$$=create_node(3,"Arguments",$1,$2);}
    | argument_list {$$=$1;}
    ;

argument_list: argument_list COMMA argument { $$=create_node(4,"Arguments",$1,$2,$3);}
    | argument { $$=$1;}
    ;

subscriptlist: subscript_list COMMA {$$=create_node(3,"Terms",$1,$2);}
    | subscript_list { $$=$1;}
    ;

subscript_list: subscript_list COMMA subscript { $$=create_node(4,"Terms",$1,$2,$3);}
    | subscript { $$=$1;}
    ;


subscript: test {$$=$1;}
    | optional_test COLON optional_test{ $$=create_node(4,"Terms",$1,$2,$3);}
    ;


argument: test { $$ = $1;}
    | test comp_for {$$=create_node(3,"Terms",$1,$2);}
    | test EQUAL test  {$$=create_node(4,"Assign_term",$1,$2,$3);}
    | POW test {$$=create_node(3,"Power_term",$1,$2);}
    | MUL test {$$=create_node(3,"Mul_term",$1,$2);}
    ;

optional_test: test {$$=$1;}
    | /*empty*/ {$$=NULL;}
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

or_test: and_test or_and_test_star{$$=create_node(3,"Expressions",$1,$2);};

or_and_test_star:OR and_test or_and_test_star {$$=create_node(4,"OR_term",$1,$2,$3);}
    | { $$ = NULL;}
    ;
    
and_test: not_test and_not_test_star {$$=create_node(3,"Expressions",$1,$2);};

and_not_test_star: AND not_test and_not_test_star {$$=create_node(4,"And_term",$1,$2,$3);}
    | { $$ = NULL;}
    ;

not_test: NOT not_test {$$=create_node(3,"Not_term",$1,$2);}
    | comparison {$$=$1;}
    ;
    
/* still not implemented comp_op_expr_star properly but currently forms valid grammar*/    
comparison: expr comp_op_expr_plus {$$=create_node(3,"Expressions",$1,$2);}
    |expr {$$=$1;}
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
    | star_expr {$$=$1;}
    ;

expr_star_expr_option_list: expr_star_expr_option COMMA expr_star_expr_option_list {$$=create_node(4,"Expressions",$1,$2,$3);}
    | expr_star_expr_option COMMA {$$=create_node(3,"Expressions",$1,$2);}
    | expr_star_expr_option {$$=$1;}
    ;

testlist_comp: namedexpr_test_star_expr_option comp_for {$$=create_node(3,"Expressions",$1,$2);} 
    | namedexpr_test_star_expr_option_list  {$$=$1;}
    ; 


namedexpr_test_star_expr_option_list: namedexpr_test_star_expr_option COMMA namedexpr_test_star_expr_option_list {$$=create_node(4,"Expressions",$1,$2,$3);}
    | namedexpr_test_star_expr_option COMMA {$$=create_node(3,"Expressions",$1,$2);}
    | namedexpr_test_star_expr_option {$$=$1;}
    ;

namedexpr_test_star_expr_option: namedexpr_test {$$=$1;}
    | star_expr {$$=$1;}
    ;

namedexpr_test: test {$$=$1;};

test: or_test {$$=$1;}
    |or_test IF or_test ELSE test {$$=create_node(6,"Expressions",$1,$2,$3,$4,$5);};

atom: SMALL_OPEN testlist_comp SMALL_CLOSE {$$=create_node(4,"Arguments",$1,$2,$3);}
    | SMALL_OPEN SMALL_CLOSE {$$=create_node(3,"Parantheses",$1,$2);}
    | BOX_OPEN testlist_comp BOX_CLOSE {$$=create_node(4,"Square_bracket",$1,$2,$3);}
    | BOX_OPEN BOX_CLOSE {$$=create_node(3,"Square_bracket",$1,$2);}
    | CURLY_OPEN CURLY_CLOSE {$$=create_node(3,"Curly_bracket",$1,$2);}
    | NAME {$$=$1;}
    | NAME TYPE_HINT {$$=create_node(3,"Identifier", $1, $2);}
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

string_plus: STRING string_plus {$$=create_node(3,"Strings", $1, $2);}
    | STRING {$$=$1;}
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
    astNode->val = parseTree->val;
    astNode->is_terminal = parseTree->is_terminal;

    for (NODE* child : parseTree->children) {
        NODE* astChild = convertParseTreeToAST(child);
        astNode->children.push_back(astChild);

    }

    return astNode;
}


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

int main(int argc, char* argv[]){
    indent_stack.push(0);
    /* yylex(); */

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



    fout<<"}";
    fout.close();

    return 0;
}


int yyerror(const char *s){
    cout << "Error: " << s << ",line: "<< yylineno << endl;
    return 0;
}