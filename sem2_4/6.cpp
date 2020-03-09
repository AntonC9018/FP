// n10
// Sa se afiseze rasturnatul unui numar utilizand o functie recursiva
// 12345 -> 54321

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