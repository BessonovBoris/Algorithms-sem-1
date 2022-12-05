#include <iostream>

using namespace std;

void countSort(string arr[], int len, int unit) {
    string sorted[len];
    int c[26] = { 0 };

    for(int i = 0; i < len; i++) {
        c[(int)arr[i][unit] - 97]++;
    }

    for(int i = 1; i < 26; i++) {
        c[i] = c[i] + c[i-1];
    }

    for(int i = len-1; i >= 0; i--) {
        sorted[c[(int)arr[i][unit] - 97] - 1] = arr[i];
        c[(int)arr[i][unit] - 97]--;
    }

    for(int i = 0; i < len; i++){
        arr[i] = sorted[i];
    }
}

void radixSort(string arr[], int len, int str_len, int k) {
    for(int i = str_len-1; i >= 0; i--) {
        countSort(arr, len, i);
        k--;
        if(k == 0) {
            for(int j = 0; j < len; j++) {
                cout << arr[j] << '\n';
            }
            break;
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    string arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    radixSort(arr, n, m, k);

    return 0;
}
