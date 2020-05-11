// Să se scrie un program care adauga cuvinte la sfarsitul fisierului, 
// iar unde intalneste litera "a" o schimba cu secvenţa "dor" 
// si afisează informatia din fişierul dat la ecran.

#include <stdio.h>
#include <string.h>

#define matchChar 'a'
#define replaceSeq "dor"
#define replaceSeqLength 3
#define fname "test.txt"
#define bufSize 100

int main()
{
    FILE *f = fopen(fname, "a+");
    char buff[bufSize];

    puts("Introduceti un sir ca sa-l scrieti in file");
    gets(buff);

    char modBuff[bufSize];
    const char *rs = replaceSeq;
    int i = 0;
    int j = 0;

    while (true) {
        if (buff[i] == matchChar) {
            for (int k = 0; k < replaceSeqLength; k++) {
                modBuff[j++] = rs[k];
            }
        } else {
            modBuff[j++] = buff[i];

            if (buff[i] == '\0') 
                break;
        }
        i++;
    }

    fputs(modBuff, f);
    fprintf(f, "\n");
    rewind(f);
    puts("Continutul fisierului:");
    fgets(buff, bufSize, f);
    puts(buff);

    return 0;
}