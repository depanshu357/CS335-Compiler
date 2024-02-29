%{
    #include <bits/stdc++.h>
    using namespace std;
    int yylex();    
    int yyerror(const char *s);
    extern int yylineno;
    extern stack<int> indent_stack;
%}
%union{
    int num;
}

%token KEYWORD NEWLINE INDENT DEDENT NAME YIELD FROM ELIF AWAIT ASYNC TRUE FALSE NONE IMPORT PASS BREAK EXCEPT RAISE CLASS FINALLY RETURN CONTINUE FOR LAMBDA TRY AS DEF NONLOCAL WHILE ASSERT DEL GLOBAL WITH
%token INTEGER FLOAT STRING
%token POW FLOOR_DIV DIV MUL ADD SUB MOD EQUAL
%token SHIFT_LEFT SHIFT_RIGHT BITWISE_AND BITWISE_XOR BITWISE_OR TILDE  
%token AT COMMA WAL_OP COLON SEMI_COLON SMALL_OPEN SMALL_CLOSE BOX_OPEN BOX_CLOSE CURLY_OPEN CURLY_CLOSE  DOT ARROW
%token DOUBLE_EQUAL NE LT GT LE GE
%token IN IS IF ELSE 
%token AND OR NOT
%token TYPE_COMMENT /*dont know what it means, just defined to remove error, doesnt work*/
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN AT_ASSIGN DIV_ASSIGN MOD_ASSIGN AND_ASSIGN OR_ASSIGN XOR_ASSIGN LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN POW_ASSIGN FLOOR_DIV_ASSIGN


%%


file_input: NEWLINE file_input
    | stmt file_input
    | ;

stmt: simple_stmt 
    |compound_stmt
    ;

compound_stmt: if_stmt
            |  while_stmt
            | for_stmt
            | try_stmt
            | funcdef 
            | classdef 
            ;

if_stmt: IF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star ELSE COLON suite
    | IF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star
    ;

elif_namedexpr_test_colon_suite_star: ELIF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star
    | 
    ;

while_stmt: WHILE namedexpr_test COLON suite ELSE COLON suite
    | WHILE namedexpr_test COLON suite
    ;

for_stmt: FOR exprlist IN testlist COLON TYPE_COMMENT suite ELSE COLON suite
    | FOR exprlist IN testlist COLON suite ELSE COLON suite
    | FOR exprlist IN testlist COLON TYPE_COMMENT suite
    | FOR exprlist IN testlist COLON suite
    ; 

try_stmt: TRY COLON suite FINALLY COLON suite
    | TRY COLON suite except_clause_colon_suite try_stmt_options 
    ;

except_clause_colon_suite: except_clause COLON suite except_clause_colon_suite
    | except_clause COLON suite
    ;

try_stmt_options: ELSE COLON suite FINALLY COLON suite
    | ELSE COLON suite
    | FINALLY COLON suite
    | 
    ;

except_clause: EXCEPT test_as_name_optional

test_as_name_optional: test
    | test AS NAME
    | 
    ;

funcdef: DEF NAME parameters ARROW test COLON TYPE_COMMENT func_body_suite
    | DEF NAME parameters ARROW test COLON  func_body_suite
    | DEF NAME parameters COLON TYPE_COMMENT func_body_suite
    | DEF NAME parameters  COLON  func_body_suite
    ;

// Written only to run START ye dono document se dekhna hai
parameters: SMALL_OPEN test SMALL_CLOSE ;

func_body_suite: simple_stmt 
    | NEWLINE INDENT stmt_plus DEDENT
    | NEWLINE TYPE_COMMENT NEWLINE INDENT stmt_plus DEDENT;

suite: simple_stmt 
    | NEWLINE INDENT stmt_plus DEDENT
    ;

stmt_plus: stmt stmt_plus
    | stmt
    ;

simple_stmt: small_stmt semi_colon_small_stmt_star NEWLINE
    ;

semi_colon_small_stmt_star: SEMI_COLON small_stmt semi_colon_small_stmt_star
    | SEMI_COLON
    |
    ;

// simple_stmt: small_stmt semi_colon_small_stmt_star SEMI_COLON NEWLINE
//     |  small_stmt semi_colon_small_stmt_star NEWLINE
//     ;

