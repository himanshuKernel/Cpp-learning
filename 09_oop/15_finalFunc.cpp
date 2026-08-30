#include <iostream>
using namespace std;

class Tea {
public:
    virtual void brew() {
        cout << "Generic tea brewing." << endl;
    }
};

class MasalaTea : public Tea {
public:
    void brew() override final {
        cout << "Brewing Masala Tea." << endl;
    }
};

// This would give an error:
//
// class SpicyMasalaTea : public MasalaTea {
// public:
//     void brew() override {
//         cout << "Spicy Masala Tea." << endl;
//     }
// };

int main() {
    MasalaTea tea;
    tea.brew();

    return 0;
}