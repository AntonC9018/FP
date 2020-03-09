// 7
// Se da un vector de lungime n de numere intregi. 
// De gasit elementele, cele mai apropiate de medie.
#include "stdio.h"


float abs(float x) {
    return x > 0 ? x : -x;
}

int main() 
{
    int n;
    printf("Introduceti n:");
    scanf("%i", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("a[%i] = ", i);
        scanf("%i", &arr[i]);
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    float avg = (float)sum / n;

    float minDistance = abs(arr[0] - avg);
    int minDistanceIndeces[n];
    minDistanceIndeces[0] = 0;
    int minDistanceElementCount = 1;

    for (int i = 1; i < n; i++) {
        float dist = abs(arr[i] - avg);
        if (dist < minDistance) {
            minDistance = dist;
            minDistanceIndeces[0] = i;
            minDistanceElementCount = 1;
        } 
        else if (dist == minDistance)
            minDistanceIndeces[minDistanceElementCount++] = i;
    }

    printf("Media este: %f\nIndicele numerelor: ", avg);

    for (int i = 0; i < minDistanceElementCount; i++) {
        printf("%i ", minDistanceIndeces[i]);
    }
}