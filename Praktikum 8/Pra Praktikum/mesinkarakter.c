#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void START() {
    pita = stdin;
    retval = fscanf(pita, "%c", &currentChar);
    if (retval == EOF) {
        EOP = true;
    } else {
        EOP = (currentChar == MARK);
    }
}

void ADV() {
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}