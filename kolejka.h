#pragma once
#include "kolejkaObj.h"
using namespace std;


class Kolejka
{
private:
	KolejkaObj *firstElement;
	KolejkaObj *lastElement;
public:

	Kolejka()
	{
		firstElement = nullptr;
		lastElement = nullptr;
	}

	void push(char * napis)
	{
		if (firstElement == nullptr){
			firstElement = new KolejkaObj(napis);
			lastElement = firstElement;
		}
		else {
			KolejkaObj* tmp = new KolejkaObj(napis);
			lastElement->obj = tmp;
			lastElement = tmp;
		}
	}

	char* pop()
	{
		if (firstElement == nullptr)
			return "";
		char* napis = firstElement->napis;
		KolejkaObj* tmp = firstElement->obj;
		delete firstElement;
		firstElement = tmp;
		return napis;
	}

	char* look()
	{
		if (firstElement == nullptr)
			return "";

		return firstElement->napis;
	}
};