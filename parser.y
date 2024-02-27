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
%token AT COMMA WAL_OP COLON SEMI_COLON SMALL_OPEN SMALL_CLOSE BOX_OPEN BOX_CLOSE CURLY_OPEN CURLY_CLOSE  DOT
%token EQ NE LT GT LE GE
%token IN IS IF ELSE 
%token AND OR NOT
%token TYPE_COMMENT /*dont know what it means, just defined to remove error, doesnt work*/
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN AT_ASSIGN DIV_ASSIGN MOD_ASSIGN AND_ASSIGN OR_ASSIGN XOR_ASSIGN LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN POW_ASSIGN FLOOR_DIV_ASSIGN

%%
/* operators*/

single_input: NEWLINE 
    | simple_stmt 
    | compound_stmt NEWLINE
    ;
    
file_input: NEWLINE file_input
    | stmt file_input
    | /*empty*/
    ;

eval_input: testlist NEWLINE
    | testlist
    ;

decorator: AT dotted_name SMALL_OPEN arglist SMALL_CLOSE NEWLINE
    | AT dotted_name SMALL_OPEN SMALL_CLOSE NEWLINE
    | AT dotted_name NEWLINE
    ;
    
decorators: decorator decorators
    | decorator
    ;

decorated: decorators classdef
    | decorators funcdef 
    | decorators async_funcdef
    ;

async_funcdef: ASYNC funcdef;

funcdef: DEF NAME parameters SUB GT test COLON TYPE_COMMENT func_body_suite
    | DEF NAME parameters SUB GT test COLON  func_body_suite
    | DEF NAME parameters COLON TYPE_COMMENT func_body_suite
    | DEF NAME parameters  COLON  func_body_suite
    ;


stmt: simple_stmt 
    |compound_stmt
    ;
    
simple_stmt: small_stmt semi_colon_small_stmt_star SEMI_COLON NEWLINE
    |  small_stmt semi_colon_small_stmt_star NEWLINE
    ;

semi_colon_small_stmt_star: SEMI_COLON small_stmt semi_colon_small_stmt_star
    | /*empty*/
    ;
    
small_stmt: expr_stmt 
    | del_stmt 
    | pass_stmt 
    | flow_stmt 
    | global_stmt 
    | nonlocal_stmt 
    | assert_stmt
    ;

expr_stmt: testlist_star_expr annassign 
    | testlist_star_expr augassign yield_expr
    | testlist_star_expr augassign testlist
    |testlist_star_expr  
    |testlist_star_expr expr_stmt_option1_star  
    |testlist_star_expr expr_stmt_option1_star TYPE_COMMENT
    ;

expr_stmt_option1_star: EQ yield_expr expr_stmt_option1_star
    |EQ testlist_star_expr expr_stmt_option1_star
    |EQ yield_expr
    |EQ testlist_star_expr
    ;

annassign: COLON test
    | COLON test EQ yield_expr
    | COLON test EQ testlist_star_expr
    ;

testlist_star_expr: test testlist_star_expr_option1_star 
    | test testlist_star_expr_option1_star COMMA
    | star_expr testlist_star_expr_option1_star 
    | star_expr testlist_star_expr_option1_star COMMA
    ;

testlist_star_expr_option1_star: COMMA test testlist_star_expr_option1_star
    | COMMA star_expr testlist_star_expr_option1_star
    | /*empty*/
    ;

augassign: ADD_ASSIGN | SUB_ASSIGN | MUL_ASSIGN | AT_ASSIGN | DIV_ASSIGN | MOD_ASSIGN | AND_ASSIGN | OR_ASSIGN | XOR_ASSIGN |
            LEFT_SHIFT_ASSIGN | RIGHT_SHIFT_ASSIGN | POW_ASSIGN | FLOOR_DIV_ASSIGN ;

del_stmt: DEL exprlist;
pass_stmt: PASS;
flow_stmt: break_stmt 
    | continue_stmt 
    | return_stmt 
    | raise_stmt 
    | yield_stmt
    ;

