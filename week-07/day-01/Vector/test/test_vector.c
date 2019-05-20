#include <stdlib.h>
#include "../src/vector.h"
#include "../vendor/ceedling/vendor/unity/src/unity.h"

void test_init(void)
{
    vector_t myvector;
    init_vector(&myvector);

    TEST_ASSERT_EQUAL(1, myvector.capacity);
    TEST_ASSERT_EQUAL(0, myvector.size);

    free_vector(&myvector);
}

void test_capacity_check(void)
{
    vector_t myvector;
    init_vector(&myvector);

    TEST_ASSERT_EQUAL(0, myvector.size);
    TEST_ASSERT_EQUAL(1, myvector.capacity);

    myvector.size++;
    capacity_check_vector(&myvector);

    TEST_ASSERT_EQUAL(1, myvector.size);
    TEST_ASSERT_EQUAL(2, myvector.capacity);

    myvector.size++;
    capacity_check_vector(&myvector);

    TEST_ASSERT_EQUAL(2, myvector.size);
    TEST_ASSERT_EQUAL(4, myvector.capacity);

    free_vector(&myvector);
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

}