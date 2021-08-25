#include <assert.h>
#include <math.h>
#include "equationSolving.h"

const float PRECISION = 0.001f;

//===========================================================================================
//! @brief ���������� ������ ����������� ���������.
//!
//! @param [in] a ����������� ����������� ��������� (������� �����������).
//! @param [in] b ����������� ����������� ��������� (����������� ��� x).
//! @param [in] c ����������� ����������� ��������� (��������� ����).
//! @param [out] x1 ������ ����������� ���������.
//! @param [out] x2 ������ ����������� ���������.
//!
//! @note ����� ����������� ��������� ���������� ��� ������ �������,
//!       ���� ���� �� ���.
//!
//! @return ���������� ������ ��������� ����������� ���������.
//------------------------------------------------------------------------------------------

int solveQuadraticEquation(float a, float b, float c, float *x1, float *x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert((x1 - x2) != 0);

    int rootsCount = 0;

    *x1 = 0;
    *x2 = 0;

    if (compareZero(a) == 0)
        return solveLinearEquation(b, c, x1);

    if(compareZero(c) == 0)
    {
        rootsCount = solveLinearEquation(a, b, x1);
        *x2 = 0;
        if(rootsCount == INF_ROOTS)
        {
            return rootsCount;
        }
        else
        {
            return (rootsCount + 1);
        }
    }

    float D = b*b - 4*a*c;
    float multiplier = 1/(a*2);

    if (compareZero(D) == -1)
    {
        rootsCount = 0;
    }
    else if (compareZero(D) == 0)
    {
        *x1 = -b*multiplier;
        rootsCount = 1;
    }
    else
    {
        float sqrtD = sqrtf(D);
        *x1 = (-b - sqrtD)*multiplier;
        *x2 = (-b + sqrtD)*multiplier;
        rootsCount = 2;
    }

    return rootsCount;
}

//===========================================================================================
//! @brief ���������� ������ ��������� ��������� ���� ax + b = 0.
//!
//! @param [in] a �������� ����������� ��������� ���������.
//! @param [in] b ����������� ��������� ��������� (��������� ����).
//! @param [out] x ������ ��������� ���������.
//!
//! @return ���������� ������ ��������� ���������.
//------------------------------------------------------------------------------------------

int solveLinearEquation(float a, float b, float *x)
{
    assert(isfinite(a));
    assert(isfinite(b));

    assert(x != nullptr);

    int rootsCount = 0;

    if (compareZero(a) != 0 && compareZero(b) != 0)
    {
        *x = -b/a;
        rootsCount = 1;
    }
    else if (compareZero(a) != 0 && compareZero(b) == 0)
    {
        *x = 0;
        rootsCount = 1;
    }
    else if (compareZero(a) == 0 && compareZero(b) != 0)
    {
        rootsCount = 0;
    }
    else
    {
        rootsCount = INF_ROOTS;
    }

    return rootsCount;
}

//==========================================================================================
//! @brief ��������� ����� � ����.
//!
//! @param [in] number �����, ������� ����� �������� � ����.
//!
//! @return ������� ����������:
//!         1)  1, ���� ����� number ������ ����;
//!         2)  0, ���� ����� number ����� ����;
//!         3) -1, ���� ����� number ������ ����.
//------------------------------------------------------------------------------------------

int compareZero(float number)
{
    if (number > 0 + PRECISION)
    {
        return 1;
    }
    else if (0 - PRECISION <= number && number <= 0 + PRECISION)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
