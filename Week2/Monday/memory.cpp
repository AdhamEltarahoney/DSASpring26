#include <iostream>
using namespace std;

// new and delete
int main() {
    int *p = new int;   // allocate
    *p = 42;

    cout << *p << endl; // prints 42
    cout << p << endl;  // prints the address stored in p

    delete p;           // free the memory
    p = nullptr;        // avoid a dangling pointer

    cout << p << endl;  // usually prints 0 or (nil)

    // DO NOT do this: dereferencing nullptr is undefined behavior
    // cout << *p << endl; 

    return 0;
}