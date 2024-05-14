#include <iostream>
#include <vector>
using namespace std;


void imprimirArreglo(vector<int>&arreglo){
	for(int i =0;i< arreglo.size();i++){
		cout<< arreglo[i] <<" ";
		
	}
	cout<<endl;
}

void merge(vector<int>&arreglo,int inicio,int mitad, int final){
	int i,j,k;
	int elementosIzq = mitad - inicio+1; // esta es la cantidad de elementos de la parte izquierda
	int elementosDer = final - mitad;// esta es la cantidad de elementos de la parte derecha
	
	vector<int>izquierda(elementosIzq);
	vector<int>derecha(elementosDer);
	
	//aqui cargamos el vector de la izquierda
	for(int i =0; i < elementosIzq;i++){
		izquierda[i] = arreglo[inicio+i];
	}
	//aqui cargamos el vector de la derecha 
	for(int j =0;j< elementosDer;j++){
		derecha[j] = arreglo[mitad + 1 +j];
	}
	
	i=0;
	j=0;
	k=inicio;
	
	
	while(i< elementosIzq && j < elementosDer){
		if(izquierda[i] <= derecha[j]){
			arreglo[k] = izquierda[i];
			i++;
		}else{
			arreglo[k] = derecha[j];
			j++;
		}
		k++;
	}
	
	while(j < elementosDer){
		arreglo[k] = derecha[j];
		j++;
		k++;
	}
	
	while(i < elementosIzq){
		arreglo[k] = izquierda[i];
		i++;
		k++;
	}
	
}


void mergeSort(vector<int>&arreglo,int inicio,int final){
	// esto repetira el algoritmo hasta que este ordenado de forma asendente es decir el inicio es menor que el final 
	if(inicio < final){
		int mitad = inicio + (final - inicio)/2; // asi sabemos cual es la mitad del arreglo 
		mergeSort(arreglo,inicio,mitad);// aqui estamos dividiendo la parte izquierda del arreglo
		mergeSort(arreglo,mitad+1,final); // aqui estamos dividiendo la parte derecha del arreglo 
		merge(arreglo,inicio,mitad,final);
	}
}

int main(int argc, char** argv) {
	
	  vector<int> prueba1 = {12,5,3,6,56,1,2,0};
	  imprimirArreglo(prueba1);
	  mergeSort(prueba1,0,prueba1.size()-1);
	  imprimirArreglo(prueba1);
	
	return 0;
}
