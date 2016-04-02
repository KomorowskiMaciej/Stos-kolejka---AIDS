#pragma once
#include "stosObj.h"
using namespace std;


class Stos
{
	private:
		StosObj *lastElement;
	public:

		Stos()
		{
			lastElement = nullptr;
		}
		void push(char * napis)
		{
			if (lastElement == nullptr)
				lastElement = new StosObj(napis);
			else{
				StosObj* tmp = new StosObj(napis);
				tmp->obj = lastElement;
				lastElement = tmp;
			}
		}

		char* pop()
		{
			if (lastElement == nullptr)
				return "";
			char* napis = lastElement->napis;
			StosObj* tmp = lastElement->obj;
			delete lastElement;
			lastElement = tmp;

			return napis;
		}

		char* look()
		{
			if (lastElement == nullptr)
				return "";

			return lastElement->napis;
		}
};