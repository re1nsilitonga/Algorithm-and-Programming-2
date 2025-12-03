/* File: bst.h */
/* ADT Binary Search Tree (BST) */
/* Representasi Binary Search Tree dengan pointer */

#ifndef BST_H
#define BST_H

#include "boolean.h"
#include <stdlib.h>

/* Definisi Type Data */
typedef int ElType;

typedef struct tNode *Address;
typedef struct tNode
{
    ElType info;
    Address left;
    Address right;
} Node;

/* Definisi Tree */
typedef Address BinTree;

/* Selektor */
#define ROOT(p) (p)->info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right

/* *** Konstruktor *** */
/* Mengalokasikan sebuah node baru dengan info X */
Address newTreeNode(ElType X);

/* I.S. sembarang */
/* F.S. Terbentuk pohon biner T kosong */
void CreateTree(BinTree *T);

/* *** Predikat *** */
/* Mengembalikan true jika T adalah pohon biner kosong */
boolean isTreeEmpty(BinTree T);

/* Mengembalikan true jika T adalah pohon dengan hanya satu elemen (daun) */
boolean isOneElmt(BinTree T);

/* Mengembalikan true jika N adalah node daun (leaf) */
boolean isLeaf(Address N);

/* *** Operasi BST *** */
/* Mencari node dengan nilai X dalam BST */
/* Mengembalikan address node jika ditemukan, NULL jika tidak */
Address searchBST(BinTree T, ElType X);

/* Menyisipkan X ke dalam BST */
/* I.S. T terdefinisi */
/* F.S. Jika alokasi berhasil, T bertambah satu node dengan info X */
/*      Jika X sudah ada di tree, tidak dilakukan penyisipan */
void insertBST(BinTree *T, ElType X);

/* Menghapus node dengan nilai X dari BST */
/* I.S. T tidak kosong */
/* F.S. X dihapus dari T jika X ada di T */
/*      Jika X tidak ada, T tidak berubah */
void deleteBST(BinTree *T, ElType X);

/* Mencari nilai minimum dalam BST */
/* Prekondisi: T tidak kosong */
ElType minBST(BinTree T);

/* Mencari nilai maksimum dalam BST */
/* Prekondisi: T tidak kosong */
ElType maxBST(BinTree T);

/* Mengembalikan jumlah node dalam BST */
int countNode(BinTree T);

/* Mengembalikan kedalaman (depth) BST */
/* Pohon kosong memiliki kedalaman 0 */
int depthBST(BinTree T);

/* Traversal In-Order: kiri - root - kanan */
void inOrder(BinTree T);

/* Traversal Pre-Order: root - kiri - kanan */
void preOrder(BinTree T);

/* Traversal Post-Order: kiri - kanan - root */
void postOrder(BinTree T);

#endif
