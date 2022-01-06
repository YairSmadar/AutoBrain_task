#include <stdio.h>
#include <stdlib.h>
#include "../include/path_finder.h"
#include "../include/graph.h"

#define NUM_OF_TESTS 5

static void print_arr(uint32_t * arr, uint32_t arr_len);
static void test(uint32_t * arr, uint32_t arr_len, uint32_t* path, int path_len, traverseable_path *path_output);
static bool is_arrays_the_same(const uint32_t *pInt1, uint32_t size1, const uint32_t *pInt2, uint32_t size2);

/*
   arr = input array
   arr_len = array length
   path = output path. if no path exist: path = NULL
   path_len = output path length. if no path exist: path_len = -1
 */
static void test(uint32_t * arr, uint32_t arr_len, uint32_t* path, int path_len, traverseable_path *path_output)
{

    if (is_array_traverseable(arr, arr_len, path_output))
    {
        if (path != NULL && path_len != -1)
        {
            if (is_arrays_the_same(path_output->traversed_path, path_output->traversed_path_size, path, path_len))
            {
                printf("Pass for: ");
            }
            else
            {
                printf("Failed for: ");
            }
        }
        else
        {
            printf("Failed for: ");
        }
    }
    else
    {
        if (path == NULL && path_len == -1)
        {
            printf("Pass for: ");
        }
        else
        {
            printf("Failed for: ");
        }
    }

    print_arr(arr, arr_len);

}

static bool is_arrays_the_same(const uint32_t *pInt1, uint32_t size1, const uint32_t *pInt2, uint32_t size2)
{
    int i;

    if (size1 != size2)
    {
        return false;
    }

    for (i = 0; i < size1; i ++)
    {
        if (pInt1[i] != pInt2[i])
        {
            return false;
        }
    }

    return true;
}

static void print_arr(uint32_t * arr, uint32_t arr_len)
{
    int i;
    for (i = 0; i < arr_len ; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{

    int i;

    /*
     * Init tests!
     */
    traverseable_path *path_output = (traverseable_path*)malloc(sizeof(traverseable_path));
    path_output->traversed_path = NULL;

    uint32_t *input_paths[NUM_OF_TESTS];
    uint32_t *output_paths[NUM_OF_TESTS];

    uint32_t input_path_sizes[NUM_OF_TESTS] = {8, 8, 6, 6, 1};
    int output_path_sizes[NUM_OF_TESTS] = {6, -1, 6, -1, 0};

    // test 0
    uint32_t input_path0[] = {4, 4, 1, 1, 2, 2, 1000, 1};
    uint32_t output_path0[] = {0, 4, 2, 1, 5, 7};
    input_paths[0] = input_path0;
    output_paths[0] = output_path0;

    // test 1
    uint32_t input_path1[] = {4, 2, 1, 3, 2, 2, 1000, 1};
    uint32_t *output_path1 = NULL;
    input_paths[1] = input_path1;
    output_paths[1] = output_path1;

    // test 2
    uint32_t input_path2[] = {1, 1, 1, 1, 1, 1};
    uint32_t output_path2[] = {0, 1, 2, 3, 4, 5};
    input_paths[2] = input_path2;
    output_paths[2] = output_path2;

    // test 3
    uint32_t input_path3[] = {0, 0, 0, 0, 0, 0};
    uint32_t *output_path3 = NULL;
    input_paths[3] = input_path3;
    output_paths[3] = output_path3;

    // test 4
    uint32_t input_path4[] = {1};
    uint32_t output_path4[] = {0};
    input_paths[4] = input_path4;
    output_paths[4] = output_path4;

    /*
     * Run tests!
     */
    for (i = 0; i < NUM_OF_TESTS; i++)
    {
        test(input_paths[i], input_path_sizes[i], output_paths[i], output_path_sizes[i], path_output);
    }

    free_traverseable_path(path_output);

    return 0;
}