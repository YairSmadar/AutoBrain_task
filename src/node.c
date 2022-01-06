#include "../include/node.h"
#include <stdio.h>
#include <stdlib.h>

// Creating a node
node* init_node(int src, int dest)
{
    node* new_node = malloc(sizeof(node));
    new_node->dest = dest;
    new_node->src = src;
    new_node->next = NULL;
    new_node->path.traversed_path_size = 0;
    new_node->path.traversed_path = (uint32_t*)malloc(sizeof(uint32_t) * max_num_of_edges);

    return new_node;
}

void free_node(node* n)
{
    node *temp_n;

    while (n != NULL)
    {
        temp_n = n;
        n  = (node *) n->next;
        if (temp_n->path.traversed_path != NULL)
            free(temp_n->path.traversed_path);
        free(temp_n);
    }
}
