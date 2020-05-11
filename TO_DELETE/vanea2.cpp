#include <stdio.h>
#include <string.h>


char firstName[] = "Ivan";
char secondName[] = "Titov";
char patronymic[] = "Igor";

char vowels[] = "auioeAUIOE";

#define buffsize 100

// #define buffsize = sizeof(firstName) + sizeof(secondName) + sizeof(patronymic) - 2


int countVowels(char *str) 
{
    int count = 0;
    for (int i = 0; i < sizeof(vowels) - 1; i++) {

        char *current = str;

        while(true) {

            current = strchr(current, vowels[i]);

            if (current == NULL) 
                break;

            count++;
            current++;
        }
    }
    return count;
}


int main() 
{
    char combined[buffsize];
    combined[0] = '\0';
    strcat(combined, firstName);
    strcat(combined, secondName);
    strcat(combined, patronymic);

    int numVowels = countVowels(firstName);
    printf("%i\n", numVowels);
    int numConsonants = strlen(firstName) - numVowels;
    printf("%i\n", numConsonants);

    #define printAtPos 3

    // strrev(patronymic);
    // puts(patronymic);

    for (
        char *current = patronymic; 
        current < patronymic + sizeof(patronymic) - 1; 
        current += printAtPos)
    {
        printf("%c", *current);
    }

    char s4[4];
    memcpy(s4, firstName, 3);
    s4[4] = '\0';

    // for (int i = 0; i < 3; i++) {
    //     s4[i] = firstName[i];
    // }
    // s4[4] = '\0'

    int greater = strcmp(s4, firstName);

    printf(greater < 0 ? "Less" : greater == 0 ? "Equal" : "Greater");
    return 1;
}
