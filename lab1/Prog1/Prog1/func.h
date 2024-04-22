#pragma once

int FindBestInRow(int Column, int Solution[3], const int Field[3][3]);
int FindBestFromPossibleMoves(int Column, int* FinalPrice, const int Field[3][3], int Solution[3]);
int FindBestFromPossibleMovesReverse(int Column, int TempSolve[3], int* TempPrice, const int Field[3][3]);
void FindMostExpensiveSolution(int* FinalPrice, int TempSolve[3], int* TempPrice, const int Field[3][3], int Solution[3]);