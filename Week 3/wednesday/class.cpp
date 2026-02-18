#include <iostream>
using namespace std;

//forward declarations
class CircularLinkedList;

class Node{
    private:
        int data;
        Node* next;
    public:
        Node(int value){
            data = value;
            next = nullptr;
        }
        friend class CircularLinkedList;
};

class CircularLinkedList
{
    private:
        Node* head; //head pointer pointing at the very start of the linked list
    public:
        // insert at the end of a circular linked list
        // print a circular linked list
        // search for a value
        // remove a node after a cursor value

        CircularLinkedList(){
            head = nullptr;
        }
        void insertAtEnd(int value)
        {
            //1. create a node with that value
            Node* newNode = new Node(value);

            //what if the linked list is initially empty, whenever you declare a cll at the very start, the object should not have any nodes
            if (!head){
                //the circular linked list is empty
                head = newNode;
                head->next = head;
                return;
            }
            // what if the linked list is not empty
            //we first wanna traverse to the very end of the linked list to know where to insert our newly created node
            Node* curr = head;
            while(curr->next != head){
                curr = curr->next;
            }
            //at the very end of this while loop, curr->next ==head which means that curr is pointing on the very last node in the CLL
            curr->next = newNode;
            newNode->next = head;
        }

        void printList() const
        {
            //1. check if the cll has nodes in the first place, if not return
            if(!head){
                // the CLL is empty
                cout<<"List is empty"<<endl;
                return;
            }

            Node* curr = head;

            do{
                cout<<curr->data<<" "<<endl;
                curr = curr->next;
            } while (curr != head);
            cout<<endl;
        }

        // searching for a value, return true if the value exists within the CLL
        bool search(int target) const{
            if (!head){
                //CLL is empty, search is definetly failing
                return false;
            }
            Node* curr = head;
            do{
                if (curr->data == target){
                    return true;
                }
                curr = curr->next;
            } while (curr != head);

            return false; //data is not found after one full loop
        }
        

        // remove node AFTER ther node that has that cursor value
        void removeAfterCursor(int cursorValue){
            // 1. check if the cll has any nodes, if it doesnt j return
            if (!head){
                return;
            }
            Node* cursor = head;
            do{
                if (cursor->data == cursorValue){
                    Node* nodeToRemove = cursor->next;

                    //if we are removing the head node, shift head forward
                    if (nodeToRemove == head){
                        head = head->next;
                    }
                    cursor->next = nodeToRemove->next;
                    delete nodeToRemove;
                    return;
                }
                cursor = cursor->next;
            } while (cursor != head);
        }
};

int main(){
    CircularLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2); // 1->2
    list.insertAtEnd(3); // 1->2->3
    list.insertAtEnd(4); // 1->2->3->4
    list.printList();

    list.removeAfterCursor(2); // should removge the node containing 3
    cout<<"List after removing 3"<<endl;
    list.printList(); // print 1->2->4

}
