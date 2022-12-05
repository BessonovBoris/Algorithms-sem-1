#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n][2];
    for(int i = 0; i<n; i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    int i;
    int key[2];
    for(int j = 1; j < n; j++){//сортировка по ID
        key[0] = arr[j][0];
        key[1] = arr[j][1];
        i = j - 1;

        while (i >= 0 && key[0] < arr[i][0]){
            arr[i+1][0] = arr[i][0];
            arr[i+1][1] = arr[i][1];
            i--;
        }
        arr[i+1][0] = key[0];
        arr[i+1][1] = key[1];
    }

    for(int j = 1; j < n; j++){//сортировка по баллам
        key[0] = arr[j][0];
        key[1] = arr[j][1];
        i = j - 1;

        while (i >= 0 && key[1] > arr[i][1]){
            arr[i+1][0] = arr[i][0];
            arr[i+1][1] = arr[i][1];
            i--;
        }
        arr[i+1][0] = key[0];
        arr[i+1][1] = key[1];
    }

    for(i = 0; i < n; i++){
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }

    return 0;
}
