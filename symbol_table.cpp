#include <bits/stdc++.h>
using namespace::std;

typedef struct st_node {
    string name;
    string type; //return type in case of a function
    int line_no;
    int sp_type;
    int size;
    int offset;
    struct sym_table* sub_symbol_table;
} st_node;

typedef struct sym_table {
    string name;
    int parameter_count;
    int total_offset = 0;
    string return_type;
    sym_table * prev_sym_table;
    vector<st_node> sym_tbl_entry; //this will contain entries of sym_table
    vector<st_node> parameters; //this will contain entries of parameters
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
    //if the first 4 chars are "list" calcualte size of "list[int]"
    else if(s.substr(0,4)=="list"){
        int start = s.find("[");
        int end = s.find("]");
        string type = s.substr(start+1,end-start-1);
        return  get_type_size(type);
    }
    else{
        return 4; //string size is also returned 4
    }
    
}

void create_entry(sym_table * curr_sym_tbl,string name, string type, int line_no, int sp_type, sym_table * sub_symbol_table=NULL){
    st_node new_entry;
    new_entry.name = name;
    new_entry.type = type;
    new_entry.line_no = line_no;
    new_entry.sp_type = sp_type;
    new_entry.size = get_type_size(type);
    new_entry.offset = curr_sym_tbl->total_offset;
    curr_sym_tbl->total_offset+=new_entry.size;
    new_entry.sub_symbol_table = sub_symbol_table;
    if(sub_symbol_table!=NULL)
    {
        new_entry.sub_symbol_table->prev_sym_table=curr_sym_tbl;
        new_entry.sub_symbol_table->total_offset=0;  
        new_entry.sub_symbol_table->name=name;  
    }
    curr_sym_tbl->sym_tbl_entry.push_back(new_entry);
}

int search_sym_table(sym_table * symbol_table,string name, int sp_type){
    sym_table * curr = symbol_table;
    while(curr!=NULL){
        for(int i=0;i<curr->parameters.size();i++){
            if(curr->parameters[i].name == name){
                return 1;
            }
        }
        for(int i=0;i<curr->sym_tbl_entry.size();i++){
            if(curr->sym_tbl_entry[i].name == name){
                return 1;
            }
        }

        curr = curr->prev_sym_table;
    }

    return 0;
}

string search_type_in_sym_table(sym_table * symbol_table,string name){
    sym_table * curr = symbol_table;
    while(curr!=NULL){
        for(int i=0;i<curr->parameters.size();i++){
            if(curr->parameters[i].name == name){
                return curr->parameters[i].type;
            }
        }
        for(int i=0;i<curr->sym_tbl_entry.size();i++){
            if(curr->sym_tbl_entry[i].name == name){
                return curr->sym_tbl_entry[i].type;
            }
        }
        curr = curr->prev_sym_table;
    }

    return "NULL";
}

void add_to_vector(vector<st_node>&v, string name, string type, int line_no){
    st_node new_entry;
    new_entry.name = name;
    new_entry.type = type;
    new_entry.line_no = line_no;
    v.push_back(new_entry);
}

void add_parameters(sym_table * symbol_table, vector<st_node>&v){
   for(int i=0;i<v.size();i++){
        v[i].offset = symbol_table->total_offset;
        v[i].size = get_type_size(v[i].type);
        symbol_table->total_offset+=v[i].size;
        v[i].sp_type = 0;
       symbol_table->parameters.push_back(v[i]);
    }
    symbol_table->parameter_count = v.size();
}

void print_sym_table(sym_table * symbol_table){
    
     cout << "entry_no,name,type,line_no,sp_type,size,offset" << endl;
    //print all parameters
    cout<<"symbol table name: "<<symbol_table->name<<endl;
    cout<<"parameters start-------"<<endl;
    for (int i = 0; i < symbol_table->parameters.size(); i++) {
        cout << i << ",";
        cout << symbol_table->parameters[i].name << ",";
        cout << symbol_table->parameters[i].type << ",";
        cout << symbol_table->parameters[i].line_no << ",";
        cout << symbol_table->parameters[i].sp_type << ",";
        cout << symbol_table->parameters[i].size << ",";
        cout << symbol_table->parameters[i].offset << endl;
    }
    cout << "parameters end-------" << endl;
    // Print data in CSV format
    for (int i = 0; i < symbol_table->sym_tbl_entry.size(); i++) {
        cout << i << ",";
        cout << symbol_table->sym_tbl_entry[i].name << ",";
        cout << symbol_table->sym_tbl_entry[i].type << ",";
        cout << symbol_table->sym_tbl_entry[i].line_no << ",";
        cout << symbol_table->sym_tbl_entry[i].sp_type << ",";
        cout << symbol_table->sym_tbl_entry[i].size << ",";
        cout << symbol_table->sym_tbl_entry[i].offset <<endl;
        if(symbol_table->sym_tbl_entry[i].sub_symbol_table!=NULL){
            cout << "-----------sub table with name start-----------" << endl;
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