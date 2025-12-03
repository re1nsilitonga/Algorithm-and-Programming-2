/* File: problem.c */
/* Implementasi fungsi Binary Search Tree (BST) */

#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

/* ============================================== */
/* TODO: Implementasi di bawah ini ====== */
/* ============================================== */

/*
 * Fungsi untuk mengalokasikan node baru dengan info X
 * I.S. X terdefinisi
 * F.S. Mengembalikan address node baru dengan info X, left dan right NULL
 *      Mengembalikan NULL jika alokasi gagal
 *
 * Contoh:
 * newTreeNode(5) -> node dengan info=5, left=NULL, right=NULL
 */
Address newTreeNode(ElType X)
{
    /* KAMUS LOKAL */
    Address p;

    /* ALGORITMA */
    p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        ROOT(p) = X;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

/*
 * Prosedur untuk membuat pohon BST kosong
 * I.S. T sembarang
 * F.S. T menjadi pohon kosong (T = NULL)
 */
void CreateTree(BinTree *T)
{
    /* ALGORITMA */
    *T = NULL;
}

/*
 * Fungsi untuk mengecek apakah pohon kosong
 * I.S. T terdefinisi
 * F.S. Mengembalikan true jika T kosong (T == NULL), false jika tidak
 */
boolean isTreeEmpty(BinTree T)
{
    /* ALGORITMA */
    return (T == NULL);
}

/*
 * Fungsi untuk mengecek apakah pohon hanya memiliki satu elemen
 * I.S. T terdefinisi
 * F.S. Mengembalikan true jika T memiliki tepat satu node (root tanpa anak)
 */
boolean isOneElmt(BinTree T)
{
    /* ALGORITMA */
    if (isTreeEmpty(T))
    {
        return false;
    }
    return (LEFT(T) == NULL && RIGHT(T) == NULL);
}

/*
 * Fungsi untuk mengecek apakah suatu node adalah daun (leaf)
 * I.S. N terdefinisi (N != NULL)
 * F.S. Mengembalikan true jika N tidak memiliki anak kiri dan kanan
 */
boolean isLeaf(Address N)
{
    /* ALGORITMA */
    if (N == NULL)
    {
        return false;
    }
    return (LEFT(N) == NULL && RIGHT(N) == NULL);
}

/*
 * Fungsi untuk mencari node dengan nilai X dalam BST
 * I.S. T terdefinisi, X terdefinisi
 * F.S. Mengembalikan address node yang berisi X jika ditemukan
 *      Mengembalikan NULL jika X tidak ada dalam T
 *
 * Contoh:
 * T = BST dengan elemen {5, 3, 7, 2, 4}
 * searchBST(T, 4) -> address node berisi 4
 * searchBST(T, 10) -> NULL
 *
 * Hint: Manfaatkan properti BST: kiri < root < kanan
 */
Address searchBST(BinTree T, ElType X)
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (isTreeEmpty(T))
    {
        return NULL;
    }
    else if (ROOT(T) == X)
    {
        return T;
    }
    else if (X < ROOT(T))
    {
        return searchBST(LEFT(T), X);
    }
    else
    {
        return searchBST(RIGHT(T), X);
    }
}

/*
 * Prosedur untuk menyisipkan X ke dalam BST
 * I.S. T terdefinisi, mungkin kosong
 * F.S. Jika X belum ada di T dan alokasi berhasil, T bertambah satu node
 *      Jika X sudah ada di T, T tidak berubah
 *
 * Contoh:
 * T = BST kosong
 * insertBST(&T, 5) -> T = {5}
 * insertBST(&T, 3) -> T = {5, 3} dengan 3 di kiri 5
 * insertBST(&T, 7) -> T = {5, 3, 7} dengan 7 di kanan 5
 * insertBST(&T, 5) -> T tetap {5, 3, 7} (tidak ada duplikasi)
 *
 * Hint: Rekursif, cari posisi yang tepat berdasarkan nilai X
 */
void insertBST(BinTree *T, ElType X)
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (isTreeEmpty(*T))
    {
        *T = newTreeNode(X);
    }
    else if (X < ROOT(*T))
    {
        insertBST(&LEFT(*T), X);
    }
    else if (X > ROOT(*T))
    {
        insertBST(&RIGHT(*T), X);
    }
    /* Jika X == ROOT(*T), tidak dilakukan apa-apa (tidak ada duplikasi) */
}

/*
 * Fungsi untuk mencari nilai minimum dalam BST
 * Prekondisi: T tidak kosong
 * I.S. T terdefinisi, T tidak kosong
 * F.S. Mengembalikan nilai terkecil dalam T
 *
 * Contoh:
 * T = BST dengan elemen {5, 3, 7, 2, 4}
 * minBST(T) -> 2
 *
 * Hint: Nilai minimum ada di node paling kiri
 */
ElType minBST(BinTree T)
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (LEFT(T) == NULL)
    {
        return ROOT(T);
    }
    else
    {
        return minBST(LEFT(T));
    }
}

/*
 * Fungsi untuk mencari nilai maksimum dalam BST
 * Prekondisi: T tidak kosong
 * I.S. T terdefinisi, T tidak kosong
 * F.S. Mengembalikan nilai terbesar dalam T
 *
 * Contoh:
 * T = BST dengan elemen {5, 3, 7, 2, 4}
 * maxBST(T) -> 7
 *
 * Hint: Nilai maksimum ada di node paling kanan
 */
ElType maxBST(BinTree T)
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (RIGHT(T) == NULL)
    {
        return ROOT(T);
    }
    else
    {
        return maxBST(RIGHT(T));
    }
}

