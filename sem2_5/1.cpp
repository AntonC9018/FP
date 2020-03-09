// ex. 42
// Numararea aparitiei unui cuvant intr-o propozitie
#include <stdio.h>
#include <string.h>
#define strlength 100

int main()
{
    char word[strlength], str[strlength];
    printf("Introduceti o propozitie: ");
    gets(str);
    printf("Introduceti un cuvant: ");
    gets(word);

    int count = 0;
    char *indexOfFind = str;
    int wordLen = strlen(word);
    while ((indexOfFind = strstr(indexOfFind, word)) != 0)
        {
            count++;
            indexOfFind += wordLen;
        }

    printf("Numarul de aparitii cuvantului \"%s\" in propozitia \"%s\" este: %i",
        word, str, count);

    return 0;
}