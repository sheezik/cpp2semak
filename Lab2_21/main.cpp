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
using namespace std;

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

// ������������ � ���������� ������� � �������m m * n ���������� �������
void cord(int**& a, int m)
{
	int  s = 0;
	int R = m-1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <= R; j++)
		{
			a[i][j] = s++;
			
		}
		for (int i = m-R; i < m; i++)
			a[i][R] = s++;
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
int main()

{
	int** a;
	int m = 4;
	createMatrix(a, m);
	cord(a, m);
	printMatrix(a,m);
	return 0;
}