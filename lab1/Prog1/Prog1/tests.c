#include <stdio.h>
#include "func.h"
#include <limits.h>
#include <assert.h>
#define N 3

static int Solution[N];

void test_FindBestInRow_ZerosRow_ReturnsZeroValue() {
    const int expected_result = 0;

    int Field[N][N] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    int result = FindBestInRow(1,Solution, Field);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindBestInRow_ZerosRow_ReturnsZeroValue passed\n");
}

void test_FindBestInRow_ColumnWithNegativeValues_ReturnsMaximumNegativeValue() {
    const int expected_result = -1;

    int Field[N][N] = {
        {-1,-2,-3},
        {-4,-5,-6},
        {-7,-8,-9}
    };

    int result = FindBestInRow(1, Solution, Field);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindBestInRow_ColumnWithNegativeValues_ReturnsMaximumNegativeValue passed\n");
}

void test_FindBestFromPossibleMoves_ZerosRow_ReturnsZeroValue() {
    const int expected_result = 0;
    int FinalPrice = 0;
    int Field[N][N] = {
        { 1,2,3 },
        {0,0,0},
        {7,8,9}
    };
    Solution[2] = 2;
    int result = FindBestFromPossibleMoves(3, &FinalPrice, Field, Solution);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindBestFromPossibleMoves_ZerosRow_ReturnsZeroValue passed\n");
}

void test_FindBestFromPossibleMoves_RowsWithPositiveAndNegativeValues_ReturnsMaximumPositiveValue() {
    const int expected_result = -2;
    int FinalPrice = 0;
    int Field[N][N] = {
        {1, 2,  3},
        {-1,-2,-3},
        {7 ,8 ,9 }
    };
    Solution[2] = 2;

    int result = FindBestFromPossibleMoves(3, &FinalPrice, Field, Solution);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindBestFromPossibleMoves_RowsWithPositiveAndNegativeValues_ReturnsMaximumPositiveValue passed\n");
}

void test_FindBestFromPossibleMoves_RowWithSameValueInMiddle_ReturnsMaximumValue() {
    const int expected_result = 6;
    int FinalPrice = 0;
    int Field[N][N] = {
        {1,2,3},
        {6,6,6},
        {7,8,9}
    };

    Solution[2] = 2;
    int result = FindBestFromPossibleMoves(3, &FinalPrice, Field, Solution);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindBestFromPossibleMoves_RowWithSameValueInMiddle_ReturnsMaximumValue passed\n");
}

void test_FindBestFromPossibleMovesReverse_ZerosRow_ReturnsZeroValue() {
    const int expected_result = 0;
    int FinalPrice = 0;
    int Field[N][N] = {
        { 1,2,3 },
        {7,8,9},
        {0,0,0}
    };
    Solution[1] = 2;
    int result = FindBestFromPossibleMovesReverse(2, Solution, &FinalPrice, Field);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindBestFromPossibleMovesReverse_ZerosRow_ReturnsZeroValue passed\n");
}

void test_FindBestFromPossibleMovesReverse_ColumnsWithPositiveAndNegativeValues_ReturnsMaximumPositiveValue() {
    const int expected_result = -2;
    int FinalPrice = 9;
    int Field[N][N] = {
        {1, 2,  3},
        {7 ,8 ,9 },
        {-1,-2,-3}
    };
    Solution[1] = 2;

    int result = FindBestFromPossibleMovesReverse(2, Solution, &FinalPrice, Field);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindBestFromPossibleMovesReverse_ColumnsWithPositiveAndNegativeValues_ReturnsMaximumPositiveValue passed\n");
}

void test_FindBestFromPossibleMovesReverse_RowWithSameValueInMiddle_ReturnsMaximumValue() {
    const int expected_result = 6;
    int FinalPrice = 0;
    int Field[N][N] = {
        {1,2,3},
        {7,8,9},
        {6,6,6}
    };

    Solution[1] = 2;
    int result = FindBestFromPossibleMovesReverse(2, Solution, &FinalPrice, Field);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindBestFromPossibleMovesReverse_RowWithSameValueInMiddle_ReturnsMaximumValue passed\n");
}

void test_FindMostExpensiveSolution_NegativeValues_ReturnMaxValue() {
    const int expected_result = -13;
    int FinalPrice = 0;
    int TempSolve[N] = { 0,0,0 };
    int Solution[N] = { 0,0,0 };
    int TempPrice = 0;
    int Field[N][N] = {
            {-3,-2,-1},
            {-6,-5,-4},
            {-7,-8,-9}
    };
    FindMostExpensiveSolution(&FinalPrice, TempSolve, &TempPrice, Field, Solution);


    assert(FinalPrice == expected_result);
    if (FinalPrice == expected_result) printf("Test FindMostExpensiveSolution_NegativeValues_ReturnMaxValue passed\n");
}

void test_FindMostExpensiveSolution_PositiveAndNegativeValues_ReturnMaxValue() {
    const int expected_result = 2;
    int FinalPrice = 0;
    int TempSolve[N] = { 0,0,0 };
    int Solution[N] = { 0,0,0 };
    int TempPrice = 0;
    int Field[N][N] = {
            {3,3,9},
            {6,-5,-4},
            {-7,-8,-9}
    };
    FindMostExpensiveSolution(&FinalPrice, TempSolve, &TempPrice, Field, Solution);


    assert(FinalPrice == expected_result);
    if (FinalPrice == expected_result) printf("Test FindMostExpensiveSolution_PositiveAndNegativeValues_ReturnMaxValue passed\n");

}