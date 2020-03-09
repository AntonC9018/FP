// 86, a, b
// de construit tablourile:
//  1. a[i] = i + 1
//  2. a[i] = n - i

#include "stdio.h"

int main() 
{
    int n = 100;
    int arr[n];
    int arr2[n]; 


    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        arr2[i] = n - i;
    }

    printf("Ordinea crescatoare:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%i] = %i\n", i, arr[i]);
    }

    printf("Ordinea descrescatoare:\n");
    for (int i = 0; i < n; i++) {
        printf("arr2[%i] = %i\n", i, arr2[i]);
    }
}