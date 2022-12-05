#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);

    int array[number];
    int k;
    int min_1, min_2;     //min_1 <= min_2

    for(int i = 0; i < number; i++){
        scanf("%d", &k);
        array[i] = k;
    }
    min_1 = array[0];
    min_2 = array[1];

    for(int i = 0; i < number; i++){
        if(min_1 > array[i]){                      // k < min_1 <= min_2
            min_2 = min_1;
            min_1 = array[i];
        } else if( min_2 > array[i]){               // min_1 <= k < min_2
            min_2 = array[i];
        }
    }

    printf("%d %d", min_1, min_2);

    return 0;
}
