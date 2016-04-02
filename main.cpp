#include <iostream>
#include "stos.h"
#include "kolejka.h"

using namespace std;

Stos *stos;
Kolejka *kolejka;

char* merge_str(int countA, int countB, char* a, char* b)
{
	char * tekst = new char[countA + countB + 1];

	for (int i = 0; i < countA+countB; i++)
	{
		if (i < countA)
			tekst[i] = a[i];
		else
			tekst[i] = b[i - countA];
	}

	tekst[countA + countB] = '\0';

	return tekst;
}

void _merge(char a, char b)
{
	char* a_s;
	char* b_s;

	int a_s_cnt;
	int b_s_cnt;

	a_s = kolejka->look();
	b_s = stos->look();

	for (int i = 0;; i++)
		if (a_s[i] == '\0') {
			a_s_cnt = i;
			break;
		}

	for (int i = 0;; i++)
		if (b_s[i] == '\0') {
			b_s_cnt = i;
			break;
		}


	switch(a){
		case 'k':
			if(b == 'k')
				kolejka->push(merge_str(a_s_cnt, b_s_cnt, a_s, b_s));
			else if (b == 's')
				stos->push(merge_str(a_s_cnt, b_s_cnt, a_s, b_s));
			break;
		case 's':
			if (b == 'k')
				kolejka->push(merge_str(b_s_cnt, a_s_cnt, b_s, a_s));
			else if (b == 's')
				stos->push(merge_str(b_s_cnt, a_s_cnt,  b_s, a_s));
			break;
		default:
			break;
	}
}


void add(char * komendy, char * tekst)
{
	if(komendy[1] == 's')
	{
		stos->push(tekst);
	}
	else if (komendy[1] == 'k')
	{
		kolejka->push(tekst);
	}
}

void _delete(char a)
{
	if (a == 's')
	{
		stos->pop();
	}
	else if (a == 'k')
	{
		kolejka->pop();
	}
}

void _copy(char a, char b)
{
	if(a == 'k')
	{
		if(kolejka->look()[0] != '\0') {

			if (b == 's'){
				stos->push(kolejka->look());
			}
			else
				kolejka->push(kolejka->look());
		}
	}
	else if(a == 's')
	{
		if (stos->look()[0] != '\0') {

			if (b == 's')
				stos->push(stos->look());
			else
				kolejka->push(stos->look());
		}
	}
}

void _move(char a, char b)
{
	if (a == 'k')
	{
		if (kolejka->look()[0] != '\0') {

			if (b == 's')
				stos->push(kolejka->pop());
			else
				kolejka->push(kolejka->pop());
		}
	}
	else if (a == 's')
	{
		if (stos->look()[0] != '\0') {
			if (b == 's')
				stos->push(stos->pop());
			else
				kolejka->push(stos->pop());
		}
	}
}

void _show(char a)
{
	
	if (a == 'k') {
		char * tekst = kolejka->look();
		if (tekst[0] != '\0')
			cout << tekst << endl;
		else cout << "#" << endl;
	}
	else if (a == 's')
	{
		char * tekst = stos->look();
		if (tekst[0] != '\0')
			cout << tekst << endl;
		else cout << "#" << endl;
	}
}


int main()
{

	stos = new Stos();
	kolejka = new Kolejka();

	int liczbaKomend = 0;
	scanf("%i", &liczbaKomend);
	char * komendy;
	char *tekst;
	komendy = new char[3];
	for (int i = 0; i < liczbaKomend; i++)
	{
		scanf("%s", komendy);
		switch (komendy[0])
		{
		case 'a':
			tekst = new char[100];
			scanf("%s", tekst);
			add(komendy, tekst);
			break;
		case 'd':
			_delete(komendy[1]);
			break;
		case 'c':
			_copy(komendy[1], komendy[2]);
			break;
		case 'm': //ok
			_move(komendy[1], komendy[2]);
			break;
		case 'j':
			_merge(komendy[1], komendy[2]);
			break;
		case 's': // ok
			_show(komendy[1]);
			break;
		default:
			break;
		}
	}
	return 0;
}



