// listasMayorMenor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node {
	int datum;
	Node *next;
};

int findMenor(Node *_list) {
	int menor = _list->datum;

	while (_list != NULL) {
		if (_list->datum < menor) {
			menor = _list->datum;
		}
		_list = _list->next;
	}

	return menor;
}

int findBiggest(Node *_list) {
	int big = _list->datum;

	while (_list != NULL) {
		if (_list->datum > big) {
			big = _list->datum;
		}
		_list = _list->next;
	}

	return big;
}

void readList(Node *_list) {

	while (_list != NULL) {
		cout << _list->datum << ' ';
		_list = _list->next;
	}
}

void insertNode(Node *&_list, int _datum) {

	Node *newNode = new Node{_datum};
	Node *aux = _list;
	
	_list = newNode;
	newNode->next = aux;
}

int main()
{
	Node *list = NULL;
	int datum = 0;

	while (datum >= 0) {
		cout << "introduce un numero: ";
		cin >> datum;
		if (datum >= 0) {
			insertNode(list, datum);
		}
	}

	readList(list);
	int menor = findMenor(list);
	cout << endl << menor << endl;
	int biggest = findBiggest(list);
	cout << biggest << endl;

    return 0;
}

