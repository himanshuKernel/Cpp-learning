#include <iostream>
using namespace std;

class Payment {
public:
    virtual void pay() = 0;

    virtual ~Payment() {}
};

class UPI : public Payment {
public:
    void pay() override {
        cout << "Payment made through UPI" << endl;
    }
};

class CreditCard : public Payment {
public:
    void pay() override {
        cout << "Payment made through Credit Card" << endl;
    }
};

int main() {
    Payment* payment1 = new UPI();
    Payment* payment2 = new CreditCard();

    payment1->pay();
    payment2->pay();

    delete payment1;
    delete payment2;

    return 0;
}