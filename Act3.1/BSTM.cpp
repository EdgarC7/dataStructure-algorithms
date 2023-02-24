# include <iostream> 
# include <vector>
# include <queue> 
# include "BST.h"

using namespace std;

int main(){
    bst_tree bst;
    bst_tree bst2; 

    //arbol
    r = bst.insert(r, 10); 
    r = bst.insert(r, 12);
    r = bst.insert(r, 7); 
    r = bst.insert(r, 6);
    r = bst.insert(r, 9);
    r = bst.insert(r, 13);
    r = bst.insert(r, 11);

   cout << "uso de funcion visit, orden por nivel" << endl;
   bst.visit(4);

   cout << endl;
   cout << endl;

   cout << "uso de la funcion height" << endl; 
   cout << bst.height(r) << endl;

    cout << endl;

   cout << "uso de la funcion ancestors" << endl; 
   bst.ancestors(r,13); 

   cout << endl;
   cout << endl;

   cout << "uso de la funcion whatlevelaml" << endl; 
   bst.whatlevelaml(13); 

    return 0;
}