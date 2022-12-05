#include <iostream>

using namespace std;

void merge(int *a[], int left, int mid, int right, int index){
    int it1 = 0;
    int it2 = 0;
    int res[right-left][2];

    while((left + it1 < mid) && (mid + it2 < right)){
        if (a[left+it1][index] < a[mid+it2][index]){
            res[it1+it2][0] = a[left+it1][0];
            res[it1+it2][1] = a[left+it1][1];
            it1++;
        } else {
            res[it1+it2][0] = a[mid+it2][0];
            res[it1+it2][1] = a[mid+it2][1];
            it2++;
        }
    }

    while (left + it1 < mid){
        res[it1+it2][0] = a[left+it1][0];
        res[it1+it2][1] = a[left+it1][1];
        it1++;
    }

    while(mid + it2 < right){
        res[it1+it2][0] = a[mid+it2][0];
        res[it1+it2][1] = a[mid+it2][1];
        it2++;
    }

    for(int i = 0; i < it1+it2; i++){
        a[left+i][0] = res[i][0];
        a[left+i][1] = res[i][1];
    }
}

void mergeS(int *a[], int left, int right, int index){
    if(left + 1 >= right){
        return;
    }
    int mid = (left + right)/2;
    mergeS(a, left, mid, index);
    mergeS(a, mid, right, index);
    merge(a, left, mid, right, index);
}

int main(){
    int len;
    cin >> len;

    int arr[len][2];
    int *arr_p[len];

    for(int i = 0; i<len; i++){
        cin >> arr[i][0] >> arr[i][1];
        arr_p[i] = arr[i];
    }
    mergeS(arr_p, 0, len, 0);
//Entry & sort end

    int res;
    int farthest = arr[0][0] - 1;
    res = 0;

    for(int i = 0; i < len; i++){
        if(farthest < arr[i][0]){
            res += arr[i][1] - arr[i][0] + 1;
            farthest = arr[i][1];
        } else if(farthest < arr[i][1]){
            res += arr[i][1] - farthest;
            farthest = arr[i][1];
        }
    }

    cout << res;
    return 0;
}
