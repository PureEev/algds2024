//Написать рекурсивные процедуры поиска, добавления, сцепления и расцепления в скошенное дерево без ссылок на предков.
#include "func.h"


int main()
{
	test_Insert_NegativeValue_ReturnTreeWithKeyOfNegValue();
	test_Insert_ZeroValue_ReturnTreeWithKeyOfZeroValue();
	test_merge_NegativeTree_ReturnTreeWithNegativeAndPositiveValues();
	test_split_NegativeAndPositiveTree_ReturnLeftNegativeAndRightPositive();
	test_search_negativeValue_TreeWithNegValue();
	test_RotateLeft_ZeroValue_ReturnTreeWithZeroVal();
	test_RotateRight_ZeroValue_ReturnTreeWithZeroVal();
	test_createNode_NegValue_NodeWithNegValue();
	test_freeTree_ZeroValue_Null();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
