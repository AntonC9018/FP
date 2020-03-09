// 6
// Cea mai lunga secventa de numere consecutive egale
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


    int longest = 1;
    int longestNum = A[0];
    int current = 1;
    int currentNum = A[0];

    for (int i = 1; i < n; i++) {

        if (A[i] == currentNum)
            current++;
        else {
            currentNum = A[i];
            current = 1;
        }

        if (current > longest) {
            longestNum = currentNum;
            longest = current;
        }
    }

    printf("Cea mai lunga secventa de numere este o secveta compusa de %i si are lungime %i", longestNum, longest);
}