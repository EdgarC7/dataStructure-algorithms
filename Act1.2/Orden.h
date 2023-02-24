#pragma once
#include <vector>

class Orden
{
public:
	static void ordIntercambio(std::vector<int> &, int );

	static void burbuja(int[], int);

	static void burbuja2(int[], int);

	static void burbuja2(std::vector<int> &);

	static void ordSeleccion(int[], int);

	static void ordInsercion(int[], int);

	static void mergeSort(std::vector<int> &, int, int);

	static void quickSort(int [], int , int );


private:
	static void swap(int*, int*);
	static void merge(std::vector<int> &, int, int, int);
	static int partition(int[], int, int);

};

