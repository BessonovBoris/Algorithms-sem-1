#include <iostream>

using namespace std;

struct Node{
    int value;
    int max_value;
    Node *previous;
};

class List{
private:
    Node *last;

public:
    List(){
        last = nullptr;
    }

    void add_node(int d){
        Node *new_node = new Node;

        new_node->value = d;
        if(last == nullptr){
            new_node->max_value = d;
        } else {
            new_node->max_value = (d >= last->max_value) ? d : last->max_value;
        }
        new_node->previous = last;

        last = new_node;
    }

    void del_element(){
        if(last != nullptr){
            last = last->previous;
        }
    }

    int get_max(){
        return last->max_value;
    }

    void print_elements(){
        Node *current = last;

        if(last == nullptr){
            cout << "Nothing ";
            return;
        }

        while(current != nullptr){
            cout << current->value << " ";
            current = current->previous;
        }
        cout << "\n";
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    List queue;

    int n;
    int input_num;
    string oper;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> oper;

        if(oper == "+"){
            cin >> input_num;
            queue.add_node(input_num);
        } else if(oper == "-"){
            queue.del_element();
        } else if(oper == "max"){
            cout << queue.get_max() << "\n";
        }
    }

    return 0;
}
