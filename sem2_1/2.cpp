// 121
// Sunt dati anii cand in Moldova au avut loc cutremuri (ordonat)
// De gasit cea mai lunga perioada intre anii consecutivi.

#include "stdio.h"

const int years[] = {
    1605,
    1620,
    1679,
    1681,
    1701,
    1738,
    1740,
    1746,
    1790,
    1802,
    1829,
    1893,
    1898,
    1908,
    1934,
    1940,
    1977,
    1986
};

int main() 
{
    int longestBoundaries[] = { years[0], years[1] };
    int longestInterval = years[1] - years[0];

    for (int i = 1; i < sizeof(years) / sizeof(int) - 1; i++) {
        if (years[i + 1] - years[i] > longestInterval) {
            longestInterval = years[i + 1] - years[i];
            longestBoundaries[0] = years[i];
            longestBoundaries[1] = years[i + 1];
        }
    }

    printf("Intervalul intre cutremuri cel mai lung a avut loc intre anii %i si %i si echivaleaza cu %i", 
        longestBoundaries[0],
        longestBoundaries[1],
        longestInterval);

    return 0;
}