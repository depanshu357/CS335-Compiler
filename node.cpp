#include "node.h"
#include <cstdarg>
#include <bits/stdc++.h>


int num=0;

NODE* create_node(int n_args, ...)
{
    NODE *element = (NODE *)calloc(1, sizeof(NODE));
    element->id=num++;
    element->is_terminal = false;
    element->type_of_node="undefined";
    element->addr="undefined";
    element->ins=0;
    element->residual_ins="undefined";
    element->size = -1;
    NODE*child;
    va_list valist;
    va_start(valist, n_args); 
    element->val = strdup(va_arg(valist, const char*));
    for (int i = 1; i < n_args; i++) {
        child = va_arg(valist, NODE*);
        element->children.push_back(child);
    }
    va_end(valist);

    return element;
}
