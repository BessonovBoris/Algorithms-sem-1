#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *left_son;
    Node *right_son;
};

Node *insert(Node *&r, int x) {
    if (r == nullptr){
        r = new Node;
        r ->data = x;
        r ->left_son = nullptr;
        r ->right_son = nullptr;
    } else if (x < r -> data) {
        insert(r->left_son, x);
    }else{
        insert(r->right_son, x);
    }

    return r;
}

void print_tree(Node *root){
    if (root != nullptr){
        print_tree(root->left_son);
        print_tree(root->right_son);

        cout << root ->data << " ";
    }
}

Node *make_tree(int *a, int *i, int key, int max, int min, int len) {
    Node* root = nullptr;

    if(*i >= len){
        return nullptr;
    }

    if(key > min && key < max) {
        root = insert(root, key);
        *i = *i + 1;

        root->left_son = make_tree(a, i, a[*i], key, min, len);

        root->right_son = make_tree(a, i, a[*i], max, key, len);
    }

    return root;
}
int main() {
    int len;
    int index = 0;
    int f_min, f_max;

    cin >> len;

    int arr[len];

    for(int i = 0; i < len; i++){
        cin >> arr[i];
    }

    f_max = arr[0];
    f_min = arr[0];
    for(int i = 0; i < len; i++) {
        f_max = f_max > arr[i] ? f_max : arr[i];
        f_min = f_min < arr[i] ? f_min : arr[i];
    }

    Node* tree = make_tree(arr, &index, arr[0], f_max + 1, f_min - 1, len);
    print_tree(tree);

    return 0;
}
