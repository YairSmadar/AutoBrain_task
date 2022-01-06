#ifndef AUTOBRAIN_NODE_H
#define AUTOBRAIN_NODE_H

#include "path_finder.h"
// Data structure to store adjacency list nodes of the graph

typedef struct
{
    int dest;
    int src;
    struct node* next;
    traverseable_path path;
} node;

node* init_node(int src, int dest);
void free_node(node* n);

#endif //AUTOBRAIN_NODE_H
