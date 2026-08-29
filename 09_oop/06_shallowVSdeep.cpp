#include <iostream>
using namespace std;

class ShallowCopy {
public:
    int* data;

    ShallowCopy(int value) {
        data = new int(value);
    }

    // Shallow copy
    ShallowCopy(const ShallowCopy& other) {
        data = other.data;
    }

    ~ShallowCopy() {
        // Destructor intentionally omitted here
        // because both objects point to the same memory.
    }
};

class DeepCopy {
public:
    int* data;

    DeepCopy(int value) {
        data = new int(value);
    }

    // Deep copy
    DeepCopy(const DeepCopy& other) {
        data = new int(*other.data);
    }

    ~DeepCopy() {
        delete data;
    }
};

int main() {

    cout << "----- Shallow Copy -----" << endl;

    ShallowCopy a(10);
    ShallowCopy b = a;

    cout << "a data: " << *a.data << endl;
    cout << "b data: " << *b.data << endl;

    cout << "\nSame address?" << endl;
    cout << (a.data == b.data ? "Yes" : "No") << endl;


    cout << "\n----- Deep Copy -----" << endl;

    DeepCopy x(20);
    DeepCopy y = x;

    cout << "x data: " << *x.data << endl;
    cout << "y data: " << *y.data << endl;

    cout << "\nSame address?" << endl;
    cout << (x.data == y.data ? "Yes" : "No") << endl;

    *x.data = 100;

    cout << "\nAfter changing x:" << endl;
    cout << "x data: " << *x.data << endl;
    cout << "y data: " << *y.data << endl;

    return 0;
}