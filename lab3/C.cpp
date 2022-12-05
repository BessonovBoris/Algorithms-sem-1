#include <iostream>

using namespace std;

struct Node{
    char value;
    Node *previous;
};


class List{
private:
    Node *last;

public:
    List(){
        last = nullptr;
    }

    void add_node(char d){
        Node *new_node = new Node;

        new_node->value = d;
        new_node->previous = last;

        last = new_node;
    }

    void del_element(){
        if(last != nullptr){
            last = last->previous;
        }
    }

    char get_element(){
        if(last == nullptr){
            return '\0';
        }
        return last->value;
    }

    void print_elements(){
        Node *current = last;

        if(last == nullptr){
            cout << "Nothing ";
            return;
        }

        while(current != nullptr){
            cout << current->value;
            current = current->previous;
        }
        cout << " ";
    }
};

int programm(string current){
    List *queue = new List;

    for(int ch = 0; current[ch] != '\0'; ch++){

        if(current[ch] == '(' || current[ch] == '['){
            queue->add_node(current[ch]);
        }else if(current[ch] == ')'){
            if(queue->get_element() == '('){
                queue->del_element();
            } else{
                queue->add_node(')');
            }
        } else if(current[ch] == ']') {
            if (queue->get_element() == '['){
                queue->del_element();
            } else{
                queue->add_node(']');
            }
        }

    }

    if(queue->get_element() == '\0'){
        delete queue;
        return 1;
    }

    delete queue;
    return 0;
}

int main(){
    string line = "";
    int answer;

    while(cin >> line){

        answer = programm(line);
        if (answer == 1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }

    }
    return 0;
}
