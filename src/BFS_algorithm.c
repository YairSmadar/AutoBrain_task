//
// Created by yair.semama on 04/01/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "../include/BFS_algorithm.h"
#include "../include/queue.h"

static void my_memcpy(void *dest, void *src, size_t n);

/*
 Breadth-first search (BFS) is an algorithm that is used to graph data or searching tree or traversing structures.
 The algorithm efficiently visits and marks all the key nodes in a graph in an accurate breadth wise fashion.
 This algorithm selects a single node (initial or source point) in a graph and then visits all the nodes adjacent to the selected node.
 Once the algorithm visits and marks the starting node, then it moves towards the nearest unvisited nodes and analyses them.
 Once visited, all nodes are marked. These iterations continue until all the nodes of the graph have been successfully visited and marked.

 I added to the algorithm a part that check if the algorithm reach the goal node. if so - return true.
 If the algorithm finish without reaching the goal node - return false
*/
bool bfs(Graph* graph, int startVertex, uint32_t goal, traverseable_path* path_output)
{
    int current_vertex, adj_vertex;
    uint32_t *temp_vertex_path, temp_vertex_path_len = 0;

    queue* q = create_queue(graph->numVertices);
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q))
    {
        current_vertex = dequeue(q);

        node* temp = graph->adj_lists[current_vertex];

        while (temp)
        {
            adj_vertex = temp->dest;
            if (adj_vertex == goal)
            {
                // add the last to ver`s to the path
                temp_vertex_path[temp_vertex_path_len++] = temp->src;
                temp_vertex_path[temp_vertex_path_len++] = temp->dest;

                // check if user input (path_output) is allocated - if not: allocate it.
                if (path_output == NULL)
                {
                    path_output = (traverseable_path*)malloc(sizeof (traverseable_path));
                    path_output->traversed_path = (uint32_t *)malloc(sizeof (uint32_t) * temp_vertex_path_len);
                }
                else if (path_output->traversed_path == NULL)
                {
                    path_output->traversed_path = (uint32_t *)malloc(sizeof (uint32_t) * temp_vertex_path_len);
                }

                // copy the path and path len to the path_output
                my_memcpy((void*)path_output->traversed_path, (void*)temp_vertex_path, temp_vertex_path_len*sizeof(int));
                path_output->traversed_path_size = temp_vertex_path_len;

                free_queue(q);
                return true;
            }
            if (graph->visited[adj_vertex] == 0)
            {
                // add the path of the last node to the current node path
                my_memcpy(&temp->path.traversed_path[temp->path.traversed_path_size], temp_vertex_path, temp_vertex_path_len*sizeof(int));
                temp->path.traversed_path_size += temp_vertex_path_len;

                graph->visited[adj_vertex] = 1;

                if (temp->path.traversed_path_size == 0 || temp->path.traversed_path[temp->path.traversed_path_size - 1] != temp->src)
                    temp->path.traversed_path[temp->path.traversed_path_size++] = temp->src;

                // keep the path and path len for the next node to use.
                temp_vertex_path = temp->path.traversed_path;
                temp_vertex_path_len = temp->path.traversed_path_size;

                enqueue(q, adj_vertex);
            }

            temp = (node*)temp->next;
        }
    }

    free_queue(q);

    return false;
}

static void my_memcpy(void *dest, void *src, size_t n)
{
    int i;
    // Typecast src and dest addresses to (char *)
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    // Copy contents of src[] to dest[]
    for (i = 0; i < n; i++)
        cdest[i] = csrc[i];
}
