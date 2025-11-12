#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

boolean EndWord;
Word currentWord;   

void IgnoreBlanks() {
    while (currentChar == BLANK && !EOP) {
        ADV();
    }
}

void STARTWORD() {
    START();
    IgnoreBlanks();
    if (EOP) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (EOP) {
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
    int i = 0;
    while (currentChar != BLANK && !EOP && i < NMax) {
        currentWord.TabWord[i] = currentChar;
        i++;
        ADV();
    }
    currentWord.Length = i;
}