#pragma once
#include <iostream>
using namespace std;

class StosObj
{
public:
	char* napis;
	StosObj* obj;

	StosObj::StosObj(char * napis)
	{
		obj = nullptr;
		this->napis = napis;
	}
};