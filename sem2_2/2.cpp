// n27 (a)
// Se da un vector de lungime n de numere intregi. 
// Sa se permute circular cu o pozitie la dreapta. 
// 12345 -> 51234
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
    
    int buffer = arr[n - 1];
    for (int i = 0; i < n; i++) {
        int t = arr[i];
        arr[i] = buffer;
        buffer = t;
    }

    puts("");

    for (int i = 0; i < n; i++) {
        printf("a[%i] = %i\n", i, arr[i]);
    }
}