#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:

    Student(string n, int a)
        : name(n), age(a)
    {
    }

    // Getter
    string getName() {
        return name;
    }

    // Setter
    void setName(string n) {
        name = n;
    }

    // Getter
    int getAge() {
        return age;
    }

    // Setter with validation
    void setAge(int a) {

        if (a >= 18) {
            age = a;
        }
        else {
            cout << "Invalid age!" << endl;
        }
    }
};

int main() {

    Student s("Himanshu", 19);

    cout << "Name: " << s.getName() << endl;
    cout << "Age: " << s.getAge() << endl;

    // Change value using setter
    s.setName("Rahul");
    s.setAge(20);

    cout << "\nAfter update:" << endl;
    cout << "Name: " << s.getName() << endl;
    cout << "Age: " << s.getAge() << endl;

    // Invalid value
    s.setAge(15);

    return 0;
}