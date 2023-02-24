#include <iostream>
#include "Orden.h"
#include "Orden.cpp"
#include "search.h"
#include "search.cpp"
#include <vector>

using namespace std;


int main()
{
    int n,m;
    int clave;

    vector<int> vector1 = {4,6,8,5,2,9,1}; 
     
    vector<int> vector2 = {2,6,8,3,1,5,9}; 

    vector<int> vector3 = {8,5,3,4,6,1,2};

    vector<int> vector4 = {1,2,3,4,5,6,7}; 

    n = vector1.size(); 
    clave = 4;

    cout << "vector1 desordenado: "<<endl;
    for (int i = 0; i < n; i++)
       std::cout << vector1[i] << " ";
    cout << endl;

    cout << endl; 

    cout << "vector2 desordenado: "<<endl;
    for (int i = 0; i < n; i++)
       std::cout << vector2[i] << " ";
    cout << endl;

    cout<<endl;

    cout << "vector3 desordenado: "<<endl;
    for (int i = 0; i < n; i++)
       std::cout << vector3[i] << " ";
    cout << endl;

    cout<<endl; 

    cout << "vector4 para busqueda (dato a encontrar 4): "<<endl;
    for (int i = 0; i < n; i++)
       std::cout << vector4[i] << " ";
    cout << endl;

    cout<<endl;
    cout<<"--------------RESULTADOS----------------"<<endl;
    cout<<endl;

    cout << "Ordenamiento Intercambio (vector1): "<< endl;
    Orden::ordIntercambio(vector1,(sizeof(vector1))/sizeof(vector1[0])-1); 
    for (int i = 0; i < n; i++)
       std::cout << vector1[i] << " ";
    cout << endl;

    cout<<endl;

    cout<< "Ordenamiento Merge (vector2):  "<<endl;
    Orden::mergeSort(vector2, 0 ,(sizeof(vector2)/sizeof(vector2[0])-2));
    for (int i = 0; i < n; i++)
       std::cout << vector2[i] << " ";
    cout << endl;

    cout<<endl;

    cout << "Ordenamiento burbuja (vector3): "<< endl;
    Orden::burbuja2(vector3); 
    for (int i = 0; i < n; i++)
       std::cout << vector3[i] << " ";
    cout << endl;

    cout << endl;

    cout << "Busqueda Binaria: "<<endl;
    cout << "Encontrado en el indice: " << search::busquedaBin(vector4,clave) << endl; 
    
    cout<<endl;

    cout << "Busqueda Secuencial "<<endl;
    cout << "Encontrado en el indice: " << search::busquedaSeq(vector4,clave) << endl;
    
}

