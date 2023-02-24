#include <iostream>
#include <vector> 
#include <queue> 
#include <stdlib.h>
#include <fstream>
#include <string.h>

using namespace std; 

struct btc {
  int key; 
  string ip; 
  struct btc* left; 
  struct btc* right;
  struct btc* padre;
}*r; 

class btc_tree{
  public: 
    btc* insert(btc *, int, string, btc*);
    void eliminar(btc*,int);
    void eliminarNodo(btc*);
    btc* minimo(btc*);
    void reemplazar(btc*,btc*);
    void destruir(btc*);
    long height(btc *); 
    void visit(int);
    void inorder (btc *);
    void preorder(btc*);
    void postorder (btc *); 
    void lbyl (btc *); 
    static void leerDoc(string, vector<string> &);
    static vector<vector<string>> separar(vector<string>);
    static int cuenta(vector<vector<string>> &, int, string);
    static void Elimina(vector<vector<string>> &, int, string);
    void searchipmayor(btc *); 
    btc_tree(){
      r = NULL; 
    }
};

btc* btc_tree::insert(btc* r, int key, string ip, btc* padre){
  if(r == NULL){
    r = new btc; 
    r->key = key; 
    r->ip = ip;
    r->right = NULL;
    r->left = NULL; 
    r->padre = padre;
    return r; 
  }

  else if(key < r->key){
    r->left = insert(r->left, key, ip, r);
  }

  else if(key >= r->key){
    r->right = insert(r->right, key, ip, r);
  } return r;
}

long btc_tree::height(btc* t){
  long h = 0;
  if(t != NULL){
    long l_height = height(t->left);
    long r_height = height(t->right); 
    long max_height = max(l_height, r_height);
    h = max_height + 1;
  }
  return h;
}

void btc_tree::eliminar(btc* t, int key){
  if(t == NULL){
    return;
  }
  else if(key < t->key){
    eliminar(t->left,key);
  }
  else if(key > t->key){
    eliminar(t->right,key);
  }
  else{
    eliminarNodo(t);
  }
}

void btc_tree::eliminarNodo(btc* nodoEliminar){
  if(nodoEliminar->left && nodoEliminar->right){
    btc* menor = minimo(nodoEliminar->right);
    nodoEliminar->key = menor->key;
    nodoEliminar->ip = menor->ip;
    eliminarNodo(menor);
  }
  else if(nodoEliminar->left){
    reemplazar(nodoEliminar,nodoEliminar->left);
    destruir(nodoEliminar);
  }
  else if(nodoEliminar->right){
    reemplazar(nodoEliminar,nodoEliminar->right);
    destruir(nodoEliminar);
  }
  else{
    reemplazar(nodoEliminar,NULL);
    destruir(nodoEliminar);
  }
}

btc* btc_tree::minimo(btc* t){
  if(t == NULL){
    return NULL;
  }
  if(t->left){
    return minimo(t->left);
  }
  else{
    return t;
  }
}

void btc_tree::reemplazar(btc* t, btc* nuevonodo){
  if(t->padre){
    // if(t->key == t->padre->left->key){
    //   t->padre->left = nuevonodo;
    // }
    if(t->key == t->padre->right->key){
      t->padre->right = nuevonodo;
    }
  } 
  if(nuevonodo){
    nuevonodo->padre = t->padre;
  } 
}

void btc_tree::destruir(btc* t){
  t->left = NULL; 
  t->right = NULL; 
  delete t;
}

void btc_tree::preorder(btc* t){
    if(t == NULL)
        return;
    cout << "ip: " << t->ip << "  llave de acceso: " << t->key << endl;
    preorder(t->left);
    preorder(t->right);
}

void btc_tree::inorder(btc* t){
    if(t == NULL)
        return; 
    inorder(t->left);
    cout << "ip: " << t->ip << "  llave de acceso: " << t->key << endl; 
    inorder(t->right);
}

void btc_tree::postorder(btc* t){
    if(t == NULL)
        return;
    postorder(t->left);
    postorder(t->right);
    cout << "ip: " << t->ip << "  llave de acceso: " << t->key << endl; 
}

void btc_tree::lbyl(btc* t){
    if(t == NULL)
        return;
    queue<btc*> q;
    q.push(t);
    while (!q.empty()){
        int nodes = q.size();
        while (nodes > 0){
            btc* temp = q.front();
            cout << "ip: " << t->ip << "  llave de acceso: " << t->key << endl; 
            q.pop();
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
            nodes--; 
        }
    }
}

void btc_tree::visit(int m){
    if (m == 1)
        return preorder(r);
    else if (m == 2)
        return inorder(r);
    else if (m == 3)
        return postorder(r);
    else if (m == 4)
        return lbyl(r);
    else{
        cout << "modo de recorrido no valido." << endl;
    }
}

void btc_tree::leerDoc(string bitacora, vector<string> &b){
  ifstream archivo(bitacora.c_str()); 
  string linea;
  while(getline(archivo, linea)){
    b.push_back(linea);
  }
}

vector<vector<string>> btc_tree::separar(vector<string> bitacora)
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

int btc_tree::cuenta(vector<vector<string>> &token, int t, string n){
    int x = 0;
    string l;
    for(int i = 0; i < t; i++){
        if(n == token[i][3]){
            x++;
        }
    }
    return x;
}

void btc_tree::Elimina(vector<vector<string>> &token, int t, string n){
    for(int i = 0; i < t; i++){
        if(n == token[i][3]){
            token[i][3] = "";
        }
    }
}

void btc_tree::searchipmayor(btc* t){
  if(t->right == NULL){
    cout << "ip: " << t->ip << " numero de accesos: " << t->key << endl;
    eliminar(t,t->key);
    return;
  }
  searchipmayor(t->right);
}