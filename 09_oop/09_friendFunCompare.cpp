#include <iostream>
using namespace std;

class Chai {
private:
    string teaName;
    int servings;

public:
    Chai(string name, int serve)
        : teaName(name), servings(serve) {}

    friend bool compareServings(
        const Chai& chai1,
        const Chai& chai2
    );
};

bool compareServings(
    const Chai& chai1,
    const Chai& chai2
) {
    return chai1.servings > chai2.servings;
}

int main() {
    Chai masalaChai("Masala Chai", 14);
    Chai gingerChai("Ginger Chai", 8);

    if (compareServings(masalaChai, gingerChai)) {
        cout << "Masala Chai has more servings." << endl;
    } else {
        cout << "Ginger Chai has more servings." << endl;
    }

    return 0;
}