#include <stdio.h>
#include <math.h>

int main()
{
    printf("Introduceti un caracter: ");

    char ch;
    scanf("%c", &ch);

    if (ch <= 'Z' && ch >= 'A') {
        printf("%c este o litera majuscula", ch);
    } else if (ch <= 'z' && ch >= 'a') {
        printf("%c este o litera minuscula", ch);
    } else if (ch >= '0' && ch <= '9') {
        printf("%c este o cifra", ch);
    }
    return 0;
}