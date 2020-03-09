// n15
// A[n][n]
// elementul maxim si minim mai sus de diagonala principala de schimbat locurile

#include <stdio.h>
#include <limits.h>
#include "print.h"

void thing(int *arr, int n);

int main() {
    int n;
    printf("Introduceti n: ");
    scanf("%i", &n);

    int A[n][n];
    scanTable(A[0], n, n, "A");
    thing(A[0], n);

    int B[n][n];
    scanTable(B[0], n, n, "B");
    thing(B[0], n);

    return 0;
}


void thing(int *arr, int n) 
{
    int min = *(arr + 1);
    int max = *(arr + 1);
    int minOffset = 1;
    int maxOffset = 1;
    for (int i = 1; i < n - 1; i++) {
        int offset = i * n + i + 1;
        int el = *(arr + offset); 
        if (el < min) {
            min = el;
            minOffset = offset;
        }
        if (el > max) {
            max = el;
            maxOffset = offset;
        }
    }
    // afisam tabloul inainte de operatii
    printf("Tabloul introdus\n");
    printTable(arr, n, n);

    // afisam max si min
    printf("\nElementul maxim de mai sus de diagonala principala: %i", *(arr + maxOffset));
    printf("\nElementul minim de mai sus de diagonala principala: %i", *(arr + minOffset));

    // interschimbam maxim si minin
    *(arr + minOffset) = max;
    *(arr + maxOffset) = min;

    printf("\n\nTabloul procesat\n");
    printTable(arr, n, n);
}
