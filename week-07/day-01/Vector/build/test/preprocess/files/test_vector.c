#include "build/temp/_test_vector.c"
#include "../vendor/ceedling/vendor/unity/src/unity.h"
#include "../src/vector.h"


void test_init(void)

{

    vector_t myVector;

    init_vector(&myVector);



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((myVector.capacity)), (((void *)0)), (UNITY_UINT)(10), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((myVector.size)), (((void *)0)), (UNITY_UINT)(11), UNITY_DISPLAY_STYLE_INT);



    free_vector(&myVector);

}



void test_capacity_check(void)

{

    vector_t myVector;

    init_vector(&myVector);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((myVector.size)), (((void *)0)), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((myVector.capacity)), (((void *)0)), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);



    myVector.size++;

    capacity_check_vector(&myVector);



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((myVector.size)), (((void *)0)), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((myVector.capacity)), (((void *)0)), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);



    myVector.size++;

    capacity_check_vector(&myVector);



    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((myVector.size)), (((void *)0)), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((myVector.capacity)), (((void *)0)), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);



    free_vector(&myVector);

}



void test_push_back(void)

{

    vector_t myVector;

    init_vector(&myVector);



    push_back(&myVector, 10);



    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((myVector.data[0])), (((void *)0)), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((myVector.size)), (((void *)0)), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((myVector.capacity)), (((void *)0)), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);



    push_back(&myVector, 3);



    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((myVector.data[0])), (((void *)0)), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((myVector.data[1])), (((void *)0)), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((myVector.size)), (((void *)0)), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((myVector.capacity)), (((void *)0)), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);



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



    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((myVector.capacity)), (((void *)0)), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((myVector.size)), (((void *)0)), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);



    insert(&myVector, 7, 2);



    UnityAssertEqualNumber((UNITY_INT)((7)), (UNITY_INT)((myVector.data[2])), (((void *)0)), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((myVector.data[3])), (((void *)0)), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((myVector.data[4])), (((void *)0)), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);



    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((myVector.capacity)), (((void *)0)), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((myVector.size)), (((void *)0)), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);



    insert(&myVector, 23, 4);



    UnityAssertEqualNumber((UNITY_INT)((23)), (UNITY_INT)((myVector.data[4])), (((void *)0)), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((myVector.data[5])), (((void *)0)), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);



    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((myVector.capacity)), (((void *)0)), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((myVector.size)), (((void *)0)), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);



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



    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((myVector.capacity)), (((void *)0)), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((myVector.size)), (((void *)0)), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_INT);



    insert(&myVector, 7, 4);



    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((myVector.capacity)), (((void *)0)), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((myVector.size)), (((void *)0)), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_INT);



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



    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((size)), (((void *)0)), (UNITY_UINT)(125), UNITY_DISPLAY_STYLE_INT);



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



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((capacity)), (((void *)0)), (UNITY_UINT)(141), UNITY_DISPLAY_STYLE_INT);



    free_vector(&myVector);

}
