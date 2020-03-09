// 102
// A[1..10] din caractere arbitrare
// B in urm. ordinea (2)

#include "stdio.h"

char A[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char B[sizeof(A) * 2];
#define lengthA sizeof(A) / sizeof(char)
#define lengthB sizeof(B) / sizeof(char)

int main() 
{
    for (int i = 0; i < lengthA; i++) {
        B[i] = A[lengthA - i - 1];
        B[sizeof(A) + i] = A[lengthA - i - 1];
    }

    for (int i = 0; i < lengthB; i++) {
        printf("%c ", B[i]);
    }

    return 0;
}