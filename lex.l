%option noyywrap
%option yylineno
%{
    #include<bits/stdc++.h>
    using namespace std;
%}

%%

.* {cout<<strlen(yytext)<<endl;}

%%

int main(){
    yylex();
    return 0;
}