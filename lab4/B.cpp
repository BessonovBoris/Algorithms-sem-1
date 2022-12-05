#include <iostream>

using namespace std;

void heap(int arr[], int len, int i) {
    int larget = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(right < len && arr[right] > arr[larget]){
        larget = right;
    }

    if(left < len && arr[left] > arr[larget]){
        larget = left;
    }

    if(larget != i){
        swap(arr[larget], arr[i]);
        heap(arr, len, larget);
    }

}

void buildHeap(int arr[], int len){
    for(int i = len/2; i >=0; i--){
        heap(arr, len, i);
    }
}

void heapSort(int arr[], int len){
    buildHeap(arr, len);

    while(len > 0){
        swap(arr[0], arr[len-1]);
        len--;
        heap(arr, len, 0);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    heapSort(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
