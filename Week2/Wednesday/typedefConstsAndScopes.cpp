#include <iostream>
using namespace std;

typedef unsigned int uint; // typedef

int main() {
    const int DAYS = 7;     // const

    uint count = 5;         // typedef in use
    cout << count << endl;

    int x = 10;             // outer scope
    {
        int x = 3;          // inner scope (shadows outer)
        cout << x << endl;  // prints 3
    }
    cout << x << endl;      // prints 10

    return 0;
}
