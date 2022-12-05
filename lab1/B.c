#include <stdio.h>

int main() {
    int number;
    int k;
    scanf("%d", &number);

    int array[number];

    for(int i = 0; i < number; i++){
        scanf("%d", &k);
        array[i] = k;
    }

    int key;
    key = array[number-1];
    for(int i = number-1; i > 0; i--){
        array[i] = array[i-1];
    }
    array[0] = key;

    for(int i = 0; i < number; i++){
        printf("%d ", array[i]);
    }

    return 0;
}
