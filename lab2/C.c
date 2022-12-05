#include <stdio.h>

void insertSort(int *arr, int len){
    int i;
    int j;
    int key;

    for(j = 1; j < len; j++){
        key = arr[j];
        i = j - 1;

        while(i >= 0 && key < arr[i]){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}


int main() {
    int n, m, k;

    scanf("%d %d", &n, &m);
    int arr[n*m];

    for(int i = 0; i < n*m; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);
    int musk_w[k];

    for(int i = 0; i < k; i++){
        scanf("%d", &musk_w[i]);
    }

    insertSort(arr, m*n);
    insertSort(musk_w, k);


    int j = n*m-1;
    int res = 0;
    for(int i = k-1; i >= 0 && j >= 0;){
        if(musk_w[i] > arr[j]){
            i--;
        } else{
            res++;
            i--;
            j--;
        }
    }

    printf("%d", res);

    return 0;
}
