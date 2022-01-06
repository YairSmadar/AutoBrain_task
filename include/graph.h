#ifndef AUTOBRAIN_GRAPH_H
#define AUTOBRAIN_GRAPH_H

#include "node.h"
typedef unsigned long uint32_t;

// Data structure to store a graph edge
typedef struct
{
    int numVertices;
    node** adj_lists;
    int* visited;
} Graph;

// Creating a graph
Graph* init_graph(uint32_t num_of_vertices);
void add_edge(Graph* graph, int src, int dest);

// Function to print adjacency list representation of a graph
void print_graph(Graph* graph);

// free all allocations
void free_graph(Graph* graph);

#endif //AUTOBRAIN_GRAPH_H
