#include <stdio.h>

void merge(int *a, int left, int mid, int right){
    int it1 = 0;
    int it2 = 0;
    int res[right-left];

    while((left + it1 < mid) && (mid + it2 < right)){
        if (a[left+it1] < a[mid+it2]){
            res[it1+it2] = a[left+it1];
            it1++;
        } else {
            res[it1+it2] = a[mid+it2];
            it2++;
        }
    }

    while (left + it1 < mid){
        res[it1+it2] = a[left+it1];
        it1++;
    }

    while(mid + it2 < right){
        res[it1+it2] = a[mid+it2];
        it2++;
    }

    for(int i = 0; i < it1+it2; i++){
        a[left+i] = res[i];
    }
}

void mergeS(int *a, int left, int right){
    if(left + 1 >= right){
        return;
    }
    int mid = (left + right)/2;
    mergeS(a, left, mid);
    mergeS(a, mid, right);
    merge(a, left, mid, right);
}

int main() {
    int len1, len2;
    int max1 = 0, max2 = 0;

    scanf("%d", &len1);
    int arr1[len1];
    for(int i = 0; i<len1; i++){
        scanf("%d", &arr1[i]);
        if(arr1[i] > max1){
            max1 = arr1[i];
        }
    }

    scanf("%d", &len2);
    int arr2[len2];
    for(int i = 0; i<len2; i++){
        scanf("%d", &arr2[i]);
        if(arr2[i] > max2){
            max2 = arr2[i];
        }
    }
//Entry end
    if(max1 != max2){
        printf("NO");
        return 0;
    }

    mergeS(arr1, 0, len1);
    mergeS(arr2, 0, len2);

    if(arr1[0] != arr2[0]){
        printf("NO");
        return 0;
    }

    int point1 = 1;
    int point2 = 1;
    int res = 1;
    while (point1 < len1 && point2 < len2){
        if(arr1[point1] == arr2[point2]){
            res++;
            point1++;
            point2++;
        } else if(arr1[point1] > arr2[point2]){
            if(arr2[point2] > arr1[point1-1]){
                printf("NO");
                return 0;
            }
            point2++;
        } else if(arr1[point1] < arr2[point2]){
            if(arr1[point1] > arr2[point2-1]){
                printf("NO");
                return 0;
            }
            point1++;
        }
    }

    printf("YES");
    return 0;
}
