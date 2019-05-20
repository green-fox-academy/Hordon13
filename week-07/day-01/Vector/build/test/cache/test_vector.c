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
