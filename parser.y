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
%token KEYWORD NEWLINE INDENT DEDENT NAME 
%token  POW FLOOR_DIV DIV MUL ADD SUB MOD 
%token SHIFT_LEFT SHIFT_RIGHT BITWISE_AND BITWISE_XOR BITWISE_OR TILDE  
%token AT COMMA
%token EQ NE LT GT LE GE
%token IN IS IF ELSE
%token AND OR NOT

%%

/* file: statements ;

statements: statements statement 
            | statement ;

statement: simple_stmts ;

simple_stmts: simple_stmt_without_semicolon
            | multiple_simple_stmts
            ;

simple_stmt_without_semicolon: simple_stmt NEWLINE
                               ;

multiple_simple_stmts: simple_stmt_multiple_times ';' NEWLINE
                      ;

simple_stmt_multiple_times: simple_stmt_multiple_times ';' simple_stmt
                           | simple_stmt
                           ;

simple_stmt: 
    KEYWORD {cout << "KEYWORD" << endl;}
    ;

block:  INDENT statements DEDENT {cout << "Block" << endl;}
    | simple_stmts; */

/* expressions */

expressions: expression COMMA expressions 
    | expression COMMA 
    | expression
    ;


expression:         
    disjunction IF disjunction ELSE disjunction
    | disjunction
    // lambda expressions are to be ignored
    ;
 
disjunction: conjuction OR disjunction
    | conjuction
    ;

conjuction: inversion AND conjuction
    | inversion
    ;

inversion: NOT inversion;
    | comparison
    ;

/* comparsion operators */

comparison: bitwise_or compare_op_bitwise_or_pairs
    | bitwise_or ;

compare_op_bitwise_or_pairs: 
    compare_op_bitwise_or_pairs compare_op_bitwise_or_pair
    | compare_op_bitwise_or_pair
    ;

compare_op_bitwise_or_pair:
    eq_bitwise_or
    | noteq_bitwise_or
    | lte_bitwise_or
    | lt_bitwise_or
    | gte_bitwise_or
    | gt_bitwise_or
    | notin_bitwise_or
    | in_bitwise_or
    | isnot_bitwise_or
    | is_bitwise_or     ;

eq_bitwise_or: EQ bitwise_or;
noteq_bitwise_or: NE bitwise_or;
lte_bitwise_or: LE bitwise_or;
lt_bitwise_or: LT bitwise_or;
gte_bitwise_or: GE bitwise_or;
gt_bitwise_or: GT bitwise_or;
notin_bitwise_or: NOT IN bitwise_or;
in_bitwise_or:  IN bitwise_or;
isnot_bitwise_or: IS NOT bitwise_or;
is_bitwise_or: IS bitwise_or;

bitwise_or: 
    bitwise_or BITWISE_OR bitwise_xor
    | bitwise_xor
    ;

bitwise_xor: 
    bitwise_xor BITWISE_XOR bitwise_and
    | bitwise_and
    ;

bitwise_and: 
    bitwise_and BITWISE_AND shift_expr
    | shift_expr
    ;

shift_expr: 
    shift_expr SHIFT_LEFT sum
    | shift_expr SHIFT_RIGHT sum
    | sum
    ;

sum : 
    sum ADD term
    | sum SUB term
    | term
    ;

term: 
    term MUL factor
    | term DIV factor
    | term FLOOR_DIV factor
    | term MOD factor
    | term AT factor
    | factor
    ;

factor:
    ADD factor
    | SUB factor
    | TILDE factor // tilde is not working , but detecting
    | power

power : atom
    | atom POW atom
    ;

atom:
     NAME {cout << "Name" << endl;}
     // aur bhi likhna hai       ;
    ;
/* compound_stmt: 
    if_stmt ;

if_stmt:  */
%%

int main(){
    indent_stack.push(0);
    yyparse();
    return 0;
}
int yyerror(const char *s){
    cout << "Error: " << s << ",line: "<< yylineno << endl;
    return 0;
}
