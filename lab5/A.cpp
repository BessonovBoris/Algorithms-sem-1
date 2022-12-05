#include <iostream>

using namespace std;

void get_depth(int *depth, int **arr, int i) {
    if(depth[i] != 0)
        return;

    if(arr[i][2] == -1) {
        depth[i] = 1;
        return;
    }

    if(depth[arr[i][2]] == 0) {
        get_depth(depth, arr, arr[i][2]);
    }

    depth[i] = depth[arr[i][2]] + 1;
}

int main() {
    int len, a;
    cin >> len;

    int arr[len][3];
    int *f_arr[len];
    int depths[len];
    for(int i = 0; i < len; i++) {
        cin >> a >> arr[i][0] >> arr[i][1];

        arr[i][0]--;
        arr[i][1]--;
        arr[i][2] = -1;
    }

    for(int i = 0; i < len; i++) {
        if(arr[i][0] != -1)
            arr[arr[i][0]][2] = i;
        if(arr[i][1] != -1)
            arr[arr[i][1]][2] = i;

        f_arr[i] = arr[i];
        depths[i] = 0;
    }

    for(int i = 0; i < len; i++) {
        get_depth(depths, f_arr, i);
    }

    int max_d = depths[0];
    for(int i = 1; i < len; i++) {
        if(depths[i] > max_d)
            max_d = depths[i];
    }

    cout << max_d;

    return 0;
}
