#include "stdafx.h"
#include "Item.h"


Item::Item()
{
	next = prev = NULL;
	value = 0;
}

Item::Item(istream &fin)
{
	fin >> value;
	next = prev = NULL;
}


Item::~Item()
{
}
