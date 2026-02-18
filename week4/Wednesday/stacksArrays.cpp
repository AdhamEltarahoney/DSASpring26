#include <iostream>
#include <vector>
#include <stdexcept>


using namespace std;

//Array-based stack
class Stack
{
private:
    vector<int> data;

public:
    //bool empty return true if stack is empty
    bool empty() const {return data.empty();}

    // int size() return the size of the stack
    int size() const {return (int)data.size();}

    
    // push function to push an element at the top of the class

    void push(int value){
        data.push_back(value);
    }

    int top() const
    {
        // return the last element in the stack (lifo)
        if (empty()){
            // nothing to return
            throw runtime_error("stack is empty");
        }
        return data.back();
    }

    void pop(){
        if (empty()){
            throw runtime_error("stack is empty");
        }
        data.pop_back();
    }

    void display(){
        for (int i = 0; i<data.size(); i++){
            cout<<data[i]<<" "<<endl;
        }
    }
};

int main(){
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.display();
    stk.pop();
    stk.pop();
    stk.pop();
    // another pop will throw an error

    stk.pop();
}


