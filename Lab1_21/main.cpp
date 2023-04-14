/*
Lab1_21 ======ВЕКТОРЫ============
Лабораторная работа №1 по предмету
Практикум по программированию, 1 курс ПИ-Э, 2 семестр

—— Задача:Натуральное число n (1 < n < 100) вводится с клавиатуры. Целочисленный линейный массив
a0, a1, …, an-1 заполняется случайными целыми числами из диапазона [0, 100). Требуется отсортировать
массив. Алгоритм сортировки, а также направление : Пирамидальная сортировка По не убыванию.
После сортировки вводится целое значение value, требуется произвести поиск в массиве
этого значения. Алгоритм поиска : Последовательный поиск с барьером по массиву справа налево. —-—

Автор: студент группы ПИ-1э Кондаков А.А.
Дата готовности : 16.03.2023 года
тест : 
*/
#include <iostream>
#include <iomanip>
#include <locale>
#include <ctime>
#include<vector>
using namespace std;
//заполнение вектора а  
void Random(vector<int>&a)
{
	srand(time(NULL));
	for (auto it=a.begin(); it !=a.end();it++)
	{
		*it = rand() % 100;
	}
}
// Вывод а на консольный экран
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
// Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

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
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(a[0], a[i]);

        // вызываем процедуру heapify на уменьшенной куче
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
        cout << "Введите n от 0 до 99:  ";
        cin >> n;
    } while ((n < 1) or (n > 99));
    i = n;
    vector<int>a(n); //= { 4,3,5,6,7,8 };
    //n = 6;
    Random(a);
    Print(a);
    heapSort(a, n);
    cout << "Отсортированный вектор : \n";
    Print(a);
    cout << "Какое число искать? : ";
    cin >> k;
    flag = search(a, k, i);
    if (flag) 
        cout << "Число найдено : "<< k << " с индексом "<< i;
    else
        cout << "Число не найдено" ;
    return 0;
}