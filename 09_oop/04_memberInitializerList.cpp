#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:

    // Member initializer list
    Student(string n, int a)
        : name(n), age(a)
    {
        cout << "Constructor called" << endl;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {

    Student s("Himanshu", 19);

    s.display();

    return 0;
}