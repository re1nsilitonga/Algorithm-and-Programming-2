#include <stdio.h>

int hitung(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return hitung(n - 1) + hitung(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", hitung(n));
    return 0;
}
