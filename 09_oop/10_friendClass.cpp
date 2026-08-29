#include <iostream>
using namespace std;

class Chai {
private:
    int servings;

public:
    Chai(int serve) : servings(serve) {}

    friend class Manager;
};

class Manager {
public:
    void showServings(const Chai& chai) {
        cout << "Servings: " << chai.servings << endl;
    }

    void changeServings(Chai& chai, int value) {
        chai.servings = value;
    }
};

int main() {
    Chai masalaChai(14);

    Manager manager;

    manager.showServings(masalaChai);

    manager.changeServings(masalaChai, 20);

    manager.showServings(masalaChai);

    return 0;
}