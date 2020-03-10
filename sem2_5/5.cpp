// n50 numar cu cifre arabe -> numar cu cifre romane
// n51 invers
#include <stdio.h>
#include <string.h>
#define strlength 100

struct RomanNumeral {
    int value;
    int maxCount; // max number of consequent same letter written in a row
    char symbol;
};

const RomanNumeral romanNumerals[] = {
    { 1,   3, 'I' },
    { 5,   1, 'V' },
    { 10,  3, 'X' },
    { 50,  1, 'L' },
    { 100, 3, 'C' },
    { 500, 1, 'D' },
    { 1000, __INT_MAX__, 'M' }
};

#define romanNumeralsCount sizeof(romanNumerals) / sizeof(RomanNumeral)

int* getRomanValuesArray(int num, int currentRomanIndex, int *resultSpace);
int convertRomanToArabic(int romanValues[], int size);
int maxPossibleRomanCombFrom(int endIndex);
void resetString(char *str, int n); 
void reverseString(char *str);
int getIndexOfLargestRoman(char *str); 
void convertArabicToRomanString(int num, char *romanString);
int convertRomanStringToValues(char *romanStr, int romanValsBuffer[]);

int main()
{
    char romanNumString[strlength];

    printf("Dati un numar in sistemul roman: ");
    gets(romanNumString);

    // roman -> arab
    int romanNumValues[strlength];
    int size = convertRomanStringToValues(romanNumString, romanNumValues);
    int result = convertRomanToArabic(romanNumValues, size);

    printf("Echivalentul arab de numarul %s este %i", romanNumString, result);

    int num;
    printf("Dati un numar: ");
    scanf("%i", &num);

    // arab -> normal
    resetString(romanNumString, strlength);
    convertArabicToRomanString(num, romanNumString);

    printf("Numarul introdus scris cu numerele romane este %s", romanNumString);

    return 0;
}


int convertRomanToArabic(int romanValues[], int size)
{
    int memory[size];
    int memoryCount = 0;
    int accum = 0;

    for (int i = 0; i < size; i++) {
        if (memoryCount == 0) {
            memory[memoryCount++] = romanValues[i];
            continue;
        }

        if (romanValues[i] < memory[memoryCount - 1]) {
            // add all previous things
            for (int j = 0; j < memoryCount; j++) {
                accum += memory[j];
            }
            memory[0] = romanValues[i];
            memoryCount = 1;
        }
        else if (romanValues[i] > memory[memoryCount - 1]) {
            // subtract all previous things
            for (int j = 0; j < memoryCount; j++) {
                accum -= memory[j];
            }
            memory[0] = romanValues[i];
            memoryCount = 1;
        }
        else {
            memory[memoryCount++] = romanValues[i];
        }
    }

    // pull together the rest of it
    for (int i = 0; i < memoryCount; i++) 
        accum += memory[i];

    return accum;
}


int maxPossibleRomanCombFrom(int endIndex) 
{
    int accum = 0;
    for (int i = 0; i <= endIndex; i++) {
        accum += romanNumerals[i].value * romanNumerals[i].maxCount;
    }
    return accum;
}



void resetString(char *str, int n) 
{
    for (int i = 0; i < n; i++) {
        *str = '\0';
        str++;
    }
}

void reverseString(char *str) 
{
    char copy[strlength];
    strcpy(copy, str);
    int length = strlen(str);
    int j = length - 1;
    for (int i = 0; i < length; i++) {
        str[j--] = copy[i++]; 
    }
}

int getIndexOfLargestRoman(char *str) 
{
    for (int i = romanNumeralsCount - 1; i >= 0; i--) {
        char *find;
        if ((find = strchr(str, romanNumerals[i].symbol)) != 0) {
            return (int)(find - str);
        }
    }
    return 0;
}


void convertArabicToRomanString(int num, char *romanString)
{   
    int romanStringOffset = 0;
    int valuesBuffer[strlength];
    int length = getRomanValuesArray(num, romanNumeralsCount - 1, valuesBuffer) - valuesBuffer;

    // for example, for XIIX the subtractionBuffer would be II
    int subtractionBuffer[strlength];
    int subtractionBufferOffset = 0;
    // for example, for XIIX, subtractFrom = 10 (the second X)
    int subtractFrom = -1;

    printf("\nValues: ");
    for (int i = 0; i < length; i++) {
        printf("%i ", valuesBuffer[i]);
    }
    
    // arrange the digits for subtraction in order in the subtractionBuffer
    for (int i = romanNumeralsCount - 2; i >= 0; i--) {
        for (int j = 0; j < length; j++) {

            // for each match, put it in the new buffer
            if (valuesBuffer[j] == -romanNumerals[i].value) {
                subtractionBuffer[subtractionBufferOffset++] = i;     

                if (subtractFrom == -1) {
                    int testingIndex = i + 1;
                    do {
                        // we have to go through all the letters higher than the highest letter subtracted
                        // and grab the one of lowest value that we find in the valuesBuffer
                        // consider the cases:
                        // IV = 4
                        // subtractionBuffer = I
                        // subtractFrom = V (V is 1 step higher than I)
                        // ------
                        // IIC = 98
                        // subtractionBuffer = II
                        // subtractFrom = C (C is 4 steps higher than I)
                        // ------
                        // CIX = 109
                        // subtractionBuffer = I
                        // subtractFrom = X (X is 2 step higher than I)
                        // ------
                        for (int k = 0; k < length; k++) {
                            if (romanNumerals[testingIndex].value == valuesBuffer[k]) {
                                // grab the lowest value, higher than the highest numeral of the subtractand
                                subtractFrom = romanNumerals[testingIndex].value;
                            }
                        }
                        testingIndex += 1;
                    } while (subtractFrom == -1);
                }
            }
        }
    }

    for (int i = romanNumeralsCount - 1; i >= 0; i--) {
        for (int j = 0; j < length; j++) {
            if (valuesBuffer[j] == romanNumerals[i].value) {
                romanString[romanStringOffset++] = romanNumerals[i].symbol;
            }
        }
        // insert the subtraction buffer
        // in reverse order!
        // before subtractFrom!
        if (subtractFrom == romanNumerals[i].value) {
            for (int j = subtractionBufferOffset - 1; j >= 0; j--) {
                romanString[romanStringOffset++] = romanNumerals[subtractionBuffer[j]].symbol;
            }
            romanString[romanStringOffset++] = romanNumerals[i].symbol;
        }
    }
}


