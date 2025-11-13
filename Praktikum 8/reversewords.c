#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"

void printreverse()
{
    for (int i = currentWord.Length-1; i >= 0; i--)
    {
        printf("%c", currentWord.TabWord[i]);
    }
    
}

int main()
{
    STARTWORD();
    while (!EndWord)
    {
        printreverse();
        printf("\n");
        ADVWORD();
    }
}
