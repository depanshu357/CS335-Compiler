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
%token KEYWORD NEWLINE INDENT DEDENT NAME YIELD FROM ELIF AWAIT ASYNC TRUE FALSE NONE
%token INTEGER FLOAT STRING
%token POW FLOOR_DIV DIV MUL ADD SUB MOD EQUAL
%token SHIFT_LEFT SHIFT_RIGHT BITWISE_AND BITWISE_XOR BITWISE_OR TILDE  
%token AT COMMA WAL_OP COLON SEMI_COLON SMALL_OPEN SMALL_CLOSE BOX_OPEN BOX_CLOSE CURLY_OPEN CURLY_CLOSE 
%token EQ NE LT GT LE GE
%token IN IS IF ELSE 
%token AND OR NOT

%%
/* operators*/
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



atom_expr: await_optional atom trailer_star;

await_optional: AWAIT
    | /*empty*/
    ;
    
trailer_star: trailer trailer_star
    | /*empty*/
    ;
    
atom: SMALL_OPEN yield_expr_testlist_comp_optional SMALL_CLOSE 
    |BOX_OPEN testlist_comp_optional BOX_CLOSE
    |CURLY_OPEN dictorsetmaker_optional CURLY_CLOSE
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
    | /*empty*/
    ;

yield_expr_testlist_comp_optional: yield_expr
    | testlist_comp
    | /*empty*/
    ;

testlist_comp_optional: testlist_comp
    | /*empty*/
    ;

dictorsetmaker_optional : dictorsetmaker
    | /*empty*/
    ;


 /* Remaining from below */
/* testlist_comp: (namedexpr_test|star_expr) ( comp_for | (',' (namedexpr_test|star_expr))* [','] )
trailer: '(' [arglist] ')' | '[' subscriptlist ']' | '.' NAME
subscriptlist: subscript (',' subscript)* [',']
subscript: test | [test] ':' [test]
exprlist: (expr|star_expr) (',' (expr|star_expr))* [',']
testlist: test (',' test)* [',']
dictorsetmaker: ( ((test ':' test | '**' expr)
                   (comp_for | (',' (test ':' test | '**' expr))* [','])) |
                  ((test | star_expr)
                   (comp_for | (',' (test | star_expr))* [','])) )

classdef: 'class' NAME ['(' [arglist] ')'] ':' suite

arglist: argument (',' argument)*  [',']

argument: ( test [comp_for] |
            test ':=' test |
            test '=' test |
            '**' test |
            '*' test )

comp_iter: comp_for | comp_if
sync_comp_for: 'for' exprlist 'in' or_test [comp_iter]
comp_for: [ASYNC] sync_comp_for
comp_if: 'if' test_nocond [comp_iter]

encoding_decl: NAME

yield_expr: 'yield' [yield_arg]
yield_arg: 'from' test | testlist_star_expr

func_body_suite: simple_stmt | NEWLINE [TYPE_COMMENT NEWLINE] INDENT stmt+ DEDENT

func_type_input: func_type NEWLINE* ENDMARKER
func_type: '(' [typelist] ')' '->' test
typelist: (test (',' test)* [','
       ['*' [test] (',' test)* [',' '**' test] | '**' test]]
     |  '*' [test] (',' test)* [',' '**' test] | '**' test) */


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
