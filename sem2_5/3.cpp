// n46
// Se da o propozitie formata din cuvinte separate prin spatiu
// De afisat:
//      a) cuvintele care incep cu o litera introdusa de la tastatura
//      b) care incep cu o vocala
//      c) care se se termina cu o vocala
//      d) in ordine alfabetica conform primei litere
#include <stdio.h>
#include <string.h>
#define strlength 100

void findWordsStartingWithLetterFromSet(char *str, char *set, char** results);
void findWordsEndingWithLetterFromSet(char *str, char *set, char** results);
void resetBuffer(char **buff);
void printResultBufferAsWords(char **buff);


int main()
{
    char string[strlength];
    printf("Dati o propozitie: ");
    gets(string);
    
    char letterSet[2];
    letterSet[1] = '\0';
    printf("Dati un caracter: ");
    scanf("%c", letterSet);

    char *resultsBuffer[strlength];
    resetBuffer(resultsBuffer);


    // A)
    findWordsStartingWithLetterFromSet(string, letterSet, resultsBuffer);

    printf("\nCuvintele care se incep cu %c sunt: ", letterSet[0]);
    printResultBufferAsWords(resultsBuffer);


    char vowelSet[] = "AEUIOaeuio";

    // B) starts with vowels
    resetBuffer(resultsBuffer);
    findWordsStartingWithLetterFromSet(string, vowelSet, resultsBuffer);

    printf("\n\nCuvintele care se incep cu o vocala sunt: ", vowelSet);
    printResultBufferAsWords(resultsBuffer);

    // C) ends with vowels
    resetBuffer(resultsBuffer);
    findWordsEndingWithLetterFromSet(string, vowelSet, resultsBuffer);

    printf("\n\nCuvintele care se termina cu o vocala sunt: ", vowelSet);
    printResultBufferAsWords(resultsBuffer);

    // D) sort by first letter
    printf("\n\nCuvintele sortate conform primei litere: ");
    for (char i = 'a'; i < 'z'; i++) {

        char letterSet[] = { i, '\0' };

        resetBuffer(resultsBuffer);
        findWordsStartingWithLetterFromSet(string, letterSet, resultsBuffer);
        printResultBufferAsWords(resultsBuffer);
    }

    return 0;
}


void findWordsStartingWithLetterFromSet(char *str, char *set, char** results)
{

    if (*str == '\0')
        return;

    int num_results = 0;

    // start from the very beginning of the string
    // assume the string is valid
    char *wordStart = str;

    do {

        // suitable word found
        if (strchr(set, *wordStart) != 0) {
            results[num_results++] = wordStart;
        }
        
        wordStart = strchr(wordStart, ' ');

        if (wordStart == 0)
            return;

        // point to the actual start of a word
        wordStart++;

    } while (true);
}


void findWordsEndingWithLetterFromSet(char *str, char *set, char** results)
{
    if (*str == '\0')
        return;

    int num_results = 0;

    // start from the very beginning of the string
    // assume the string is valid
    char *wordStart = str;

    do {
        // the address of the end of the current word
        char *nextAddress = strchr(wordStart, ' ');

        if (nextAddress == 0)
            nextAddress = strlen(str) + str - 1;
        else 
            nextAddress--;

        // suitable word found
        if (strchr(set, *nextAddress) != 0) {
            results[num_results++] = wordStart;
        }        

        // point to the start of a new word, which is the end of the current word 
        // + one space for space and + one to get to the letter
        wordStart = nextAddress + 2;
    } 

    while (*(wordStart - 1) != '\0');
}


void resetBuffer(char **buff) 
{
    for (int i = 0; i < strlength; i++)
        buff[i] = 0;
}

void printResultBufferAsWords(char **buff) 
{
    for (int i = 0; i < strlength; i++) {
        if (buff[i] == 0)
            break;
            
        puts("");
        for (char *j = buff[i]; *j != ' ' && *j != '\0'; j++)
            printf("%c", *j);
    }
}