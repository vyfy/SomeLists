#pragma once
class Item
{
	int value;
	Item *next, *prev;
public:
	Item();
	Item(istream &fin);
	void SetNext(Item *p){ next = p; }
	void SetPrev(Item *p){ prev = p; }
	Item*GetNext(){ return next; }
	Item*GetPrev(){ return prev; }
	int GetValue(){ return value; }

	~Item();
};

