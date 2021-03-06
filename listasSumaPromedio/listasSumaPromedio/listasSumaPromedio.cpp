// listasSumaPromedio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node {
	int datum;
	Node *next;
};

int suma(Node *_list) {
	int suma = 0;

	while (_list != NULL) {
		suma += _list->datum;
		_list = _list->next;
	}

	return suma;
}

int promedio(Node *_list, int _suma) {
	int cont = 0;

	while (_list != NULL) {
		cont++;
		_list = _list->next;
	}

	return (_suma / cont);
}

void readList(Node *_list) {
	while (_list != NULL) {
		cout << _list->datum << ' ';
		_list = _list->next;
	}
}

void insertNode(Node *&_list, int _datum) {
	Node *newNode = new Node{ _datum };

	Node *aux1 = _list;
	Node *aux2;

	if (_list != NULL) {
		/*aux2 = aux1;
		aux1 = aux1->next;
		aux2->next = newNode;
		newNode->next = aux1;*/
		
		newNode->next = _list->next;
		_list->next = newNode;
	}
	else {
		newNode->next = _list;
		_list = newNode;	
	}
	
	
}


int main()
{
	Node *list = NULL;
	int n;
	
	insertNode(list, 2);
	insertNode(list, 7);
	insertNode(list, 9);
	readList(list);
	int sum = suma(list);
	cout << endl <<sum << endl;
	int prom = promedio(list, sum);
	cout << prom << endl;
    return 0;
}

