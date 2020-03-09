// 104 
// Din tabloul X[n] de format Y 
// X = 1 2 3
// Y = 1 1.5 2 2.5 3

#include "stdio.h"


int main() 
{
    
    int n;
    printf("Introduceti n: ");
    scanf("%i", &n);
    float X[n];

    for (int i = 0; i < n; i++) {
        printf("X[%i] = ", i);
        scanf("%f", &X[i]);
    }

    float Y[n * 2 - 1];
    for (int i = 0; i < n - 1; i++) {
        Y[i*2] = X[i];
        Y[i*2 + 1] = (X[i] + X[i + 1]) / 2;
    }
    Y[n * 2 - 2] = X[n - 1];

    for (int i = 0; i < n * 2 - 1; i++) {
        printf("Y[%i] = %f\n", i, Y[i]);
    }

}

// X = 1 2 3
// Y = 1 1.5 2 