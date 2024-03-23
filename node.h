

#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int id;
    char * lexeme;
    char* val;
    bool is_terminal;
    string addr;
    int ins;
    string residual_ins;
    string type_of_node;
    vector<struct node*> children;
    vector<int> truelist;
    vector<int> falselist;
    vector<int> nextlist;
}NODE;

NODE* create_node(int n_args, ...);

#endif // NODE_H