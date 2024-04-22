#pragma once

void test_FindBestInRow_ZerosRow_ReturnsZeroValue();
void test_FindBestInRow_ColumnWithNegativeValues_ReturnsMaximumNegativeValue();
void test_FindBestFromPossibleMoves_ZerosRow_ReturnsZeroValue();
void test_FindBestFromPossibleMoves_RowsWithPositiveAndNegativeValues_ReturnsMaximumPositiveValue();
void test_FindBestFromPossibleMoves_RowWithSameValueInMiddle_ReturnsMaximumValue();
void test_FindBestFromPossibleMovesReverse_ZerosRow_ReturnsZeroValue();
void test_FindBestFromPossibleMovesReverse_ColumnsWithPositiveAndNegativeValues_ReturnsMaximumPositiveValue();
void test_FindBestFromPossibleMovesReverse_RowWithSameValueInMiddle_ReturnsMaximumValue();
void test_FindMostExpensiveSolution_NegativeValues_ReturnMaxValue();
void test_FindMostExpensiveSolution_PositiveAndNegativeValues_ReturnMaxValue();