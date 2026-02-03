#include <iostream>
#include <stdexcept>
using namespace std;

//Node class
class Node{
public:
    int data;
    Node* next;

    Node(int d, Node* n=nullptr): data(d), next(n){}
};

// Single linked list class
class SingleLinkedList{

private:
    Node* head;
public:

    SingleLinkedList():head(nullptr){}

    // checking whether a linked list is empty (has no nodes)
    bool isEmpty() const {
        return head == nullptr;
    }
    //adding to front
    void addToFront(int value){
        head = new Node(value, head);
    }

    //check what the first element in the linked list is
    int front() const {
        if (isEmpty())
            throw runtime_error("List is empty!");
        return head->data;    
    }
    void removeFront(){
        if (isEmpty())
            throw runtime_error("List is empty");
        Node* oldHead = head; //the node that will be deleted
        head = head->next;
        delete oldHead;
    }
    // function that prints all elements in ll
    void print() const {
        Node* curr = head;
        while (curr!=nullptr){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<"Null\n";
    }
};

int main(){
    SingleLinkedList list;
    list.addToFront(1);
    list.addToFront(2);
    list.addToFront(3);
    // list 3->2->1
    list.print(); //
    list.removeFront();
    cout<<"3 should be deleted"<<endl;
    list.print(); //2->1

}