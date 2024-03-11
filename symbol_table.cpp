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

int  get_type_size(string s){
    
    if(s=="int"){
        return 4;
    }
    else if(s=="float"){
        return 4;
    }
    else if(s=="char"){
        return 1;
    }
    else if(s=="double"){
        return 8;
    }
    else if(s=="void"){
        return 0;
    }
    else if(s=="bool"){
        return 4;
    }
    else{
        return 4; //string size is also returned 4
    }
    
}

void create_entry(sym_table * curr_sym_tbl,string name, string type, int line_no, int is_func, int offset, sym_table * sub_symbol_table=NULL){
    st_node new_entry;
    new_entry.name = name;
    new_entry.type = type;
    new_entry.line_no = line_no;
    new_entry.is_func = is_func;
    new_entry.size = get_type_size(type);
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
            if(curr->sym_tbl_entry[i].name == name){
                return 1;
            }
        }
        curr = curr->prev_sym_table;
    }

    return 0;
}

void print_sym_table(sym_table * symbol_table){
    
     std::cout << "entry_no,name,type,line_no,is_func,size,offset" << std::endl;

    // Print data in CSV format
    for (int i = 0; i < symbol_table->sym_tbl_entry.size(); i++) {
        std::cout << i << ",";
        std::cout << symbol_table->sym_tbl_entry[i].name << ",";
        std::cout << symbol_table->sym_tbl_entry[i].type << ",";
        std::cout << symbol_table->sym_tbl_entry[i].line_no << ",";
        std::cout << symbol_table->sym_tbl_entry[i].is_func << ",";
        std::cout << symbol_table->sym_tbl_entry[i].size << ",";
        std::cout << symbol_table->sym_tbl_entry[i].offset << std::endl;
        if(symbol_table->sym_tbl_entry[i].sub_symbol_table!=NULL){
            cout << "-----------sub table start-----------" << endl;
            print_sym_table(symbol_table->sym_tbl_entry[i].sub_symbol_table);
            cout << "-----------sub table end-----------" << endl;
        }
    }
}

void delete_sym_table(sym_table * symbol_table, string name){
   for(int i=0;i<symbol_table->sym_tbl_entry.size();i++){
       if(symbol_table->sym_tbl_entry[i].name == name){
           symbol_table->sym_tbl_entry.erase(symbol_table->sym_tbl_entry.begin()+i);
           return;
       }
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