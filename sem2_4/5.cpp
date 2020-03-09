// n10
// Sa se afiseze rasturnatul unui numar utilizand o functie recursiva
// 12345 -> 54321

#include <stdio.h>
#include <math.h>

void printInsideOut(int n)
{
    if (n == 0)
        return;
    printf("%i", n % 10);
    printInsideOut(n / 10);
}

int main() {
    int n;
    printf("Intorudceti n: ");
    scanf("%i", &n);

    printInsideOut(n);

    return 0;
}