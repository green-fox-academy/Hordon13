#include "list.h"
#include <stdlib.h>

void insertEnd(lnkd_list_t *head, int data)
{
    lnkd_list_t *newNode = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    newNode->data = data;
    newNode->ptr = NULL;

    lnkd_list_t *it = head;
    while (it->ptr != NULL) {
        it = it->ptr;
    }

    it->ptr = newNode;
}

void insertBegin(lnkd_list_t *head, int data)
{
    lnkd_list_t *newNode = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    newNode->data = data;
    newNode->ptr = head->ptr;

    head->ptr = newNode;
}

void insertAfter(lnkd_list_t *head, lnkd_list_t *point, int data)
{
    lnkd_list_t *newNode = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    newNode->data = data;
    newNode->ptr = point->ptr;
    point->ptr = newNode;

    lnkd_list_t *it = head;
    while (it->ptr != point) {
        it = it->ptr;
    }
}

int size(lnkd_list_t *head)
{
    int size = 0;
    lnkd_list_t *it = head;
    while (it->ptr != NULL) {
        it = it->ptr;
        size++;
    }

    return size;
}

int empty(lnkd_list_t *head)
{
    int sizeOf = size(head);
    if (sizeOf != 0) {
        return 0;
    }

    return 1;
}