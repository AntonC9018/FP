// 43 
// 23
// Cea mai lunga secventa de zerouri
#include "stdio.h"


int main() 
{
    int n;
    printf("Introduceti n: ");
    scanf("%i", &n);
    int A[n];

    for (int i = 0; i < n; i++) {
        printf("A[%i] = ", i);
        scanf("%i", &A[i]);
    }


    int longest = 0;
    int current = 0;

    for (int i = 0; i < n; i++) {

        if (A[i] == 0)
            current++;
        else
            current = 0;

        if (current > longest)
            longest = current;
    }

    printf("Cea mai lunga secventa de zerouri este de lungime %i", longest);

}