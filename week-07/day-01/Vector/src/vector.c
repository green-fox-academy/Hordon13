#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "vector.h"

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

void push_back_vector(vector_t *vector, int value)
{
    capacity_check_vector(vector);
    vector->data[vector->size] = value;
    vector->size++;
}

void insert_vector(vector_t *vector, int value, int index)
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

void pop_back_vector(vector_t *vector)
{
    vector->data[vector->size - 1] = -1;
    vector->size--;
    capacity_check_vector(vector);
}

void deleteIndex_vector(vector_t *vector, int index)
{
    if (index < vector->size) {
        for (int i = index; i < vector->size - 1; ++i) {
            vector->data[i] = vector->data[i + 1];
        }
        vector->data[vector->size - 1] = -1;
        vector->size--;
        capacity_check_vector(vector);
    } else {
        printf("Delete error: invalid index");
    }
}

int search_vector(vector_t *vector, int value)
{
    for (int i = 0; i < vector->size; ++i) {
        if (vector->data[i] == value) {
            return i;
        }
    }

    return -1;
}

void shuffle_vector(vector_t *vector)
{
    srand(time(NULL));
    vector_t randomNumbers;
    init_vector(&randomNumbers);

    do {
        int random = rand() % vector->size;
        if (search_vector(&randomNumbers, random) == -1) {
            push_back_vector(&randomNumbers, random);
        }
    } while (size_vector(&randomNumbers) != vector->size);

    vector_t temp;
    init_vector(&temp);

    for (int i = 0; i < vector->size; ++i) {
        temp.data[i] = vector->data[randomNumbers.data[i]];
    }

    vector->data = temp.data;

    free_vector(&temp);
    free_vector(&randomNumbers);
}

void unique_vector(vector_t *vector)
{
    vector_t unique;
    init_vector(&unique);

    for (int i = 0; i < vector->size; ++i) {
        if (search_vector(&unique, vector->data[i]) == -1) {
            push_back_vector(&unique, vector->data[i]);
        }
    }

    vector->data = unique.data;
    vector->size = unique.size;
    capacity_check_vector(vector);

    free_vector(&unique);
}

void transform(vector_t *vector, void (*func)(int *))
{
    for (int i = 0; i < vector->size; ++i) {
        func(&(vector->data[i]));
    }
}

// ---------------------- //

void doubleValue(int *num)
{
    *num *= 2;
}