// De calculat numar de combinatii in care se poate urca
// starile daca se poate lua pasi de lungime 1 sau 2

#include <stdio.h>
#include <math.h>

int climb(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return (climb(n - 1) + climb(n - 2));
}

int main() {
    int n;
    printf("Introduceti n: ");
    scanf("%i", &n);

    printf("Numarul de moduri: %i", climb(n));

    return 0;
}