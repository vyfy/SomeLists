// lab4.cpp: ���������� ����� ����� ��� ����������� ����������.
//����: ������������ ��������� ������ 
//��������������� ������������ �������� ������ ������������ ����� ��������� ����� ������ �� ����� ��� ���������.
//���������� ��������� �������� ������ ���������, ���������� � ����.�������� � ����� ���� ������� �������� ������������������, 
//� ����� ��� �� ������������������ � �������� �������, �� ��� ������������� ���������.


#include "stdafx.h"
#include "List.h"
void FillFile(ofstream &file, int q)
//�������� ����� � ���������� ���������� � ������ ���������.
{
	int temp;
	file << q << ' ';
	for (int i = 0; i != q; i++)
	{
		temp = rand() % 100 - 50;
		file << temp << ' ';
	}
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int quontity;
	cout << "������� ����������� ���������� ��������� �����: " << endl;
	cin >> quontity;
	ofstream FileOff("Text.txt");
	FillFile(FileOff, quontity);
	FileOff.close();

	ifstream fin("Text.txt");
	List list(fin);
	list.Write();
	ofstream FileOn("Text2.txt");
	for(int i =0;i<50;i++)
		list.Delete();

	list.WriteFileWithoutFirst(FileOn);
	list.WriteFileWithoutNegativeReverse(FileOn);
	list.Delete();
	fin.close();
	return 0;
}

