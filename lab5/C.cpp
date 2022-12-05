#include <iostream>
#include <cmath>

using namespace std;

int maximum(int **arr, int i) {
    if(arr[i][1] != -1) {
        return maximum(arr, arr[i][1]);
    }

    return i;
}

int prev(int **arr, int i) {
    if(arr[i][0] != -1)
        return maximum(arr, arr[i][0]);

    int y = arr[i][2];
    while(y != -1 && i == arr[y][0]) {
        i = y;
        y = arr[y][2];
    }

    return y;
}

int main() {
    int len;
    cin >> len;

    int arr[len][3];
    int *f_arr[len];
    int answer[len];

    for(int i = 0; i < len; i++) {
        cin >> arr[i][0] >> arr[i][1];
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
    }

    int i = 0;
    while(arr[i][1] != -1) {
        i = arr[i][1];
    }

    answer[i] = len;

    for(int j = len-1; j > 0; j--) {
        i = prev(f_arr, i);
        answer[i] = j;
    }

    for (int j = 0; j < len; j++) {
        cout << answer[j] << " ";
    }

    return 0;
}
