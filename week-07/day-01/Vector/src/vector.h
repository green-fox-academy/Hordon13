#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

typedef struct vector_t {
    int *data;
    int size;
    int capacity;
} vector_t;

void init_vector(vector_t *vector);

void free_vector(vector_t *vector);

void capacity_check_vector(vector_t *vector);

#endif
