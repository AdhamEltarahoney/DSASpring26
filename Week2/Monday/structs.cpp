#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    int id;
    double gpa;
};

int main(){
    Student s1;
    s1.name = "Adham";
    s1.id = 123;
    s1.gpa = 3.9;
    cout << s1.name << " has an id of: " << s1.id << " and a gpa of: " << s1.gpa <<endl;
    s1.gpa = 3.95;

    cout << s1.name << " has an id of: " << s1.id << " and his gpa became: " << s1.gpa <<endl;

    return 0;

}