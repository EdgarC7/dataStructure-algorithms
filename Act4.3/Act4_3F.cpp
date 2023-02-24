#include <iostream>
#include <vector> 
#include <queue> 
#include <stdlib.h>
#include <fstream>
#include <string.h>

#define Nodo struct nodo
#define Arista struct arista

using namespace std; 


/*
Equipo: 
Edgar Cruz Vázquez - A01730577
Sergio Alejandro Esparza González - A01625430
Carlos Antonio Solano Vega - A01540077 
*/

Nodo{
    int numero; 
    int conex;
    int repeat; 
    Arista* adyacencia;
    Nodo* siguiente; 
}*r;

Arista{
    int vrt;
    Arista* siguiente;
};

class Graph{
public: 
    static void leerDoc(string, vector<string> &);
    static vector<vector<string>> separar(vector<string>);
    static vector<string> dividir(string, char);
    static vector<int> listaN(vector<vector<string>> &);
    static int partition(vector<int> &, int, int);
    static void quicksort(vector<int> &, int, int);
    static int cuenta(vector<int> &, int, int);
    static void Elimina(vector<int> &, int, int);
    nodo* insertarNodo(nodo*, int, int, int);
    arista* createEdge();
    static void insertarArista(int, int);
    static void agregarArista(nodo*, nodo*, arista*);
    static void insertConex(nodo*);
    static void maxRepeat(nodo *);
    Graph(){
        r = NULL;
    }
};

void Graph::leerDoc(string bitacora, vector<string> &b){
  ifstream archivo(bitacora.c_str()); 
  string linea;
  while(getline(archivo, linea)){
    b.push_back(linea);
  }
}

vector<vector<string>> Graph::separar(vector<string> bitacora)
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

vector<string> Graph::dividir(string str, char pattern)
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

vector<int> Graph::listaN(vector<vector<string>> &lista){

    vector<int> numeros;
    vector<string> aux;
    for (int i = 0; i < lista.size(); i++){
        aux = dividir(lista[i][3], '.'); 
        numeros.push_back(stoi(aux[0]));
    }

    return numeros; 
}

int Graph::partition(vector<int> &lista, int left, int right){
    int pivotIndex = left + (right - left) / 2; 
    int pivotValue = lista[pivotIndex]; 
    int i = left, j = right; 
    int temp; 
    while(i <= j){
        while(lista[i] < pivotValue){
            i++;
        }

        while(lista[j] > pivotValue){
            j--;
        }

        if(i <= j){
            temp = lista[i]; 
            lista[i] = lista[j]; 
            lista[j] = temp; 
            i++; 
            j--;
        }
    }
    return i; 
}

void Graph::quicksort(vector<int> &lista, int left, int right){
    if(left < right){
        int pivotIndex = partition(lista,left,right); 
        quicksort(lista, left, pivotIndex - 1); 
        quicksort(lista, pivotIndex, right);  
    }
}

int Graph::cuenta(vector<int> &lista, int t, int n){
    int x = 0;
    for(int i = 0; i < t; i++){
        if(n == lista[i]){
            x++;
        }
    }
    return x;
}

void Graph::Elimina(vector<int> &lista, int t, int n){
    for(int i = 0; i < t; i++){
        if(n == lista[i]){
            lista[i] = 0;
        }
    }
}

nodo* Graph::insertarNodo(nodo* r,int numero, int conex, int repeat){
    if(r == NULL){
        r = new nodo; 
        r->numero = numero; 
        r->conex = conex; 
        r->repeat = repeat; 
        r->adyacencia = NULL;
        r->siguiente = NULL;
    }

    else{
        r->siguiente = insertarNodo(r->siguiente, numero, conex, repeat);
    }

    return r;
}

void Graph::agregarArista(nodo* aux, nodo* aux2, arista* nuevo){
    Arista *a;
    if(aux->adyacencia == NULL){
        aux->adyacencia = nuevo;
        nuevo->vrt = aux2->numero;
        aux->adyacencia->siguiente = NULL;
        aux->conex++;
        return;
    }
    else{
        a = aux->adyacencia;
        while(a->siguiente != NULL)
            a = a->siguiente;
        nuevo->vrt = aux2->numero;
        a->siguiente = nuevo;
        a->siguiente->siguiente = NULL;
        aux->conex++;
        return;
    }
}

void Graph::insertarArista(int src, int dest){
    if(r == NULL)
        return;

    Nodo *aux, *aux2;
    Arista *nuevo = new arista;
    aux = r;
    aux2 = r;

    while(aux2 != NULL){
        if(aux2->numero == dest)
            break;
        aux2 = aux2->siguiente;
    }

    if(aux2 == NULL){
        cout << "Error: vertice dest no encontrado.";
        return;
    }

    while(aux != NULL){
        if(aux->numero == src){
            agregarArista(aux,aux2,nuevo);
            return;
        }
        aux = aux->siguiente;
    }

    if(aux == NULL){
        cout << "Error: vertice src no encontrado.";
        return;
    }
}

