#include <iostream>

using namespace std;

int elementFind(int *array, int left, int right, int k){
    int mid;
    int i, j;

    while(left < right){
        mid = array[k];
        i = left;
        j = right;

        while(i <= j){
            while(array[i] < mid){
                i++;
            }
            while(array[j] > mid) {
                j--;
            }
            if(i <= j){
                swap(array[i], array[j]);
                i++;
                j--;
            }
        }
        if(j < k){
            left = i;
        }
        if(i > k){
            right = j;
        }
    }

    return array[k];
}


int main(){
    int len, k;
    int A, B, C;
    int answer;

    cin >> len >> k;

    int *array = new int[len];

    cin >> A >> B >> C >> array[0] >> array[1];

    for(int i = 2; i < len; i++){
        array[i] = A * array[i-2] + B * array[i-1] + C;
    }

    answer = elementFind(array, 0, len - 1, k - 1);

    cout << answer;

    return 0;
}
