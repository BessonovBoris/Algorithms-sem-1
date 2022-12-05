#include <vector>
#include <iostream>
#include <map>

using namespace std;

class queue_priority{
private:
    int size;
    vector<vector<int>> tree;
    map <int, int> past;
public:
    queue_priority() {
        size = 0;
    }

    void add(int a,int num) {
        vector<int> new_element;
        new_element.push_back(a);
        new_element.push_back(num);
        tree.push_back(new_element);
        past[num] = size;
        up(size);
        size += 1;
    }

    void sift_down(int i) {
        int j;
        int left;
        int right;

        while(i * 2 + 1 < size) {
            left = 2*i + 1;
            right = 2*i + 2;

            if(right >= size) {
                j = left;
            }else {
                if (tree[left] > tree[right]) {
                    j = right;
                } else {
                    j = left;
                }
            }
            if(tree[i] > tree[j]) {
                swap(tree[j], tree[i]);
                swap(past[tree[j][1]], past[tree[i][1]]);
                i = j;
            } else {
                break;
            }
        }
    }

    void up(int n) {
        while(((n + (n % 2))/ 2 > 0) and (tree[(n + (n % 2)) / 2 - 1]) > tree[n]) {
            swap(tree[(n + (n % 2)) / 2 - 1], tree[n]);
            swap(past[tree[(n + (n % 2)) / 2 - 1][1]], past[tree[n][1]]);
            n = (n + (n % 2)) / 2 - 1;
        }
    }

    void extract_min() {
        if(size > 0) {
            cout << tree[0][0] << '\n';
            swap(tree[0], tree[size - 1]);
            swap(past[tree[0][1]], past[tree[size - 1][1]]);
            size -= 1;
            tree.pop_back();
            sift_down(0);
        }else {
            cout << "*\n";
        }
    }

    void decrease_key(int x, int y) {
        tree[past[x]][0] = y;
        up(past[x]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue_priority tree;
    string str;
    int num;
    int place;
    int i = 1;

    while(cin >> str) {
        if(str[0] == 'p') {
            cin >> num;
            tree.add(num, i);
        }else if(str[0] == 'e') {
            tree.extract_min();
        }else {
            cin >> place >> num;
            tree.decrease_key(place, num);
        }
        i++;
    }
    return 0;
}
