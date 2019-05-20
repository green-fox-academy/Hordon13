#include <stdio.h>
#include <stdlib.h>
#include "src/vector.h"

int main()
{
    vector_t myVector;
    init_vector(&myVector);

    push_back_vector(&myVector, 1);
    push_back_vector(&myVector, 1);
    push_back_vector(&myVector, 2);
    push_back_vector(&myVector, 2);
    push_back_vector(&myVector, 3);
    push_back_vector(&myVector, 3);
    push_back_vector(&myVector, 4);
    push_back_vector(&myVector, 4);
    push_back_vector(&myVector, 5);
    push_back_vector(&myVector, 5);

    shuffle_vector(&myVector);
    unique_vector(&myVector);

    for (int i = 0; i < myVector.size; ++i) {
        printf("%d", myVector.data[i]);
    }

    free_vector(&myVector);

    return 0;
}