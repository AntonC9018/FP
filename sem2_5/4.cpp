// 47
// Se da o propozitie cu cuvintele separate cu spatiile
// De afisat cuvintele de pe pozitii pare

#include <stdio.h>
#include <string.h>
#define strlength 100

void printEvenWords(char *str);

int main()
{
    char string[strlength];
    printf("Dati o propozitie: ");
    gets(string);

    printEvenWords(string);

    return 0;
}

void printEvenWords(char *str) 
{
    
    do {
        while (*str != ' ' && *str != '\0') {
            printf("%c", *str);
            str++;
        }
        printf(" ");
        str = strchr(str + 1, ' ');

        if (str == 0)
            return;

        str++;

    } while(1);

}
