
#include <iostream>

using namespace std;

struct node {
    int value = 0;
    int parent = -1;
    int left_son = -1;
    int right_son = -1;
};

int get_delta(node *arr, int *delta, int i) {
    int left_h = 0;
    int right_h = 0;

    if(arr[i].right_son != -1)
        right_h = get_delta(arr, delta, arr[i].right_son);
    if(arr[i].left_son != -1)
        left_h = get_delta(arr, delta, arr[i].left_son);

    delta[i] = right_h - left_h;

    int max_h = left_h > right_h ? left_h : right_h;

    return max_h + 1;
}

int main() {
    int len;
    cin >> len;

    node arr[len];
    int delta[len];

    for(int i = 0; i < len; i++) {
        cin >> arr[i].value >> arr[i].left_son >> arr[i].right_son;

        arr[i].left_son--;
        arr[i].right_son--;

        if(arr[i].left_son != -1)
            arr[arr[i].left_son].parent = i;

        if(arr[i].right_son != -1)
            arr[arr[i].right_son].parent = i;

        delta[i] = 0;
    }

    get_delta(arr, delta, 0);

    for(int i = 0; i < len; i++)
        cout << delta[i] << "\n";

    return 0;
}
