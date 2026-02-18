#include <iostream>
#include <stdexcept>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int v) {
        value = v;
        next = nullptr;
    }
};

class Stack {
private:
    Node* topNode;
    int count;

public:
    Stack() {
        topNode = nullptr;
        count = 0;
    }

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    bool empty() const {
        return topNode == nullptr;
    }

    int size() const {
        return count;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    int top() const {
        if (empty())
            throw runtime_error("Stack is empty");
        return topNode->value;
    }

    void pop() {
        if (empty())
            throw runtime_error("Stack is empty");

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;   // 30
    s.pop();
    cout << "Top after pop: " << s.top() << endl; // 20
    cout << "Size: " << s.size() << endl; // 2

    return 0;
}
