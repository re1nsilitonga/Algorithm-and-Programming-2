/* File: problem.c */
/* Implementasi fungsi untuk mengecek apakah kalimat sesuai grammar dengan daftar objek */

/* Grammar yang digunakan:
 * <Kalimat> ::= <Subjek> <Predikat> <Objek> {, <Objek>}*
 *
 * Contoh kalimat valid:
 * - "aku beli buku."
 * - "aku beli buku, pensil, penggaris."
 * - "dia ambil tas, buku."
 *
 * Contoh tidak valid:
 * - "aku beli."
 * - "beli buku."
 * - "aku beli , pensil."
 */

#include "mesinkata.h"
#include "boolean.h"
#include <stdio.h>
#include <string.h>

/* ====== FSM Parser ====== */
typedef enum
{
    S_EXPECT_SUBJECT = 0,
    S_EXPECT_PREDICATE,
    S_EXPECT_FIRST_OBJECT,
    S_EXPECT_SEPARATOR_OR_END,
    S_EXPECT_OBJECT_AFTER_COMMA
} State;

/* ====== Helper ====== */
/* Membandingkan dua kata secara case-insensitive */
int eqWordCStrInsensitive(Word w, const char *s)
{
    int n = (int)strlen(s);
    if (w.Length != n)
        return 0;
    for (int i = 0; i < n; i++)
    {
        char cw = w.TabWord[i];
        if ('A' <= cw && cw <= 'Z')
            cw = (char)(cw - 'A' + 'a');
        char cs = s[i];
        if ('A' <= cs && cs <= 'Z')
            cs = (char)(cs - 'A' + 'a');
        if (cw != cs)
            return 0;
    }
    return 1;
}

int isSubjek(const Word w)
{
    return eqWordCStrInsensitive(w, "aku") || eqWordCStrInsensitive(w, "kamu") || eqWordCStrInsensitive(w, "dia");
}

int isPredikat(const Word w)
{
    return eqWordCStrInsensitive(w, "beli") || eqWordCStrInsensitive(w, "ambil");
}

/* Helper untuk mengecek apakah token adalah koma tunggal */
int isCommaToken(Word w)
{
    return (w.Length == 1 && w.TabWord[0] == ',');
}

/* Helper untuk mengecek apakah token adalah objek valid (alfabet)
 * dan apakah memiliki koma di akhir
 * Return: 1 jika valid, 0 jika tidak
 * hasTrailingComma: 1 jika ada koma di akhir, 0 jika tidak
 */
int isObjToken(Word w, int *hasTrailingComma)
{
    int i;
    int lastIdx;

    *hasTrailingComma = 0;

    // Token kosong atau hanya koma bukan objek
    if (w.Length == 0 || isCommaToken(w))
    {
        return 0;
    }

    // Cek apakah karakter terakhir adalah koma
    lastIdx = w.Length - 1;
    if (w.TabWord[lastIdx] == ',')
    {
        *hasTrailingComma = 1;
        lastIdx--; // Kurangi untuk cek alfabet
    }

    // Jika setelah menghapus koma tidak ada karakter, bukan objek valid
    if (lastIdx < 0)
    {
        return 0;
    }

    // Cek semua karakter (kecuali koma di akhir) harus alfabet
    for (i = 0; i <= lastIdx; i++)
    {
        char c = w.TabWord[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
        {
            return 0;
        }
    }

    return 1;
}

/*
 * Fungsi utama untuk mengecek apakah kalimat sesuai grammar daftar objek
 * I.S. Mesin kata sudah siap digunakan (panggil STARTWORD() sebelumnya)
 * F.S. Mengembalikan true (1) jika kalimat valid, false (0) jika tidak
 */
int cfg_parser()
{
    State state;
    int objectCount;
    int hasTrailingComma;

    STARTWORD();

    state = S_EXPECT_SUBJECT;
    objectCount = 0;

    while (!EndWord)
    {
        switch (state)
        {
        case S_EXPECT_SUBJECT:
            if (!isSubjek(currentWord))
            {
                return 0; // Harus subjek
            }
            state = S_EXPECT_PREDICATE;
            break;

        case S_EXPECT_PREDICATE:
            if (!isPredikat(currentWord))
            {
                return 0; // Harus predikat
            }
            state = S_EXPECT_FIRST_OBJECT;
            break;

        case S_EXPECT_FIRST_OBJECT:
            // Harus objek, tidak boleh koma
            if (isCommaToken(currentWord))
            {
                return 0; // Koma langsung setelah predikat
            }

            if (!isObjToken(currentWord, &hasTrailingComma))
            {
                return 0; // Bukan objek valid
            }

            objectCount++;

            if (hasTrailingComma)
            {
                state = S_EXPECT_OBJECT_AFTER_COMMA;
            }
            else
            {
                state = S_EXPECT_SEPARATOR_OR_END;
            }
            break;

        case S_EXPECT_SEPARATOR_OR_END:
            // Di state ini, hanya boleh koma
            if (!isCommaToken(currentWord))
            {
                return 0; // Token tidak valid
            }
            state = S_EXPECT_OBJECT_AFTER_COMMA;
            break;

        case S_EXPECT_OBJECT_AFTER_COMMA:
            // Setelah koma, harus objek
            if (isCommaToken(currentWord))
            {
                return 0; // Dua koma berurutan
            }

            if (!isObjToken(currentWord, &hasTrailingComma))
            {
                return 0; // Bukan objek valid
            }

            objectCount++;

            if (hasTrailingComma)
            {
                state = S_EXPECT_OBJECT_AFTER_COMMA;
            }
            else
            {
                state = S_EXPECT_SEPARATOR_OR_END;
            }
            break;

        default:
            return 0;
        }

        ADVWORD();
    }

    // Kondisi akhir: harus sudah membaca minimal 1 objek
    // dan state terakhir harus S_EXPECT_SEPARATOR_OR_END
    if (objectCount >= 1 && state == S_EXPECT_SEPARATOR_OR_END)
    {
        return 1;
    }

    return 0;
}