#include <stdio.h>
#include <string.h>
#include"testProgram.h"
#include"userInteraction.h"
#include"equationSolution.h"

//------------------------------------------------------------------------------------------
//! @brief ������������ ������� isLessZero � isEqualZero �� ������������ ������.
//!
//! @param [in] number �����, ������� ����� �������� � ����.
//! @param [in] correctIsLessZero �����, ������� ������ ������� �������
//!             isLessZero ��� ���������� ������, ���� � �������� ���������
//!             �� �������� ����� number.
//! @param [in] correctIsEqualZero �����, ������� ������ ������� �������
//!             isLessZero ��� ���������� ������, ���� � �������� ���������
//!             �� �������� ����� number.
//!
//! @note � ������ ��������� ������ ������� isLessZero � isEqualZero, � ������� ����� ���������
//!       ��������������� ���������.
//------------------------------------------------------------------------------------------
void testIsLessZeroAndIsEqualZero(float number, bool correctIsLessZero, bool correctIsEqualZero)
{
    bool returnIsLessZero = isLessZero(number);
    bool returnIsEqualZero = isEqualZero(number);

    printf("[%s]isLessZero(%.4f) returned: %d, expected: %d\n",
           returnIsLessZero == correctIsLessZero ? "correct" : "incorrect",
           number, returnIsLessZero, correctIsLessZero);

    printf("[%s]isEqualZero(%.4f) returned: %d, expected: %d\n",
           returnIsEqualZero == correctIsEqualZero ? "correct" : "incorrect",
           number, returnIsEqualZero, correctIsEqualZero);
}

//------------------------------------------------------------------------------------------
//! @brief ������������ ������� solveLinearEquation,
//!        �������� �������� ��������� ���� a*x + b = 0, �� ������������ ������.
//!
//! @param [in] a �������� ����������� ��������� ���������.
//! @param [in] b ����������� ��������� ��������� (��������� ����).
//! @param [in] correctX ������, ������� ������ ������� �������
//!        solveLinearEquation ��� ���������� ������, ���� � �������� ����������
//!        �� �������� ����� a � b.
//! @param [in] correctRootsCount ���������� �������, ������� ������ ������� �������
//!        solveLinearEquation ��� ���������� ������, ���� � �������� ����������
//!        �� �������� ����� a � b.
//!
//! @note � ������ ��������� ������ ������� solveLinearEquation, � ������� ����� ���������
//!       ��������������� ���������.
//------------------------------------------------------------------------------------------
void testSolveLinearEquation(float a, float b, float correctX, int correctRootsCount)
{
    float x = 0;
    int rootsCount = 0;

    rootsCount = solveLinearEquation(a, b, &x);
    printf("[%s]solveLinearEquation(%.3f, %.3f) returned: "
           "%.3f and %d, expected: %.3f and %d\n",
           isEqualZero(x - correctX) && rootsCount == correctRootsCount ? "correct" : "incorrect",
           a, b, x, rootsCount, correctX, correctRootsCount);
}

//------------------------------------------------------------------------------------------
//! @brief ������������ ������� solveQuadraticEquation,
//!        �������� ���������� ��������� ���� a*x^2 + b*x + c = 0, �� ������������ ������.
//!
//! @param [in] a ����������� ����������� ��������� (������� �����������).
//! @param [in] b ����������� ����������� ��������� (����������� ��� x).
//! @param [in] c ����������� ����������� ��������� (��������� ����).
//! @param [in] correctX1 ������ ������, ������� ������ ������� �������
//!        solveQuadraticEquation ��� ���������� ������, ���� � �������� ����������
//!        �� �������� ����� a, b � c.
//! @param [in] correctX2 ������ ������, ������� ������ ������� �������
//!        solveQuadraticEquation ��� ���������� ������, ���� � �������� ����������
//!        �� �������� ����� a, b � c.
//! @param [in] correctRootsCount ���������� �������, ������� ������ ������� �������
//!        solveQuadraticEquation ��� ���������� ������, ���� � �������� ����������
//!        �� �������� ����� a, b � c.
//!
//! @note � ������ ��������� ������ ������� solveQuadraticEquation, � ������� ����� ���������
//!       ��������������� ���������.
//------------------------------------------------------------------------------------------
void testSolveQuadraticEquation(float a, float b, float c, float correctX1, float correctX2, int correctRootsCount)
{
    float x1 = 0;
    float x2 = 0;
    int rootsCount = 0;

    rootsCount = solveQuadraticEquation(a, b, c, &x1, &x2);
    printf("[%s]solveQuadraticEquation(%.3f, %.3f, %.3f) returned: "
           "%.3f, %.3f and %d, expected: %.3f, %.3f and %d\n",
           isEqualZero(x1 - correctX1) && isEqualZero(x2 - correctX2)&& rootsCount == correctRootsCount ? "correct" : "incorrect",
           a, b, c, x1, x2, rootsCount,
           correctX1, correctX2, correctRootsCount);
}

//------------------------------------------------------------------------------------------
//! @brief ������� ��������� ���������� ��������� ������.
//!
//! @param [in] argc ���������� ���������� ��������� ������.
//! @param [in] argv ������ ���������� ��������� ������.
//!
//! @note � ������, ���� ����� �� ��������� ������� argv ����� ������ "--test"
//!       ��� "-t", �� ����� ������� ������� testProgram.
//------------------------------------------------------------------------------------------
void processCommandLineArguments(int argc, char *argv[])
{
    for (int i = 0; i < argc; i += 1)
    {
        if (!strcmp(argv[i], "--test") || !strcmp(argv[i], "-t"))
        {
            testProgram();
            break;
        }
    }
}

//------------------------------------------------------------------------------------------
//! @brief ������� ������������ ��������� �� ����������� ������.
//!
//! @note  ������� testProgram �������� ����������� �������: testIsLessZero,
//!        testIsEqualZero, testSolveLinearEquation � testSolveQuadraticEquation,
//!        ������� � ���� ������� �������� �� ������������ ������ ��������������� ��
//!        �������: isLessZero, isEqualZero, solveLinearEquation � solveQuadraticEquation.
//------------------------------------------------------------------------------------------
void testProgram()
{
    testIsLessZeroAndIsEqualZero(-1.0f,    true,  false);
    testIsLessZeroAndIsEqualZero(-0.0011f, true,  false);
    testIsLessZeroAndIsEqualZero(-0.001f,  false, true);
    testIsLessZeroAndIsEqualZero( 0.0f,    false, true);
    testIsLessZeroAndIsEqualZero( 0.001f,  false, true);
    testIsLessZeroAndIsEqualZero( 0.0011f, false, false);
    testIsLessZeroAndIsEqualZero( 1.0f,    false, false);

    testSolveLinearEquation(0, 0,  0, INF_ROOTS);
    testSolveLinearEquation(0, 1,  0, 0);
    testSolveLinearEquation(1, 1, -1, 1);

    testSolveQuadraticEquation(1, 1,  1,  0, 0, 0);
    testSolveQuadraticEquation(0, 0,  0,  0, 0, INF_ROOTS);
    testSolveQuadraticEquation(1, 2,  1, -1, 0, 1);
    testSolveQuadraticEquation(1, 5, -6, -6, 1, 2);
}
