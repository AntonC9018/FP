#include <stdio.h>
#include <math.h>

int main()
{
    printf("Alege: 1 - minimum, 2 - triunghi, 3 - alfabet: ");
    int choise;
    scanf("%i", &choise);

    switch (choise) 
    {
    case 1: {
        float b, x, z;
        scanf("%f%f%f", &b, &x, &z);
        float acc1 = 1, acc2 = 1, acc3 = 0;

        for (int k = 1; k <= 6; k++) 
            acc1 *= b + k;
        for (int i = 1; i <= 5; i++)
            acc2 *= i + 2.3f * x;
        for (int f = 1; f <= 3; f++)
            acc3 += f + 3.2f * z;
        
        float min;
        if (acc1 < acc2 && acc1 < acc3) {
            min = acc1;
        } else if (acc2 < acc1 && acc2 < acc3) {
            min = acc2;
        } else {
            min = acc3;
        }

        printf("min = %f", min);
        break;
    }

    case 2:
        for (int i = 1; i <= 5; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%i", j);
            }
            printf("\n");
        }
        break;

    case 3:
        for (int i = 0; i <= 'z' - 'a'; i++) {
            for (int j = 0; j < pow(2, i + 1); j++) {
                printf("%c", i + 'a');
                if (j > 8) break;
            }
            printf("\n");
        }
        break;

    default:
        printf("Optiunea nu e admisibila");
    }
}                                    