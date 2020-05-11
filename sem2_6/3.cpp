// Se dă o structură:
//      numar_locuri(int), 
//      marca(char), 
//      culoarea(char), 
//      anul_fabricarii(int), 
//      pret(float), 
//      ziua_fabricarii(int), 
//      luna_fabricarii(int). 
//
// Să se calculeze procentul automobilelor de marca “Nissan” unde anul_fabricarii=2010 si luna_fabricarii=2
#include <stdio.h>
#include <string.h>

#define seekFirm "Nissan"
#define seekYear 2010
#define seekMonth 2

#define strlength 100

struct Date {
    int anul_fabricarii;
    int ziua_fabricarii;
    int luna_fabricarii;
};

struct Car {
    int numar_locuri;
    char marca[strlength];
    char culoarea[strlength];
    float pret;
    Date date;
};

#define maxNumCars 100

Car data[maxNumCars];

void printCar(Car *car);
void scanCar(Car *car);

int main()
{
    int numCars;
    printf("Introduceti numarul de masini: ");
    scanf("%i", &numCars);

    printf("\nProcesul de introducere a datelor este initializat.\n");
    for (int i = 0; i < numCars; i++) {
        scanCar(&data[i]);
    }

    puts("\n");

    // afisam toate masinile:
    for (int i = 0; i < numCars; i++) {
        printCar(&data[i]);
    }

    Car matches[numCars];
    int matchesCount = 0; // index into to matches array


    for (int i = 0; i < numCars; i++) {
        if (strcmp(seekFirm, data[i].marca) == 0 
            && data[i].date.anul_fabricarii == seekYear
            && data[i].date.luna_fabricarii == seekMonth)

                matches[matchesCount++] = data[i];
    }

    // afisam rezultatele
    printf("\n\nOfertele de marca \"%s\" care sunt produse in anul %i, luna %i\n\n", seekFirm, seekYear, seekMonth);
    for (int i = 0; i < matchesCount; i++) {
        printCar(&matches[i]);
    }

    float share = ((float)matchesCount) / ((float)numCars) * 100;
    printf("\nProcentajul lor este %5.2f", share);

    return 0;
}


void printCar(Car *car) 
{
    printf("\nNumar de locuri ......... %i", car->numar_locuri);
    printf("\nMarca ................... %s", car->marca);
    printf("\nCuloarea ................ %s", car->culoarea);
    printf("\nAnul fabricarii ......... %i", car->date.anul_fabricarii);
    printf("\nPretul .................. %f", car->pret);
    printf("\nZiua fabricarii ......... %i", car->date.ziua_fabricarii);
    printf("\nLuna fabricarii ......... %i", car->date.luna_fabricarii);
    printf("\n---------------------------------\n");
}

void scanCar(Car *car)
{
    printf("\nIntroduceti Numarul de locuri: ");
    scanf("%i", &car->numar_locuri);
    printf("Introduceti Marca: ");
    scanf("%s", &car->marca);
    printf("Introduceti Culoarea: ");
    scanf("%s", &car->culoarea);
    printf("Introduceti Anul fabricarii: ");
    scanf("%i", &car->date.anul_fabricarii);
    printf("Introduceti Pretul: ");
    scanf("%f", &car->pret);
    printf("Introduceti Ziua fabricarii: ");
    scanf("%i", &car->date.ziua_fabricarii);
    printf("Introduceti Luna fabricarii: ");
    scanf("%i", &car->date.luna_fabricarii);
    printf("\n---------------------------------\n");
}