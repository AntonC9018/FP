// Se consideră  o listă cu oferte de vânzare a locuinţelor ce conţin urmatoarele date: 
//      numărul ofertei(int),
//      sector(char),
//      numarul_de_odai(int),
//      pretul(float). 
// Să se scrie un program care ar afişa procentul sectorului ce se începe cu litera “T”.
//
// Remarca: Presupun ca sectorii sunt char*. In alt caz, "se incepe" n-are sens.
//

#include <stdio.h>
#include <string.h>

#define charToLookForAtStart 'T'

struct Offer {
    int num;
    const char *sector;
    int num_rooms;
    float price;
};

// cream datele pentru demonstratie
Offer data[] = {
    { 0, "TA", 2, 100.0f },
    { 1, "TB", 3, 200.0f },
    { 2, "QA", 1, 300.0f },
    { 3, "AA", 1, 400.0f },
    { 4, "QB", 1, 500.0f },
    { 5, "TA", 1, 200.0f },
    { 6, "TA", 1, 500.0f },
    { 7, "TB", 5, 900.0f },
    { 8, "QA", 2, 600.0f },
    { 9, "QB", 3, 550.0f }
};

#define dataLength sizeof(data) / sizeof(Offer)

void printOffer(Offer *offer);


int main()
{
    // afisam toate ofertele:
    for (int i = 0; i < dataLength; i++) {
        printOffer(&data[i]);
    }

    Offer matches[dataLength];
    int matchesCount = 0; // index into to matches array

    // gasim ofertele cu "T"
    for (int i = 0; i < dataLength; i++) {
        if (data[i].sector[0] == charToLookForAtStart)
            matches[matchesCount++] = data[i];
    }

    // afisam rezultatele
    printf("\nOfertele, sectorul carora se incepe cu %c\n\n", charToLookForAtStart);
    for (int i = 0; i < matchesCount; i++) {
        printOffer(&matches[i]);
    }

    float share = (float) matchesCount / dataLength * 100;

    printf("\nProcentajul lor este %6.2f", share);

    return 0;
}


void printOffer(Offer *offer) 
{   
    printf("Oferta numarul %i:",        offer->num);
    printf("\nLocatia ......... %8s",   offer->sector);
    printf("\nNumarul de camere %8i",   offer->num_rooms);
    printf("\nPretul .......... %8.2f", offer->price);
    printf("\n---------------------------------\n");
}
