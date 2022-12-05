#include <stdio.h>

int main() {
    struct fridge{
        float milk;
        float meat;
        int cheese;
        int my_favourite_des;
    };

    struct fridge Samsung = {20, 12.5f, 1, 45};
    struct fridge Huawei = {4, 2, 0, 21};

    Samsung.milk -= 5;  //drink milk
    Huawei.cheese += 34; //add some cheese

    return 0;
}
