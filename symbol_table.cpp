#include <bits/stdc++.h>
using namespace::std;

typedef struct st_node {
    string name;
    string type; //return type in case of a function
    int line_no;
    int is_func;
    int size;
    int offset;
    struct sym_table* sub_symbol_table;
} st_node;

typedef struct sym_table {
    sym_table * prev_sym_table;
    vector<st_node> sym_tbl_entry; //this will contain entries of sym_table
} sym_table;


void create_entry(sym_table * curr_sym_tbl,string name, string type, int line_no, int is_func, int size, int offset, sym_table * sub_symbol_table=NULL){
    st_node new_entry;
    new_entry.name = name;
    new_entry.type = type;
    new_entry.line_no = line_no;
    new_entry.is_func = is_func;
    new_entry.size = size;
    new_entry.offset = offset;
    new_entry.sub_symbol_table = sub_symbol_table;
    if(sub_symbol_table!=NULL)
    new_entry.sub_symbol_table->prev_sym_table=curr_sym_tbl;
    curr_sym_tbl->sym_tbl_entry.push_back(new_entry);
}

int search_sym_table(sym_table * symbol_table,string name, int is_func){
    sym_table * curr = symbol_table;
    while(curr!=NULL){
        for(int i=0;i<curr->sym_tbl_entry.size();i++){
            if(curr->sym_tbl_entry[i].name == name && curr->sym_tbl_entry[i].is_func == is_func){
                return 1;
            }
        }
        curr = curr->prev_sym_table;
    }

    return 0;
}

void print_sym_table(sym_table * symbol_table){
    
    for(int i=0;i<symbol_table->sym_tbl_entry.size();i++){
        cout<<"entry_no: "<<i<<"-----------------------------"<<endl;
        cout<<"name: "<<symbol_table->sym_tbl_entry[i].name<<endl;
        cout<<"type: "<<symbol_table->sym_tbl_entry[i].type<<endl;
        cout<<"line_no: "<<symbol_table->sym_tbl_entry[i].line_no<<endl;
        cout<<"is_func: "<<symbol_table->sym_tbl_entry[i].is_func<<endl;
        cout<<"size: "<<symbol_table->sym_tbl_entry[i].size<<endl;
        cout<<"offset: "<<symbol_table->sym_tbl_entry[i].offset<<endl;
    
    }
}

// int main(){
    
//     sym_table * global_sym_table = new sym_table;
//     global_sym_table->prev_sym_table = NULL;
//     global_sym_table->sym_tbl_entry.clear();
//     create_entry(global_sym_table,"main","int",1,1,0,0);
//     cout<<search_sym_table(global_sym_table,"main",1)<<endl; //returns 1
//     cout<<search_sym_table(global_sym_table,"mains",1)<<endl; //returns 0
//     sym_table * local_sym_table = new sym_table;

//     create_entry(global_sym_table,"a","int",2,0,4,0, local_sym_table);
//     create_entry(local_sym_table,"b","int",3,0,4,4);
//     cout<<search_sym_table(local_sym_table,"a",0)<<endl; //returns 1
//     return 0;
// }