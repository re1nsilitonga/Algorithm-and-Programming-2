/* File: main.c */
/* Driver program untuk testing implementasi BST */

#include "bst.h"
#include <stdio.h>

int main()
{
    BinTree T;
    Address found;

    printf("=== Test Binary Search Tree ===\n\n");

    /* Test CreateTree dan isTreeEmpty */
    CreateTree(&T);
    printf("1. CreateTree - Tree kosong: %s\n", isTreeEmpty(T) ? "Ya" : "Tidak");

    /* Test insertBST */
    printf("\n2. insertBST - Menambahkan elemen 5, 3, 7, 2, 4, 6, 8:\n");
    insertBST(&T, 5);
    insertBST(&T, 3);
    insertBST(&T, 7);
    insertBST(&T, 2);
    insertBST(&T, 4);
    insertBST(&T, 6);
    insertBST(&T, 8);

    printf("   Tree tidak kosong: %s\n", !isTreeEmpty(T) ? "Ya" : "Tidak");
    printf("   Jumlah node: %d (expected: 7)\n", countNode(T));

    /* Test traversal */
    printf("\n3. Traversal:\n");
    printf("   In-Order (terurut): ");
    inOrder(T);
    printf("\n   Expected: 2 3 4 5 6 7 8\n");

    printf("   Pre-Order: ");
    preOrder(T);
    printf("\n   Expected: 5 3 2 4 7 6 8\n");

    printf("   Post-Order: ");
    postOrder(T);
    printf("\n   Expected: 2 4 3 6 8 7 5\n");

    /* Test searchBST */
    printf("\n4. searchBST:\n");
    found = searchBST(T, 4);
    printf("   Cari 4: %s (expected: Ditemukan)\n", found != NULL ? "Ditemukan" : "Tidak ditemukan");
    found = searchBST(T, 10);
    printf("   Cari 10: %s (expected: Tidak ditemukan)\n", found != NULL ? "Ditemukan" : "Tidak ditemukan");

    /* Test minBST dan maxBST */
    printf("\n5. minBST dan maxBST:\n");
    printf("   Nilai minimum: %d (expected: 2)\n", minBST(T));
    printf("   Nilai maksimum: %d (expected: 8)\n", maxBST(T));

    /* Test depthBST */
    printf("\n6. depthBST:\n");
    printf("   Kedalaman tree: %d (expected: 3)\n", depthBST(T));

    /* Test isOneElmt */
    printf("\n7. isOneElmt:\n");
    printf("   Tree dengan 7 elemen - isOneElmt: %s (expected: Tidak)\n", isOneElmt(T) ? "Ya" : "Tidak");

    /* Test deleteBST */
    printf("\n8. deleteBST:\n");
    printf("   Hapus node daun (2):\n");
    deleteBST(&T, 2);
    printf("   In-Order setelah hapus 2: ");
    inOrder(T);
    printf("\n   Expected: 3 4 5 6 7 8\n");

    printf("   Hapus node dengan 1 anak (3):\n");
    deleteBST(&T, 3);
    printf("   In-Order setelah hapus 3: ");
    inOrder(T);
    printf("\n   Expected: 4 5 6 7 8\n");

    printf("   Hapus node dengan 2 anak (5, root):\n");
    deleteBST(&T, 5);
    printf("   In-Order setelah hapus 5: ");
    inOrder(T);
    printf("\n   Expected: 4 6 7 8\n");

    printf("   Jumlah node sekarang: %d (expected: 4)\n", countNode(T));

    /* Test insert duplikat */
    printf("\n9. Test insert duplikat:\n");
    insertBST(&T, 7);
    printf("   Insert 7 (sudah ada) - Jumlah node: %d (expected: 4, tidak berubah)\n", countNode(T));

    /* Test deleteBST element tidak ada */
    printf("\n10. Delete element tidak ada:\n");
    deleteBST(&T, 100);
    printf("    Delete 100 (tidak ada) - Jumlah node: %d (expected: 4, tidak berubah)\n", countNode(T));

    /* Test tree dengan 1 elemen */
    printf("\n11. Test tree dengan 1 elemen:\n");
    BinTree T2;
    CreateTree(&T2);
    insertBST(&T2, 10);
    printf("    isOneElmt: %s (expected: Ya)\n", isOneElmt(T2) ? "Ya" : "Tidak");
    printf("    isLeaf(root): %s (expected: Ya)\n", isLeaf(T2) ? "Ya" : "Tidak");

    printf("\n=== Semua test selesai ===\n");

    return 0;
}
