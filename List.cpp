#include "stdafx.h"
#include "List.h"


List::List()
{
	First = Last = Cur = Sel = NULL;
}
List::List(istream &fin)
{
	do{
		Add(fin);
	} while (!fin.eof());
}
void List::Add(istream &fin){
	Item* p = new Item(fin);
	if (!Cur) {
		First = Cur = Last = p;
		return;
	}
	if (Cur == Last){
		Last->SetNext(p);
		p->SetPrev(Last);
		Last = p;
		Cur = Last;
		return;
	}
	Cur->GetNext()->SetPrev(p);
	p->SetNext(Cur->GetNext());
	p->SetPrev(Cur);
	Cur->SetNext(p);
}
void List::Delete(){
	if (!Cur) return;
	if (Cur == First){
		First = First->GetNext();
		if (First) First->SetPrev(NULL);
		else Last = NULL;
		delete Cur;
		Cur = First;
		return;
	}
	if (Cur == Last){
		Last = Last->GetPrev();
		Last->SetNext(NULL);
		delete Cur;
		Cur = Last;
		return;
	}
	Item *p = Cur->GetPrev();
	Item *n = Cur->GetNext();
	p->SetNext(n);
	n->SetPrev(p);
	delete Cur;
	Cur = p;
}
void List::Next(){
	if (Cur && Cur->GetNext())
		Cur = Cur->GetNext();
}
void List::Prev(){
	if (Cur && Cur->GetPrev())
	Cur = Cur->GetPrev();
}
void List::Write()//Вывод в консоль.
{
	for (Item*p = First; p != Last->GetNext(); p = p->GetNext()) 
	{
		if (p == Last)break;
		cout << p->GetValue() << " "; 
	}

}
List::List(Item *f, Item *l)
{
	First = f; Last = Cur = Sel = l;
}
void List::WriteFileWithoutFirst(ofstream &fin) //Запись в файл без первого элемента.
	{
	for (Item*p = First; p != Last->GetNext(); p = p->GetNext())
	{
		if (p == Last) break;
		if (p != First)
		{
			fin << p->GetValue() << ' ';
		}
	}
	}
void List::WriteFileWithoutNegativeReverse(ofstream &fin)//Вывод в файл обратных значений без отрицательных чисел.
{
	Item*p = First;
		while (p->GetNext() != Last)
			p = p->GetNext();  // переход к концу списка.
	do {
		if (p == First) break;
		if (p->GetValue() > 0) 
		{
			fin << p->GetValue() << ' ';
		}// вывод значения элемента p.
		p = p->GetPrev(); // переход к предыдущему узлу.
	} while (p != Last); // условие окончания обхода.
}
List::~List()
{
	while (Cur)
		Delete();
}

//void List::DeleteElem(int x)//тест,недоделана
//{
//	for (Item*p = First; p != Last->GetNext(); p = p->GetNext())
//	{
//		for (Item*p = First; p != Last->GetNext(); p = p->GetNext())
//		{
//			if (p == Last)break;
//			if(){Item*temp = First}
//		}
//						
//		Item *temp = First, *temp2;                        //temp-Удаляемый элемент, temp2 нужен, чтобы не потерять данные
//											//cout<<count_<<"\n";
//		for (int i = 0; i<13; i++) temp = temp->GetNext;  //Идем к адресу удаляемого элемента
//
//		temp2 = temp;	                                //Временно запоминаем адрес удаляемого элемента
//		temp2->GetPrev()->GetNext() = temp->GetNext();	            //Записываем данные, что следующий за перед сейчас удаляемым элементом - это следующий от удаляемого
//		temp2->GetNext()->GetPrev() = temp->GetPrev();               //а предыдущий для следующего - это предыдущий для удаляемого
//		delete temp;                               //теперь смело можно освободить память, удалив адрес на начало удаляемого элемента                    
//	}
//	for (Item*p = First; p != Last->GetNext(); p = p->GetNext())
//	{
//		if (p == Last)break;
//		cout << p->GetValue() << " ";
//	}
//}