#include<stdio.h>
#include "func.h"


int main() {

    test_FindLowestInRow_ZerosRow_ReturnsZeroValue();
    test_FindLowestInRow_NegValues_ReturnsMinValue();
   
    return 0;
}

//1 Задана матрица натуральных чисел A(n,m). За каждый проход через клетку (i,j) взимается
//штраф A(i, j).Необходимо минимизировать штраф и пройти из какой - либо клетки 1 - ой
//строки в n - ую строчку, при этом из текущей клетки можно перейти в любую из 3 - х
//соседних, стоящих в строке с номером на 1 - цу большем;



