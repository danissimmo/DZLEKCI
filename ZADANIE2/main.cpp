#include <iostream>
#include "strutil.cpp"
#include "strutil.h"
using namespace std;

/*
�������� ������� ��� ���������� ������� ������ a � ������ str
int strConteins(char *a, char* str)
���������� -1, ���� �� ��������
������� ������, ���� ��������
����������:
1. ������� ���� ������ ������ ���������
2. ��������� ������ �������� ��������� �����:
main.cpp � ������� ��� ������������ strConteins
strutil.cpp � ���������� ������� strConteins
strutil.h - ���������� ������� strConteins
*/

int main()
{
	char s1[100], s2[200];

	cin >> s1 >> s2;

	cout << strConteins(s1, s2);
}
