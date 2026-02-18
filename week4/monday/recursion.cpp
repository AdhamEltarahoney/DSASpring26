// factorial and recursive arrays sum

#include <iostream>
using namespace std;



int factorial(int n){
    if (n < 0 || n == 1){
        cout<<"factorial only works with positives"<<endl;
    }
    if (n == 0){
        return 1;
    }
    return n * factorial(n-1);
}

int sumOfArray(int A[], int n, int i){
    if (i == n){
        return 0;
    }
    return A[i] + sumOfArray(A, n, i+1);

}


int fib(int n){
    if (n <= 1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main(){
    int n = 5;
    cout<< "Factorial of 5 is: "<<factorial(5)<<endl;


    int A[] = {1,2,3,4,5}; // sum 15
    int size = 5;
    cout<<"sum of the array is "<<sumOfArray(A, size, 0)<<endl;

    //plain recursion for fibnonacci
    // fib(5) = 5
    cout << "fib(5): " << fib(99) << endl;
}
