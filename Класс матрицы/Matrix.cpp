#include "Matrix.h"
#include <iostream>
#include <vector>
using namespace std;
//здесь уже описываются все функции/методы
void Matrix::print() {
	cout << "mtrx:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mtrx[i][j] <<" ";
		}
		cout << endl;
	}
}
int** Matrix::transponirovanie() {//транспонирование
	int** x =  new int* [n];
	for (int i = 0; i < n; i++)
	{
		x[i] = new int[m];
	}
	cout << "x:\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x[i][j] = mtrx[j][i];
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
	return x;
}
void Matrix::plus(int **x)//сложение двух матриц
{
	//создаю вторую матрицу, которая будет действовать и существовать только в методе плюс чтобы основная не изменялась 
	int** mtrx2;
	mtrx2 = new int* [n];
	for (int i = 0; i < n; i++)
		mtrx2[i] = new int[m];
	for (int i = 0; i < n; i++)//копирую значения основной матрицы в эту
		for (int j = 0; j < m; j++)
			mtrx2[i][j] = mtrx[i][j];
	for (int i = 0; i < n; i++)//сложение
	{
		for (int j = 0; j < m; j++)
		{
			mtrx2[i][j] += x[i][j];
		}
	}
	cout << "mtrx + x:\n";
	for (int i = 0; i < n; i++)//вывод
	{
		for (int j = 0; j < m; j++)
		{
			cout << mtrx2[i][j] << " ";
		}
		cout << endl;
	}
}
void Matrix::findcommon(int **x)//нахождение общих элементов матрицы x и mtrx
{
	int** cm;//создание матрницы для сравнения, которая будет состоять из 0 и 1
	cm = new int* [n];
	for (int i = 0; i < n; i++)
		cm[i] = new int[m];
	for (int i = 0; i < n; i++)//алгоритм сравнения
	{
		for (int j = 0; j < m; j++)
		{
			if (mtrx[i][j] == x[i][j])
			{
				cm[i][j] = 1;
			}
			else
				cm[i][j] = 0;
		}
	}
	cout << "Find common between mtrx and x:\n";
	for (int i = 0; i < n; i++)//вывод
	{
		for (int j = 0; j < m; j++)
		{
			cout << cm[i][j] << " ";
		}
		cout << endl;
	}
}
void Matrix::minus(int** x)//сложение двух матриц
{
	//создаю вторую матрицу, которая будет действовать и существовать только в методе плюс чтобы основная не изменялась 
	int** mtrx2;
	mtrx2 = new int* [n];
	for (int i = 0; i < n; i++)
		mtrx2[i] = new int[m];
	for (int i = 0; i < n; i++)//копирую значения основной матрицы в эту
		for (int j = 0; j < m; j++)
			mtrx2[i][j] = mtrx[i][j];
	for (int i = 0; i < n; i++)//вычитание
	{
		for (int j = 0; j < m; j++)
		{
			mtrx2[i][j] -= x[i][j];
		}
	}
	cout << "mtrx - x:\n";
	for (int i = 0; i < n; i++)//вывод
	{
		for (int j = 0; j < m; j++)
		{
			cout << mtrx2[i][j] << " ";
		}
		cout << endl;
	}
}
void Matrix::tovector()//метод для представления двумерного массива в одномерный вектор
{
	int counter = 0;//переменная-счетчик
	vector <int> vec;//создание вектора в который будет записываться двумерный массив
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			vec.push_back(mtrx[i][j]);
		}
	}
	cout << "Vector: ";
	for (int i = 0; i < n * m; i++)
		cout<<vec[i] <<" ";
	cout << endl;
}
void Matrix::selfsum()//метод для суммы всех элементов матрицы
{
	int k=0;//счетчик для суммы всех элементов матрицы
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			k += mtrx[i][j];
		}
	}
	cout << "Self sum of mtrx:\n" << k <<endl;
}

//конструкторы
Matrix::Matrix(int n, int m)//конструктор для создания матрицы пустой
{
	this->n = n;
	this->m = m;
	mtrx = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mtrx[i] = new int[m];
	}
}
Matrix::Matrix(int n, int m, int c)//конструктор для создания матрицы заполненной элементами с
{
	this->n = n;
	this->m = m;
	mtrx = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mtrx[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mtrx[i][j] = c;
		}
	}
}
Matrix::Matrix(int** arr, int n, int m)//конструктор для создания матрицы заполненной элементами массива arr
{
	this->n = n;
	this->m = m;
	mtrx = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mtrx[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mtrx[i][j] = arr[i][j];
		}
	}
}