break_stmt: BREAK;

continue_stmt: CONTINUE;

return_stmt: RETURN testlist_star_expr
    | RETURN 
    ;
    
yield_stmt: yield_expr;

raise_stmt: RAISE 
    | RAISE test 
    | RAISE test FROM test
    ;

/* 
import_stmt: import_name 
    | import_from
    ;
import_name: IMPORT dotted_as_names;

import_from: ('from' (('.' | '...')* dotted_name | ('.' | '...')+)
              'import' ('*' | '(' import_as_names ')' | import_as_names))
import_as_name: NAME ['as' NAME] */

dotted_as_name: dotted_name 
    |dotted_name AS NAME
    ;

/* import_as_names: import_as_name (',' import_as_name)* [','] */

dotted_as_names: dotted_as_name comma_dotted_as_name_star;

comma_dotted_as_name_star: COMMA dotted_as_name comma_dotted_as_name_star
    | /*empty*/
    ;

dotted_name: NAME dot_name_star;

dot_name_star: DOT NAME dot_name_star
    | /*empty*/
    ;

global_stmt: 'global' NAME comma_name_star ;

nonlocal_stmt: NONLOCAL NAME comma_name_star ;

comma_name_star: COMMA NAME comma_name_star
    | /*empty*/
    ;

assert_stmt: ASSERT test COMMA test
    | ASSERT test
    ;

compound_stmt: if_stmt 
    | while_stmt 
    | for_stmt 
    | try_stmt 
    | with_stmt 
    | funcdef 
    | classdef 
    | decorated 
    | async_stmt
    ;
    
async_stmt: ASYNC funcdef
    | ASYNC with_stmt
    | ASYNC for_stmt
    | ASYNC for_stmt
    ;

if_stmt: IF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star ELSE COLON suite
    | IF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star
    ;

elif_namedexpr_test_colon_suite_star: ELIF namedexpr_test COLON suite elif_namedexpr_test_colon_suite_star
    | /*empty*/
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
    | /*empty*/
    ;


with_stmt: WITH with_item comma_with_item_star COLON suite
    | WITH with_item comma_with_item_star COLON TYPE_COMMENT suite
    ;

comma_with_item_star: COMMA with_item comma_with_item_star
    | /*empty*/
    ;

with_item: test 
    | test AS expr
    ;

except_clause: EXCEPT test_as_name_optional

test_as_name_optional: test
    | test AS NAME
    | /*empty*/
    ;

suite: simple_stmt 
    | NEWLINE INDENT stmt_plus DEDENT
    ;

stmt_plus: stmt stmt_plus
    | stmt
    ;

/*clean below*/
namedexpr_test: test ;

test: or_test;
    |or_test IF or_test ELSE test;

test_nocond: or_test;

or_test: and_test or_and_test_star;

or_and_test_star:OR and_test or_and_test_star 
    | /*empty*/
    ;
    
and_test: not_test and_not_test_star;

and_not_test_star: AND not_test and_not_test_star
    | /*empty*/
    ;

not_test: NOT not_test
    | comparison
    ;
    
comparison: expr comp_op_expr_star ;

comp_op_expr_star: comp_op expr comp_op_expr_star
    | /*empty*/
    ;

comp_op: LT
    |GT
    |EQ
    |GE
    |LE
    |NE
    |IN
    |NOT IN 
    |IS 
    |IS NOT 
    ;

star_expr: MUL expr;

expr: xor_expr symbol_xor_expr_star;

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
    
atom: SMALL_OPEN yield_expr_testlist_comp_optional SMALL_CLOSE 
    |BOX_OPEN testlist_comp BOX_CLOSE
    |BOX_OPEN BOX_CLOSE
    |CURLY_OPEN dictorsetmaker CURLY_CLOSE
    |CURLY_OPEN CURLY_CLOSE
    | NAME 
    | number 
    | string_plus
    | NONE 
    | TRUE 
    | FALSE
    ;

number: INTEGER
    | FLOAT
    ;

string_plus: STRING string_plus
    | STRING
    ;