/*
 * Prosedur untuk menghapus node dengan nilai X dari BST
 * I.S. T terdefinisi, tidak kosong
 * F.S. Node dengan nilai X dihapus dari T jika ada
 *      Jika X tidak ada di T, T tidak berubah
 *
 * Contoh:
 * T = BST dengan elemen {5, 3, 7, 2, 4}
 * deleteBST(&T, 3) -> T = {5, 2, 7, 4}
 * deleteBST(&T, 10) -> T tidak berubah
 *
 * Hint: Ada 3 kasus:
 *       1. Node adalah daun -> hapus langsung
 *       2. Node punya 1 anak -> ganti dengan anaknya
 *       3. Node punya 2 anak -> ganti dengan successor (min dari subtree kanan)
 */
void deleteBST(BinTree *T, ElType X)
{
    /* KAMUS LOKAL */
    Address temp;
    ElType successor;

    /* ALGORITMA */
    if (isTreeEmpty(*T))
    {
        return;
    }

    if (X < ROOT(*T))
    {
        deleteBST(&LEFT(*T), X);
    }
    else if (X > ROOT(*T))
    {
        deleteBST(&RIGHT(*T), X);
    }
    else
    {
        /* X ditemukan di node ini */
        if (isLeaf(*T))
        {
            /* Kasus 1: Node adalah daun */
            free(*T);
            *T = NULL;
        }
        else if (LEFT(*T) == NULL)
        {
            /* Kasus 2a: Hanya punya anak kanan */
            temp = *T;
            *T = RIGHT(*T);
            free(temp);
        }
        else if (RIGHT(*T) == NULL)
        {
            /* Kasus 2b: Hanya punya anak kiri */
            temp = *T;
            *T = LEFT(*T);
            free(temp);
        }
        else
        {
            /* Kasus 3: Punya dua anak */
            /* Cari successor (nilai terkecil di subtree kanan) */
            successor = minBST(RIGHT(*T));
            ROOT(*T) = successor;
            deleteBST(&RIGHT(*T), successor);
        }
    }
}

/*
 * Fungsi untuk menghitung jumlah node dalam BST
 * I.S. T terdefinisi
 * F.S. Mengembalikan jumlah node dalam T
 *      Pohon kosong memiliki 0 node
 *
 * Contoh:
 * T = BST dengan elemen {5, 3, 7, 2, 4}
 * countNode(T) -> 5
 * T = pohon kosong
 * countNode(T) -> 0
 */
int countNode(BinTree T)
{
    /* KAMUS LOKAL */

    /* ALGORITMA */
    if (isTreeEmpty(T))
    {
        return 0;
    }
    else
    {
        return 1 + countNode(LEFT(T)) + countNode(RIGHT(T));
    }
}

/*
 * Fungsi untuk menghitung kedalaman (depth) BST
 * I.S. T terdefinisi
 * F.S. Mengembalikan kedalaman T
 *      Pohon kosong memiliki kedalaman 0
 *      Pohon dengan satu node memiliki kedalaman 1
 *
 * Contoh:
 * T = BST dengan elemen {5, 3, 7} (seimbang)
 * depthBST(T) -> 2
 *
 * Hint: Kedalaman = 1 + max(kedalaman kiri, kedalaman kanan)
 */
int depthBST(BinTree T)
{
    /* KAMUS LOKAL */
    int leftDepth, rightDepth;

    /* ALGORITMA */
    if (isTreeEmpty(T))
    {
        return 0;
    }
    else
    {
        leftDepth = depthBST(LEFT(T));
        rightDepth = depthBST(RIGHT(T));
        if (leftDepth > rightDepth)
        {
            return 1 + leftDepth;
        }
        else
        {
            return 1 + rightDepth;
        }
    }
}

/*
 * Prosedur Traversal In-Order: kiri - root - kanan
 * I.S. T terdefinisi
 * F.S. Menampilkan semua elemen T secara in-order
 *      Untuk BST, hasil in-order adalah urutan terurut
 *
 * Contoh:
 * T = BST dengan elemen {5, 3, 7, 2, 4}
 * inOrder(T) -> mencetak: 2 3 4 5 7
 */
void inOrder(BinTree T)
{
    /* ALGORITMA */
    if (!isTreeEmpty(T))
    {
        inOrder(LEFT(T));
        printf("%d ", ROOT(T));
        inOrder(RIGHT(T));
    }
}

/*
 * Prosedur Traversal Pre-Order: root - kiri - kanan
 * I.S. T terdefinisi
 * F.S. Menampilkan semua elemen T secara pre-order
 *
 * Contoh:
 * T = BST dengan elemen {5, 3, 7, 2, 4}
 * preOrder(T) -> mencetak: 5 3 2 4 7
 */
void preOrder(BinTree T)
{
    /* ALGORITMA */
    if (!isTreeEmpty(T))
    {
        printf("%d ", ROOT(T));
        preOrder(LEFT(T));
        preOrder(RIGHT(T));
    }
}

/*
 * Prosedur Traversal Post-Order: kiri - kanan - root
 * I.S. T terdefinisi
 * F.S. Menampilkan semua elemen T secara post-order
 *
 * Contoh:
 * T = BST dengan elemen {5, 3, 7, 2, 4}
 * postOrder(T) -> mencetak: 2 4 3 7 5
 */
void postOrder(BinTree T)
{
    /* ALGORITMA */
    if (!isTreeEmpty(T))
    {
        postOrder(LEFT(T));
        postOrder(RIGHT(T));
        printf("%d ", ROOT(T));
    }
}
