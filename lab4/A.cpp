#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        if(2*i + 1 < n){
            if(arr[i] > arr[2*i+1]){
                cout << "NO";
                return 0;
            }
        } else if (2*i + 2 < n){
            if(arr[i] > arr[2*i + 2]){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";

    return 0;
}
