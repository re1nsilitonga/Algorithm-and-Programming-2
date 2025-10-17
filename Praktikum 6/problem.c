/* File: problem.c */
/* Implementasi fungsi untuk membalik linked list */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk membalik linked list secara in-place
 * I.S. l terdefinisi, mungkin kosong
 * F.S. Elemen-elemen dalam list l dibalik urutannya
 *
 * Contoh:
 * Jika l adalah [1,2,3,4,5], maka setelah reverseList(&l), l menjadi [5,4,3,2,1]
 * Jika l adalah [], maka setelah reverseList(&l), l tetap []
 * Jika l adalah [1], maka setelah reverseList(&l), l tetap [1]
 *
 * Hint: Gunakan 3 pointer (prev, current, next) untuk membalik arah pointer
 *       Jangan lupa update FIRST(l) di akhir!
 */
void reverseList(List *l)
{
    Address current, prev, next;
    current = FIRST(*l);
    prev = NULL;
    if (!isEmpty(*l))
    {
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        FIRST(*l) = prev;
    }
}
