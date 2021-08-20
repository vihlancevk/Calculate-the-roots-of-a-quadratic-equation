#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

const int INF_ROOTS = 3;
const float PRECISION = 0.001f;

float readCoefficient(char coefficientDesignation);
void outputAnswer(float x1, float x2, int rootsCount);
int isLessZero(float number);
int isEqualZero(float number);
void solveQuadraticEquation(float a, float b, float c, float *x1, float *x2, int *rootsCount);

int main()
{
    float a = 0, b = 0, c = 0;

    char const coefficientsDesignation[3] = {'a', 'b', 'c'};

    printf("Enter coefficients in quadratic equation in format a*x^2 + b*x + c = 0\n");

    a = readCoefficient(coefficientsDesignation[0]);
    b = readCoefficient(coefficientsDesignation[1]);
    c = readCoefficient(coefficientsDesignation[2]);

    int rootsCount = 0;
    float x1 = 0, x2 = 0;

    solveQuadraticEquation(a, b, c, &x1, &x2, &rootsCount);

    outputAnswer(x1, x2, rootsCount);

    return 0;
}

float readCoefficient(char coefficientDesignation)
{
    float number = 0;
    int characterInputStream  = 0;

    printf("%c: ", coefficientDesignation);
    int numberEnteredCharacters = scanf("%f", &number);

    while (numberEnteredCharacters == 0 || getchar() != '\n')
    {
        while ((characterInputStream = getchar()) != '\n');

        printf("Please, enter the correct value for the coefficient\n");
        printf("%c: ", coefficientDesignation);
        numberEnteredCharacters = scanf("%f", &number);
    }

    return number;
}

void outputAnswer(float x1, float x2, int rootsCount)
{
    switch (rootsCount)
    {
        case 0:
        {
            printf("No valid roots");
            break;
        }
        case 1:
        {
            printf("The quadratic equation has only one root:\n%.3f", x1);
            break;
        }
        case 2:
        {
            printf("The quadratic equation has two roots:\n%.3f and %.3f", x1, x2);
            break;
        }
        case INF_ROOTS:
        {
            printf("Infinitely many roots");
            break;
        }
        default:
        {
            printf("Wrong parameter value rootsCount");
        }
    }
}

int isLessZero(float number)
{
    return number < 0 - PRECISION;
}

int isEqualZero(float number)
{
    return number >= 0 - PRECISION && number <= 0 + PRECISION;
}

void solveQuadraticEquation(float a, float b, float c, float *x1, float *x2, int *rootsCount)
{
    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(rootsCount != nullptr);

    *x1 = 0;
    *x2 = 0;

    if (!isEqualZero(a))
    {
        float D = b*b - 4*a*c;
        float multiplier = 1/(a*2);

        if (isLessZero(D))
        {
            *rootsCount = 0;
        }
        else if (isEqualZero(D))
        {
            *x1 = -b*multiplier;
            *rootsCount = 1;
        }
        else
        {
            float sqrtD = sqrtf(D);
            *x1 = (-b - sqrtD)*multiplier;
            *x2 = (-b + sqrtD)*multiplier;
            *rootsCount = 2;
        }
    }
    else
    {
        if (isEqualZero(b) && isEqualZero(c))
        {
            *rootsCount = INF_ROOTS;
        }
        else if (isEqualZero(b) && !isEqualZero(c))
        {
            *rootsCount = 0;
        }
        else if (!isEqualZero(b) && isEqualZero(c))
        {
            *rootsCount = 1;
        }
        else
        {
            *x1 = -c/b;
            *rootsCount = 1;
        }
    }
}


