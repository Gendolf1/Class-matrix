#pragma once
//в файле .h происходит инициализация всех переменных
class Matrix
{
public:
	int n;//кол.во строк в матрице
	int m;//столбцов
	int** x;//вторая матрица
	int** mtrx;//основная матрица
	void print();//вывод
	void tovector();//метод для представления двумерного массива в одномерный вектор
	int** transponirovanie();//транспортирование
	void plus(int **x);//сложение матрицы mtrx и x
	void minus(int** x);//вычитание матрицы x из mtrx 
	void selfsum();//сложение всех элементов матрицы
	void findcommon(int** x);//нахождение общих элементов матрицы x и mtrx
	//конструкторы
	Matrix(int n, int m);
	Matrix(int n, int m, int c);
	Matrix(int** arr, int n, int m);
};