yield_expr_testlist_comp_optional: yield_expr
    | testlist_comp
    | /*empty*/
    ;

 /* Remaining from below */
testlist_comp:namedexpr_test_star_expr_option comp_for 
    |namedexpr_test_star_expr_option  COMMA namedexpr_test_star_expr_option_star  
    |namedexpr_test_star_expr_option  COMMA namedexpr_test_star_expr_option_star COMMA
    ; 

namedexpr_test_star_expr_option: namedexpr_test
    | star_expr
    ;

namedexpr_test_star_expr_option_star: namedexpr_test_star_expr_option namedexpr_test_star_expr_option_star
    | /*empty*/
    ;

    
trailer: SMALL_OPEN arglist SMALL_CLOSE 
    |SMALL_OPEN  SMALL_CLOSE  
    |BOX_OPEN subscriptlist BOX_CLOSE 
    |DOT NAME
    ;
    
subscriptlist: subscript symbol_subscript_star
    | subscript symbol_subscript_star COMMA
    ;

symbol_subscript_star: /*empty*/
    | COMMA subscript symbol_subscript_star
    ;

subscript: test 
    | optional_test COLON optional_test
    ;

optional_test: test 
    | /*empty*/
    ;
    
exprlist: expr_star_expr_option symbol_expr_star_expr_option_star COMMA
    |expr_star_expr_option symbol_expr_star_expr_option_star 
    ;

expr_star_expr_option: expr
    | star_expr
    ;

symbol_expr_star_expr_option_star: COMMA expr_star_expr_option symbol_expr_star_expr_option_star
    | /*empty*/
    ;
    
testlist: test symbol_test_star COMMA
    | test symbol_test_star
    ;

symbol_test_star: COMMA test symbol_test_star
    | /*empty*/
    ;
    
dictorsetmaker: dictorsetmaker_option1 comp_for 
    |dictorsetmaker_option1 dictorsetmaker_option1_star 
    |dictorsetmaker_option1 dictorsetmaker_option1_star COMMA
    |dictorsetmaker_option2 comp_for 
    |dictorsetmaker_option2 dictorsetmaker_option1_star 
    |dictorsetmaker_option2 dictorsetmaker_option1_star COMMA
    ;

dictorsetmaker_option1:test COLON test 
    |POW expr
    ;
    
dictorsetmaker_option1_star: COMMA dictorsetmaker_option1 dictorsetmaker_option1_star
    | /*empty*/
    ;

dictorsetmaker_option2: test
    | star_expr
    ;

classdef: CLASS NAME bracket_arglist_optional COLON suite;

bracket_arglist_optional: SMALL_OPEN SMALL_CLOSE
    | SMALL_OPEN arglist SMALL_CLOSE
    | /*empty*/
    ;

arglist: argument comma_arg_star
    | argument comma_arg_star  COMMA
    ;

comma_arg_star: COMMA argument comma_arg_star
    | /*empty*/
    ;



argument: test 
    | test comp_for 
    | test EQUAL test 
    | POW test 
    | MUL test
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

encoding_decl: NAME ;

yield_expr: YIELD
    | YIELD yield_arg
    ;

yield_arg: FROM test 
    | testlist_star_expr
    ;

func_body_suite: simple_stmt 
    | NEWLINE INDENT stmt_plus DEDENT
    | NEWLINE TYPE_COMMENT NEWLINE INDENT stmt_plus DEDENT

func_type_input: func_type
    | func_type NEWLINE
    ;

func_type: SMALL_OPEN SMALL_CLOSE SUB GT test
    | SMALL_OPEN typelist SMALL_CLOSE SUB GT test
    ;

typelist: test comma_test_star
    | test comma_test_star COMMA typelist_options
    |  typelist_options
    ;

typelist_options: MUL test_optional comma_test_star COMMA POW test 
    | MUL test_optional comma_test_star 
    | POW test
    ;

comma_test_star: COMMA test comma_test_star
    | /*empty*/
    ;
test_optional: test
    | /*empty*/
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
