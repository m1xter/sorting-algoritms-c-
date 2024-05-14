#include <iostream>
#include <vector>

using namespace std;




void imprimirArreglo(vector<int>&arreglo){
	for(int i =0;i< arreglo.size();i++){
		cout << arreglo[i] << " ";
	}
	cout<<endl;
}

void bubble_sort(vector<int>&arreglo){
	for(int i =0;i< arreglo.size()-1;i++){
		for(int j =0; j < arreglo.size() - i - 1;j++){
			if(arreglo[j] > arreglo[j+1] ){
				int temp = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = temp;
			}
		}
	}
}

int main(int argc, char** argv) {
	
	vector<int> v = {4,1,53,0,3,9,0};
	
	bubble_sort(v);
	
	imprimirArreglo(v);
	
	
	
	return 0;
}
