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

// -------------------- //

void push_back_vector(vector_t *vector, int value);

void insert_vector(vector_t *vector, int value, int index);

int size_vector(vector_t *vector);

int capacity_vector(vector_t *vector);

int empty_vector(vector_t *vector);

void pop_back_vector(vector_t *vector);

void deleteIndex_vector(vector_t *vector, int index);

int search_vector(vector_t *vector, int value);

void shuffle_vector(vector_t *vector);

void unique_vector(vector_t *vector);

#endif
