#include <iostream>
#include "FLinked.h"

int main()
{
    //Inicializamos la lista
    FLinked<int> list; 
    //Caso prueba 1: Añadir nuestro primer elemento, cuando la lista esta vacía.
    list.add(1);
    
    //Mostramos la lista inicial
    std::cout << "Mostramos la lista inicial: " << std::endl;
    list.impList();

    std::cout << std::endl;

    //Caso prueba 2: Añadir elemento al inicio de la lista.
    std::cout << "Insertamos el elemento 7 al principio de la lista con el metodo add(data, index)" << std::endl; 
    list.add(7,0);
    list.impList(); 

    std::cout << std::endl; 

    //Caso prueba 3: Añadir elemento en medio o en n posición de la lista. 
    std::cout << "Insertamos el elemento 5 a la mitad de la lista con metodo add(data, index)" << std::endl; 
    list.add(5,1);
    list.impList();

    std::cout << std::endl; 

    //Caso prueba 4: Añadir elemento al final de la lista. 
    std::cout << "Insertamos el elemento 9 al final de la lista con el metodo add(data)" << std::endl; 
    list.add(9);
    list.impList();
    
    return 0;
    

    //https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=vs-2019


}

