#include <stdio.h>
#include <iostream>
#include <chrono>
#include <string>

using namespace std;
int numComp = 0;

void troca(int arr[], int i, int j)
{
	int aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}
void ordenado(int arr[], int sup){
    bool flag = false;
    for (int i = 1; !flag && i <= sup ; i++)
    {   
        if(arr[i-1] > arr[i] ){
            flag = true;
        }
		numComp++;
    }
}
void permuta(int arr[], int inf, int sup)
{
	if(inf == sup)
	{
		ordenado(arr,sup);
	}
	else
	{
		for(int i = inf; i <= sup; i++)
		{
			troca(arr, inf, i);
			permuta(arr, inf + 1, sup);
			troca(arr, inf, i); 
		}
	}
}

int main()
{
	int TAM = 14;
    //Array Random
    int* v = (int*) malloc(TAM * 4);
    for(int i=TAM;i>=0;i--)
      v[i]=rand()%TAM;

    int n = TAM;
	
	auto start = chrono::steady_clock::now();
	permuta(v, 0, n - 1);
	auto end = chrono::steady_clock::now();

	cout << "\nTempo teorico: " << numComp;
    cout << "\nTempo pratico: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns\n";

	return 0;
}
