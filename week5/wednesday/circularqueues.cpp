#include <iostream>
using namespace std;



class CircularQueues{
private:
    int *arr;
    int front;
    int rear;
    int size;
public:
    CircularQueues(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool empty(){
        //is the queue emptyu?
        if (front == -1 && rear == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool full(){
        return (rear + 1) % size == front;
    }

    void enqueue(int val){
        //is the queue fuill
        if (full()){
            cout<<"Queue is full "<<endl;
            return;
        }
        if (empty()){
            front = rear = 0;
        }
        else{
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
    }

    void dequeue(){
        if (empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        if (front == rear){ //queue has only one element
            front = rear = -1;
        }
        else{
            front = (front + 1) % size;
        }
    }

    int getFront(){
        if (empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }        
    
        return arr[front];
    }

    int getRear(){
        if (empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }        
    
        return arr[rear];
    }
};


int main() {
    CircularQueues q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.dequeue(); //removes 10
    q.dequeue(); //removes 20;

    q.enqueue(60);
    q.enqueue(70);

    cout << "Front: " << q.getFront() << endl; //30
    cout << "Rear: " << q.getRear() << endl; //70

    return 0;
}