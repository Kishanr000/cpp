#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){

    int mid = (e + s)/2;
    int len1 = mid - s +1;
    int len2 = e - mid ;

    int *leftarr = new int[len1];
    int *rightarr = new int[len2]; 

    int mainindex = s;

    // copying value on arrays
    for(int i=0; i<len1; i++){
        leftarr[i] = arr[mainindex++];
    }

    mainindex = mid+1;
    for(int i=0; i<len2; i++){
        rightarr[i] = arr[mainindex++];
    }

    // merging two arrays
    mainindex = s;
    int index1 = 0;
    int index2 = 0;

    while(index1 < len1 && index2 < len2){
        if(leftarr[index1] < rightarr[index2])
            arr[mainindex++] = leftarr[index1++];
        else
            arr[mainindex++] = rightarr[index2++];
    }

    // if left array length is greater than right array
    while(index1 < len1){
        arr[mainindex++] = leftarr[index1++];
    }

    // if right array length is greater than right array
    while(index2 < len2){
        arr[mainindex++] = rightarr[index2++];
    }

    delete []leftarr;
    delete []rightarr;
}

void mergeSort(int *arr, int s, int e){

    if(s >= e)
        return;
    
    int mid = (e + s)/2;

    // left arr sort
    mergeSort(arr, s, mid);

    // right arr sort
    mergeSort(arr, mid+1, e);

    // merge two arr
    merge(arr, s, e);
}

int main() {

    int arr[10] = {4,5,7,2,1,34,62,654,656,23};
    int size = 10;
    int start = 0;

    mergeSort(arr, start, size-1);

    merge(arr, start, size-1);

    // printing sorted array
    for(int i=0; i< size; i++){
        cout<< arr[i] << " ";
    }

}