#include "password.h"

int length(int angka)
{
    if (angka == 0)
        return 1;
    return (int)floor(log10(angka)) + 1;
}

int getDigit(int angka, int index)
{
    int len = length(angka);
    if (index < 0 || index >= len)
        return -1;

    long long sepuluhPangkatFloor = (long long)pow(10, index);
    long long sepuluhPangkatMod = (long long)pow(10, index + 1);
    int hasilMod = angka % sepuluhPangkatMod;
    return hasilMod / sepuluhPangkatFloor;
}

int removeDigit(int angka, int index)
{
    int len = length(angka);
    if (index < 0 || index >= len)
        return angka;

    long long powVal = (long long)pow(10, index);
    long long powValPlus = (long long)pow(10, index + 1);

    int kiri = angka / powValPlus;
    int kanan = angka % powVal;
    return kiri * powVal + kanan;
}

void cariKombinasiHelper(int angka, int current, int panjangAwal, int digitDiambil)
{
    if (digitDiambil == panjangAwal)
    {
        printf("%0*d\n", panjangAwal, current);
        return;
    }

    int len = length(angka);

    for (int i = 0; i < len; i++)
    {
        int digit = getDigit(angka, i);
        int sisa = removeDigit(angka, i);
        cariKombinasiHelper(sisa, current * 10 + digit, panjangAwal, digitDiambil + 1);
    }
}

void cariKombinasi(int angka, int current, int panjangAwal)
{
    cariKombinasiHelper(angka, current, panjangAwal, 0);
}

void findPassword(int angka)
{
    cariKombinasi(angka, 0, length(angka));
}