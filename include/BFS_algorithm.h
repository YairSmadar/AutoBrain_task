//
// Created by yair.semama on 04/01/2022.
//

#ifndef AUTOBRAIN_BFS_ALGORITHM_H
#define AUTOBRAIN_BFS_ALGORITHM_H

#include "graph.h"

bool bfs(Graph* graph, int startVertex, uint32_t goal, traverseable_path* path_output);

#endif //AUTOBRAIN_BFS_ALGORITHM_H
