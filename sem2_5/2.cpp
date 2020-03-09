// ex. 14
// De gasit cel mai lung (a) si cel mai scurt (b)
// cuvant intr-o propozitie, unde ele sunt separate cu spatiile
#include <stdio.h>
#include <string.h>
#define strlength 100

struct Word {
    char *ptr;
    int size;
};

enum State {
    NO_WORD, READING_WORD
};

// The bit determines whether the longest or the shortest string is to be searched for
// The bit being equal to 1 means that we look for the shortest substring
// Conversely, bit = 0 means we look for the shortest one
Word findWordAlgo(char *str, int bit)
{
    Word result = {str, bit ? __INT_MAX__ : 0};
    Word currentWord = {0, 0};

    State state = NO_WORD;

    while (true) {
        if (state == NO_WORD) {
            // ignore consecutive spaces and spaces at the first position
            if (*str != ' ' && *str != '\0') {  
                currentWord.ptr = str;
                currentWord.size = 0;
                state = READING_WORD;
            }
        }
        if (state == READING_WORD) {
            // reached the end of word/string
            if (*str == ' ' || *str == '\0') {      
                if (bit                                     // depending on the algo selected
                        ? (result.size > currentWord.size)  // look for min
                        : (result.size < currentWord.size)) // look for max
                {
                    result.size = currentWord.size;         // reset best result
                    result.ptr = currentWord.ptr;
                    state = NO_WORD;
                }
            } else {
                currentWord.size++;
            }
        }
        if (*str == '\0') break;
        str++;  // go to the next character
    }
    
    return result;
}


Word findLongestWord(char *str)
{
    return findWordAlgo(str, 0);
}


Word findShortestWord(char *str)
{
    return findWordAlgo(str, 1);
}


int main()
{
    char str[strlength];
    printf("Introduceti o propozitie: ");
    gets(str);
    Word longest = findLongestWord(str);
    Word shortest = findShortestWord(str);

    // debug
    // printf("%p, %i\n", longest.ptr, longest.size);
    // printf("%p, %i\n", shortest.ptr, shortest.size);

    *(longest.ptr + longest.size) = '\0';
    *(shortest.ptr + shortest.size) = '\0';

    printf("Cel mai lung cuvant este \"%s\" si are lungimea %i\n", longest.ptr, longest.size);
    printf("Cel mai scurt cuvant este \"%s\" si are lungimea %i", shortest.ptr, shortest.size);

    return 0;
}