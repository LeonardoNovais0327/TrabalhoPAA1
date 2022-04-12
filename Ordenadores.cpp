#include <iostream>
#include <chrono>
#include <string>

using namespace std;

int numComp = 0;
int TAM = 0;

//Quick Sort
int partition(int arr[], int ini, int fim){
    int pivo = arr[fim];
    int i = ini;
    for(int j = ini; j < fim; j++){
        if(arr[j] <= pivo){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
        numComp++;
    }

    int temp = arr[fim];
    arr[fim] = arr[i];
    arr[i] = temp;

    return i;
}

void quickSort(int arr[], int ini, int fim){
    if(ini < fim){
        int p = partition(arr, ini, fim);
        quickSort(arr, ini, p-1);
        quickSort(arr, p+1, fim);
    }
    numComp++;
}

//Selection Sort
void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int minInd = i;
        for(int j = i; j < n; j++){
            if(arr[j] < arr[minInd])
                minInd = j;
            numComp++;
        }
        if(arr[i] > arr[minInd]){
            int temp = arr[i];
            arr[i] = arr[minInd];
            arr[minInd] = temp;
        }
        numComp++;
    }
        
}

//Heap Sort
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    numComp++;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
    numComp++;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
        numComp++;
    }
        
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main (void){  
    numComp = 0;
    //500.000
    TAM = 1000000;
    //Array Random
    int* v = (int*) malloc(TAM * 4);
    for(int i=TAM;i>=0;i--)
      v[i]=rand()%TAM;

    int n = TAM;
    //Inicio Timer
    auto start = chrono::steady_clock::now();

    //quickSort(v, 0, n-1);
    //selectionSort(v,n);
    heapSort(v, n);
    
    //Fim Timer
    auto end = chrono::steady_clock::now();
    
    cout << "\nTamanho: " << TAM;
    cout << "\nTempo teorico: " << numComp;
    cout << "\nTempo pratico: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns\n";
    return 0;
}