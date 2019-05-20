#include "vector.h"
#include <stdlib.h>

void init_vector(vector_t *vector)
{
    vector->size = 0;
    vector->capacity = 1;
    vector->data = (int *) malloc(sizeof(int) * vector->capacity);
}

void free_vector(vector_t *vector)
{
    free(vector->data);
}

void capacity_check_vector(vector_t *vector)
{
    if (vector->size >= vector->capacity) {
        vector->capacity *= 2;
        vector->data = (int *) realloc(vector->data, sizeof(int) * vector->capacity);
    }
}