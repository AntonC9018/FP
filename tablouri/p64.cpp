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

    float positiveSum = 0;
    float sum = 0;

    float min;
    int minIndices[n];
    int numberMinElements = 0;

    float max;
    int maxIndices[n];
    int numberMaxElements = 0;

    float arr[n];
    for (int i = 0; i < n; i++) {

        // enter values
        printf("Introduceti a[%i]: ", i);
        scanf("%f", &arr[i]);

        // update minimums
        // if this is the first number
        if (!numberMinElements) {
            min = arr[i];
            minIndices[0] = 0;
            numberMinElements++;
        }
        else {
            if (arr[i] == min) {
                minIndices[numberMinElements] = i;
                numberMinElements++;
            }
            if (arr[i] < min) {
                min = arr[i];
                minIndices[0] = i;
                numberMinElements = 1;
            }
        }

        // update maximums
        // if this is the first number
        if (!numberMaxElements) {
            max = arr[i];
            maxIndices[0] = i;
            numberMaxElements = 1;
        }
        else {
            if (arr[i] == max) {
                maxIndices[numberMaxElements] = i;
                numberMaxElements++;
            }
            if (arr[i] > max) {
                max = arr[i];
                maxIndices[0] = i;
                numberMaxElements = 1;
            }
        }

        // calculate sums
        sum += arr[i];
        if (arr[i] > 0) {
            positiveSum += arr[i];
        }
    }

    // calculate the average
    float average = sum / n;

    // min elements <- average
    for (int i = 0; i < numberMinElements; i++) {
        printf("Setting arr[%i] to %f\n", minIndices[i], average);
        int currentIndex = minIndices[i];
        arr[currentIndex] = average;
    }

    // max elements <- sum of positives
    for (int i = 0; i < numberMaxElements; i++) {
        printf("Setting arr[%i] to %f\n", maxIndices[i], positiveSum);
        int currentIndex = maxIndices[i];
        arr[currentIndex] = positiveSum;
    }

    // print out the array
    for (int i = 0; i < n; i++) {
        printf("arr[%i] = %f\n", i, arr[i]);
    }

    return 0;
}