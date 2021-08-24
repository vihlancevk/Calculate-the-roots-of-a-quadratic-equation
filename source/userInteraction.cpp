#include <stdio.h>
#include <assert.h>
#include <math.h>
#include"userInteraction.h"
#include"equationSolution.h"

//------------------------------------------------------------------------------------------
//! @brief ������� ����� � �������.
//------------------------------------------------------------------------------------------
void clearInputBuffer()
{
    while (getchar() != '\n');
}

//------------------------------------------------------------------------------------------
//! @brief ���������� � ������� ��������� ������������ ����������� ���������.
//!
//! @param [in] coefficientSymbol ��������� ����������� ��������� ������������.
//!
//! @note ������������ ������ �������� ������������,
//!       ������� ������������ �������� coefficientSymbol;
//!       ����� ��������� ���� ����� ���������� ������ Enter.
//!
//! @return �������� � ������� �����.
//------------------------------------------------------------------------------------------
float readCoefficient(char coefficientSymbol)
{
    float number = 0;

    printf("%c: ", coefficientSymbol);
    int isCorrectInput = scanf("%f", &number);

    while (isCorrectInput == 0 || getchar() != '\n')
    {
        clearInputBuffer();

        printf("Please, enter the correct value for the coefficient\n");
        printf("%c: ", coefficientSymbol);
        isCorrectInput = scanf("%f", &number);
    }

    return number;
}

//------------------------------------------------------------------------------------------
//! @brief ����� ������� ����������� ��������� �� �������.
//!
//! @param [in] x1 ������ ������ ���������.
//! @param [in] x2 ������ ������ ���������.
//! @param [in] rootsCount ���������� ������ ���������.
//!
//! @note � ������� ������������ ������ ���� �� ��������� ��������� ������:
//!       1) No valid roots - ��� ������,
//!       ��� � ����������� ��������� ��� �������������� ������;
//!       2) The quadratic equation has only one root: x1 - ��� ������,
//!       ��� ���������� ��������� ����� ������ ���� ������ x1,
//!       ��� x1 - ������������ �����;
//!       3) The quadratic equation has two roots:
//!       x1 and x2 - ��� ������, ��� ���������� ��������� ����� ��� �����:
//!       x1 � x2, ��� x1 � x2 - ������������ �����;
//!       4) Infinitely many roots - ��� ������,
//!       ��� ���������� ��������� ����� ���������� ����� ������.
//!
//! @warning � ������, ���� � ���� ���������� ��������� �� ���� ������ �������
//!          ����� �������� rootsCount � ������������
//!          ��� ���� ��������� (���������� ��������: 0, 1, 2, INF_ROOTS (=-1)),
//!          �� � ������� ����� ��������� ��������� �� ������:
//!          Wrong parameter value rootsCount.
//------------------------------------------------------------------------------------------
void outputAnswer(float x1, float x2, int rootsCount)
{
    assert(isfinite(x1));
    assert(isfinite(x2));

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
