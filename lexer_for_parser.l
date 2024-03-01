%option noyywrap
%option yylineno
%{
    #include<bits/stdc++.h>
    #include <iostream>
    #include <stack>
    #include "test.tab.h"
    using namespace std;

    int current_indent = 0;
    stack<int> indent_stack;
    int temp_count=0;

%}

KEYWORD "False"|"await"|"else"|"import"|"pass"|"None"|"break"|"except"|"in"|"raise"|"True"|"class"|"finally"|"is"|"return"|"continue"|"for"|"lambda"|"try"|"as"|"def"|"from"|"nonlocal"|"while"|"assert"|"del"|"global"|"with"|"async"|"elif"|"if"|"yield"|{LOGICAL_OP}
PRIMITIVE_TYPES "int"|"str"|"float"|"bool" 
TYPE_HINT {PRIMITIVE_TYPES}|("list["{PRIMITIVE_TYPES}"]")

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


STRINGLITERAL   {STRINGPREFIX}?({SHORTSTRING}|{LONGSTRING})
STRINGPREFIX    "r"|"u"|"R"|"U"|"f"|"F"|"fr"|"Fr"|"fR"|"FR"|"rf"|"rF"|"Rf"|"RF"
SHORTSTRING     "'"({SHORTSTRINGITEM})*"'"|\"({SHORTSTRINGITEM})*\"
LONGSTRING      (["]{3,3}{LONGSTRINGITEM}*["]{3,3})|([']{3,3}{LONGSTRINGITEM}*[']{3,3})
SHORTSTRINGITEM {SHORTSTRINGCHAR}|{STRINGESCAPESEQ}
LONGSTRINGITEM  {LONGSTRINGCHAR}|{STRINGESCAPESEQ}
SHORTSTRINGCHAR [^\\\n'"]
LONGSTRINGCHAR  [^\\]
STRINGESCAPESEQ "\\"{SOURCECHAR}
SOURCECHAR "\n"|"\\"|"'"|"\""|"a"|"b"|"f"|"n"|"r"|"t"|"v"|"ooo"|"xhh"

ARITHMETIC_OP "+"|"-"|"*"|"/"|"//"|"%"|"**"

RELATIONAL_OP "=="|"!="|">"|"<"|">="|"<="
LOGICAL_OP "and"|"or"|"not"
BITWISE_OP "&"|"|"|"^"|"~"|"<<"|">>"
ASSIGNMENT_OP "="|"+="|"-="|"*="|"/="|"%="|"**="|"&="|"|="|"^="|"<<="|">>="|"//="|":="


DELIMITER "("|")"|"["|"]"|"{"|"}"|","|":"|"."|";"|"@"|"->"|"@="|"|="


COMMENT "#"[^\n]*

INDENTATIONS ^[ \t]* 

IDENTIFIER [A-Za-z_][A-Za-z0-9_]*

ERRORCHAR "$"|"?"|"`" 

%x STATE
%x DEDENT_STATE
%x HELP
%x BOX_STATE
%x CURLY_STATE
%x SMALL_STATE
%%

<STATE>(.|[\n]) {
    if(temp_count==0){
        BEGIN(INITIAL);
    }else{
    // cout<<temp_count<<endl;
        unput(yytext[0]);
        temp_count--;
        return DEDENT;
    }
}


<DEDENT_STATE>(.|[\n])/([ ]) {
    BEGIN(INITIAL);
    
}
<HELP>(.|[\n]) {
    temp_count--; 
    if(temp_count==0){
        BEGIN(INITIAL);
        }
    else{
            return DEDENT;
            cout<<"spaces already present after newline"<<endl;
            unput(yytext[0]);
    }
}


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
    else if(oper=="yield") return YIELD;
    else if(oper=="from") return FROM;
    else if(oper=="elif") return ELIF;
    else if(oper=="async") return ASYNC;
    else if(oper=="await") return AWAIT;
    else if(oper=="None") return NONE;
    else if(oper=="False") return FALSE;
    else if(oper=="import") return IMPORT;
    else if(oper=="pass") return PASS;
    else if(oper=="break") return BREAK;
    else if(oper=="except") return EXCEPT;
    else if(oper=="raise") return RAISE;
    else if(oper=="True") return TRUE;
    else if(oper=="class") return CLASS;
    else if(oper=="finally") return FINALLY;
    else if(oper=="return") return RETURN;
    else if(oper=="continue") return CONTINUE;
    else if(oper=="for") return FOR;
    else if(oper=="lambda") return LAMBDA;
    else if(oper=="try") return TRY;
    else if(oper=="as") return AS;
    else if(oper=="def") return DEF;
    else if(oper=="nonlocal") return NONLOCAL;
    else if(oper=="while") return WHILE;
    else if(oper=="assert") return ASSERT;
    else if(oper=="del") return DEL;
    else if(oper=="global") return GLOBAL;
    else if(oper=="with") return WITH;
    else if(oper=="None") return NONE;
}

