/*Act 2.3 - Actividad Integral estrucutra de datos lineales (Evidencia Competencia)
  En equipos de tres personas, hacer una aplicación que:

  1. Abra el archivo de entrada llamado (bitacora.txt) lealo y almacene los datos en un vector.
  2. Ordene la información por fecha para la realización de las búsquedas. 
  3. Solicite al usuario las ips de inicio y fin de búsqueda de información. 
  4. Despliegue los registros correspondientes a esas ips. 
  5. Almacenar en un archivo el resultado del ordenamiento. 

------------------Integrantes del Equipo:------------------
--------------Edgar Cruz Vazquez (A01730577)---------------
----------Carlos Antonio Solano Vega (A01540077)-----------
-------Sergio Alejandro Esparza González (A01625430)-------
*/

#include <iostream>
#include <vector> 
#include <stdlib.h>
#include <string.h> 
#include <fstream>
#include "functions.h"

using namespace std;

//Función main. 
int main(){

  vector<string> b;
  vector<vector<string>> datos;
  vector<vector<string>> conversionesM;
  vector<vector<string>> vordenado; 
  string ip1, ip2;
  int indiceI, indiceF;
  
  //caso prueba en donde verificamos si esta corriendo el programa.   
  cout<<"Espere un momento... (esto puedo tomar de 3 a 5 min :D)"<<endl;  
  functions::leerDoc("bitacoraB.txt",b);
  datos = functions::separar(b);
  functions::ipsConvertidos(datos);
  functions::ordenBurbuja(datos);
  functions::ipsDesconvertidos(datos);
  
  // Inicio de programa
  cout << "Ingrese la primera ip a buscar: "<< endl; //Se ingresa el primer valor a buscar.
  cin >> ip1;
  cout << "Ingrese la segunda ip a buscar: " << endl;
  cin >> ip2;

  // Utilización de busqueda secuencial para obtener los indices.
  indiceI = functions::busquedaSeq(datos, ip1);
  indiceF = functions::busquedaSeq(datos, ip2);

  while ((indiceI == -1) || (indiceF == -1))
  {
    cout << endl;
    cout << "datos incorrectos, vuelva a ingresar las ips." << endl;
    cout << endl;
    cout << "Ingrese la primera ip a buscar: "<< endl; //Se ingresa el primer valor a buscar.
    cin >> ip1;
    cout << "Ingrese la segunda ip a buscar: " << endl;
    cin >> ip2;

  //  Utilización de busqueda secuencial para obtener los indices.
    indiceI = functions::busquedaSeq(datos, ip1);
    indiceF = functions::busquedaSeq(datos, ip2);
  }

  cout<<endl;
  
  // Impresión del vector desde el primer valor buscado hasta el segundo valor. 
  for(int i=indiceI-1;i<=indiceF-1;i++){
    functions::imprimirVec(datos[i]);
  }

  ofstream bitacoraR;

  // Apertura del bloc de notas y comprobación
  if (std::ofstream bitacoraR{"BitacoraResultado2.txt"}) //Se guarda el resultado en un archivo de texto
  {
    for (int i = indiceI; i < (indiceF-1);i++)
    {
      for (int j = 0; j < datos[i].size(); j++)
      {
        bitacoraR << datos[i][j] << " ";
      }
      bitacoraR << endl;
    }
  }
  else
  {
    cout << "Error al intentar abrir el archivo BitacoraResultado2" << endl; //En caso de error.
  }
  bitacoraR.close();

  return 0;
}