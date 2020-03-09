#include <stdio.h>
#include <math.h>

int main() 
{
    int a, b, c;
    printf("Introduceti variabile a, b, c:\n");
    scanf("%i%i%i", &a, &b, &c);

    if (a == b) 
        printf("%i", c);
    else if (a == c)
        printf("%i", b);
    else if (b == c)
        printf("%i", a);
    else
        printf("Numere sunt diferite! Doua numere trebuie sa fie egale");
    return 0;
}