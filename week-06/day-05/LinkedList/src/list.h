#ifndef LINKEDLIST_MATHFUNCT_H
#define LINKEDLIST_MATHFUNCT_H

typedef struct lnkd_list_t {
    int data;
    struct lnkd_list_t *ptr;
} lnkd_list_t;

void freeAll(lnkd_list_t *head);

void insertEnd(lnkd_list_t *head, int data);

void insertBegin(lnkd_list_t *head, int data);

void insertAfter(lnkd_list_t *head, lnkd_list_t *point, int data);

int size(lnkd_list_t *head);

int empty(lnkd_list_t *head);

void delete(lnkd_list_t *head);

int deleteValue(lnkd_list_t *head, int value);

lnkd_list_t *search(lnkd_list_t *head, int value);

#endif
