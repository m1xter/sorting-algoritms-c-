#include <iostream>
#include <vector>
#include <string.h>

#include "producto.h"
#include "producto.cpp"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */




void imprimirArreglo(vector<producto>&arreglo){
	for(int i =0;i< arreglo.size();i++){
		cout << arreglo[i] << " ";
	}
	cout<<endl;
}

// menor que cero es alfabeticamente menor
// mayor que cero es alfabeticamente mayor 
// igual que cero es que son iguales


int  particion(vector<producto>&array,int inicio,int final){
	
	producto pivot = array[final];
	int i = inicio -1,j;
	
	for ( j = inicio; j <= final -1;j++){
		if(strmcp(array[j].,pivot.getdescripcion())){
			i++;
			producto temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			
		}
	}
	i++;
			producto temp = array[i];
			array[i] = array[final];
			array[final] = temp;
	
	
	return i;
}






void qs(vector<producto>&array,int inicio,int final){
	
	if(final <= inicio) return;
	
	int pivot = particion(array,inicio,final);
	qs(array,inicio,pivot-1); //left
	qs(array,pivot+1,final);  //right
	
}



int main(int argc, char** argv) {
	vector<int> v = {17,4,2,1,6,3,9,0};
	
	imprimirArreglo(v);
	qs(v,0,v.size()-1);
	imprimirArreglo(v);
	
	
	
	
	
	
	return 0;
}
