#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

void sort(List *l, boolean asc)
{
    Address p, prev, next;
    p = FIRST(*l);
    if (asc == true)
    {
        while (p != NULL)
        {
            if (prev != NULL)
            {
                if (p < prev)
                {
                    next = p->next;
                    p->next = prev;
                    prev = p;
                }
            }
            else
            {
                prev = p;
            }

            p = p->next;
        }
    }
    else
    {
        while (p != NULL)
        {
            if (p != FIRST(*l))
            {
                if (p > prev)
                {
                    next = p->next;
                    p->next = prev;
                    prev = p;
                }
            }
            else
            {
                prev = p;
            }

            p = p->next;
        }
    }
}

void main()
{
    List l;
    CreateList(&l);

    int arr1[] = {19, 1, 2, 3, 4, 5};
    for (int i = 0; i < 6; i++)
    {
        insertLast(&l, arr1[i]);
    }
    printf("Before: ");
    displayList(l);
    sort(&l, true);
    printf("After: ");
    displayList(l);

    Address temp;
    while (FIRST(l) != NULL)
    {
        temp = FIRST(l);
        FIRST(l) = NEXT(FIRST(l));
        free(temp);
    }
}