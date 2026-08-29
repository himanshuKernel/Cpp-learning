#include <iostream>
using namespace std;

class Chai {
public:
    string teaName;
    int servings;

    // Default constructor
    Chai() {
        teaName = "Unknown Tea";
        servings = 1;

        cout << "Default constructor called" << endl;
    }

    void display() {
        cout << "Tea: " << teaName << endl;
        cout << "Servings: " << servings << endl;
    }
};

int main() {

    Chai chai;

    chai.display();

    return 0;
}