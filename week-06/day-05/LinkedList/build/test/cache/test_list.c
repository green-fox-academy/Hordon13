#include "build/temp/_test_list.c"
#include "../vendor/ceedling/vendor/unity/src/unity.h"
#include "../src/list.h"


void test_insertEnd(void)

{

    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));

    head->data = -1;

    head->ptr = ((void *)0);



    insertEnd(head, 0);

    insertEnd(head, 5);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((head->ptr->data)), (((void *)0)), (UNITY_UINT)(14), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((head->ptr->ptr->data)), (((void *)0)), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_INT);

}



void test_insertBegin(void)

{

    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));

    head->data = -1;

    head->ptr = ((void *)0);



    insertEnd(head, 0);

    insertEnd(head, 5);

    insertBegin(head, 5);

    insertBegin(head, 3);



    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((head->ptr->data)), (((void *)0)), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((head->ptr->ptr->data)), (((void *)0)), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

}



void test_insertAfter(void)

{

    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));

    head->data = -1;

    head->ptr = ((void *)0);



    insertEnd(head, 0);

    insertEnd(head, 5);

    insertBegin(head, 10);

    insertBegin(head, 15);



    insertAfter(head, head->ptr->ptr, 7);



    UnityAssertEqualNumber((UNITY_INT)((7)), (UNITY_INT)((head->ptr->ptr->ptr->data)), (((void *)0)), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);

}



void test_size(void)

{

    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));

    head->data = -1;

    head->ptr = ((void *)0);



    insertEnd(head, 0);

    insertEnd(head, 5);

    insertBegin(head, 10);

    insertBegin(head, 15);

    insertAfter(head, head->ptr->ptr, 7);



    int result = size(head);



    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((result)), (((void *)0)), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

}



void test_emptyFalse(void)

{

    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));

    head->data = -1;

    head->ptr = ((void *)0);



    insertEnd(head, 0);

    insertEnd(head, 5);

    insertBegin(head, 10);

    insertBegin(head, 15);

    insertAfter(head, head->ptr->ptr, 7);



    int result = empty(head);



    if (!(result)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(80)));}

}



void test_emptyTrue(void)

{

    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));

    head->data = -1;

    head->ptr = ((void *)0);



    int result = empty(head);



    if ((result)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(91)));};

}
