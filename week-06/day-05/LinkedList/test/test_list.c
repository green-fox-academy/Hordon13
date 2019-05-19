#include <stdlib.h>
#include "../src/list.h"
#include "../vendor/ceedling/vendor/unity/src/unity.h"

void test_insertEnd(void)
{
    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    head->data = -1;
    head->ptr = NULL;

    insertEnd(head, 0);
    insertEnd(head, 5);

    TEST_ASSERT_EQUAL(0, head->ptr->data);
    TEST_ASSERT_EQUAL(5, head->ptr->ptr->data);
}

void test_insertBegin(void)
{
    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    head->data = -1;
    head->ptr = NULL;

    insertEnd(head, 0);
    insertEnd(head, 5);
    insertBegin(head, 5);
    insertBegin(head, 3);

    TEST_ASSERT_EQUAL(3, head->ptr->data);
    TEST_ASSERT_EQUAL(5, head->ptr->ptr->data);
}

void test_insertAfter(void)
{
    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    head->data = -1;
    head->ptr = NULL;

    insertEnd(head, 0);
    insertEnd(head, 5);
    insertBegin(head, 10);
    insertBegin(head, 15);

    insertAfter(head, head->ptr->ptr, 7);

    TEST_ASSERT_EQUAL(7, head->ptr->ptr->ptr->data);
}

void test_size(void)
{
    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    head->data = -1;
    head->ptr = NULL;

    insertEnd(head, 0);
    insertEnd(head, 5);
    insertBegin(head, 10);
    insertBegin(head, 15);
    insertAfter(head, head->ptr->ptr, 7);

    int result = size(head);

    TEST_ASSERT_EQUAL(5, result);
}

void test_emptyFalse(void)
{
    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    head->data = -1;
    head->ptr = NULL;

    insertEnd(head, 0);
    insertEnd(head, 5);
    insertBegin(head, 10);
    insertBegin(head, 15);
    insertAfter(head, head->ptr->ptr, 7);

    int result = empty(head);

    TEST_ASSERT_FALSE(result)
}

void test_emptyTrue(void)
{
    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    head->data = -1;
    head->ptr = NULL;

    int result = empty(head);

    TEST_ASSERT_TRUE(result);
}

void test_delete(void)
{
    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    head->data = -1;
    head->ptr = NULL;

    //15, 10, 7, 0, 5
    insertEnd(head, 0);
    insertEnd(head, 5);
    insertBegin(head, 10);
    insertBegin(head, 15);
    insertAfter(head, head->ptr->ptr, 7);

    delete(head);
    int result = size(head);

    TEST_ASSERT_EQUAL(10, head->ptr->data);
    TEST_ASSERT_EQUAL(4, result);
}

void test_deleteValueInListOnce(void)
{
    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    head->data = -1;
    head->ptr = NULL;

    //15, 10, 7, 0, 5
    insertEnd(head, 0);
    insertEnd(head, 5);
    insertBegin(head, 10);
    insertBegin(head, 15);
    insertAfter(head, head->ptr->ptr, 7);

    int result = deleteValue(head, 7);
    int sizeResult = size(head);

    TEST_ASSERT_EQUAL(1, result);
    TEST_ASSERT_EQUAL(4, sizeResult);
}

void test_deleteValueInListMultiple(void)
{
    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    head->data = -1;
    head->ptr = NULL;

    //15, 7, 7, 10, 0, 5, 7
    insertEnd(head, 0);
    insertEnd(head, 5);
    insertBegin(head, 10);
    insertBegin(head, 7);
    insertBegin(head, 15);
    insertAfter(head, head->ptr->ptr, 7);
    insertEnd(head, 7);

    int result = deleteValue(head, 7);
    int sizeResult = size(head);

    TEST_ASSERT_EQUAL(3, result);
    TEST_ASSERT_EQUAL(4, sizeResult);
}

void test_deleteValueNotInList(void)
{
    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    head->data = -1;
    head->ptr = NULL;

    //15, 7, 7, 10, 0, 5, 7
    insertEnd(head, 0);
    insertEnd(head, 5);
    insertBegin(head, 10);
    insertBegin(head, 7);
    insertBegin(head, 15);
    insertAfter(head, head->ptr->ptr, 7);
    insertEnd(head, 7);

    int result = deleteValue(head, 8);
    int sizeResult = size(head);

    TEST_ASSERT_EQUAL(0, result);
    TEST_ASSERT_EQUAL(7, sizeResult);
}
