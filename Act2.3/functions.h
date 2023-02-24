#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector> 
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

class functions{
    public: 
        static void leerDoc(string, vector<string> &); 
        static vector<vector<string>> separar(vector<string>); 
        static vector<string> dividir(string, char); 
        static void ipsConvertidos(vector<vector<string>> &); 
        static void imprimirVec(vector<string>); 
        static void ordenBurbuja(vector<vector<string>> &); 
        static void ipsDesconvertidos(vector<vector<string>> &);
        static int busquedaSeq(vector<vector<string>>, string);

}; 

//Lee el archivo y lo almacena en un vector
void functions::leerDoc(string bitacora, vector<string> &b)
{
  ifstream archivo(bitacora.c_str());
  string linea;
  // Obtiene la  línea de archivo, y la almacena el contenido en "linea"
  while (getline(archivo, linea))
  {
    // Se imprime
    b.push_back(linea);
  }
}

//Recibe los datos del vector y en cada linea insertamos vectores "tokenizar", ejemplo: [[Aug,09,14:35:10,345.232.123.34,Failed,password],[]]...
vector<vector<string>> functions::separar(vector<string> bitacora)
{
  vector<vector<string>> bitacoraAcomodada;
  string spaceDelimiter = " ";
  size_t pos = 0;
  std::string token;

  // Recorre cada elemento de la bitácora.
  for (int i = 0; i < bitacora.size(); i++)
  {
    vector<string> vectorTemp;
    string s = bitacora[i];
    // Separa cada que encuentre un espacio y lo guarda en el vector.
    while ((pos = s.find(spaceDelimiter)) != std::string::npos)
    {
      token = s.substr(0, pos);
      vectorTemp.push_back(token);
      s.erase(0, pos + spaceDelimiter.length());
    }
    // El vector se guarda en el vector del archivo
    vectorTemp.push_back(s);
    bitacoraAcomodada.push_back(vectorTemp);
  }
  return bitacoraAcomodada;
}

// Elimina el char : de nuestro vector donde marca las horas
vector<string> functions::dividir(string str, char pattern)
{
  int posInit = 0;
  int posFound = 0;
  string splitted;
  vector<string> results;

  // Divide cada posición mientras que la posición sea mayor o igual a cero.
  while (posFound >= 0)
  {
    posFound = str.find(pattern, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }

  return results;
}

//Hacemos una concatenación de strings de las horas, minutos y segundos, lo guradamos en el vector en donde estaban las horas. 
void functions::ipsConvertidos(vector<vector<string>> &lista)
{
  vector<string> vectorTemp, vectorTemp2;
  string suma,suma1,suma2,suma3,suma4;
  for (int i = 0; i < lista.size(); i++)
  {
    vectorTemp = dividir(lista[i][3], '.');
    vectorTemp2 = dividir(vectorTemp[3],':');
    suma = (vectorTemp[0]); 
    suma1 = (vectorTemp[1]); 
    suma2 = (vectorTemp[2]);
    suma3 = (vectorTemp2[0]);
    suma4 = (vectorTemp2[1]);
    lista[i].insert(lista[i].begin(),suma4); 
    lista[i].insert(lista[i].begin(),suma3);
    lista[i].insert(lista[i].begin(),suma2);
    lista[i].insert(lista[i].begin(),suma1);
    lista[i].insert(lista[i].begin(),suma);
  }
}

//Impresión del vector seleccionado. 
void functions::imprimirVec(vector<string> a){
  int n; 
  n = a.size(); 
  for(int i = 0;i < n ;i++){
    cout << a[i] << " ";
  }
  cout << endl;
}

//Función Bubblesort para ordenar los datos de los vectores de menor a mayor. 
void functions::ordenBurbuja(vector<vector<string>> &a)
{
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (stoll(a[j][0]+a[j][1]+a[j][2]+a[j][3]+a[j][4]) > stoll(a[j + 1][0]+a[j + 1][1]+a[j + 1][2]+a[j + 1][3]+a[j + 1][4])) //se usa el id que creamos para buscar el valor
      {
        vector<string> tmp_value = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp_value;
      }
    }
  }
}

void functions::ipsDesconvertidos(vector<vector<string>> &a){
  for(int i = 0; i < a.size(); i++){
    a[i].erase(a[i].begin());
    a[i].erase(a[i].begin());
    a[i].erase(a[i].begin());
    a[i].erase(a[i].begin());
    a[i].erase(a[i].begin());
  } 
}

//Función de manera secuencial para buscar el vector seleccionado. 
int functions::busquedaSeq(vector<vector<string>> a, string clave)
{
	int n, i=0; 
	n = a.size();
	char band = 'F';
	while((band == 'F') && (i<n)){
		if(a[i][3] == clave){
			band = 'V';
		}
		i++;
	}
	if(band == 'V'){
		return i;
	}
	else{
		return -1;
	}
}

#endif