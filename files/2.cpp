// 9)	Se dă o structură:
//    cod(int),
//    denumire_bookte(char),
//    numar_pagini(int),
//    nume_autor(char),
//    prenume_autor(char),
//    tematica(char),
//    pretul(float),
//    editura(char).
// Să se înscrie într-un fisier text booktile cu pretul mai mic decât pretul mediu.(Curmanschi Anton)
#include <stdio.h>
#include <string.h>

#define strlength 100
#define fname "test.txt"

struct Book
{
    int cod;
    char denumire_carte[strlength];
    int numar_pagini;
    char nume_autor[strlength];
    char prenume_autor[strlength];
    char tematica[strlength];
    float pretul;
    char editura[strlength];
};

void printBook(Book *book);
void scanBook(Book *book);
void writeBook(Book *book, FILE *f);

int main()
{
    int numBooks;
    printf("Introduceti numarul de carti: ");
    scanf("%i", &numBooks);

    Book data[numBooks];

    printf("\nProcesul de introducere a datelor este initializat.\n");
    for (int i = 0; i < numBooks; i++)
    {
        scanBook(&data[i]);
    }

    puts("\n");

    // afisam toate cartile:
    // for (int i = 0; i < numBooks; i++)
    // {
    //     printBook(&data[i]);
    // }

    // calculam media
    float sum = 0;
    for (int i = 0; i < numBooks; i++)
    {
        sum += data[i].pretul;
    }
    float avg = sum / (float) numBooks;

    Book matches[numBooks];
    int matchesCount = 0; // index into to matches array

    for (int i = 0; i < numBooks; i++)
    {
        if (data[i].pretul < avg)
            matches[matchesCount++] = data[i];
    }

    // scriem in fisier
    FILE *f = fopen(fname, "w+");

    for (int i = 0; i < matchesCount; i++)
    {
        writeBook(&matches[i], f);
    }

    // ne intoarcem la inceput
    rewind(f);

    // afisam continutul
    char buff[strlength];
    while (fgets(buff, strlength, f) != NULL)
    {
        printf(buff);
    }
    fclose(f);

    return 0;
}

void printBook(Book *book)
{
    writeBook(book, stdout);
}

void scanBook(Book *book)
{
    printf("\nIntroduceti Codul: ");
    scanf("%i", &book->cod);
    printf("Introduceti Denumire: ");
    scanf("%s", &book->denumire_carte);
    printf("Introduceti Numar de pagini: ");
    scanf("%i", &book->numar_pagini);
    printf("Introduceti Numele autorului: ");
    scanf("%s", &book->nume_autor);
    printf("Introduceti Prenumele autorului: ");
    scanf("%s", &book->prenume_autor);
    printf("Introduceti Tematica: ");
    scanf("%s", &book->tematica);
    printf("Introduceti Pretul: ");
    scanf("%f", &book->pretul);
    printf("Introduceti Editura: ");
    scanf("%s", &book->editura);
    printf("\n---------------------------------\n");
}

void writeBook(Book *book, FILE *f)
{
    fprintf(f, "Cod ...................... %i",   book->cod);
    fprintf(f, "\nDenumire ................. %s", book->denumire_carte);
    fprintf(f, "\nNumar de pagini .......... %i", book->numar_pagini);
    fprintf(f, "\nNumele autorului ......... %s", book->nume_autor);
    fprintf(f, "\nPrenumele autorului ...... %s", book->prenume_autor);
    fprintf(f, "\nTematica ................. %s", book->tematica);
    fprintf(f, "\nPretul ................... %f", book->pretul);
    fprintf(f, "\nEditura .................. %s", book->editura);
    fprintf(f, "\n---------------------------------\n");
}