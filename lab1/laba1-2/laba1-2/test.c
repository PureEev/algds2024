#include <stdio.h>
#include "func.h"
#include <limits.h>
#include <assert.h>
#define N 4
#define M 5

static int Solution[N];

void test_FindLowestInRow_ZerosRow_ReturnsZeroValue() {
    const int expected_result = 0;

    int Field[N][M] = {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    int result = FindLowestInRow(1, Solution, Field);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindLowestInRow_ZerosRow_ReturnsZeroValue passed\n");
}

void test_FindLowestInRow_ExampleValues_ReturnsMinValue() {
    const int expected_result = -16;

    int Field[N][M] = {
        {-1,-2,-3,-4,-5},
        {-6,-7,-8,-9,-10},
        {-11,-12,-13,-14,-15},
        {-16,-17,-18,-19,-20}
    };

    int result = FindLowestInRow(4, Solution, Field);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindLowestInRow_ExampleValues_ReturnsMinValue passed\n");
}

void test_FindBestFromPossibleMoves_ZerosRow_ReturnsZeroValue() {
    const int expected_result = 0;
    int FinalPrice = 0;
    int Field[N][M] = {
        {-1,-2,-3,-4,-5},
        {-6,-7,-8,-9,-10},
        {0, 0, 0, 0, 0},
        {-16,-17,-18,-19,-20}
    };
    Solution[3] = 0;
    int result = FindBestFromPossibleMoves(4, &FinalPrice, Field, Solution);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindBestFromPossibleMoves_ZerosRow_ReturnsZeroValue passed\n");
}

void test_FindBestFromPossibleMoves_RowsWithSimularValues_ReturnsMinValue() {
    const int expected_result = -5;
    int FinalPrice = 0;
    int Field[N][M] = {
        {-1,-2,-3,-4,-5},
        {-6,-7,-8,-9,-10},
        {-5, -5, -5, -5, -5},
        {-16,-17,-18,-19,-20}
    };
    Solution[3] = 0;

    int result = FindBestFromPossibleMoves(4, &FinalPrice, Field, Solution);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindBestFromPossibleMoves_RowsWithSimularValues_ReturnsMinValue passed\n");
}

void test_FindBestFromPossibleMovesReverse_ZerosRow_ReturnsZeroValue() {
    const int expected_result = 0;
    int FinalPrice = 0;
    int Field[N][M] = {
        {-1,-2,-3,-4,-5},
        {-6,-7,-8,-9,-10},
        {-13, -12, -11, -14, -7},
        {0,0,0,0,0}
    };
    Solution[3] = 0;
    int result = FindBestFromPossibleMovesReverse(3, Solution, &FinalPrice, Field);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindBestFromPossibleMovesReverse_ZerosRow_ReturnsZeroValue passed\n");
}

void test_FindBestFromPossibleMovesReverse_RowsWithSimularValues_ReturnsMinValue() {
    const int expected_result = -5;
    int FinalPrice = 9;
    int Field[N][M] = {
        {-1,-2,-3,-4,-5},
        {-6,-7,-8,-9,-10},
        {-16,-17,-18,-19,-20},
        {-5, -5, -5, -5, -5}
    };
    Solution[3] = 0;

    int result = FindBestFromPossibleMovesReverse(3, Solution, &FinalPrice, Field);

    assert(result == expected_result);
    if (result == expected_result) printf("Test FindBestFromPossibleMovesReverse_RowsWithSimularValues_ReturnsMinValue passed\n");
}

void test_FindMostExpensiveSolution_ExampleValues_ReturnMinValue() {
    const int expected_result = -30;
    int FinalPrice = 0;
    int TempSolve[N] = { 0,0,0,0 };
    int Solution[N] = { 0,0,0,0 };
    int TempPrice = 0;
    int Field[N][M] = {
        {-5,-3,-3,-1,-1},
        {-6,-7,-8,-6,-11},
        {-16,-17,-18,-19,-20},
        {-5, -5, -5, -5, -5}
    };
    FindMostCheapSolution(&FinalPrice, TempSolve, &TempPrice, Field, Solution);


    assert(FinalPrice == expected_result);
    if (FinalPrice == expected_result) printf("Test FindMostExpensiveSolution_ExampleValues_ReturnMinValue passed\n");
}

