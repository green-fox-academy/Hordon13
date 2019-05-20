#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

void init_vector(vector_t *vector)
{
    vector->size = 0;
    vector->capacity = 1;
    vector->data = (int *) malloc(sizeof(int) * vector->capacity);
}

void free_vector(vector_t *vector)
{
    vector->data = NULL;
    free(vector->data);
}

void capacity_check_vector(vector_t *vector)
{
    if (vector->size >= vector->capacity) {
        vector->capacity *= 2;
        vector->data = (int *) realloc(vector->data, sizeof(int) * vector->capacity);
    } else if (vector->size >= 2 && vector->size <= vector->capacity / 2) {
        vector->capacity -= (vector->capacity) / 4;
        vector->data = (int *) realloc(vector->data, sizeof(int) * vector->capacity);
    }
}

void push_back(vector_t *vector, int value)
{
    capacity_check_vector(vector);
    vector->data[vector->size] = value;
    vector->size++;
}

void insert(vector_t *vector, int value, int index)
{
    if (index < vector->size) {
        capacity_check_vector(vector);
        for (int i = vector->size; i > index; --i) {
            vector->data[i] = vector->data[i - 1];
        }
        vector->data[index] = value;
        vector->size++;
    } else {
        printf("Insert error: invalid index");
    }
}

int size_vector(vector_t *vector)
{
    return vector->size;
}

int capacity_vector(vector_t *vector)
{
    return vector->capacity - vector->size;
}

int empty_vector(vector_t *vector)
{
    if (vector->size == 0) {
        return 1;
    }

    return 0;
}

void pop_back(vector_t *vector)
{
    vector->size--;
    capacity_check_vector(vector);
}