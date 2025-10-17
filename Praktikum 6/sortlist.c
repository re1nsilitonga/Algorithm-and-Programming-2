#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Fungsi yang melakukan pengurutan dengan urutan menaik jika asc = true
 * dan menurun jika asc = false
 *
 * I.S. List l terdefinisi dan berisi setidaknya 1 elemen
 * F.S. List l terurut secara urutan tertentu
 *
 * Contoh:
 * - Untuk l = [1, 5, 2, 3, 3], maka setelah sort(&l, true), l menjadi [1, 2, 3, 3, 5]
 */

void sort(List *l, boolean asc)
{
    if (isEmpty(*l) || NEXT(FIRST(*l)) == NULL)
        return;

    boolean swapped;
    Address current;
    Address last = NULL;

    do
    {
        swapped = false;
        current = FIRST(*l);

        while (NEXT(current) != last)
        {
            boolean shouldSwap = false;

            if (asc)
            {
                shouldSwap = INFO(current) > INFO(NEXT(current));
            }
            else
            {
                shouldSwap = INFO(current) < INFO(NEXT(current));
            }

            if (shouldSwap)
            {
                int temp = INFO(current);
                INFO(current) = INFO(NEXT(current));
                INFO(NEXT(current)) = temp;
                swapped = true;
            }
            current = NEXT(current);
        }
        last = current;
    } while (swapped);
}