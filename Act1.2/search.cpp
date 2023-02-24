#include "search.h"
#include "string.h"
#include <vector>

int search::busquedaBin(std::vector<int> &v, int clave)
{
	int central, bajo, alto, valorCentral, n;
	bajo = 0;
	n = v.size();
	alto = n - 1;
	while (bajo <= alto) {
		central = (bajo + alto) / 2;
		valorCentral = v[central];
		if (clave == valorCentral)
			return central;
		else if (clave < valorCentral)
			alto = central - 1;
		else
			bajo = central + 1;
	}
	return -1;
}

int search::busquedaSeq(std::vector<int> &v, int clave)
{
	int n, i=0; 
	n = (sizeof(v))/sizeof(v[0]);
	char band = 'F';
	while((band == 'F') && (i<n)){
		if(v[i] == clave){
			band = 'V';
		}
		i++;
	}
	if(band == 'V'){
		return i-1;
	}
	else{
		return -1;
	}
}