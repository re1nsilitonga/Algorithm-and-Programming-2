/* File: telegram.c */
/* Implementasi fungsi untuk memproses dan menghitung biaya telegram */

#include "mesinkata.h"
#include "boolean.h"
#include <stdio.h>
#include <string.h>

/*
 * Fungsi untuk membandingkan apakah sebuah Word sama dengan string tertentu
 * Dua kata dikatakan sama jika panjang dan urutan karakternya identik
 * I.S. K1 dan str terdefinisi
 * F.S. Mengembalikan true jika K1 sama dengan str, false jika tidak
 *
 * Contoh:
 * - K1 = "KOMA", str = "KOMA" -> return true
 * - K1 = "TITIK", str = "KOMA" -> return false
 * - K1 = "", str = "" -> return true
 */
boolean IsKataSama(Word K1, char *str)
{
    int n = (int)strlen(str);
    if (K1.Length != n)
        return false;
    for (int i = 0; i < n; i++)
    {
        if (K1.TabWord[i] != str[i])
            return false;
    }
    return true;
}

void printWord()
{
    for (int i = 0; i < currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
}

/*
 * Fungsi utama untuk memproses telegram
 * Program membaca input telegram, menampilkan hasil konversi,
 * dan menghitung biaya berdasarkan aturan berikut:
 *
 * Aturan penulisan telegram:
 * - Setiap kata dipisahkan oleh satu atau lebih spasi.
 * - Tanda baca dituliskan dalam bentuk kata: "KOMA" dan "TITIK".
 * - Pita karakter diakhiri dengan karakter titik '.'.
 *
 * Aturan biaya telegram:
 * - Perhitungan biaya didasarkan pada jumlah kata yang dikirim (tanda baca tidak dihitung).
 * - Kata reguler (< 10 karakter) → biaya Rp1000
 * - Kata panjang (>= 10 karakter) → biaya Rp1500
 * - Jika jumlah kata (termasuk tanda baca) > 10 → potongan 10%.
 *
 * Output yang harus ditampilkan:
 * - Isi telegram setelah dikonversi ("KOMA" → ',', "TITIK" → '.')
 * - Jumlah kata reguler
 * - Jumlah kata panjang
 * - Total biaya yang harus dibayar
 *
 * Contoh:
 * Input  : SEGERA PULANG KOMA ADIK SAKIT TITIK.
 * Output :
 * SEGERA PULANG, ADIK SAKIT.
 * 4
 * 0
 * 4000
 *
 * Input  : APA KABAR TITIK SAYA SENANG MENERIMA TAWARANNYA KOMA SEGERA KIRIM PROPOSAL KE KANTOR BANDUNG TITIK.
 * Output :
 * APA KABAR. SAYA SENANG MENERIMA TAWARANNYA, SEGERA KIRIM PROPOSAL KE KANTOR BANDUNG.
 * 11
 * 1
 * 11250
 */

void processTelegram()
{
    int katapanjang = 0;
    int katapendek = 0;
    int tandabaca = 0;
    int totalKata = 0;
    int total = 0;
    boolean setelahTandaBaca = false;

    STARTWORD();

    while (!EndWord)
    {
        if (IsKataSama(currentWord, "KOMA"))
        {
            printf(",");
            tandabaca++;
            setelahTandaBaca = true;
        }
        else if (IsKataSama(currentWord, "TITIK"))
        {
            printf(".");
            tandabaca++;
            setelahTandaBaca = true;
        }
        else
        {
            if (!setelahTandaBaca && totalKata > 0)
            {
                printf(" ");
            }
            else if (setelahTandaBaca)
            {
                printf(" ");
                setelahTandaBaca = false;
            }
            printWord();

            if (currentWord.Length >= 10)
                katapanjang++;
            else
                katapendek++;
        }

        totalKata++;
        ADVWORD();
    }

    printf("\n");

    total = katapendek * 1000 + katapanjang * 1500;
    if (totalKata > 10)
    {
        total = total * 9 / 10;
    }

    printf("%d\n", katapendek);
    printf("%d\n", katapanjang);
    printf("%d\n", total);
}