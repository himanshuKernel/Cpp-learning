#include <iostream>
using namespace std;

class Chai {
public:
    string teaName;
    int servings;

    // Parameterized constructor
    Chai(string name, int serve) {
        teaName = name;
        servings = serve;

        cout << "Parameterized constructor called" << endl;
    }

    void display() {
        cout << "Tea: " << teaName << endl;
        cout << "Servings: " << servings << endl;
    }
};

int main() {

    Chai lemonTea("Lemon Tea", 2);

    lemonTea.display();

    return 0;
}