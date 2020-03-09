// n13
// Se dau 2 tablouri bidimensionale A si B
// Sa se calculeze z=(s1-s2)/(p1*p2), unde:
// s1 — media aritmetica din A
// p1 — numarul de elemente A
// s2 — media aritmetica din B
// p2 — numarul de elemente B
// Se considera numai elementele pare de pe diagonala secundara 

#include <stdio.h>
#include <math.h>
#include "print.h"

int condition(int el);
float avg(int *arr, int n);
int count(int *arr, int n);

int main() {
    int n;
    printf("Intorudceti n: ");
    scanf("%i", &n);

    int A[n][n];
    scanTable(A[0], n, n, "A");
    float s1 = avg(A[0], n);
    int p1 = count(A[0], n);

    int B[n][n];
    scanTable(B[0], n, n, "B");
    float s2 = avg(B[0], n);
    int p2 = count(B[0], n);

    printf("Tabloul introdus A:\n");
    printTable(A[0], n, n);

    printf("\nTabloul introdus B:\n");
    printTable(B[0], n, n);

    printf("\ns1 = %f", s1);
    printf("\np1 = %i", p1);
    printf("\ns2 = %f", s2);
    printf("\np2 = %i", p2);

    float z = (s1 + s2) / (float)(p1 + p2); 

    printf("\nz = %f", z);

    return 0;
}

int condition(int el)
{
    if (el % 2 == 0) 
        return 1;
    return 0;
}

float avg(int *arr, int n)
{
    int s = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int el = *(arr + i * n + n - i - 1);
        if (condition(el)) {
            s += el;
            count++;
        }
    }
    return (float)s / count;
}

int count(int *arr, int n)
{
    float num = 0;
    for (int i = 0; i < n; i++) {
        int el = *(arr + i * n + n - i - 1);
        if (condition(el)) {
            num++;
        }
    }
    return num;
}