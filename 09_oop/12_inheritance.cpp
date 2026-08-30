#include <iostream>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(string n) : name(n) {}

    void eat() {
        cout << name << " is eating." << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void bark() {
        cout << name << " is barking." << endl;
    }
};

int main() {
    Dog dog("Tommy");

    dog.eat();   // inherited
    dog.bark();  // own function

    return 0;
}