void Graph::insertConex(nodo* r){
    if(r == NULL){
        cout << "No puedo crear conexiones si no existen vertices." << endl;
        return;
    }
    Nodo *aux, *aux2; 
    aux = r;
    aux2 = r;
    int u; 

    while(aux != NULL){
        u = aux->numero;
        if(aux2->numero == u){
            aux = aux->siguiente;
            continue;
        }

        else if(u < 100){
            insertarArista(aux2->numero, u);
            insertarArista(u, aux2->numero);
            aux = aux->siguiente; 
            continue;
        }

        else if((u >= 100) && (u < 200)){
            while(aux2->numero != 10){
                aux2 = aux2->siguiente;
            }
            insertarArista(aux2->numero, u);
            insertarArista(u, aux2->numero);
            aux = aux->siguiente; 
            continue;
        }

        else if((u >= 200) && (u < 300)){
            while(aux2->numero != 20){
                aux2 = aux2->siguiente;
            }
            insertarArista(aux2->numero, u);
            insertarArista(u, aux2->numero);
            aux = aux->siguiente; 
            continue;
        }

        else if((u >= 300) && (u < 400)){
            while(aux2->numero != 30){
                aux2 = aux2->siguiente;
            }
            insertarArista(aux2->numero, u);
            insertarArista(u, aux2->numero);
            aux = aux->siguiente; 
            continue;
        }

        else if((u >= 400) && (u < 500)){
            while(aux2->numero != 40){
                aux2 = aux2->siguiente;
            }
            insertarArista(aux2->numero, u);
            insertarArista(u, aux2->numero);
            aux = aux->siguiente; 
            continue;
        }

        else if((u >= 500) && (u < 600)){
            while(aux2->numero != 50){
                aux2 = aux2->siguiente;
            }
            insertarArista(aux2->numero, u);
            insertarArista(u, aux2->numero);
            aux = aux->siguiente; 
            continue;
        }

        else if((u >= 600) && (u < 700)){
            while(aux2->numero != 60){
                aux2 = aux2->siguiente;
            }
            insertarArista(aux2->numero, u);
            insertarArista(u, aux2->numero);
            aux = aux->siguiente; 
            continue;
        }

        else if((u >= 700) && (u < 800)){
            while(aux2->numero != 70){
                aux2 = aux2->siguiente;
            }
            insertarArista(aux2->numero, u);
            insertarArista(u, aux2->numero);
            aux = aux->siguiente; 
            continue;
        }

        else if((u >= 800) && (u < 900)){
            while(aux2->numero != 80){
                aux2 = aux2->siguiente;
            }
            insertarArista(aux2->numero, u);
            insertarArista(u, aux2->numero);
            aux = aux->siguiente; 
            continue;
        }

        else if((u >= 900) && (u < 1000)){
            while(aux2->numero != 90){
                aux2 = aux2->siguiente;
            }
            insertarArista(aux2->numero, u);
            insertarArista(u, aux2->numero);
            aux = aux->siguiente; 
            continue;
        }
    }
    return;
}

void Graph::maxRepeat(nodo* r){
    int n, v;
    Nodo *aux;
    aux = r;
    n = aux->repeat;
    while(aux != NULL){
        if(aux->siguiente == NULL)
            break;

        else if(n < aux->siguiente->repeat){
            aux = aux->siguiente;
            n = aux->repeat;
            v = aux->numero;
        }

        else{
            aux = aux->siguiente;
        }
    }
    cout << "La IP que mas se repite es el " << v << " con " << n << " veces." << endl;
    return;
}

int main(){

    Graph g;
    vector<string> bitacora; 
    vector<vector<string>> btoken; 
    vector<int> listaN; 

    Graph::leerDoc("BitacoraB.txt",bitacora); 
    btoken = Graph::separar(bitacora); 
    listaN = Graph::listaN(btoken);

    Graph::quicksort(listaN, 0, listaN.size()-1); //sizeof(listaN)/sizeof(listaN[0])-1 listaN.size()-1

    for(int i = 0; i < listaN.size(); i++){
        int n;
        int re;
        n = listaN[i];
        if(n != 0){
            re = Graph::cuenta(listaN,listaN.size(), n);
            r = g.insertarNodo(r,n,0,re); 
            Graph::Elimina(listaN, listaN.size(), n);
        }
    }

    Graph::insertConex(r);

    // CASO 1:
    // Graph::insertarArista(1,1000);
    
    // Ejemplo de muestra de todos los datos de un solo nodo: 
    // cout << "IP: " << r->numero << " Repeticiones: " << r->repeat << " Conexiones: " << r->conex << endl;
    // cout << "IPS adyacentes del vertice: " << r->numero << endl;
    // while(r->adyacencia != NULL){
    //     cout << r->adyacencia->vrt << " ";
    //     r->adyacencia = r->adyacencia->siguiente;
    // }

    // Muestra de todos nodos con sus respectivas repeticiones y conexiones.
    // while(r != NULL){
    //     cout << "IP: " << r->numero << "  Repeticiones: " << r->repeat << "  Conexiones: " << r->conex << endl;
    //     r = r->siguiente;
    // }

    Graph::maxRepeat(r);

return 0;
}