#include "../include/graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph* init_graph(uint32_t num_of_vertices)
{
    int i;
    Graph* graph = malloc(sizeof(Graph));

    graph->numVertices = (int)num_of_vertices;

    graph->adj_lists = (node**)malloc(num_of_vertices * sizeof(node*));
    graph->visited = (int*)malloc(num_of_vertices * sizeof(int));

    for (i = 0; i < num_of_vertices; i++)
    {
        graph->adj_lists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void add_edge(Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    node* new_node = init_node(src, dest);
    new_node->next = (struct node*)graph->adj_lists[src];
    graph->adj_lists[src] = new_node;
}

// print all the edges
void print_graph(Graph* graph)
{
    int i;

    for (i = 0; i < 7; i++)
    {
        // print current dest and all its neighbors
        node* ptr = graph->adj_lists[i];
        while (ptr != NULL)
        {
            printf("(%d -> %d)\t", i, ptr->dest);
            ptr = (node*)ptr->next;
        }

        printf("\n");
    }
}

// free allocated graph
void free_graph(Graph* graph)
{
    int i;

    if (graph != NULL)
    {
        if (graph->visited != NULL)
            free(graph->visited);

        // free all nodes
        if (graph->adj_lists != NULL)
        {
            for (i = 0; i < graph->numVertices; i++)
            {
                if (graph->adj_lists[i] != NULL)
                {
                    free_node(graph->adj_lists[i]);
                }
            }
            free(graph->adj_lists);
        }

        free(graph);
    }
}

