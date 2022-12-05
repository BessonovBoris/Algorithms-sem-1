#include <iostream>

using namespace std;

int minimum(int **arr, int i) {
    while(arr[i][1] != -1)
        i = arr[i][1];

    return i;
}

bool check(int **arr, int i, int len) {
    int n = 0;
    int prev = i;

    while(n < len) {
        if(arr[i][2] != -1) {
            i = minimum(arr, arr[i][2]);
        } else {
            int y = arr[i][3];
            while(y != -1 && i == arr[y][2]) {
                i = y;
                y = arr[y][3];
            }
            i = y;
        }

        if(i != -1) {
            if (arr[prev][0] >= arr[i][0])
                return false;
        } else if(n != len-1) {
            return false;
        }

        prev = i;

        n++;
    }

    return true;
}

int main() {
    int len;
    cin >> len;

    if(len == 0) {
        cout << "YES";
        return 0;
    }

    int arr[len][4];
    int *f_arr[len];

    int f_min = 0;

    for(int i = 0; i < len; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

        arr[i][1]--;
        arr[i][2]--;

        arr[i][3] = -1;

        f_min = arr[f_min][0] < arr[i][0] ? f_min : i;

        f_arr[i] = arr[i];
    }

    for(int i = 0; i < len; i++) {
        if(arr[i][1] != -1)
            arr[arr[i][1]][3] = i;
        if(arr[i][2] != -1)
            arr[arr[i][2]][3] = i;
    }

    bool ans = check(f_arr, f_min, len);

    if(!ans)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}
