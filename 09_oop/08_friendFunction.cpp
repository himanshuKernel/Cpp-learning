#include <iostream>
using namespace std;

class Chai {
private:
    int servings;

public:
    Chai(int serve) : servings(serve) {}

    friend void showServings(const Chai& chai);
};

void showServings(const Chai& chai) {
    cout << "Servings: " << chai.servings << endl;
}

int main() {
    Chai masalaChai(14);

    showServings(masalaChai);

    return 0;
}