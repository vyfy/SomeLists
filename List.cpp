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
void List::Write()//����� � �������.
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
void List::WriteFileWithoutFirst(ofstream &fin) //������ � ���� ��� ������� ��������.
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
void List::WriteFileWithoutNegativeReverse(ofstream &fin)//����� � ���� �������� �������� ��� ������������� �����.
{
	Item*p = First;
		while (p->GetNext() != Last)
			p = p->GetNext();  // ������� � ����� ������.
	do {
		if (p == First) break;
		if (p->GetValue() > 0) 
		{
			fin << p->GetValue() << ' ';
		}// ����� �������� �������� p.
		p = p->GetPrev(); // ������� � ����������� ����.
	} while (p != Last); // ������� ��������� ������.
}
List::~List()
{
	while (Cur)
		Delete();
}

//void List::DeleteElem(int x)//����,����������
//{
//	for (Item*p = First; p != Last->GetNext(); p = p->GetNext())
//	{
//		for (Item*p = First; p != Last->GetNext(); p = p->GetNext())
//		{
//			if (p == Last)break;
//			if(){Item*temp = First}
//		}
//						
//		Item *temp = First, *temp2;                        //temp-��������� �������, temp2 �����, ����� �� �������� ������
//											//cout<<count_<<"\n";
//		for (int i = 0; i<13; i++) temp = temp->GetNext;  //���� � ������ ���������� ��������
//
//		temp2 = temp;	                                //�������� ���������� ����� ���������� ��������
//		temp2->GetPrev()->GetNext() = temp->GetNext();	            //���������� ������, ��� ��������� �� ����� ������ ��������� ��������� - ��� ��������� �� ����������
//		temp2->GetNext()->GetPrev() = temp->GetPrev();               //� ���������� ��� ���������� - ��� ���������� ��� ����������
//		delete temp;                               //������ ����� ����� ���������� ������, ������ ����� �� ������ ���������� ��������                    
//	}
//	for (Item*p = First; p != Last->GetNext(); p = p->GetNext())
//	{
//		if (p == Last)break;
//		cout << p->GetValue() << " ";
//	}
//}