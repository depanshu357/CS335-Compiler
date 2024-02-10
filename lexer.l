%option noyywrap
%option yylineno
%{
    #include<bits/stdc++.h>
    #include <iostream>
    #include <stack>
    using namespace std;

    int current_indent = 0;
    stack<int> indent_stack;

%}

KEYWORD "False"|"await"|"else"|"import"|"pass"|"None"|"break"|"except"|"in"|"raise"|"True"|"class"|"finally"|"is"|"return"|"and"|"continue"|"for"|"lambda"|"try"|"as"|"def"|"from"|"nonlocal"|"while"|"assert"|"del"|"global"|"not"|"with"|"async"|"elif"|"if"|"or"|"yield"

INTEGER {DECINTEGER}|{BININTEGER}|{OCTINTEGER}|{HEXINTEGER}
DECINTEGER {NONZERODIGIT}(["_"]?{DIGIT})*|"0"+(["_"]?"0")*
BININTEGER "0"("b"|"B")(["_"]?{BINDIGIT})+
OCTINTEGER "0"("o"|"O")(["_"]?{OCTDIGIT})+
HEXINTEGER "0"("x"|"X")(["_"]?{HEXDIGIT})+
DIGIT [0-9]
NONZERODIGIT [1-9]
BINDIGIT [0-1]
OCTDIGIT [0-7]
HEXDIGIT {DIGIT}|[a-fA-F]


FLOATNUMBER   {POINTFLOAT}|{EXPONENTFLOAT}
POINTFLOAT    ({DIGITPART}?{F   CTION})|({DIGITPART}".")
EXPONENTFLOAT ({DIGITPART}|{POINTFLOAT}){EXPONENT}
DIGITPART     {DIGIT}(["_"]?{DIGIT})*
FRACTION      "."{DIGITPART}
EXPONENT      ("e"|"E")("+"|"-")?{DIGITPART}


STRINGLITERAL   {STRINGPREFIX}?({SHORTSTRING}{LONGSTRING})
STRINGPREFIX    "r"|"u"|"R"|"U"|"f"|"F"|"fr"|"Fr"|"fR"|"FR"|"rf"|"rF"|"Rf"|"RF"
SHORTSTRING     "'"{SHORTSTRINGITEM}*"'"|"\""{SHORTSTRINGITEM}*"\""
LONGSTRING      "'''"{LONGSTRINGITEM}*"'''"|"\"\"\"" {LONGSTRINGITEM}* "\"\"\""
SHORTSTRINGITEM {SHORTSTRINGCHAR}|{STRINGESCAPESEQ}
LONGSTRINGITEM  {LONGSTRINGCHAR}|{STRINGESCAPESEQ}
SHORTSTRINGCHAR [^\\\n']
LONGSTRINGCHAR  [^\\]
STRINGESCAPESEQ "\\"{SOURCECHAR}
SOURCECHAR "\\n"|"\\"|"'"|"\""|"a"|"b"|"f"|"n"|"r"|"t"|"v"|"ooo"|"xhh"

ARITHMETIC_OP "+"|"-"|"*"|"/"|"//"|"%"|"**"
RELATIONAL_OP "=="|"!="|">"|"<"|">="|"<="
LOGICAL_OP "and"|"or"|"not"
BITWISE_OP "&"|"|"|"^"|"~"|"<<"|">>"
ASSIGNMENT_OP "="|"+="|"-="|"*="|"/="|"%="|"**="|"&="|"|="|"^="|"<<="|">>="


DELIMITER "("|")"|"["|"]"|"{"|"}"|","|":"|"."|";"|"@"|"->"|"//="|"@="|"|="


COMMENT "#"[^\n]*

INDENTATIONS ^[ \t]* 

IDENTIFIER [A-Za-z_][A-Za-z0-9_]*

ERRORCHAR "$"|"?"|"`" 

PRINT "print"
RANGE "range"

%%
{KEYWORD} { cout<<"KEYWORD"<<" "<<yytext<<endl;}
{IDENTIFIER} { cout<<"IDENTIFIER"<<" "<<yytext<<endl;}
{INTEGER} { cout<<"INTEGER"<<" "<<yytext<<endl;}

{COMMENT} { cout<<"COMMENT"<<" "<<yytext<<endl;}

{INDENTATIONS} {
            int new_indent = strlen(yytext);
            if (new_indent > indent_stack.top()) {
                indent_stack.push( new_indent);
                cout<<"INDENT"<<endl;
                // return INDENT;
            }
            else { 
                while (indent_stack.top()!=0 &&  new_indent < indent_stack.top()) {
                    indent_stack.pop();
                    // return DEDENT;
                }
                if(indent_stack.top()!=new_indent){
                    cout<<"ERROR: wrong indentation"<<endl;
                    return 0;
                }
                cout<<"DEDENT"<<endl;
            }
        }

{DELIMITER} { cout<<"DELIMITER"<<" "<<yytext<<endl;}
{ERRORCHAR} {
    cout<<"Error: Unexpected character "<<yytext<< " at line "<<yylineno<< endl;
    return 0;
}


. { }
"\n" { cout<<"NEWLINE"<<yytext<<endl;}
%%

int main(){
    indent_stack.push(0);

    yylex();
    return 0;
}
