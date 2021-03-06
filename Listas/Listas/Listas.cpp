// Listas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
};

void insertList(Node *&list, int n) {
	auto *newNode = new Node{n};

	Node *aux1 = list;
	Node *aux2 = NULL;

	while ((aux1 != NULL) && (aux1->data < n)) {
		aux2 = aux1;
		aux1 = aux1->next;
	}

	if (list == aux1) {
		list = newNode;
	}
	else {
		aux2->next = newNode;
	}

	newNode->next = aux1;
}

void readList(Node *list) {
	Node *actual = new Node();

	actual = list;

	while (actual != NULL) {
		cout << actual->data << ' ';
		actual = actual->next;
	}

	cout << endl;
}

void searchList(Node *list, int n) {
	
	bool flag = false;
	Node *actual = new Node();

	actual = list;

	while (actual != NULL && actual->data <= n) {
		if (actual->data == n) {
			flag = true;
		}
		actual = actual->next;
	}

	if (flag == true) {
		cout << "The number exist" << endl;
	}
	else {
		cout << "The number doesnt exist" << endl;
	}
}

void deleteNode(Node *&list, int n) {
	
	Node *auxDelete = NULL;
	Node *auxBefore = NULL;
	
	auxDelete = list;

	while (auxDelete != NULL && auxDelete->data != n) {
		auxBefore = auxDelete;
		auxDelete = auxDelete->next;
	}

	if (auxBefore == NULL) {
		list = list->next;
		delete auxDelete;
	}
	else if (auxDelete == NULL) {
		cout << "The element doesnt exist" << endl;
	}
	else {
		auxBefore->next = auxDelete->next;
		delete auxDelete;
	}
}

Node *list = NULL;

int main()
{	
	int n, s;
	int option; 

	do {
		cout << "1.Insert | ";
		cout << "2.Read | ";
		cout << "3.Search | ";
		cout << "4.Delete | ";
		cout << "5.Exit -> ";
		cin >> option;

		switch (option) {
		case 1:
			cout << "Introduce a number: ";
			cin >> n;
			insertList(list, n);
			break;
		case 2:
			readList(list);
			break;
		case 3:
			cout << "Introduce the number to search: ";
			cin >> s;
			searchList(list, s);
			break;
		case 4: 
			cout << "Introduce the number to delete: ";
			cin >> n;
			deleteNode(list, n);
			break;
		}
	} while (option != 5);

    return 0;
}

