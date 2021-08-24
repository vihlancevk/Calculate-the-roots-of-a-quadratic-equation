#include <assert.h>
#include <math.h>
#include"equationSolution.h"

const float PRECISION = 0.001f;

//------------------------------------------------------------------------------------------
//! @brief ��������� ����� � ����.
//!
//! @param [in] number �����, ������� ����� �������� � ����.
//!
//! @note ��������� ����� ���������� ��� ������ ��������� PRECISION = 0.001f,
//!       ����� �������, ���� ����� �������� � �������� �� ����� �������������
//!       �� 0 - PRECISION,
//!       �� ��� ������ ����.
//!
//! @return ������ �� ���� �����.
//------------------------------------------------------------------------------------------
bool isLessZero(float number)
{
    assert(isfinite(number));

    return number < 0 - PRECISION;
}

//------------------------------------------------------------------------------------------
//! @brief ��������� ����� � ����.
//!
//! @param [in] number �����, ������� ����� �������� � ����.
//!
//! @note ��������� ����� ���������� ��� ������ ��������� PRECISION = 0.001f,
//!       ����� �������, ���� ����� �������� � �������� �� 0 - PRECISION
//!       �� 0 + PRECISION,
//!       �� ��� ����� ����.
//!
//! @return �������� �� ����� ����.
//------------------------------------------------------------------------------------------
bool isEqualZero(float number)
{
    assert(isfinite(number));

    return number >= 0 - PRECISION && number <= 0 + PRECISION;
}

//------------------------------------------------------------------------------------------
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

    if (!isEqualZero(a) && !isEqualZero(b))
    {
        *x = -b/a;
        rootsCount = 1;
    }
    else if (!isEqualZero(a) && isEqualZero(b))
    {
        *x = 0;
        rootsCount = 1;
    }
    else if (isEqualZero(a) && !isEqualZero(b))
    {
        rootsCount = 0;
    }
    else
    {
        rootsCount = INF_ROOTS;
    }

    return rootsCount;
}

//------------------------------------------------------------------------------------------
//! @brief ���������� ������ ����������� ���������.
//!
//! @param [in] a ����������� ����������� ��������� (������� �����������).
//! @param [in] b ����������� ����������� ��������� (����������� ��� x).
//! @param [in] c ����������� ����������� ��������� (��������� ����).
//! @param [out] x1 ������ ����������� ���������.
//! @param [out] x2 ������ ����������� ���������.
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

    if (!isEqualZero(a))
    {
        float D = b*b - 4*a*c;
        float multiplier = 1/(a*2);

        if (isLessZero(D))
        {
            rootsCount = 0;
        }
        else if (isEqualZero(D))
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
    }
    else
    {
        rootsCount = solveLinearEquation(b, c, x1);
    }

    return rootsCount;
}
