// ------------------Integrantes del Equipo:------------------
// --------------Edgar Cruz Vazquez (A01730577)---------------
// ----------Carlos Antonio Solano Vega (A01540077)-----------
// -------Sergio Alejandro Esparza González (A01625430)-------

#include <iostream>
#include "functions.h"
using namespace std; 

int main(){
    btc_tree bst; 
    vector<string> b; 
    vector<vector<string>> btoken; 

    cout << "Espere un momento ... (esto puedo tomar entre 3 a 5)" << endl; 
    cout << endl;
    btc_tree::leerDoc("bitacoraB.txt", b);
    btoken = btc_tree::separar(b);

    for(int i = 0; i < btoken.size(); i++){

        string n;
        int na;
        n = btoken[i][3];
        if(n != ""){
            na = btc_tree::cuenta(btoken, btoken.size(), n);
            r = bst.insert(r,na,n,NULL);
            btc_tree::Elimina(btoken, btoken.size(), n); 
        }
        
    }

    // bst.visit(2);

    cout << "Top 5 ips con mayor numero de accesos: " << endl;
    bst.searchipmayor(r);
    bst.searchipmayor(r);
    bst.searchipmayor(r);
    bst.searchipmayor(r);
    bst.searchipmayor(r);
    return 0;
}