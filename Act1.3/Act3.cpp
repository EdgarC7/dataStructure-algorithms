/*Act 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales (Evidencia Competencia)
  En equipos de tres personas, hacer una aplicación que:

  1. Abra el archivo de entrada llamado (bitacora.txt) lealo y almacene los datos en un vector.
  2. Ordene la información por fecha para la realización de las búsquedas. 
  3. Solicite al usuario las fehas de inicio y fin de búsqueda de información. 
  4. Despliegue los registros correspondientes a esas fechas. 
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

using namespace std;

//Lee el archivo y lo almacena en un vector
void leerDoc(string bitacora, vector<string> &b)
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
vector<vector<string>> separar(vector<string> bitacora)
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
vector<string> dividir(string str, char pattern)
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

//Función en la cual convertimos los meses a numeros. 
vector<vector<string>> convertirMAN(vector<vector<string>> vectorm)
{
  for (int i = 0; i < vectorm.size(); i++)
  {
    if (vectorm[i][0] == "Jan")
    {
      vectorm[i][0] = "1";
    }
    else if (vectorm[i][0] == "Feb")
    {
      vectorm[i][0] = "2";
    }
    else if (vectorm[i][0] == "Mar")
    {
      vectorm[i][0] = "3";
    }
    else if (vectorm[i][0] == "Apr")
    {
      vectorm[i][0] = "4";
    }
    else if (vectorm[i][0] == "May")
    {
      vectorm[i][0] = "5";
    }
    else if (vectorm[i][0] == "Jun")
    {
      vectorm[i][0] = "6";
    }
    else if (vectorm[i][0] == "Jul")
    {
      vectorm[i][0] = "7";
    }
    else if (vectorm[i][0] == "Aug")
    {
      vectorm[i][0] = "8";
    }
    else if (vectorm[i][0] == "Sep")
    {
      vectorm[i][0] = "9";
    }
    else if (vectorm[i][0] == "Oct")
    {
      vectorm[i][0] = "10";
    }
    else if (vectorm[i][0] == "Nov")
    {
      vectorm[i][0] = "11";
    }
    else if (vectorm[i][0] == "Dec")
    {
      vectorm[i][0] = "12";
    }
    else
    {
      cout << "Error" << endl;
    }
  }
  return vectorm;
}

//Función en la cual convertimos los numeros de nuevo a meses. 
vector<vector<string>> convertirNAM(vector<vector<string>> vectorn)
{
  for (int i = 0; i < vectorn.size(); i++)
  {
    if (vectorn[i][0] == "1")
    {
      vectorn[i][0] = "Jan";
    }
    else if (vectorn[i][0] == "2")
    {
      vectorn[i][0] = "Feb";
    }
    else if (vectorn[i][0] == "3")
    {
      vectorn[i][0] = "Mar";
    }
    else if (vectorn[i][0] == "4")
    {
      vectorn[i][0] = "April";
    }
    else if (vectorn[i][0] == "5")
    {
      vectorn[i][0] = "May";
    }
    else if (vectorn[i][0] == "6")
    {
      vectorn[i][0] = "Jun";
    }
    else if (vectorn[i][0] == "7")
    {
      vectorn[i][0] = "Jul";
    }
    else if (vectorn[i][0] == "8")
    {
      vectorn[i][0] = "Aug";
    }
    else if (vectorn[i][0] == "9")
    {
      vectorn[i][0] = "Sep";
    }
    else if (vectorn[i][0] == "10")
    {
      vectorn[i][0] = "Oct";
    }
    else if (vectorn[i][0] == "11")
    {
      vectorn[i][0] = "Nov";
    }
    else if (vectorn[i][0] == "12")
    {
      vectorn[i][0] = "Dec";
    }
    else
    {
      cout << "Error" << endl;
    }
  }
  return vectorn;
}

//Hacemos una concatenación de strings de las horas, minutos y segundos, lo guradamos en el vector en donde estaban las horas. 
vector<vector<string>> convertirHoras(vector<vector<string>> lista)
{
  vector<string> vectorTemp;
  string suma;
  for (int i = 0; i < lista.size(); i++)
  {
    vectorTemp = dividir(lista[i][2], ':');
    suma = (vectorTemp[0]) + (vectorTemp[1]) + (vectorTemp[2]); 
    lista[i][2] = suma; 
  }
  return lista;
}

//Función en la cual volvemos a separar los numeros en el indice dos con el char : para que sean horas nuevamente. 
vector<vector<string>> desconvertirHoras(vector<vector<string>> lista)
{
  for (int i = 0; i < lista.size(); i++)
  {
    lista[i][2].insert(2, ":");
    lista[i][2].insert(5, ":");
  }
  return lista;
}

//Impresión del vector seleccionado. 
void imprimirVec(vector<string> a){
  int n; 
  n = a.size(); 
  for(int i = 0;i < n ;i++){
    cout << a[i] << " ";
  }
  cout << endl;
}

//Función Bubblesort para ordenar los datos de los vectores de menor a mayor. 
vector<vector<string>> ordenBurbuja(vector<vector<string>> a)
{
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (stoi(a[j][0] + a[j][1] + a[j][2]) > stoi(a[j + 1][0] + a[j + 1][1] + a[j + 1][2])) //se usa el id que creamos para buscar el valor
      {
        vector<string> tmp_value = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp_value;
      }
    }
  }
  return a;
}

//Función de manera secuencial para buscar el vector seleccionado. 
int busqSecuencialOrd(vector<vector<string>> a, int k)
{
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    if (k <= (stoi(a[i][0] + a[i][1])))
    {
      if (k == (stoi(a[i][0] + a[i][1])))
      {
        return i;
      }
      else
      {
        return -1;
      }
    }
  }
  return -1;
}

//Función main. 
int main(){

  vector<string> b;
  vector<vector<string>> datos;
  vector<vector<string>> conversionesM;
  vector<vector<string>> conversionesMH;
  vector<vector<string>> bordenado;
  vector<vector<string>> bcasifinal;
  vector<vector<string>> bfinal;
  int mes,mes2,indiceI,indiceF;
  string fecha1,fecha2,dia,dia2;

  //caso prueba en donde verificamos si esta corriendo el programa.   
  cout<<"Espere un momento... (esto puedo tomar de 3 a 5 min :D)"<<endl;  
  leerDoc("bitacoraB.txt",b);
  datos = separar(b);
  conversionesM = convertirMAN(datos);
  conversionesMH = convertirHoras(conversionesM); 
  bordenado = ordenBurbuja(conversionesMH);  

  //Inicio de programa
  cout << "Ingresa el mes de inicio (numero de mes): "<< endl; //Se ingresa el primer valor a buscar.
  cin >> mes;
  cout << "Ingresa el dia de inicio: " << endl;
  cin >> dia;
  cout << endl;
  cout << "Ingresa el mes de fin (numero de mes): " << endl; //Se ingresa el segundo valor a buscar.
  cin >> mes2;
  cout << "Ingresa el dia de fin: " << endl;
  cin >> dia2; 

  //Se guardan ambas fechas para buscarlas después.
  fecha1 = (to_string(mes) + dia);
  fecha2 = (to_string(mes2) + dia2);

  //Utilización de busqueda secuencial para obtener los indices.
  indiceI = busqSecuencialOrd(bordenado, stoi(fecha1));
  indiceF = busqSecuencialOrd(bordenado, stoi(fecha2));

  while ((indiceI == -1) || (indiceF == -1))
  {
    cout << endl;
    cout << "datos incorrectos, vuelva a ingresar la fecha." << endl;
    cout << endl;
    cout << "Ingresa el mes de inicio (numero de mes): " << endl; //Se ingresa el primer valor a buscar.
    cin >> mes;
    cout << "Ingresa el dia de inicio: " <<endl;
    cin >> dia;
    cout << endl;
    cout << "Ingresa el mes de fin (numero de mes): " << endl; //Se ingresa el segundo valor a buscar.
    cin >> mes2;
    cout << "Ingresa el dia de fin: " << endl;
    cin >> dia2;

    //Se guardan ambas fechas para buscarlas después.
    fecha1 = (to_string(mes) + dia);
    fecha2 = (to_string(mes2) + dia2);

    //Utilización de busqueda secuencial para obtener los indices.
    indiceI = busqSecuencialOrd(bordenado, stoi(fecha1));
    indiceF = busqSecuencialOrd(bordenado, stoi(fecha2));
  }

  bcasifinal = convertirNAM(bordenado);
  //obtención del vector ordenado  
  bfinal = desconvertirHoras(bcasifinal);
  
  cout<<endl;
  
  //Impresión del vector desde el primer valor buscado hasta el segundo valor. 
  for(int i=indiceI;i<=indiceF;i++){
    imprimirVec(bfinal[i]);
  }

  ofstream bitacoraR;

  // Apertura del bloc de notas y comprobación
  if (std::ofstream bitacoraR{"BitacoraResultado2.txt"}) //Se guarda el resultado en un archivo de texto
  {
    for (int i = indiceI; i < (indiceF-1);i++)
    {
      for (int j = 0; j < bfinal[i].size(); j++)
      {
        bitacoraR << bfinal[i][j] << " ";
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