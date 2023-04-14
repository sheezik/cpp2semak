/*
Lab1_21 ======�������============
������������ ������ �1 �� ��������
��������� �� ����������������, 1 ���� ��-�, 2 �������

�� ������:����������� ����� n (1 < n < 100) �������� � ����������. ������������� �������� ������
a0, a1, �, an-1 ����������� ���������� ������ ������� �� ��������� [0, 100). ��������� �������������
������. �������� ����������, � ����� ����������� : ������������� ���������� �� �� ��������.
����� ���������� �������� ����� �������� value, ��������� ���������� ����� � �������
����� ��������. �������� ������ : ���������������� ����� � �������� �� ������� ������ ������. �-�

�����: ������� ������ ��-1� �������� �.�.
���� ���������� : 16.03.2023 ����
���� : 
*/
#include <iostream>
#include <iomanip>
#include <locale>
#include <ctime>
#include<vector>
using namespace std;
//���������� ������� �  
void Random(vector<int>&a)
{
	srand(time(NULL));
	for (auto it=a.begin(); it !=a.end();it++)
	{
		*it = rand() % 100;
	}
}
// ����� � �� ���������� �����
void Print(vector<int> a)
{
	for (auto it = a.begin(); it != a.end(); it++)
	{
			cout << setw(3) << *it;
	}
    cout << endl;
	return;
}
void heapify(vector<int>& a, int n, int i)
{
    int largest = i;   
// �������������� ���������� ������� ��� ������
    int l = 2*i + 1; // ����� = 2*i + 1
    int r = 2*i + 2; // ������ = 2*i + 2

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
    for (int i=n-1; i>=0; i--)
    {
        // ���������� ������� ������ � �����
        swap(a[0], a[i]);

        // �������� ��������� heapify �� ����������� ����
        heapify(a, i, 0);
    }
}
bool search(vector<int> a, int k,int& i)
{
    a.insert(a.begin(),k);
    while ((i > 0) && (a[i] != k))
        i--;
    i--;
    if (i > 0)
        return true;
    
};
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, k, i;
    bool flag = false;
    do
    {
        cout << "������� n �� 0 �� 99:  ";
        cin >> n;
    } while ((n < 1) or (n > 99));
    i = n;
    vector<int>a(n); //= { 4,3,5,6,7,8 };
    //n = 6;
    Random(a);
    Print(a);
    heapSort(a, n);
    cout << "��������������� ������ : \n";
    Print(a);
    cout << "����� ����� ������? : ";
    cin >> k;
    flag = search(a, k, i);
    if (flag) 
        cout << "����� ������� : "<< k << " � �������� "<< i;
    else
        cout << "����� �� �������" ;
    return 0;
}