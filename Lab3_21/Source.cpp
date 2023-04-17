/*
Lab3_21
Лабораторная работа №3 по предмету
Практикум по программированию, 1 курс ПИ - Э, 2 семестр

—— Задача : Дано натуральное m (1  m  10), целочисленный квадратный массив-матрица
размера mm. Матрица заполнена случайными числами из диапазона [0, 100).
Отсортировать элементы матрицы так, чтобы при прохождении по схеме, указанной в таблице № 3 (своего варианта), они были бы упорядочены по не убыванию.
Метод сортировки тот же, что и в таблице № 1.Пирамидальная сортировка По не убыванию, Последовательный поиск с барьером по массиву справа налево.
			— - — 0    1    2          0    1    2    3     --------
				  5    6    3          7    8    9    4     ------ |
				  8    7    4		  12   13   10    5     ---- | |
									  15   14   11    6		-- V V V



	Автор : студент группы ПИ - 1э Кондаков А.А.
	Дата готовности : 17.04.2023 года
	тест :
*/
#include <iostream>
#include <iomanip>
#include <locale>
#include <ctime>


using namespace std;

void createMatrix(int**& a, int m)
{
	srand(time(NULL));
	if ((1 <= m) && (m <= 10))
	{
		a = new int* [m];
		for (int i = 0; i < m; i++)
		{
			a[i] = new int[m];
			for (int j = 0; j < m; j++)
				a[i][j] = rand() % 100;
		}

	}
	else
		a = NULL;
	return;
}
void createMassive(int*& b,int n)
{
	b = new int [n];
}
void copyMatrixToArray(int** a, int*& b, int m)
{
	int k = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			b[k++] = a[i][j];
}

void heapify(int*& a, int n,int i)
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
void heapSort(int*& a, int n)
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


// Формирование и заполнение матрицы а размераm m * n случайными числами
void copy(int**& a,int* b, int m)
{
	int  s = 0;
	int R = m - 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <= R; j++)
		{
			a[i][j] = b[s++];

		}
		for (int i = m - R; i < m; i++)
			a[i][R] = b[s++];
		R--;
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


// Вывод массива а на консольный экран
void PrintMassive(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(3) << a[i];
	}
	return;
}

int main()
{	
	setlocale(LC_ALL, "Ru");
	int m , n ;
	do
	{
		cout << "Введите размер матрицы m : ";
		cin >> m;
	} while ((m > 10) || (m < 1));
	n = m * m;
	int** a, *b;
	int i = n - 1;
	createMatrix(a, m);
	printMatrix(a, m);
	createMassive(b, n);
	copyMatrixToArray(a, b, m);
	cout << "Копированный массив : " << endl;
	PrintMassive(b, n);
	cout << endl;
	heapSort(b, n);
	cout << "Отсортированный массив : " << endl;
	PrintMassive(b, n);
	cout << endl;
	copy(a,b, m);
	cout << "Отсортированная матрица : " << endl;
	printMatrix(a, m);
	
	return 0;
}