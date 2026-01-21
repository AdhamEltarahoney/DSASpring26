//C++ basics

//stdio.h 
#include <iostream>
#include <string>

using namespace std;

int main(){
    int age; 
    string name;


    //basic input output stuff
    cout << "Enter your name: ";
    cin >> name;

    cout << "How old are you? ";
    cin >> age;

    cout << "Welcome "<<name<<"! You are "<<age<< " years old"<<endl;




    // for loops and while loops
    // a while loop
    
    cout << "How many times should I print your name? ";
    int numberOfTimes;
    cin >> numberOfTimes;
    int i = 0;
    while (i < numberOfTimes){
        cout<<name<<endl;
        i++;
    }


    // fixed sized arrays
    int numbers[5] = {10, 20, 30, 40, 50};
    cout << "Numbers in array: "<<endl;

    for (int i = 0; i < 5; i++){
        cout<<numbers[i]<<endl;
    }

    return 0;
}