":"[ \t]*{TYPE_HINT} { cout<<"TYPE"<<": "<<yytext<<endl; return TYPE_HINT; }
"->"[ \t]*({TYPE_HINT}|"None") { cout<<"TYPE"<<": "<<yytext<<endl; return FUNC_TYPE_HINT; }

<INITIAL,SMALL_STATE,CURLY_STATE,BOX_STATE>{IDENTIFIER} { cout<<"IDENTIFIER"<<" "<<yytext<<endl; return NAME; }
<INITIAL,SMALL_STATE,CURLY_STATE,BOX_STATE>{INTEGER} { cout<<"INTEGER"<<" "<<yytext<<endl;return INTEGER;}
<INITIAL,SMALL_STATE,CURLY_STATE,BOX_STATE>{FLOATNUMBER} { cout<<"FLOAT"<<" "<<yytext<<endl;return FLOAT;}
<INITIAL,SMALL_STATE,CURLY_STATE,BOX_STATE>{STRINGLITERAL} { cout<<"STRING"<<" "<<yytext<<endl;return STRING;}
<INITIAL,SMALL_STATE,CURLY_STATE,BOX_STATE>{COMMENT} { cout<<"COMMENT"<<" "<<yytext<<endl;}

{INDENTATIONS} {
            int new_indent = strlen(yytext); 
            if(new_indent%2==1){
                cout<<"ERROR: wrong indentation"<<endl;
                return 0;
            }   
            new_indent = new_indent/2;
            if (new_indent > indent_stack.top()) {
                indent_stack.push( new_indent);
                cout<<"INDENT"<<endl;
                return INDENT;
            }
            else if(new_indent<indent_stack.top()){ 
                while (indent_stack.top()!=0 &&  new_indent < indent_stack.top()) {
                    indent_stack.pop();
                    cout<<"DEDENT"<<endl;
                    temp_count++;
                }
                if(indent_stack.top()!=new_indent){
                    cout<<"ERROR: wrong indentation"<<endl;
                    return 0;
                }
                // temp_count--;
                unput(yytext[0]);
                BEGIN(STATE);
                // return DEDENT;
                // cout<<"DEDENT"<<endl;
                // return DEDENT;
            }
}



<INITIAL,SMALL_STATE,CURLY_STATE,BOX_STATE>{ARITHMETIC_OP} { 
    string oper = yytext;
    if(oper=="**") return POW;
    else if(oper=="//") return FLOOR_DIV;
    else if(oper=="/") return DIV;
    else if(oper=="*") return MUL;
    else if(oper=="+") return ADD;
    else if(oper=="-") return SUB;
    else if(oper=="%") {return MOD;}
}

<INITIAL,SMALL_STATE,CURLY_STATE,BOX_STATE>{BITWISE_OP} { 
    string oper = yytext;
    if(oper=="<<") return SHIFT_LEFT;
    else if(oper==">>") return SHIFT_RIGHT;
    else if(oper=="&") return BITWISE_AND;
    else if(oper=="|") return BITWISE_OR;
    else if(oper=="^") return BITWISE_XOR;
    else if(oper=="~") {cout<<"sending ~"<<endl;return TILDE;}
}

