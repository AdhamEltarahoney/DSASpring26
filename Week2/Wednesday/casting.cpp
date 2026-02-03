#include <iostream>
using namespace std;

int main() {
    double x = 3.9;

    int a = (int)x;               // C-style cast
    int b = static_cast<int>(x);  // C++ cast

    cout << a << endl;
    cout << b << endl;

    return 0;
}
