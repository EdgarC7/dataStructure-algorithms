#pragma once
#include <iostream>
using namespace std;

template<class T>
struct node {
	node<T>* next;
	T data;
};



template<class T>
class FLinked
{
public:
	node<T>* first;
	node<T>* last;
	FLinked<T>() {
		first = NULL;
		last = NULL;
	}

	void add(T data) {
		if (!first) {
			// The list is empty
			first = new node<T>;
			first->data = data;
			first->next = NULL;
			last = first;
		}
		else {
			// The list isn't empty
			if (last == first) {
				// The list has one element
				last = new node<T>;
				last->data = data;
				last->next = NULL;
				first->next = last;
			}
			else {
				// The list has more than one element
				node<T>* insdata = new node<T>;
				insdata->data = data;
				insdata->next = NULL;
				last->next = insdata;
				last = insdata;
			}
		}
	}

	T get(int index) {
		if (index == 0) {
			// Get the first element
			return this->first->data;
		}
		else {
			// Get the index'th element
			node<T>* curr = this->first;
			for (int i = 0; i < index; ++i) {
				curr = curr->next;
			}
			return curr->data;
		}
	}

	void update(int index, T data) {
		if (index == 0) {
			// Update the first element
			this->first->data = data;
		}
		else {
			// update the index'th element
			node<T>* curr = this->first;
			for (int i = 0; i < index; ++i) {
				curr = curr->next;
			}
			curr->data = data;
		}
	}

	void del(int index){
		//Creacion de nodo temporal apuntando a first
		node<T>* temp1 = first; 
		//Caso en donde el valor a eliminar sea en el indice 0
		if(index == 0){
			first = temp1->next;
			free(temp1); 
			return;
		}

		//Caso donde el valor a eliminar este en el indice diferente de 0
		for(int i = 0;i < index-1;i++){
			temp1 = temp1->next;
		}
		node<T>* temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
	}

	void impList(){
		//Creacion de nodo temporal apuntando a first 
		node<T>* temp = first;
		//Impresion de la lista
		while(temp!=NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	T operator[](int index) {
		return get(index);
	}

};
