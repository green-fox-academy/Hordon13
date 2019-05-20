#include <stdio.h>
#include "src/vector.h"

int main()
{
    vector_t myVector;
    init_vector(&myVector);

    push_back(&myVector, 2);
    push_back(&myVector, 5);
    push_back(&myVector, 10);
    push_back(&myVector, 15);

    insert(&myVector, 7, 4);
    return 0;
}