// semi_colon_small_stmt_star: SEMI_COLON small_stmt semi_colon_small_stmt_star
//     | 
//     ;

small_stmt: expr_stmt 
    | flow_stmt 
    | global_stmt 
    | nonlocal_stmt 
    | assert_stmt
    ;

flow_stmt: break_stmt 
    | continue_stmt 
    | return_stmt 
    | raise_stmt 
    ;

break_stmt: BREAK;

continue_stmt: CONTINUE;

return_stmt: RETURN testlist_star_expr
    | RETURN 
    ;

raise_stmt: RAISE 
    | RAISE test 
    | RAISE test FROM test
    ;

global_stmt: GLOBAL NAME comma_name_star ;

nonlocal_stmt: NONLOCAL NAME comma_name_star ;

comma_name_star: COMMA NAME comma_name_star
    | 
    ;

assert_stmt: ASSERT test COMMA test
    | ASSERT test
    ;

expr_stmt: testlist_star_expr annassign 
    | testlist_star_expr augassign testlist
    |testlist_star_expr  
    |testlist_star_expr expr_stmt_option1_plus  
    |testlist_star_expr expr_stmt_option1_plus TYPE_COMMENT
    ;

testlist:  test symbol_test_star    ;

symbol_test_star: COMMA test symbol_test_star
    | COMMA
    |
    ;

/* testlist: test symbol_test_star COMMA
    | test symbol_test_star
    ;
symbol_test_star: COMMA test symbol_test_star
    | 
    ; */
    
expr_stmt_option1_plus:EQUAL testlist_star_expr expr_stmt_option1_plus
    |EQUAL testlist_star_expr
    ;

annassign: COLON test
    | COLON test EQUAL testlist_star_expr
    ;

testlist_star_expr: test testlist_star_expr_option1_star 
    | star_expr testlist_star_expr_option1_star 
    ;

testlist_star_expr_option1_star: COMMA test testlist_star_expr_option1_star
    | COMMA star_expr testlist_star_expr_option1_star
    | COMMA
    |
    ;
/* expr_stmt_option1_star:DOUBLE_EQUAL testlist_star_expr expr_stmt_option1_star
    |DOUBLE_EQUAL testlist_star_expr
    ;

annassign: COLON test
    | COLON test DOUBLE_EQUAL testlist_star_expr
    ; 

testlist_star_expr: test testlist_star_expr_option1_star 
    | star_expr testlist_star_expr_option1_star 
    ;

testlist_star_expr: test testlist_star_expr_option1_star 
    | test testlist_star_expr_option1_star COMMA
    | star_expr testlist_star_expr_option1_star 
    | star_expr testlist_star_expr_option1_star COMMA
    ;

testlist_star_expr_option1_star: COMMA test testlist_star_expr_option1_star
    | COMMA star_expr testlist_star_expr_option1_star
    | 
    
    ; */

augassign: ADD_ASSIGN | SUB_ASSIGN | MUL_ASSIGN | AT_ASSIGN | DIV_ASSIGN | MOD_ASSIGN | AND_ASSIGN | OR_ASSIGN | XOR_ASSIGN |
            LEFT_SHIFT_ASSIGN | RIGHT_SHIFT_ASSIGN | POW_ASSIGN | FLOOR_DIV_ASSIGN ;

expr: xor_expr symbol_xor_expr_star;

star_expr: MUL expr;

symbol_xor_expr_star: BITWISE_OR xor_expr symbol_xor_expr_star
    | /*empty*/
    ;

xor_expr: and_expr symbol_and_expr_star;

symbol_and_expr_star: BITWISE_XOR and_expr symbol_and_expr_star
    | /*empty*/
    ;

and_expr: shift_expr symbol_shift_expr_star;

symbol_shift_expr_star: BITWISE_AND shift_expr symbol_shift_expr_star
    | /*empty*/
    ;

shift_expr: arith_expr shift_arith_expr_star ;

shift_arith_expr_star: /*empty*/
    | SHIFT_LEFT arith_expr shift_arith_expr_star
    | SHIFT_RIGHT arith_expr shift_arith_expr_star
    ;

arith_expr: term symbol_term_star ;

symbol_term_star: /*empty*/
    | ADD term symbol_term_star
    | SUB term symbol_term_star
    ;

term: factor symbol_factor_star ;

