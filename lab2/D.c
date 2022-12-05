#include <stdio.h>

int main() {
    int len, is_sorted = 0;
    int k;

    scanf("%d", &len);
    int arr[len];

    for(int i = 0; i < len; i++){
        scanf("%d", &k);
        arr[i] = k;

        if(i > 0){
            if(arr[i-1] > k){
                is_sorted = 1;
            }
        }
    }

    if(is_sorted == 0){
        return 0;
    }

    int i;
    int key;
    for(int j = 1; j<len; j++){
        key = arr[j];
        i = j - 1;

        while(i>=0 && key<arr[i]){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;

        if(i+1 != j){
            for(int u = 0; u < len; u++){
                printf("%d ", arr[u]);
            }
            printf("\n");
        }
    }

    return 0;
}
