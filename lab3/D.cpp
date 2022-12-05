#include <iostream>

using namespace std;

struct Node{
    int value;
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
        new_node->previous = last;

        last = new_node;
    }

    int del_element(){
        int ret = 0;

        if(last != nullptr){
            ret = last->value;
            last = last->previous;
        }
        return ret;
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
    List queue;

    string input;
    string token;

    int pos = 2;

    int first_operand;
    int second_operand;
    int result;
    int num;

    getline(cin, input);

    pos = input.find(' ');
    while(1){
        if(pos != string::npos){
            token = input.substr(0, pos);
        } else {
            token = input;
        }

        if(token != "+" && token != "-" && token != "*"){
            num = stoi(token);
            queue.add_node(num);
        } else{
            second_operand = queue.del_element();
            first_operand = queue.del_element();

            if(token == "+"){
                result = first_operand + second_operand;
            } else if(token == "-"){
                result = first_operand - second_operand;
            } else if(token == "*"){
                result = first_operand * second_operand;
            }
            queue.add_node(result);
        }

        input.erase(0, pos + 1);

        if(pos == string::npos){
            break;
        }

        pos = input.find(' ');
    }

    queue.print_elements();
    return 0;
}
