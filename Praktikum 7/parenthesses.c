#include <stdio.h>

int parenthesses(int n)
{
    if (n <= 1)
        return 1;
    int hasil = 0;
    for (int i = 0; i < n; i++)
        hasil += parenthesses(i) * parenthesses(n - 1 - i);
    return hasil;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("0\n");
        return 0;
    }
    printf("%d\n", parenthesses(n));
    return 0;
}
