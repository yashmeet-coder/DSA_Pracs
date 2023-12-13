#include <iostream>
#include <math.h>
using namespace std;

void maxHeapify(int arr[], int n, int index){
    int left = 2*index+1;
    int right = 2*index + 2;

    int max = index;

    if(arr[max] < arr[left]  && left < n){
        max = left;
    }

    if(arr[max] < arr[right] && right < n){
        max = right;
    }

    if(max != index){
        swap(arr[index], arr[max]);
        maxHeapify(arr,n,max);
    }
}
void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void buildMaxHeap(int arr[], int n){
    for (int i = floor(n/2); i >= 0; i--){
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr, n);

    for (int i = n-1; i>0; i--){
        swap(arr[0],arr[i]);
        n--;
        maxHeapify(arr, n, 0);
    }    
}


int main(){
    int arr[] = {2,7,3,8,0,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr,size);
    heapSort(arr,size);
    display(arr,size);
}