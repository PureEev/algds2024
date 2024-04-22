#pragma once
#include <limits.h>
#include <stdio.h>
#include <string.h> // ��� ������������� memset
#include <assert.h>
#define N 3


int FindBestInRow(int Column, int Solution[N], const int Field[N][N]) {
    int result = Field[Column - 1][0];
    for (int i = 1; i < N; i++) {
        if (Field[Column - 1][i] > result) {
            Solution[Column - 1] = i;
            result = Field[Column - 1][i];
        }
    }
    return result;
}

int FindBestFromPossibleMoves(int Column, int *FinalPrice, const int Field[N][N], int Solution[N]) {
    if(Column == 0) return 0;
    int PrevIndex = Solution[Column - 1];
    int result = Field[Column - 2][PrevIndex];
    Solution[Column - 2] = Solution[Column - 1];
    if (PrevIndex > 0 && (Field[Column - 2][PrevIndex - 1] > result)) {
        result = Field[Column - 2][PrevIndex - 1];
        Solution[Column - 2] = PrevIndex - 1;
    }
    if (PrevIndex < N - 1 && (Field[Column - 2][PrevIndex + 1] > result)) {
        result = Field[Column - 2][PrevIndex + 1];
        Solution[Column - 2] = PrevIndex + 1;
    }
    *FinalPrice += result;
    return result;
}

int FindBestFromPossibleMovesReverse(int Column, int TempSolve[N], int* TempPrice, const int Field[N][N]) {
    if (Column == 3) return 0;
    int PrevIndex = TempSolve[Column - 1];
    int result = Field[Column][PrevIndex];
    TempSolve[Column] = TempSolve[Column - 1];
    if (PrevIndex > 0 && (Field[Column][PrevIndex - 1] > result)) {
        result = Field[Column][PrevIndex - 1];
        TempSolve[Column] = PrevIndex - 1;
    }
    if (PrevIndex < N - 1 && (Field[Column][PrevIndex + 1] > result)) {
        result = Field[Column][PrevIndex + 1];
        TempSolve[Column] = PrevIndex + 1;
    }
    *TempPrice += result;
    return result;
}

void FindMostExpensiveSolution(int* FinalPrice, int TempSolve[N], int* TempPrice, const int Field[N][N], int Solution[N]) {
    *FinalPrice += FindBestInRow(N, Solution, Field);
    for (int i = N; i > 1; i--) {
        FindBestFromPossibleMoves(i, FinalPrice, Field, Solution);
        *TempPrice += FindBestInRow(i - 1, TempSolve, Field);
        for (int j = i - 1; j <= N; j++) {
            FindBestFromPossibleMovesReverse(j, TempSolve, TempPrice, Field);
        }
        if (*TempPrice > *FinalPrice) {
            memcpy(Solution, TempSolve, N);
            *FinalPrice = *TempPrice;
        }
        *TempPrice = 0;
        memset(TempSolve, 0, N);
    }
}