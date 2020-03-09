#include <stdio.h>
#include <math.h>

int main()
{
    printf(
        "Alege:\n\
1. Calculati schema bloc numarul 1 \n\
2. max(2a, 2b, xc) / min(2x, cb, 2a)\n\
3. Calculati schema bloc numarul 2 \n\
");

    int t;
    scanf("%d", &t);

    switch (t)
    {
    case 1:
    {
        float a, b, c, x;
        printf("Introduceti variabila a, b, c, x:\n");
        scanf("%f%f%f%f", &a, &b, &c, &x);

        float y = log(a + x * x) + pow(sin(x / b), 2);

        float z = exp(-c * x) * (x + sqrt(x + a)) / (x - sqrt(abs(x - b)));

        printf("y = %f\n", y);
        printf("z = %f", z);
        break;
    }

    case 2:
    {
        float a, b, c, x;
        printf("Introduceti variabile a, b, c, x:\n");
        scanf("%f%f%f%f", &a, &b, &c, &x);

        float max, min;
        float t0 = 2 * a;
        float t1 = 2 * b;
        float t2 = x * c;
        float b0 = 2 * x;
        float b1 = c * b;
        float b2 = 2 * a;

        if (t0 > t1 && t0 > t2)
            max = t0;
        else if (t1 > t0 && t1 > t2)
            max = t1;
        else
            max = t2;

        if (b0 < b1 && b0 < b2)
            min = b0;
        else if (b1 < b0 && b1 < b2)
            min = b1;
        else
            min = b2;

        float y = max / min;
        printf("y = %f", y);
        return 0;
    }

    case 3:
    {
        printf("Introduceti a, b, x:\n");
        float a, b, x, s;
        scanf("%f%f%f", &a, &b, &x);
        if (x < 2.8) {
            s = (a + b) / (exp(x) + cos(x));
        } else if (x < 6) {
            s = (a + b) / (x + 1);
        } else {
            s = exp(x) + sin(x);
        }
        printf("s = %f", s);
        break;
    }

    default:
        printf("Optiunea nu este admisibila", t);
    }

    return 0;
}