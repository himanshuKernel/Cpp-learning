#include <iostream>
using namespace std;

class SecuritySystem final {
public:
    void start() {
        cout << "Security system started." << endl;
    }
};

// This would give an error:
//
// class AdvancedSecurity : public SecuritySystem {
// };

int main() {
    SecuritySystem system;
    system.start();

    return 0;
}