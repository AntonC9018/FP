// n3
// Se dau 2 tablouri unidimensionale A si B
// Sa se calculeze z=(s1-s2)/sqrt(k1*k2), unde:
// s1 — suma elementelor pare pozitive din A
// k1 — numarul de elemente pare pozitive din A
// s2 — suma elementelor pare pozitive din B
// k2 — numarul de elemente pare pozitive din B

#include <stdio.h>
#include <math.h>

int condition(float el);
float sum(float *arr, int n);
int count(float *arr, int n);

int main() {
    int n;
    printf("Intorudceti n: ");
    scanf("%i", &n);

    float A[n];
    for (int i = 0; i < n; i++) {
        printf("A[%i] = ", i);
        scanf("%f", A + i);
    }

    float B[n];
    for (int i = 0; i < n; i++) {
        printf("B[%i] = ", i);
        scanf("%f", B + i);
    }

    float s1 = sum(A, n);
    float s2 = sum(B, n);
    int k1 = count(A, n);
    int k2 = count(B, n);
    float z = (s1 + s2) / sqrt(k1 + k2); 

    printf("z = %f", z);

    return 0;
}

int condition(float el)
{
    if (el > 0) 
        return 1;
    return 0;
}

float sum(float *arr, int n)
{
    float s = 0;
    for (int i = 0; i < n; i++) {
        if (condition(arr[i])) {
            s += arr[i];
        }
    }
    return s;
}

int count(float *arr, int n)
{
    float num = 0;
    for (int i = 0; i < n; i++) {
        if (condition(arr[i])) {
            num++;
        }
    }
    return num;
}