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
%token KEYWORD NEWLINE INDENT DEDENT NAME YIELD FROM ELIF
%token  POW FLOOR_DIV DIV MUL ADD SUB MOD EQUAL
%token SHIFT_LEFT SHIFT_RIGHT BITWISE_AND BITWISE_XOR BITWISE_OR TILDE  
%token AT COMMA WAL_OP COLON SEMI_COLON 
%token EQ NE LT GT LE GE
%token IN IS IF ELSE 
%token AND OR NOT

%%

file: 
    /* empty */
    |newline_star statements;

/* interactive: 
    statement_newline;

eval: 
    expressions newlines; */

newline_star: NEWLINE newline_star
    | ;

newline_plus: NEWLINE newline_star
    ;


/* statement_newline: 
    compound_stmt NEWLINE
    | simple_stmt NEWLINE
    NEWLINE */

statements: statement newline_star statements 
            | statement ;

statement: simple_stmts | compound_stmt;

simple_stmts: simple_stmt_without_semicolon
            | multiple_simple_stmts
            ;

simple_stmt_without_semicolon: simple_stmt NEWLINE
                               ;

multiple_simple_stmts: simple_stmt SEMI_COLON NEWLINE
| simple_stmt SEMI_COLON simple_stmt_multiple_times SEMI_COLON NEWLINE
| simple_stmt SEMI_COLON simple_stmt_multiple_times NEWLINE
                      ;

simple_stmt_multiple_times: simple_stmt_multiple_times SEMI_COLON simple_stmt
                           | simple_stmt
                           ;

simple_stmt: assignment ; /* incomplete */

compound_stmt:  // incomplete
    if_stmt;

/* if statement */

if_stmt:
      IF named_expression COLON block elif_stmt 
    | IF named_expression COLON block else_block 
    | IF named_expression COLON block {cout << "If" << endl;}
    ;

/* if_stmt: a b c d {cout << "If" << endl;}
    ;
a: IF {cout << "1" << endl;};
b: named_expression {cout << "2" << endl;};
c: COLON {cout << "3" << endl;}
d: block {cout << "4" << endl;} */

elif_stmt:
     ELIF named_expression COLON block elif_stmt 
    | ELIF named_expression COLON block else_block
    | ELIF named_expression COLON block 
    ;
else_block:
     ELSE COLON block
    ;
block: NEWLINE INDENT statements DEDENT {cout << "Block" << endl;} //not defined properly
    | simple_stmts;

assignment: //incomplete
    NAME COLON expression {cout << "Assignment" << endl;}
    | NAME COLON expression EQUAL annotated_rhs
    ;
annotated_rhs: 
    yield_expr | star_expressions;

/* expressions */

expressions: expression COMMA expressions 
    | expression COMMA 
    | expression
    ;

named_expression: 
    assignment_expression
    | expression ;

assignment_expression:
     NAME WAL_OP expression ;

yield_expr: 
    YIELD FROM expression
    | YIELD star_expressions
    | YIELD ;

star_expressions: 
    star_expression COMMA star_expressions 
    | star_expression COMMA
    | star_expression

star_expression:
    MUL bitwise_or ; 
    | expression ;

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
    compare_op_bitwise_or_pair compare_op_bitwise_or_pairs
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
    ADD factor {cout<<"ADD working\n";}
    | SUB factor {cout<<"SUB working\n";}
    | TILDE factor  {cout<<"TILDE working\n";} 
    | power 
;
power : atom
    | atom POW atom
    ;

atom:
     NAME {cout << "Name" << endl;}
     // aur bhi likhna hai       ;
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
