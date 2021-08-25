#include <stdio.h>
#include <string.h>
#include "testProgram.h"
#include "userInteraction.h"
#include "equationSolving.h"

//==========================================================================================
//! @brief ������������ ������� compareZero �� ������������ ������.
//!
//! @param [in] number �����, ������� ����� �������� � ����.
//! @param [in] correctAnswer �����, ������� ������ ������� �������
//!             campareZero ��� ���������� ������, ���� � �������� ���������
//!             �� �������� ����� number
//!
//! @note � ������ ��������� ������ ������� compareZero, � ������� ����� ���������
//!       ��������������� ���������.
//------------------------------------------------------------------------------------------

void testCompareZero(float number, int correctAnswer)
{
    int returnAnswer = compareZero(number);

    printf("[%s]compareZero(%.4f) returned: %d, expected: %d\n",
           (returnAnswer == correctAnswer) ? "correct" : "incorrect",
           number, returnAnswer, correctAnswer);
}

//==========================================================================================
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
    int rootsCount = solveLinearEquation(a, b, &x);

    printf("[%s]solveLinearEquation(%.3f, %.3f) returned: "
           "%.3f and %d, expected: %.3f and %d\n",
           (compareZero(x - correctX) == 0 && rootsCount == correctRootsCount) ? "correct" : "incorrect",
           a, b, x, rootsCount, correctX, correctRootsCount);
}

//==========================================================================================
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
    float x1 = 0, x2 = 0;
    int rootsCount = solveQuadraticEquation(a, b, c, &x1, &x2);

    printf("[%s]solveQuadraticEquation(%.3f, %.3f, %.3f) returned: "
           "%.3f, %.3f and %d, expected: %.3f, %.3f and %d\n",
           (compareZero(x1 - correctX1) == 0 && compareZero(x2 - correctX2) == 0 && rootsCount == correctRootsCount) ? "correct" : "incorrect",
           a, b, c, x1, x2, rootsCount,
           correctX1, correctX2, correctRootsCount);
}

//==========================================================================================
//! @brief ������� ��������� ���������� ��������� ������.
//!
//! @param [in] argc ���������� ���������� ��������� ������.
//! @param [in] argv ������ ���������� ��������� ������.
//!
//! @note � ������, ���� ����� �� ��������� ������� argv ����� ������ "--test"
//!       ��� "-t", �� ����� ������� ������� testProgram.
//------------------------------------------------------------------------------------------

void processCommandLineArguments(const int argc, const char *argv[])
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

//==========================================================================================
//! @brief ������� ������������ ��������� �� ����������� ������.
//!
//! @note  ������� testProgram �������� ����������� �������: testIsLessZero,
//!        testIsEqualZero, testSolveLinearEquation � testSolveQuadraticEquation,
//!        ������� � ���� ������� �������� �� ������������ ������ ��������������� ��
//!        �������: isLessZero, isEqualZero, solveLinearEquation � solveQuadraticEquation.
//------------------------------------------------------------------------------------------

void testProgram()
{
    testCompareZero(-1.0f,    -1);
    testCompareZero(-0.0011f, -1);
    testCompareZero(-0.001f,   0);
    testCompareZero( 0.0f,     0);
    testCompareZero( 0.001f,   0);
    testCompareZero( 0.0011f,  1);
    testCompareZero( 1.0f,     1);

    testSolveLinearEquation(0, 0,  0, INF_ROOTS);
    testSolveLinearEquation(0, 1,  0, 0);
    testSolveLinearEquation(1, 1, -1, 1);

    testSolveQuadraticEquation(1, 1,  1,  0, 0, 0);
    testSolveQuadraticEquation(0, 0,  0,  0, 0, INF_ROOTS);
    testSolveQuadraticEquation(1, 2,  1, -1, 0, 1);
    testSolveQuadraticEquation(1, 5, -6, -6, 1, 2);
}
