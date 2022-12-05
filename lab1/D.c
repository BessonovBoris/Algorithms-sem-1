#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);

    int array[number];
    int k;
    int res = 0;

    for(int i = 0; i < number; i++){
        scanf("%d", &k);
        array[i] = k;

        if (i > 1){
            if(array[i-1] > array[i-2] && array[i-1] > array[i]){
                res++;
            }
        }
    }

    printf("%d", res);

    return 0;
}
