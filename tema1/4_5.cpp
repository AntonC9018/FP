#include <stdio.h>
#include <math.h>

int main() 
{
    int x, y;
    printf("Introduceti numere x, y:\n");
    scanf("%i%i", &x, &y);

    int a;
    if (x == y)
        a = 0;
    else if (x > y)
        a = 1;
    else
        a = 2;
    printf("%i", a);

    return 0;
}   