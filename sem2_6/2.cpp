// Pentru o listă de abonaţi se cunoaşte: 
//      nume(char), 
//      prenume(char), 
//      num_de_telefon(char),
//      orasul(char), 
//      strada(char).
//
// Să se scrie un program care calculează procentul abonaţilor din oraşul “Bălţi”.       

#include <stdio.h>
#include <string.h>

const char *matchCity = "Balti";

struct Person {
    const char *nume;
    const char *prenume;
    const char *num_de_telefon;
    const char *orasul;
    const char *strada;
};

// cream datele pentru demonstratie
Person data[] = {
    {"Mihail",  "Basmacov", "+1234",  "Balti",    "Stefan cel Mare"},
    {"Ion",     "Bursa",    "+1234",  "Chisinau", "Stefan Voda"},
    {"Nichita", "Mihalkov", "+12311", "Chisinau", "Bogdan"},
    {"Ion",     "Rosu",     "+12312", "Chisinau", "Bogdan"},
    {"Ion",     "Ion",      "+12334", "Chisinau", "Bogdan Voievod"},
    {"Cristian","Balti",    "+12313", "Balti",    "Stefan cel Mare"},
    {"Orian",   "Verde",    "+12344", "Balti",    "Bogan Voievod"},
};

#define dataLength sizeof(data) / sizeof(Person)

void printPerson(Person *person);

int main()
{
    // afisam toate persoanele:
    for (int i = 0; i < dataLength; i++) {
        printPerson(&data[i]);
    }

    Person matches[dataLength];
    int matchesCount = 0; // index into to matches array

    // gasim personele locuite in Balti
    for (int i = 0; i < dataLength; i++) {
        if (strcmp(data[i].orasul, matchCity) == 0)
            matches[matchesCount++] = data[i];
    }

    // afisam rezultatele
    printf("\nPersoanele din %s:\n", matchCity);
    for (int i = 0; i < matchesCount; i++) {
        printPerson(&matches[i]);
    }

    float share = ((float)matchesCount) / ((float)dataLength) * 100;
    printf("\nProcentajul lor este %f", share);

    return 0;
}


void printPerson(Person *person) 
{
    printf("Persoana %s %s este locuita in %s, str. %s, si are numarul de telefon %s\n",
           person->nume,
           person->prenume,
           person->orasul,
           person->strada,
           person->num_de_telefon);
}
