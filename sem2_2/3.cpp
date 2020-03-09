// n27 (b)
// Se da un vector de lungime n de numere intregi. 
// Sa se permute circular cu o pozitie la stanga. 
// 12345 -> 23451
#include "stdio.h"

int main() 
{
    int n;
    printf("Introduceti n:");
    scanf("%i", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("a[%i] = ", i);
        scanf("%i", &arr[i]);
    }
    
    int buffer = arr[0];
    for (int i = n - 1; i >= 0; i--) {
        int t = arr[i];
        arr[i] = buffer;
        buffer = t;
    }

    puts("");

    for (int i = 0; i < n; i++) {
        printf("a[%i] = %i\n", i, arr[i]);
    }
}