#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
	int o=0;//счетчик для заполнения матрицы x
	int** x;//создание двумерного массива
	int a = 3, b = 3;//размеры двумерного массива
	x = new int* [a];//инициализация строк
	for (int i = 0; i < a; i++)
	{
		x[i] = new int[b];//выделение памяти под столбцы
	}
	for (int i = 0; i < a; i++)//заполнение двумерного массива
	{
		for (int j = 0; j < b; j++)
		{
			x[i][j] = o;
			o++;
		}
	}
	Matrix result(x, a, b);//создание основного объекта
	result.print();
	x = result.transponirovanie();
	result.plus(x);
	result.minus(x);
	result.selfsum();
	result.tovector();
	result.findcommon(x);
	return 0;
}	