symbol_factor_star : /*empty*/
    | symbol_factor symbol_factor_star
    ;

symbol_factor: MUL factor
    | AT factor
    | DIV factor
    | FLOOR_DIV factor
    ;

factor: ADD factor
    | SUB factor
    | TILDE factor
    | power
    ;
    
power: atom_expr 
    | atom_expr POW factor
    ;

atom_expr: AWAIT atom trailer_star
    | atom trailer_star
    ;

trailer_star: trailer trailer_star
    | /*empty*/
    ;

trailer: SMALL_OPEN arglist SMALL_CLOSE 
    |SMALL_OPEN SMALL_CLOSE
    |BOX_OPEN subscriptlist BOX_CLOSE 
    |DOT NAME
    ;

classdef: CLASS NAME bracket_arglist_optional COLON suite;

bracket_arglist_optional: SMALL_OPEN SMALL_CLOSE
    | SMALL_OPEN arglist SMALL_CLOSE
    | 
    ;

arglist: argument_list COMMA
    | argument_list
    ;

argument_list: argument_list COMMA argument
    | argument
    ;

subscriptlist: subscript_list COMMA
    | subscript_list
    ;

subscript_list: subscript_list COMMA subscript
    | subscript
    ;


subscript: test 
    | optional_test COLON optional_test
    ;


argument: test 
    | test comp_for 
    | test EQUAL test 
    | POW test 
    | MUL test
    ;

optional_test: test 
    | /*empty*/
    ;

comp_iter: comp_for 
    | comp_if
    ;

sync_comp_for: FOR exprlist IN or_test
    | FOR exprlist IN or_test comp_iter
    ;


comp_for:  sync_comp_for
    | ASYNC sync_comp_for
    ;

comp_if: IF test_nocond
    | IF test_nocond comp_iter
    ;

test_nocond: or_test;

or_test: and_test or_and_test_star;

or_and_test_star:OR and_test or_and_test_star 
    | 
    ;
    
and_test: not_test and_not_test_star;

and_not_test_star: AND not_test and_not_test_star
    | 
    ;

not_test: NOT not_test
    | comparison
    ;
    
/* still not implemented comp_op_expr_star properly but currently forms valid grammar*/    
comparison: expr comp_op_expr_plus
    |expr
   ;

comp_op_expr_plus: comp_op expr comp_op_expr_plus
    | comp_op expr
    ;

/* comparison: expr comp_op_expr_star
   ;

comp_op_expr_star: comp_op expr comp_op_expr_star
    | 
    ; */

comp_op: LT
    |GT
    |DOUBLE_EQUAL
    |GE
    |LE
    |NE
    |IN
    |NOT IN 
    |IS 
    |IS NOT 
    ;



exprlist: 
     expr_star_expr_option_list
    ;

expr_star_expr_option: expr
    | star_expr
    ;

expr_star_expr_option_list: expr_star_expr_option COMMA expr_star_expr_option_list
    | expr_star_expr_option COMMA
    | expr_star_expr_option
    ;

testlist_comp: namedexpr_test_star_expr_option comp_for 
    | namedexpr_test_star_expr_option_list 
    ; 

namedexpr_test_star_expr_option_list: namedexpr_test_star_expr_option COMMA namedexpr_test_star_expr_option_list
    | namedexpr_test_star_expr_option COMMA
    | namedexpr_test_star_expr_option
    ;

namedexpr_test_star_expr_option: namedexpr_test
    | star_expr
    ;

namedexpr_test: test ;

test: or_test
    |or_test IF or_test ELSE test;

atom: SMALL_OPEN testlist_comp SMALL_CLOSE
    | SMALL_OPEN SMALL_CLOSE
    | BOX_OPEN testlist_comp BOX_CLOSE
    | BOX_OPEN BOX_CLOSE
    | CURLY_OPEN CURLY_CLOSE
    | NAME 
    | number 
    | string_plus
    | NONE 
    | TRUE 
    | FALSE
    ;
// dictionary , setliterals are to be ignored

number: INTEGER
    | FLOAT
    ;

string_plus: STRING string_plus 
    | STRING
    ;




%%

int main(){
    indent_stack.push(0);
    /* yylex(); */
    yyparse();
    return 0;
}
int yyerror(const char *s){
    cout << "Error: " << s << ",line: "<< yylineno << endl;
    return 0;
}