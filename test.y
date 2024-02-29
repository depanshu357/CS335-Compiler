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
    | test EQUAL test 
    | POW test 
    | MUL test
    ;

optional_test: test 
    | /*empty*/
    ;

sync_comp_for: FOR exprlist IN or_test
    /* | FOR exprlist IN or_test comp_iter */
    ;


comp_for:  sync_comp_for
    | ASYNC sync_comp_for
    ;


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
    
comparison: expr comp_op_expr_star ;

comp_op_expr_star: comp_op expr comp_op_expr_star
    | 
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

test: atom {cout<<"recognized"<<endl;};

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