int* getRomanValuesArray(int num, int currentRomanIndex, int *resultSpace) 
{
    printf("Number: %i, Roman: %c\n", num, romanNumerals[currentRomanIndex].symbol);
    int romanStringOffset = 0;
    int count = 0;
    auto currentRoman = romanNumerals[currentRomanIndex];

    // first get all whole things of this type
    while (count < currentRoman.maxCount && num >= currentRoman.value) {
        *resultSpace = currentRoman.value;
        resultSpace++;
        num -= currentRoman.value;
        count++;
        printf("Current valiables: num = %i\n", num);
    }

    printf("Count: %i\n", count);

    // we're finished
    if (num == 0)
        return resultSpace;
    

    if (num <= maxPossibleRomanCombFrom(currentRomanIndex - 1)) {
        return getRomanValuesArray(num, currentRomanIndex - 1, resultSpace);
    }

    // if it is not possible to represent it using lower values
    else {
        int *nextResultSpace = 
            getRomanValuesArray(currentRoman.value - num, currentRomanIndex - 1, resultSpace);

        for (int *i = resultSpace; i < nextResultSpace; i++) {
            *i = -*i;
        }

        *nextResultSpace = currentRoman.value;

        return nextResultSpace + 1;        
    }
}



int convertRomanStringToValues(char *romanStr, int romanValsBuffer[]) 
{
    int offset = 0;
    while (*romanStr != '\0') {
        for (int i = 0; i < romanNumeralsCount; i++) {
            if (*romanStr == romanNumerals[i].symbol) {
                romanValsBuffer[offset++] = romanNumerals[i].value;
                break;
            }
        }
        romanStr++;
    }
    return offset;
}

// -------
// OLDER ALGO
// that sort of got too messy
// -------
// void convertArabicToRomanString(int num, char *romanString, int start = romanNumeralsCount - 1)
// {
//     printf("Number: %i\n", num);
//     int romanStringOffset = 0;
//     for (int i = start; i >= 0; i--) {
//         int count = 0;
//         auto currentRoman = romanNumerals[i];

//         // first get all whole things of this type
//         while (count < currentRoman.maxCount && num > currentRoman.value) {
//             romanString[romanStringOffset++] = currentRoman.symbol;
//             num -= currentRoman.value;
//             count++;
//             printf("\nCurrent valiables: i = %i, num = %i, str = %s", i, num, romanString);
//         }
//         // we're finished
//         if (num == 0)
//             return;

//         printf("alert\n");

//         int j = 0;
//         int changed = 0;
//         for (; j < i - 1; j++)
//             if (num <= romanNumerals[j].value) {
//                 i = j + 1;
//                 changed = 1;
//             }
//         if (changed)
//             continue;

//         // if it is not possible to represent it using lower values
//         if (num > maxPossibleRomanCombFrom(i - 1)) {
//             int leftover = currentRoman.value - num;
//             // get the substring using the same function
//             char substring[strlength];
//             resetString(substring, strlength);
//             convertArabicToRomanString(leftover, substring, i + 1);
//             // reverse it
//             reverseString(substring);
//             // concatenate
//             int j = 0;
//             // find the largest thing in string
//             int indexLargest = getIndexOfLargestRoman(romanString);
//             // subtract off the largest thing
//             char buffer[strlength];
//             resetString(buffer, strlength);
//             int bufferIndex = 0;
//             while (substring[j] != '\0') {
//                 buffer[bufferIndex++] = substring[j++];
//             }
//             for (int k = 0; k < romanStringOffset; k++) {
//                 buffer[bufferIndex++] = romanString[k];
//             }
//             // write the buffer back
//             strcpy(romanString, buffer);
//             romanStringOffset = bufferIndex;
//             romanString[romanStringOffset++] = currentRoman.symbol;
//             return;
//         }
//     }
// }