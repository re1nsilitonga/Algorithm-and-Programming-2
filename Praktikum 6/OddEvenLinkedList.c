/* File: problem.c */
/* Implementasi fungsi untuk menyusun ulang linked list berdasarkan idx ganjil dan genap */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk menyusun ulang elemen-elemen linked list sehingga
 * semua elemen pada idx ganjil (1, 3, 5, ...) muncul lebih dulu,
 * diikuti oleh elemen pada idx genap (2, 4, 6, ...).
 * Urutan relatif antar elemen ganjil maupun antar elemen genap
 * harus tetap dipertahankan.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : Elemen-elemen dalam list l diubah urutannya secara in-place
 *          tanpa alokasi/dealokasi node baru.
 *
 * Contoh:
 * Jika l adalah [1,2,3,4,5], maka setelah oddEvenLinkedList(&l), l menjadi [1,3,5,2,4]
 * Jika l adalah [10,20,30,40,50,60], maka hasilnya [10,30,50,20,40,60]
 * Jika l adalah [7], maka tetap [7]
 * Jika l adalah [], maka tetap []

*/
boolean isEmpty(List l)
{
    return (FIRST(l) == NULL);
}

void oddEvenLinkedList(List *l)
{
    if (isEmpty(*l))
        return;

    Address headGanjil = NULL, tailGanjil = NULL;
    Address headGenap = NULL, tailGenap = NULL;
    Address current = FIRST(*l);
    int idx = 1;

    while (current != NULL)
    {
        if (idx % 2 == 1)
        {
            if (headGanjil == NULL)
            {
                headGanjil = current;
                tailGanjil = current;
            }
            else
            {
                NEXT(tailGanjil) = current;
                tailGanjil = current;
            }
        }
        else
        {
            if (headGenap == NULL)
            {
                headGenap = current;
                tailGenap = current;
            }
            else
            {
                NEXT(tailGenap) = current;
                tailGenap = current;
            }
        }

        current = current->next;
        idx++;
    }

    if (tailGanjil != NULL)
    {
        NEXT(tailGanjil) = headGenap;
    }
    if (tailGenap != NULL)
    {
        NEXT(tailGenap) = NULL;
    }

    FIRST(*l) = headGanjil;
}