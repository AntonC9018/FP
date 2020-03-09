// n35
// Folosind cirul lui Eratostene, de gasit toate numerele gemene mai mici decat n. 
// Numere gemene sunt cele numere prime, diferenta carora este 2.
#include "stdio.h"

int main() 
{
    int n;
    printf("Introduceti n:");
    scanf("%i", &n);
    n -= 2;

    int valid[n];
    int nums[n];

    for (int i = 0; i < n; i++) {
        valid[i] = 1;
        nums[i] = i + 2;
    }

    int primes[n];
    int p = 0;
    for (int i = 0; i < n; i++) {
        // printf("Testing %i\n", nums[i]);
        if (valid[i]) {
            for (int j = i; j < n; j += nums[i])
            {
                valid[j] = 0;
            }
            primes[p++] = nums[i];
        }
    }

    for (int i = 0; i < p - 1; i++) {
        // printf("Prime: %i\n", primes[i]);
        if (primes[i + 1] - primes[i] == 2) {
            printf("O pereche de numere geneme: %i, %i\n", primes[i], primes[i + 1]);
        }
    }
    
}