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