#include <iostream>
#include "cmath"

using namespace std;

double const eps = 0.00000001;

bool equal(double a, double b){
    if(abs(a-b) <= eps){
        return true;
    }

    return false;
}

bool less_(double a, double b) {
    if((a < b) && !equal(a, b)){
        return true;
    }

    return false;
}

bool more_(double a, double b) {
    if((a > b) && !equal(a, b)){
        return true;
    }

    return false;
}

double programm(double *arr, int n){
    double res = 1e9;
    double l = 0;
    double r = arr[0];
    bool higher_floor;

    while (less_(l, r)) {
        arr[1] = (l + r) / 2;
        higher_floor = true;

        for (int i = 2; i < n; i++) {
            arr[i] = 2*arr[i-1] - arr[i-2] + 2;
            if (!more_(arr[i], 0)) {
                higher_floor = false;
                break;
            }
        }

        if (higher_floor) {
            r = arr[1];
            res = min(arr[n-1], res);
        }
        else {
            l = arr[1];
        }
    }

    return res;
}

int main(){
    int n;
    cin >> n;

    double arr[n];
    cin >> arr[0];

    double answer = programm(arr, n);

    printf("%.2f", answer);
    return 0;
}
