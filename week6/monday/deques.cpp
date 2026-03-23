#include <iostream>
using namespace std;

class DequeArray{
    private:
        int *arr;
        int front;
        int rear;
        int size;
        int capacity;
    public:
        DequeArray(int cap){
            capacity = cap;
            arr = new int[capacity];
            front = 0;
            rear = -1;
            size = 0;
        }

        bool empty() const{
            //tell us whether or not our deque is empty
            return size == 0;
        }
        bool full() const{
            return size == capacity;
        }

        int getSize(){
            return size;
        }

        // getFront -> returns first element in the deque 
        // getBack -> return last element in deque

        int getFront() const{
            if (empty()){
                throw runtime_error("Deque is empty, nothing is at the front");
            }
            return arr[front];
        }

        int getBack() const{
            if (empty()){
                throw runtime_error("Deque is empty, nothing is at the front");
            }
            return arr[rear];
        }
        //pushing and popping functions
        //pushfront and pushback popfront and popback

        void push_front(int val){
            if (full()){
                throw runtime_error("Deque is full");
            }
            if (empty()){
                front = rear = 0;
            }
            else{
                front = (front - 1 + capacity) % capacity;
            }
            arr[front] = val;
            size++;
        }


        void push_back(int val){
            if (full()){
                throw runtime_error("Deque is full");
            }
            if (empty()){
                front = rear = 0;
            }
            else{
                rear = (rear+1) % capacity;
            }
                arr[rear] = val;
            size++;
        }

        //popping methods
        void pop_front(){
            if (empty()){
                throw runtime_error("Deque is empty");
            }
            front = (front + 1) % capacity;
            size--;
        }
        void pop_back(){
            if (empty()){
                throw runtime_error("Deque is empty");
            }
            rear = (rear - 1 + capacity) % capacity;
            size--;

        }
};


int main(){
    DequeArray dq(5);
    dq.push_front(10); //[10]
    dq.push_front(20); // [20, 10]
    dq.push_front(30); // 30, 20., 10
    cout << dq.getFront() <<endl; //30
    cout << dq.getBack() <<endl; //10
    dq.pop_front(); //20, 10
    cout<< dq.getFront() <<endl;//20


}