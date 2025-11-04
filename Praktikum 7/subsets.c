#include <stdio.h>

int n;
int input[15];
int subset[15];

void cetak(int ukuranskrg)
{
    printf("[");
    for (int i = 0; i < ukuranskrg; i++)
    {
        printf("%d", subset[i]);
        if (i < ukuranskrg - 1)
            printf(",");
    }
    printf("]\n");
}

void rekursif(int idx, int start, int ukuranskrg)
{
    if (ukuranskrg == idx)
    {
        cetak(ukuranskrg);
        return;
    }
    for (int i = start; i < n; i++)
    {
        subset[idx] = input[i];
        rekursif(idx + 1, i + 1, ukuranskrg);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }
    cetak(0);
    for (int ukuranskrg = 1; ukuranskrg <= n; ukuranskrg++)
    {
        rekursif(0, 0, ukuranskrg);
    }
    return 0;
}
