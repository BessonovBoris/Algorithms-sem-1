#include <stdio.h>
#include <math.h>

int main(){
    int len = 0;
    int num;
    int place;
    scanf("%d", &len);

    int arr[len+1];

    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d %d", &num, &place);

    for(int i = len; i > place-1; i--){
        arr[i] = arr[i-1];
    }
    arr[place-1] = num;

    for(int i = 0; i < len+1; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
