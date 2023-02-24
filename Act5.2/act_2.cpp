#include <iostream>
#include <list> 
#include <vector> 
#include <fstream> 
#include <stdlib.h> 
#include <cstring> 

using namespace std; 
#define Nodo struct nodo

Nodo{
    string ip; 
    string info; 
    int repeat;
    Nodo* siguiente; 
}*r;

class Hash{
public: 
    static void leerDoc(string, vector<string> &);
    static vector<vector<string>> separar(vector<string>);
    static vector<string> dividir(string, char);
    static vector<vector<string>> listaips(vector<vector<string>> &, vector<string> &);
    static int cuenta(vector<vector<string>> &, int, string); 
    static void Elimina(vector<vector<string>> &, int, string); 
    nodo* insertarNodo(nodo*, int, string, string);
    Hash(){
        r = NULL;
    }
};


void Hash::leerDoc(string bitacora, vector<string> &b){
  ifstream archivo(bitacora.c_str()); 
  string linea;
  while(getline(archivo, linea)){
    b.push_back(linea);
  }
}

vector<vector<string>> Hash::separar(vector<string> bitacora)
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

vector<string> Hash::dividir(string str, char pattern)
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

vector<vector<string>> Hash::listaips(vector<vector<string>> & bitacora,vector<string> &b){
    vector<vector<string>> ips; 
    vector<string> info;
    for(int i = 0;i < bitacora.size(); i++){
        info.push_back(bitacora[i][3]);
        info.push_back(b[i]);
        ips.push_back(info);
        info.erase(info.begin(),info.begin()+2);
    }
    return ips;
}

int Hash::cuenta(vector<vector<string>> &ips, int t, string n){
    int x = 0;
    for(int i = 0; i < t; i++){
        if(n == ips[i][0]){
            x++;
        }
    }
    return x;
}

void Hash::Elimina(vector<vector<string>> &ips, int t, string n){
    for(int i = 0; i < t; i++){
        if(n == ips[i][0]){
            ips[i][0] = "";
        }
    }
}

nodo* Hash::insertarNodo(nodo* r, int repeat, string ip, string info){
    if(r == NULL){
        r = new nodo; 
        r->ip = ip;
        r->repeat = repeat;
        r->info = info;
        r->siguiente = NULL;
    }

    else{
        r->siguiente = insertarNodo(r->siguiente,repeat,ip,info);
    }
    return r; 
}

class H{
    private:
        int BUCKET;
        list<nodo*> *table;
    public: 
        H(int V);
        vector<string> dividir2(string ip, char pattern);
        int hashFuncion(string ip);
        void insertItem(string ip, nodo* r);
        void displaytable();
        void buscardato(string ip);
        void printTable(); 
};

H::H(int V){
    this->BUCKET = V;
    table = new list<nodo*>[BUCKET];
}

vector<string> H::dividir2(string str, char pattern)
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

int H::hashFuncion(string ip){
    vector<string> ipd;
    ipd = dividir2(ip,':'); //(34.231.2423, 4355)
    return stoi(ipd[1]) % BUCKET;
}

void H::insertItem(string ip, nodo* r){
    int index = hashFuncion(ip); 
    table[index].push_back(r);
}

void H::displaytable(){
     for (int i = 0; i < BUCKET; i++) {
        cout << i;
    for (auto x : table[i])
        cout << " --> " << x->ip;
        cout << endl;
  }
}

void H::buscardato(string ip){
    int index = hashFuncion(ip);

    list <nodo*> :: iterator i;
    for(i = table[index].begin(); i != table[index].end(); i++){
        nodo *a = *i;
        if(a->ip == ip){
            cout << a->info << "     No. de acessos: " << a->repeat << endl;
            return;
        }
    } 
    cout << "ip no valida, inserte ip existente" << endl;
    return;
}

int main(){
    Hash g; 
    H j(200);
    vector<string> bitacora;
    vector<vector<string>> btoken;
    vector<vector<string>> ips;

    Hash::leerDoc("bitacoraB.txt",bitacora);
    btoken = Hash::separar(bitacora);
    ips = Hash::listaips(btoken,bitacora);

    for(int i = 0;i < ips.size(); i++){
        string n,h;
        int re;
        n = ips[i][0];
        h = ips[i][1];
        if(n != ""){
            re = Hash::cuenta(ips,ips.size(),n);
            r = g.insertarNodo(r,re,n,h);
            Hash::Elimina(ips,ips.size(),n);
        }
    }

    while(r != NULL){
        j.insertItem(r->ip,r);
        r = r->siguiente;
    }
    // j.displaytable();
    j.buscardato("580.81.104.17:22222");
    return 0;
}

