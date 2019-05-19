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



    freeAll(head);

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



    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((head->ptr->data)), (((void *)0)), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((head->ptr->ptr->data)), (((void *)0)), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);



    freeAll(head);

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



    UnityAssertEqualNumber((UNITY_INT)((7)), (UNITY_INT)((head->ptr->ptr->ptr->data)), (((void *)0)), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);



    freeAll(head);

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



    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((result)), (((void *)0)), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);



    freeAll(head);

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



    if (!(result)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(88)));}



    freeAll(head);

}



void test_emptyTrue(void)

{

    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));

    head->data = -1;

    head->ptr = ((void *)0);



    int result = empty(head);



    if ((result)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(101)));};



    freeAll(head);

}



void test_delete(void)

{

    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));

    head->data = -1;

    head->ptr = ((void *)0);





    insertEnd(head, 0);

    insertEnd(head, 5);

    insertBegin(head, 10);

    insertBegin(head, 15);

    insertAfter(head, head->ptr->ptr, 7);



    delete(head);

    int result = size(head);



    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((head->ptr->data)), (((void *)0)), (UNITY_UINT)(122), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((result)), (((void *)0)), (UNITY_UINT)(123), UNITY_DISPLAY_STYLE_INT);



    freeAll(head);

}



void test_deleteValueInListOnce(void)

{

    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));

    head->data = -1;

    head->ptr = ((void *)0);





    insertEnd(head, 0);

    insertEnd(head, 5);

    insertBegin(head, 10);

    insertBegin(head, 15);

    insertAfter(head, head->ptr->ptr, 7);



    int result = deleteValue(head, 7);

    int sizeResult = size(head);



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((result)), (((void *)0)), (UNITY_UINT)(144), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((sizeResult)), (((void *)0)), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_INT);



    freeAll(head);

}



void test_deleteValueInListMultiple(void)

{

    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));

    head->data = -1;

    head->ptr = ((void *)0);





    insertEnd(head, 0);

    insertEnd(head, 5);

    insertBegin(head, 10);

    insertBegin(head, 7);

    insertBegin(head, 15);

    insertAfter(head, head->ptr->ptr, 7);

    insertEnd(head, 7);



    int result = deleteValue(head, 7);

    int sizeResult = size(head);



    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((result)), (((void *)0)), (UNITY_UINT)(168), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((sizeResult)), (((void *)0)), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_INT);



    freeAll(head);

}



void test_deleteValueNotInList(void)

{

    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));

    head->data = -1;

    head->ptr = ((void *)0);





    insertEnd(head, 0);

    insertEnd(head, 5);

    insertBegin(head, 10);

    insertBegin(head, 7);

    insertBegin(head, 15);

    insertAfter(head, head->ptr->ptr, 7);

    insertEnd(head, 7);



    int result = deleteValue(head, 8);

    int sizeResult = size(head);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((result)), (((void *)0)), (UNITY_UINT)(192), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((7)), (UNITY_INT)((sizeResult)), (((void *)0)), (UNITY_UINT)(193), UNITY_DISPLAY_STYLE_INT);



    freeAll(head);

}



void test_search(void)

{

    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));

    head->data = -1;

    head->ptr = ((void *)0);





    insertEnd(head, 0);

    insertEnd(head, 5);

    insertBegin(head, 10);

    insertBegin(head, 7);

    insertBegin(head, 15);

    insertAfter(head, head->ptr->ptr, 7);

    insertEnd(head, 7);







    UnityAssertEqualNumber((UNITY_INT)((head->ptr->ptr->ptr->ptr->data)), (UNITY_INT)((search(head, 10)->data)), (((void *)0)), (UNITY_UINT)(215), UNITY_DISPLAY_STYLE_INT);



    freeAll(head);

}
