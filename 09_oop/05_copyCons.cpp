#include <iostream>
using namespace std;

class Chai {
private:
    string teaName;
    int servings;

public:

    Chai(string name, int serve)
        : teaName(name), servings(serve)
    {
        cout << "Parameterized constructor called" << endl;
    }

    // Copy constructor
    Chai(const Chai& other)
        : teaName(other.teaName),
          servings(other.servings)
    {
        cout << "Copy constructor called" << endl;
    }

    void display() {
        cout << "Tea: " << teaName << endl;
        cout << "Servings: " << servings << endl;
    }
};

int main() {

    Chai lemonTea("Lemon Tea", 2);

    // Creating a new object using existing object
    Chai copiedChai = lemonTea;

    cout << "\nOriginal:" << endl;
    lemonTea.display();

    cout << "\nCopy:" << endl;
    copiedChai.display();

    return 0;
}