#include<bits/stdc++.h>
// #include "parser.y"
using namespace std;

// extern vector<vector<string>> instructions;
// extern int tempCount;

void print_x86_ins(vector<string> ins,ofstream &x86_file){
    if(ins[0]=="3"){
        if(ins[1]=="+"){
            x86_file << "movq 0(%r1) %r2" << endl;
            x86_file << "movq 8(%r1) %r3" << endl;
            x86_file<<"add %r2 %r3"<<endl;
            x86_file<<"movq %r2 16(%r1)"<<endl;
        }else if(ins[0]=="-"){
            x86_file << "movq 0(%r1) %r2" << endl;
            x86_file << "movq 8(%r1) %r3" << endl;
            x86_file<<"sub %r2 %r3"<<endl;
            x86_file<<"movq %r2 16(%r1)"<<endl;}
    }
}


void create_x86_code(vector<vector<string>> &instructions)
{
    //open file x86.s
    ofstream x86_file;
    x86_file.open("x861.s");
    //print .data section in this file
    x86_file << ".data" << endl;
    x86_file << "        integer_format:	.asciz,	\"%ld\\n\"" << endl;
    x86_file << ".global	main" << endl;
    x86_file << ".text" << endl;




    for(int i=0;i<instructions.size();i++){
        print_x86_ins(instructions[i],x86_file);
        // for(int j=0;j<instructions[i].size();j++){
        //     x86_file << instructions[i][j] << endl;
        // }
        // x86_file << endl;
    }
    x86_file << "mov     $60, %rax" << endl;
    x86_file << "xor     %rdi, %rdi" << endl;
    x86_file << "syscall" << endl;
    x86_file.close();
}

// int main(int argc, char *argv[]){
//     create_x86_code();
//     return 0;
// }