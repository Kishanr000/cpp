#include<iostream>
using namespace std;

int partition(int *arr, int s, int e){

    int pivot = arr[s];

    //check how many values are less or more than pivot and place pivot in its correct place
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot)
            count++;
    }

    int pivotIndex = s+count;
    swap(arr[pivotIndex], arr[s]);

    //check left and right of pivot
    for(int i=s; i<pivotIndex; i++){
        for(int j=e; j>pivotIndex; j--){
            if(arr[i] > pivot && arr[j] < pivot)
                swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e){
    if(s >= e)
        return;
    
    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);

    // right
    quickSort(arr, p+1, e);

}

int main() {

    int arr[6] = {1,6,3,7,2,8};
    int size = 6;
    int start = 0;

    quickSort(arr, start, size -1);

    // printing  values
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
}