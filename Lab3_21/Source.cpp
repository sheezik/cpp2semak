/*
Lab2_21
������������ ������ �2 �� ��������
��������� �� ����������������, 1 ���� �� - �, 2 �������

�� ������ : � - � 0    1    2          0    1    2    3     --------
				  5    6    3          7    8    9    4     ------ |
				  8    7    4		  12   13   10    5     ---- | |
									  15   14   11    6		-- V V V



	����� : ������� ������ �� - 1� �������� �.�.
	���� ���������� : 16.03.2023 ����
	���� :
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
	// �������������� ���������� ������� ��� ������
	int l = 2 * i + 1; // ����� = 2*i + 1
	int r = 2 * i + 2; // ������ = 2*i + 2

	// ���� ����� �������� ������� ������ �����
	if (l < n && a[l] > a[largest])
		largest = l;

	// ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
	if (r < n && a[r] > a[largest])
		largest = r;

	// ���� ����� ������� ������� �� ������
	if (largest != i)
	{
		swap(a[i], a[largest]);

		// ���������� ����������� � �������� ���� ���������� ���������
		heapify(a, n, largest);
	}
}

// �������� �������, ����������� ������������� ����������
void heapSort(vector<int>& a, int n)
{
	// ���������� ���� (�������������� ������)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);

	// ���� �� ������ ��������� �������� �� ����
	for (int i = n - 1; i >= 0; i--)
	{
		// ���������� ������� ������ � �����
		swap(a[0], a[i]);

		// �������� ��������� heapify �� ����������� ����
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
// ������������ � ���������� ������� � �������m m * n ���������� �������
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


// ����� ������� � �� ���������� �����
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