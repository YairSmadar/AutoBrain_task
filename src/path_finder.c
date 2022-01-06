#include "../include/path_finder.h"
#include "../include/graph.h"
#include "../include/BFS_algorithm.h"
#include <stdio.h>
#include <stdlib.h>

uint32_t max_num_of_edges = 0;

bool is_array_traverseable(const uint32_t* input_path, uint32_t input_path_size, traverseable_path* path_output)
{
    int i, edge_index;
    bool ans;
    uint32_t jump_to;
    Graph *graph;

    // validate user inputs
    if (input_path == NULL || input_path_size == 0)
        return false;

    // handle spacial case for size = 1
    if (input_path_size == 1)
    {
        path_output->traversed_path_size = 0;
        path_output->traversed_path[0] = input_path[0];

        return true;
    }


    // because each index has 2 possible edges, except for the two in the edges if the array
    max_num_of_edges = input_path_size * 2 - 2;

    graph = init_graph(max_num_of_edges);

    // build the graph
    for (i = 0; i < input_path_size; i++)
    {
        jump_to = input_path[i];

        // since it does not make sense to have an edge between node to itself
        if (jump_to == 0)
            continue;

        // check if the index from the top is valid
        edge_index = i + jump_to;
        if (edge_index < input_path_size)
        {
            add_edge(graph, i, edge_index);
        }

        // check if the index from the down is valid
        edge_index = i - jump_to;
        if (edge_index >= 0)
        {
            add_edge(graph, i, edge_index);
        }
    }

    ans = bfs(graph, 0, input_path_size - 1, path_output);

//    print_graph(graph);

    free_graph(graph);

    return ans;
}

// free allocated traverseable_path
void free_traverseable_path(traverseable_path* t_path)
{
    if (t_path != NULL)
    {
        if (t_path->traversed_path != NULL)
        {
            free(t_path->traversed_path);
        }
        free(t_path);
    }
}