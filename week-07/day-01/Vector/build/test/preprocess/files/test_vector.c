#include "build/temp/_test_vector.c"
#include "../vendor/ceedling/vendor/unity/src/unity.h"
#include "../src/vector.h"


void test_init(void)

{

    vector_t myvector;

    init_vector(&myvector);



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((myvector.capacity)), (((void *)0)), (UNITY_UINT)(10), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((myvector.size)), (((void *)0)), (UNITY_UINT)(11), UNITY_DISPLAY_STYLE_INT);



    free_vector(&myvector);

}



void test_capacity_check(void)

{

    vector_t myvector;

    init_vector(&myvector);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((myvector.size)), (((void *)0)), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((myvector.capacity)), (((void *)0)), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);



    myvector.size++;

    capacity_check_vector(&myvector);



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((myvector.size)), (((void *)0)), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((myvector.capacity)), (((void *)0)), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);



    myvector.size++;

    capacity_check_vector(&myvector);



    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((myvector.size)), (((void *)0)), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((myvector.capacity)), (((void *)0)), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);



    free_vector(&myvector);

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



}
