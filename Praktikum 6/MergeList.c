#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk menggabungkan nilai-nilai di antara dua node bernilai 0
 * menjadi satu node dengan nilai hasil penjumlahan, dan menghapus seluruh node 0.
 *
 * I.S.  l terdefinisi, berisi minimal tiga elemen, dengan ketentuan:
 *      - Elemen pertama dan terakhir bernilai 0
 *      - Tidak ada dua node 0 yang bersebelahan
 *
 * F.S.  Setiap rentang elemen di antara dua 0 dijumlahkan menjadi satu node baru,
 *       dan list hasil tidak mengandung nilai 0 sama sekali.
 *
 * Contoh:
 * Jika l = [0,3,1,0,4,5,2,0], maka setelah mergeList(&l), l menjadi [4,11]
 * Jika l = [0,1,0,3,0,2,2,0], maka setelah mergeList(&l), l menjadi [1,3,4]
 *
 * Hint:
 * - Gunakan variabel untuk menampung hasil penjumlahan sementara
 * - Jangan lupa update FIRST(l) di akhir!
 */
void mergeList(List *l)
{
    /* KAMUS LOKAL */
    Address p;
    int sum = 0, n;
    n = length(*l);

    /* ALGORITMA */
    p = FIRST(*l);

    while (n != 0)
    {
        if (p->info == 0)
        {
            if (sum != 0)
            {
                insertLast(l, sum);
            }
            sum = 0;
        }
        else
        {
            sum = sum + p->info;
        }

        deleteFirst(l, &p->info);
        p = p->next;
        n--;
    }
}