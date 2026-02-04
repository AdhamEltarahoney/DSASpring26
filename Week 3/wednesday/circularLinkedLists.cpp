#include <iostream>
using namespace std;

class CircularLinkedList; // forward declaration

class Node {
private:
    int data;
    Node* next;

public:
    Node(int value) {
        data = value;
        next = nullptr;
    }

    friend class CircularLinkedList;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }

        current->next = newNode;
        newNode->next = head;
    }

    // Print list once around the circle
    void printList() const {
        if (!head) {
            cout << "(empty)\n";
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);

        cout << "\n";
    }

    // Search for a value
    bool search(int target) const {
        if (!head) return false;

        Node* current = head;
        do {
            if (current->data == target) {
                return true;
            }
            current = current->next;
        } while (current != head);

        return false;
    }

    // Remove node AFTER cursorValue
    void removeAfterCursor(int cursorValue) {
        if (!head) return;

        // Single-node list
        if (head->next == head) return;

        Node* cursor = head;
        do {
            if (cursor->data == cursorValue) {
                Node* nodeToRemove = cursor->next;

                // If removing head, shift head forward
                if (nodeToRemove == head) {
                    head = head->next;
                }

                cursor->next = nodeToRemove->next;
                delete nodeToRemove;
                return;
            }
            cursor = cursor->next;
        } while (cursor != head);
    }

    // Destructor
    ~CircularLinkedList() {
        if (!head) return;

        Node* current = head->next;
        while (current != head) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete head;
        head = nullptr;
    }
};

int main() {
    CircularLinkedList list;

    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(4);

    cout << "Initial list: ";
    list.printList();

    cout << "Search 3? " << (list.search(3) ? "true" : "false") << endl;
    cout << "Search 9? " << (list.search(9) ? "true" : "false") << endl;

    list.removeAfterCursor(2);
    cout << "After removeAfterCursor(2): ";
    list.printList();

    list.removeAfterCursor(4); // wrap-around case
    cout << "After removeAfterCursor(4): ";
    list.printList();

    return 0;
}
