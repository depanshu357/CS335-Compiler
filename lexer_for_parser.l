%option noyywrap
%option yylineno
%{
    #include<bits/stdc++.h>
    #include <iostream>
    #include <stack>
    #include "parser.tab.h"
    using namespace std;

    int current_indent = 0;
    stack<int> indent_stack;

%}

KEYWORD "False"|"await"|"else"|"import"|"pass"|"None"|"break"|"except"|"in"|"raise"|"True"|"class"|"finally"|"is"|"return"|"continue"|"for"|"lambda"|"try"|"as"|"def"|"from"|"nonlocal"|"while"|"assert"|"del"|"global"|"with"|"async"|"elif"|"if"|"yield"|{LOGICAL_OP}

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
POINTFLOAT    ({DIGITPART}?{FRACTION})|({DIGITPART}".")
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
{KEYWORD} { 
    cout<<"KEYWORD"<<" "<<yytext<<endl; ; 
    string oper = yytext;
    if(oper=="is") return IS;
    else if(oper=="in") return IN;
    else if(oper=="if") return IF;
    else if(oper=="else") {cout<<"else"<<endl;return ELSE; }
    else if(oper=="and") return AND;
    else if(oper=="or") return OR;
    else if(oper=="not") return NOT;
    // baki ka likhna baki hai
}
{IDENTIFIER} { cout<<"IDENTIFIER"<<" "<<yytext<<endl; return NAME; }
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
                // cout<<new_indent<<endl;
                // cout<<indent_stack.top()<<endl;
                while (indent_stack.top()!=0 &&  new_indent < indent_stack.top()) {
                    indent_stack.pop();
                    // cout<<indent_stack.top()<<endl;
                    cout<<"DEDENT"<<endl;
                    // return DEDENT;
                }
                if(indent_stack.top()!=new_indent){
                    cout<<"ERROR: wrong indentation"<<endl;
                    return 0;
                }
                // cout<<"DEDENT"<<endl;
            }
}



{ARITHMETIC_OP} { 
    string oper = yytext;
    if(oper=="**") return POW;
    else if(oper=="//") return FLOOR_DIV;
    else if(oper=="/") return DIV;
    else if(oper=="*") return MUL;
    else if(oper=="+") return ADD;
    else if(oper=="-") return SUB;
    else if(oper=="%") return MOD;
}

{BITWISE_OP} { 
    string oper = yytext;
    if(oper=="<<") return SHIFT_LEFT;
    else if(oper==">>") return SHIFT_RIGHT;
    else if(oper=="&") return BITWISE_AND;
    else if(oper=="|") return BITWISE_OR;
    else if(oper=="^") return BITWISE_XOR;
    else if(oper=="~") {cout<<"sending ~"<<endl;return TILDE;}
}

{RELATIONAL_OP} {
    string oper = yytext;
    if(oper=="==") return EQ;
    else if(oper=="!=") return NE;
    else if(oper==">") return GT;
    else if(oper=="<") return LT;
    else if(oper==">=") return GE;
    else if(oper=="<=") return LE;
}



{DELIMITER} { 
    cout<<"DELIMITER"<<" "<<yytext<<endl;
    string oper = yytext;
    if(oper=="@") return AT;
}

{ERRORCHAR} {
    cout<<"Error: Unexpected character "<<yytext<< " at line "<<yylineno<< endl;
    return 0;
}

. { }
"\n" { cout<<"NEWLINE"<<endl; ;}
%%

// int main(){
//     indent_stack.push(0);

//     yylex();
//     return 0;
// }
