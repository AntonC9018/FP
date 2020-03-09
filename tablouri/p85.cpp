#include <stdio.h>
#include <math.h>

int main()
{   
    int n = 0;
    do {
        printf("Intoduceti n (n <= 100): ");
        scanf("%i", &n);
        if (n > 100) {
            printf("n > 100 nu este admisibil.\n");
        }
    }
    while (n > 100);

    float arr[n];
    for (int i = 0; i < n; i++) {

        // enter values
        printf("Introduceti a[%i]: ", i);
        scanf("%f", arr + i);

        for (int j = 0; j < i; j++) {
            // aflam elementul, care este mai mic decat numarul intodus
            if (arr[i] > arr[j]) {
                float cut = arr[j];
                arr[j] = arr[i];
                // punem numarul introdus in loc de acel element, 
                // si miscam totul sir la dreapta
                for (int k = j + 1; k <= i; k++) {
                    float temp = arr[k];
                    arr[k] = cut;
                    cut = temp;
                }
                break;
            }
        }
    }

    // print out the array
    for (int i = 0; i < n; i++) {
        printf("arr[%i] = %f\n", i, arr[i]);
    }
}   