

#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int id;
    char * lexeme;
    char* val;
    bool is_terminal;
    string type_of_node;
    vector<struct node*> children;
}NODE;

NODE* create_node(int n_args, ...);

#endif // NODE_H