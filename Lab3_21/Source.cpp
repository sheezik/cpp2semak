/*
Lab2_21
Лабораторная работа №2 по предмету
Практикум по программированию, 1 курс ПИ - Э, 2 семестр

—— Задача : — - — 0    1    2          0    1    2    3     --------
				  5    6    3          7    8    9    4     ------ |
				  8    7    4		  12   13   10    5     ---- | |
									  15   14   11    6		-- V V V



	Автор : студент группы ПИ - 1э Кондаков А.А.
	Дата готовности : 16.03.2023 года
	тест :
*/
#include <iostream>
#include <iomanip>
#include <locale>
#include<vector>
#include <time.h>

using namespace std;

void heapify(vector<int>& a, int n,int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if (l < n && a[l] > a[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && a[r] > a[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(a[i], a[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(a, n, largest);
	}
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(vector<int>& a, int n)
{
	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(a[0], a[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(a, i, 0);
	}
}
void createMatrix(int**& a, int m)
{
	if ((1 <= m) && (m <= 10))
	{
		a = new int* [m];
		for (int i = 0; i < m; i++)
			a[i] = new int[m];
	}
	else
		a = NULL;
	return;
}
void createMassive(vector<int>& b,int n)
{
	srand(time(NULL));
	for (int i = 0;i<n;i++)
		b[i] = rand() % 100;
}
// Формирование и заполнение матрицы а размераm m * n случайными числами
void cord(int**& a,vector<int>b, int m)
{
	int z = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <m; j++)
		{
			a[i][j] = b[z++];

		}
		
	}

}
void printMatrix(int** a, int m)
{
	for (int i = 0; i < m; i++)

	{
		for (int j = 0; j < m; j++)
			cout << setw(5) << a[i][j];
		cout << endl;
	}
	return;
}


// Вывод матрицы а на консольный экран
void PrintMatrix(vector<vector<int>>& a)
{
	for (auto it = a.begin(); it != a.end(); it++)
	{
		for (auto jt = it->begin(); jt != it->end(); jt++)
			cout << setw(3) << *jt;
		cout << endl;
	}
	return;
}
void Print(vector<int> a)
{
	for (auto it = a.begin(); it != a.end(); it++)
	{
		cout << setw(3) << *it;
	}
	cout << endl;
	return;
}
int main()

{	
	const int m = 4, n = m * m;
	int** a;
	int i = n - 1;
	vector<int>b;
	createMatrix(a, m);
	createMassive(b, n);
	heapSort(b, n);
	cord(a,b, m);
	Print(b);
	printMatrix(a, m);
	return 0;
}