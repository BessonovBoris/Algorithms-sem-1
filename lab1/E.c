#include <stdio.h>
#include "math.h"

int main() {
    int number;
    scanf("%d", &number);

    int array[number];
    int k;
    int res, res_abs;

    for(int i = 0; i < number; i++){
        scanf("%d", &k);
        array[i] = k;
    }

    scanf("%d", &k);

    res = array[0];
    res_abs = abs(k-res);

    for(int i = 0; i < number; i++){
        if(abs(array[i] - k) <= res_abs) {
            res = array[i];
            res_abs = abs(array[i] - k);
        }
    }

    printf("%d", res);

    return 0;
}
