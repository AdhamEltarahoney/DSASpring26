#include <iostream>
using namespace std;

class DLinkedList; // forward declaration

class DNode {
private:
    int data;      
    DNode* prev;
    DNode* next;
    friend class DLinkedList;
};

class DLinkedList {
public:
    DLinkedList();
    ~DLinkedList();

    bool empty() const;
    int front() const;
    int back() const;

    void addFront(int x);
    void addBack(int x);
    void removeFront();
    void removeBack();

    void printForward() const;
    void printBackward() const;

private:
    DNode* header;   // front sentinel
    DNode* trailer;  // back sentinel

    void add(DNode* v, int x); // insert before v
    void remove(DNode* v);     // remove node v
};

// ---- Implementation ----

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;

    header->next = trailer;
    header->prev = nullptr;

    trailer->prev = header;
    trailer->next = nullptr;
}

DLinkedList::~DLinkedList() {
    while (!empty()) {
        removeFront();
    }
    delete header;
    delete trailer;
}

bool DLinkedList::empty() const{
    return header->next == trailer;
}

int DLinkedList::front() const{
    return header->next->data;
}


int DLinkedList::back() const{
    return trailer->prev->data;
}

void DLinkedList::add(DNode* v, int x){ // inserts a new node before v
    DNode* u = new DNode;
    u->data = x;

    u->next = v;
    u->prev = v->prev;

    v->prev->next = u;
    v->prev = u;
}

void DLinkedList::addFront(int x){
    add(header->next, x);
}

void DLinkedList::addBack(int x){
    add(trailer, x);
}


void DLinkedList::remove(DNode* v){
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

void DLinkedList::removeFront(){
    if (!empty()){
        remove(header->next);
    }
}

void DLinkedList::removeBack(){
    if (!empty()){
        remove(trailer->prev);
    }
}



void DLinkedList::printForward() const {
    cout << "Forward: ";
    for (DNode* cur = header->next; cur != trailer; cur = cur->next) {
        cout << cur->data << " ";
    }
    cout << endl;
}

void DLinkedList::printBackward() const {
    cout << "Backward: ";
    for (DNode* cur = trailer->prev; cur != header; cur = cur->prev) {
        cout << cur->data << " ";
    }
    cout << endl;
}

int main() {
    DLinkedList dll;

    dll.addFront(2);
    dll.addFront(1);//1->2
    dll.addBack(3);//1->2->3
    dll.addBack(4);//1->2->3->4

    dll.printForward();   // 1 2 3 4
    dll.printBackward();  // 4 3 2 1

    dll.removeFront();    // remove 1
    dll.removeBack();     // remove 4
    //1->2->3->4 -->>> 2->3

    dll.printForward();   // 2 3
    dll.printBackward();  // 3 2

    return 0;
}