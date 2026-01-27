#include <iostream>
#include <string>
using namespace std;

int main(){

    string author = "Adham";
    
    cout <<author<<endl;
    string &authorname = author; //declares authorname as a reference to author
    // its a reference so it is NOT a new variable
    //it is just an alias for the same block of memory
    authorname = "james";

    cout << author << endl; // I should get james

}