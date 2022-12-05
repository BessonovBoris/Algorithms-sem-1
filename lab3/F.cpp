#include <iostream>
using namespace std;

int Binary_Search_l(int *nums, int n, int target)
{
    int low = -1, high = n;
    while (low + 1 < high)
    {
        int mid = (low + high)/2;

        if (target <= nums[mid]) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    if(target != nums[high]){
        return -1;
    }

    return high+1;
}

int Binary_Search_r(int *nums, int n, int target)
{
    int low = -1, high = n;
    while (low + 1 < high)
    {
        int mid = (low + high)/2;

        if (target < nums[mid]) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    if(target != nums[low]){
        return -1;
    }

    return low + 1;
}

int main()
{
    int num;
    cin >> num;

    int mas[num];

    for (int i = 0; i < num; i++){
        cin >> mas[i];
    }

    int count;
    cin >> count;

    int elements[count];

    for (int i = 0; i < count; i++){
        cin >> elements[i];
    }

    for (int element = 0; element < count; element++){
        int index = Binary_Search_r(mas, num, elements[element]);

        if (index != -1)
        {
            cout << Binary_Search_l(mas, num, elements[element]) << " " << Binary_Search_r(mas, num, elements[element]) << "\n";
        }
        else {
            cout << "-1 -1\n";
        }
    }
    return 0;
}
