/*Act 2.1 - Implementación de un ADT de estrucutra de datos lineales
  
------------------Integrantes del Equipo:------------------
--------------Edgar Cruz Vazquez (A01730577)---------------
----------Carlos Antonio Solano Vega (A01540077)-----------
-------Sergio Alejandro Esparza González (A01625430)-------
*/
#include <iostream>
#include "FLinked.h"

int main()
{
    //Inicializamos la lista
    FLinked<int> list; 
    //Añadimos los elementos que queremos a la lista
    list.add(1);
    list.add(23);
    list.add(3);
    
    //Mostramos la lista inicial
    std::cout << "Mostramos la lista inicial: " << std::endl;
    list.impList();

    std::cout << std::endl;

    //Mostramos la lista pero con los elementos que le añadimos en este caso serian el 6 y 9
    std::cout << "Usamos la funcion add() para insertar elementos a la lista [6 y 9]: " << std::endl;
    list.add(6);
    list.add(9);
    list.impList();

    std::cout << std::endl; 

    //Uso de la funcion get() para obtener el valor del elemento del indice insertado en la funcion
    std::cout << "Usamos la funcion get() para asi obtener el elemento buscado por indice en este caso [3]: " << std::endl;
    std::cout << list.get(3) << std::endl; 
 
    //Uso de la funcion update() para cambiar valores en indices especificos en este caso los indices a cambiar serian 2 y 3
    std::cout << "Usamos la funcion update() para asi actualizar la lista o cambiar el valor de un elemento mediante indices [2 y 3]: " << std::endl;
    std::cout << "Lista antes del cambio: " << std::endl;
    list.impList();

    std::cout << std::endl;

    //Impresion de la lista con los valores cambiados 7 y 8 en los indices 2 y 3 respectivamente
    std::cout << "Lista despues del cambio con la funcion update(): " << std::endl;
    list.update(2,7);
    list.update(3,8);
    list.impList();

    std::cout << std::endl;

    //Uso de la funcion del() para remover o eliminar el elemento en el indice deseado en este caso los indices a eliminar son el 0 y 4
    std::cout << "Uso de la funcion del() para eliminar o remover elementos de la lista mediante indices [0 y 4]: " << std::endl;
    list.del(0); 
    list.del(3);
    list.impList();
    return 0;
    

    //https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=vs-2019


}

