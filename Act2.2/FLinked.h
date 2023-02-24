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
	FLinked<T>() {
		first = NULL;
	}
	
	//función para insertar nodo al final de la lista
	void add(T data) {
		if (!first) {
			// En caso si la lista esta vacía. 
			first = new node<T>;
			first->data = data;
			first->next = NULL;
		}
		// Cuando la lista no esta vacía. 
		else {
			//Creación de un nuevo nodo. 
			node<T>* newNode = new node<T>;
			newNode->data = data; 
			newNode->next = NULL; 
			//Creación de un nodo temporal "last" apuntando al primer nodo. 
			node<T>* last = this->first; 
			//Bucle while que recorre el puntero hasta que cuando nodolast->next = NULL
			while (last->next != NULL){
				last = last->next;
			}
			//el nodolast->next = al primer nodo creado con el elemento que se añadio.  
			last->next = newNode; 
			}
		}

		// https://youtu.be/RNMIDj62o_o link que ayudo para la creación de la función add(data)

	//función para insertar nodo en n posición
	void add(T data, int index){
		node<T>* temp1 = new node<T>; 
		temp1->data = data; 
		temp1->next = NULL; 
		//En caso que el usuario quiera insertar el nodo al principio
		if(index == 0){
			temp1->next = this->first;
			this->first = temp1; 
			return;
		}
		node<T>* temp2 = this->first;
		//iterador para buscar la posición-1 
		for(int i = 0; i < index-1; i++){
			temp2 = temp2->next;
		}
		//inserción del nodo a la lista
		temp1->next = temp2->next;
		temp2->next = temp1;
	}

		// https://youtu.be/IbvsNF22Ud0 link que ayudo para la creación de al función add(data, index)

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