<INITIAL,SMALL_STATE,CURLY_STATE,BOX_STATE>{RELATIONAL_OP} {
    string oper = yytext;
    if(oper=="==") return DOUBLE_EQUAL;
    else if(oper=="!=") return NE;
    else if(oper==">") return GT;
    else if(oper=="<") return LT;
    else if(oper==">=") return GE;
    else if(oper=="<=") return LE;
}

{ASSIGNMENT_OP} {
    string oper = yytext;
    if(oper==":=") return WAL_OP;
    else if(oper=="=") return EQUAL;
    else if(oper=="+=") return ADD_EQUAL;
    else if(oper=="-=") return SUB_EQUAL;
    else if(oper=="*=") return MUL_EQUAL;
    else if(oper=="/=") return DIV_EQUAL;
    else if(oper=="%=") return MOD_EQUAL;
    else if(oper=="**=") return POW_EQUAL;
    else if(oper=="&=") return BITWISE_AND_EQUAL;
    else if(oper=="|=") return BITWISE_OR_EQUAL;
    else if(oper=="^=") return BITWISE_XOR_EQUAL;
    else if(oper=="<<=") return SHIFT_LEFT_EQUAL;
    else if(oper==">>=") return SHIFT_RIGHT_EQUAL;
    else if(oper=="//=") return FLOOR_DIV_EQUAL;

}

<SMALL_STATE,CURLY_STATE,BOX_STATE>[ \n\t] {
}


<INITIAL,SMALL_STATE,CURLY_STATE,BOX_STATE>{DELIMITER} { 
    cout<<"DELIMITER"<<" "<<yytext<<endl;
    string oper = yytext;

    if(oper=="@") return AT;
    else if(oper==",") return COMMA;
    else if(oper==":") return COLON;
    else if(oper=="(") {BEGIN(SMALL_STATE);return SMALL_OPEN;}
    else if(oper==")") {BEGIN(INITIAL);return SMALL_CLOSE;}
    else if(oper=="[") { BEGIN(BOX_STATE);return BOX_OPEN;}
    else if(oper=="]") { BEGIN(INITIAL);return BOX_CLOSE;}
    else if(oper=="{") {BEGIN(CURLY_STATE);return CURLY_OPEN;}
    else if(oper=="}") {BEGIN(INITIAL);return CURLY_CLOSE;}
    else if(oper==".") return DOT;
    else if(oper=="->") return ARROW;
    
}

<INITIAL,SMALL_STATE,CURLY_STATE,BOX_STATE>{ERRORCHAR} {
    cout<<"Error: Unexpected character "<<yytext<< " at line "<<yylineno<< endl;
    return 0;
}
    

<INITIAL>"\n"+/[^ \t\#] {
      while (indent_stack.top()!=0) {
            indent_stack.pop();
            cout<<"DEDENT"<<endl;
            temp_count++;
        }
        if(indent_stack.top()!=0){
            cout<<"ERROR: wrong indentation"<<endl;
            return 0;
        }
        // temp_count--;
        unput(yytext[0]);
        BEGIN(STATE);
        cout<<"NEWLINE"<<endl; 
        return NEWLINE ;
    }

    /*^[ \t]*{COMMENT}?"\n" {
        //ignore empty lines and lines only with comment
    }*/


"\n"+/[ \t] {
    cout<<"NEWLINE"<<endl;
    return NEWLINE;
}

"\n"+[ \t]*/[\n] {
    cout<<"EMpty line";
}

"\n"+[ \t]*[\#][^\n]* {
    cout<<"comment detected"<<endl;
}

"\n"+ {
     while (indent_stack.top()!=0) {
            indent_stack.pop();
            cout<<"DEDENT"<<endl;
            temp_count++;
        }
        if(indent_stack.top()!=0){
            cout<<"ERROR: wrong indentation"<<endl;
            return 0;
        }
        // temp_count--;
        unput(yytext[0]);
        BEGIN(STATE);
        cout<<"Last NEWLINE"<<endl; 
        return NEWLINE ;
        // this will only when the last is newline not followed by spaces and tabs

}
    /*explicit line joining*/
[\\][\n][ \t]* {}
. { }
%%

// int main(){
//     indent_stack.push(0);

//     yylex();
//     return 0;
// }
