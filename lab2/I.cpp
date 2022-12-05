#include <iostream>

using namespace std;

int partion(int *array, int left, int right){
    int pivot = array[left];
    int l_hold = left;
    int r_hold = right;

    while (left < right){
        while (array[right] >= pivot && left < right){
            right--;
        }
        if (left != right){
            array[left] = array[right];
            left++;
        }
        while (array[left] <= pivot && left < right){
            left++;
        }
        if (left != right){
            array[right] = array[left];
            right--;
        }
    }
    array[left] = pivot;
    return left;
}

int quickSort(int *numbers, int left, int right, int k){
    int mid = partion(numbers, left, right);

    if (left < mid) {
        quickSort(numbers, left, mid - 1, k);
    }
    if (right > mid) {
        quickSort(numbers, mid + 1, right, k);
    }
    return 0;
}

int main() {
    int len;
    cin >> len;
    int arr[len];

    for(int i = 0; i < len; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, len-1, 1);

    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
