#include <iostream>

using namespace std;

struct node {
    int value = 0;
    int parent = -1;
    int left_son = -1;
    int right_son = -1;
};

int height(node *arr, int i) {
    int left_h = 0;
    int right_h = 0;

    if(arr[i].right_son != -1)
        right_h = height(arr, arr[i].right_son);
    if(arr[i].left_son != -1)
        left_h = height(arr, arr[i].left_son);

    int max_h = left_h > right_h ? left_h : right_h;

    return max_h + 1;
}

void right_s_turn(node *arr, int i) {
    int y =  arr[i].left_son;
    arr[i].left_son = arr[y].right_son;
    arr[y].right_son = i;

    arr[y].parent = arr[i].parent;
    arr[i].parent = y;

    if(arr[y].parent != -1)
        arr[arr[y].parent].right_son = y;
}

void left_turn(node *arr, int i) {
    int r_r = 0;
    int r_l = 0;

    if(arr[arr[i].right_son].left_son != -1)
        r_l = height(arr, arr[arr[i].right_son].left_son);
    if(arr[arr[i].right_son].right_son != -1)
        r_r = height(arr, arr[arr[i].right_son].right_son);

    if(r_l > r_r)
        right_s_turn(arr, arr[i].right_son);

    int y = arr[i].right_son;
    arr[i].right_son = arr[y].left_son;
    arr[y].left_son = i;

    arr[y].parent = arr[i].parent;
    arr[i].parent = y;
}

void print(node *arr, int i, int *j, node *new_arr) {
    int ind = *j;

    new_arr[ind].value = arr[i].value;

    if(arr[i].right_son != -1) {
        *j = *j + 1;
        new_arr[ind].right_son = *j;
        print(arr, arr[i].right_son, j, new_arr);
    }

    if(arr[i].left_son != -1) {
        *j = *j + 1;
        new_arr[ind].left_son = *j;
        print(arr, arr[i].left_son, j, new_arr);
    }
}

int main() {
    int len;
    cin >> len;

    node arr[len];
    node new_arr[len];

    for(int i = 0; i < len; i++) {
        cin >> arr[i].value >> arr[i].left_son >> arr[i].right_son;

        arr[i].left_son--;
        arr[i].right_son--;

        if(arr[i].left_son != -1)
            arr[arr[i].left_son].parent = i;

        if(arr[i].right_son != -1)
            arr[arr[i].right_son].parent = i;

        new_arr[i].right_son = new_arr[i].left_son = -1;
    }

    left_turn(arr, 0);

    int j = 0;
    print(arr, arr[0].parent, &j, new_arr);

    cout << len << '\n';
    for(int i = 0; i < len; i++)
        cout << new_arr[i].value << " " << new_arr[i].left_son+1 << " " << new_arr[i].right_son+1 << '\n';

    return 0;
}
