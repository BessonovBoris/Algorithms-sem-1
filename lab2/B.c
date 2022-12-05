#include <stdio.h>

int main() {
    int len;
    scanf("%d", &len);

    int arr[len];
    for(int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    int i;
    int key;
    for(int j = 1; j < len; j++){
        key = arr[j];
        i = j - 1;

        while(i>=0 && key < arr[i]){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }

    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
