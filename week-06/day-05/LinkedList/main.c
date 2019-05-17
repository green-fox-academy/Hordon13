#include <stdio.h>
#include <stdlib.h>
#include "src/list.h"

int main()
{
    lnkd_list_t *head = (lnkd_list_t *) malloc(sizeof(lnkd_list_t));
    head->data = -1;
    head->ptr = NULL;

    insertEnd(head, 0);
    insertEnd(head, 1);
    printf("%d", head->ptr->ptr->data);

    return 0;
}