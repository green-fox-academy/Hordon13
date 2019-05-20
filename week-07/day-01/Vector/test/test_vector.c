#include <stdlib.h>
#include "../src/vector.h"
#include "../vendor/ceedling/vendor/unity/src/unity.h"

void test_init(void)
{
    vector_t myVector;
    init_vector(&myVector);

    TEST_ASSERT_EQUAL(1, myVector.capacity);
    TEST_ASSERT_EQUAL(0, myVector.size);

    free_vector(&myVector);
}

void test_capacity_check(void)
{
    vector_t myVector;
    init_vector(&myVector);

    TEST_ASSERT_EQUAL(0, myVector.size);
    TEST_ASSERT_EQUAL(1, myVector.capacity);

    myVector.size++;
    capacity_check_vector(&myVector);

    TEST_ASSERT_EQUAL(1, myVector.size);
    TEST_ASSERT_EQUAL(2, myVector.capacity);

    myVector.size++;
    capacity_check_vector(&myVector);

    TEST_ASSERT_EQUAL(2, myVector.size);
    TEST_ASSERT_EQUAL(4, myVector.capacity);

    free_vector(&myVector);
}

void test_push_back(void)
{
    vector_t myVector;
    init_vector(&myVector);

    push_back(&myVector, 10);

    TEST_ASSERT_EQUAL(10, myVector.data[0]);
    TEST_ASSERT_EQUAL(1, myVector.size);
    TEST_ASSERT_EQUAL(1, myVector.capacity);

    push_back(&myVector, 3);

    TEST_ASSERT_EQUAL(10, myVector.data[0]);
    TEST_ASSERT_EQUAL(3, myVector.data[1]);
    TEST_ASSERT_EQUAL(2, myVector.size);
    TEST_ASSERT_EQUAL(2, myVector.capacity);

    free_vector(&myVector);
}

void test_insert(void)
{
    vector_t myVector;
    init_vector(&myVector);

    push_back(&myVector, 2);
    push_back(&myVector, 5);
    push_back(&myVector, 10);
    push_back(&myVector, 15);

    TEST_ASSERT_EQUAL(4, myVector.capacity);
    TEST_ASSERT_EQUAL(4, myVector.size);

    insert(&myVector, 7, 2);

    TEST_ASSERT_EQUAL(7, myVector.data[2]);
    TEST_ASSERT_EQUAL(10, myVector.data[3]);
    TEST_ASSERT_EQUAL(15, myVector.data[4]);

    TEST_ASSERT_EQUAL(8, myVector.capacity);
    TEST_ASSERT_EQUAL(5, myVector.size);

    insert(&myVector, 23, 4);

    TEST_ASSERT_EQUAL(23, myVector.data[4]);
    TEST_ASSERT_EQUAL(15, myVector.data[5]);

    TEST_ASSERT_EQUAL(8, myVector.capacity);
    TEST_ASSERT_EQUAL(6, myVector.size);

    free_vector(&myVector);
}

void test_insertInvalid(void)
{
    vector_t myVector;
    init_vector(&myVector);

    push_back(&myVector, 2);
    push_back(&myVector, 5);
    push_back(&myVector, 10);
    push_back(&myVector, 15);

    TEST_ASSERT_EQUAL(4, myVector.capacity);
    TEST_ASSERT_EQUAL(4, myVector.size);

    insert(&myVector, 7, 4);

    TEST_ASSERT_EQUAL(4, myVector.capacity);
    TEST_ASSERT_EQUAL(4, myVector.size);

    free_vector(&myVector);
}

void test_size(void)
{
    vector_t myVector;
    init_vector(&myVector);

    push_back(&myVector, 2);
    push_back(&myVector, 5);
    push_back(&myVector, 10);

    int size = size_vector(&myVector);

    TEST_ASSERT_EQUAL(3, size);

    free_vector(&myVector);
}

void test_capacity(void)
{
    vector_t myVector;
    init_vector(&myVector);

    push_back(&myVector, 2);
    push_back(&myVector, 5);
    push_back(&myVector, 10);

    int capacity = capacity_vector(&myVector);

    TEST_ASSERT_EQUAL(1, capacity);

    free_vector(&myVector);
}

void test_empty(void)
{
    vector_t myVector;
    init_vector(&myVector);

    int empty = empty_vector(&myVector);

    TEST_ASSERT_TRUE(empty)

    push_back(&myVector, 2);

    int empty2 = empty_vector(&myVector);

    TEST_ASSERT_FALSE(empty2)

    free_vector(&myVector);
}

void test_pop_back(void)
{
    vector_t myVector;
    init_vector(&myVector);

    push_back(&myVector, 1);
    push_back(&myVector, 2);
    push_back(&myVector, 3);
    push_back(&myVector, 4);
    push_back(&myVector, 5);

    TEST_ASSERT_EQUAL(5, size_vector(&myVector));
    TEST_ASSERT_EQUAL(8, myVector.capacity);

    pop_back(&myVector);

    TEST_ASSERT_EQUAL(4, myVector.data[3]);
    TEST_ASSERT_EQUAL(4, size_vector(&myVector));
    TEST_ASSERT_EQUAL(6, myVector.capacity);

    free_vector(&myVector);
}

void test_deleteIndex(void)
{
    vector_t myVector;
    init_vector(&myVector);

    push_back(&myVector, 1);
    push_back(&myVector, 2);
    push_back(&myVector, 3);
    push_back(&myVector, 4);
    push_back(&myVector, 5);

    TEST_ASSERT_EQUAL(3, myVector.data[2]);
    TEST_ASSERT_EQUAL(5, size_vector(&myVector));
    TEST_ASSERT_EQUAL(8, myVector.capacity);

    deleteIndex(&myVector, 2);

    TEST_ASSERT_EQUAL(4, myVector.data[2]);
    TEST_ASSERT_EQUAL(4, size_vector(&myVector));
    TEST_ASSERT_EQUAL(6, myVector.capacity);

    free_vector(&myVector);
}

void test_search(void)
{
    vector_t myVector;
    init_vector(&myVector);

    push_back(&myVector, 1);
    push_back(&myVector, 2);
    push_back(&myVector, 3);
    push_back(&myVector, 4);
    push_back(&myVector, 5);

    int index = search_vector(&myVector, 4);

    TEST_ASSERT_EQUAL(3, index);

    int index2 = search_vector(&myVector, 7);

    TEST_ASSERT_EQUAL(-1, index2);

    free_vector(&myVector);
}

