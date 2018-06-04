// lab4.cpp: определяет точку входа для консольного приложения.
//Тема: Динамические структуры данных 
//Двунаправленный динамический линейный список вещественных чисел создается путем чтения из файла его элементов.
//Количество элементов является первым значением, записанным в файл.Выведите в новый файл сначала исходную последовательность, 
//а потом эту же последовательность в обратном порядке, но без отрицательных элементов.


#include "stdafx.h"
#include "List.h"
void FillFile(ofstream &file, int q)
//Создание файла с случайными значениями и числом элементов.
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
	cout << "Введите необходимое количество случайных чисел: " << endl;
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

