#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    unsigned long num, base, power;

    printf("Introduceti numarul: ");
    scanf("%U", &num);

    int valid = 0;

    do {

        printf("Introduceti baza: ");
        scanf("%U", &base);
        float p = log2(base);
        power = floor(p);

        // if power is an integer
        if (p == power) {
            valid = 1;
        }

        if (!valid) {
            printf("Invalid input. The base must be a power of 2.\n");
        }

    } while (!valid);

    // numar de cifre in numarul final
    // log2(num) - cate cifre are numarul in expansiunea binara
    // in extensiunea 2^`power` numarul va avea `power` mai putine cifre 
    int numDigits = log2(num) / power + 1;

    // masca pe care noi o vom folosi
    // de exemplu, pentru baza 8 masca ar fi
    // 0000 0111
    // fiindca o cifra in baza 8 = 3 cifre in baza 2
    unsigned long mask = base - 1;

    // aici scriem baza numarului urmator si omitem `numDigits`
    // numar de spatii care in urmare vor fi ocupate cu numarul introdus
    printf("Numarul in baza %i:", base);
    for (int i = 0; i < numDigits + 2; i++) {
        putch(' ');
    }

    do {
        
        int digit = num & mask;

        // go back two spaces
        printf("\b\b");
        // then print the digit
        if (digit < 10) {
            printf("%c", digit + '0');
        } 
        // extend the base (use letters as digits)
        else {
            // de exemplu, daca digit este 10, vom primi
            // 'A' + 10 - 10 = 'A'
            // daca digit = 12
            // 'A' + 12 - 10 = 'A' + 2 = 'C'
            char letter = 'A' + (digit - 10);

            printf("%c", letter);
        }
        // shift the number to the right e.g.
        // 0100 1111 in baza 8 ne da 0000 0111 = 7 dupa aplicarea mascii
        // 0000 1111 >> 3 (adica log2(8)) = 0000 1001
        // aplicam masca iar o data si primim 0000 0001 = 1
        // 0000 1001 >> 3 = 0000 0001
        // aplicam masca, primim 0000 0001 = 1
        // primim 1, inseamna ca numarul in baza 8 este 117
        num = num >> power;

    } while (num > 0);

    return 0;
}