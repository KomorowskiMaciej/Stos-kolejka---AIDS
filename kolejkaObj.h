#pragma once
#include <iostream>
using namespace std;

class KolejkaObj
{
public:
	char* napis;
	KolejkaObj* obj;

	KolejkaObj::KolejkaObj(char * napis)
	{
		obj = nullptr;
		this->napis = napis;
	}
};
