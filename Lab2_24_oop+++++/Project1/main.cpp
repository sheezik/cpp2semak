/*
Lab2_24 OO� 2
������������ ������ �2 �� ��������
��������� �� ����������������, 1 ���� �� - �, 2 �������

�� ������ : ����������. ������ ���������� ���������� ����� ����� ��������� � �����. ���������� ������ ���� �����: ������� (����, ����), ������ (�����),
���������� (���� ������,���� ���������, ����). ������ ������ ����������.

                                ------------------------------------


��������� ����������� ������� �� ���� (��� ���, �������� � �����) �������,
���������� ��������� ����-��� ����� ����������, � ��������������
��������� ������������ � ������������.
���� �������� (������� �����) ������ ������������ ����� ����� �������,
������ (����������� ������) � ����� ���������� �������. � ������� ������
����������� � ����������� ����� ��� ���� ����������������, � ����������
������� � ����������������, ����������� ��� ���������� �����.
���������� ������������ ��� ������� ���� ����������� �����, ����������� � ���������� ������� ��-������. ����� �������� ������� ����� �������
�����������, ���� ����������� ����� �� ����� ���� � ��� ����������.


�����: ������� ������ �� - 1� �������� �.�.
���� ���������� : 17.04.2023 ����
���� :
*/
#include <iostream>
#include <locale.h>
#include "Post.h"
#include "News.h"
#include "Article.h"
#include "Ads.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	const int size = 3;
	Post* posts[size];
	



	News* post1 = new News("������ ������� �����","�������� ����� ������ Good Doctor ������ �� Netflix", "16.06.2002", "�������");
	posts[0] = post1;
	cout << *post1 << endl << endl;
	Article* post2 = new Article("��������� ����� ���������", "�� ����������� ������ ������ ���������� ��������� ���������� ������� �� ��������� � ������� �����, ��������� �������� ������� ����...", "������");
	posts[1] = post2;
	cout << *post2 << endl << endl;
	Ads* post3 = new Ads("����� ����������", "������ ����� ���������� � ������� 50 �� rx580 (�� ���������, ������)", "12.06.2023","16.06.2023", 10000);
	posts[2] = post3;
	cout << *post3 << endl << endl;
	int maxLength = 0;
	for (int i = 1; i < size; i++) {
		if (posts[i]->getText().length() > posts[i - 1]->getText().length())
			maxLength = i;
	}
	cout << "����� ������� ����������  : " << posts[maxLength]->getHeader() << endl << endl;

	
	

}