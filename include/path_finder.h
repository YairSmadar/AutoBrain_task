#ifndef UNTITLED_PATH_FINDER_H
#define UNTITLED_PATH_FINDER_H

#include <stdbool.h>

typedef unsigned long uint32_t;

extern uint32_t max_num_of_edges;

typedef struct
{
    uint32_t* traversed_path;
    uint32_t traversed_path_size;
} traverseable_path;

bool is_array_traverseable(const uint32_t* input_path, uint32_t input_path_size, traverseable_path* path_output);

void free_traverseable_path(traverseable_path* t_path);

#endif //UNTITLED_PATH_FINDER_H
