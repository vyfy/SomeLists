#pragma once
#include "Item.h"

class List
{
	Item*First;
	Item*Last;
	Item*Cur;
	Item*Sel;
public:
	List();
	List(istream &fin);
	List(Item *f, Item*l);
	
	void Add(istream &fin);
	void Delete();
	void Next();
	void Prev();
	void Write();
	void WriteFileWithoutFirst(ofstream &fin);
	void WriteFileWithoutNegativeReverse(ofstream &fin);
	void DeleteElem(int x);
	~List();
};

