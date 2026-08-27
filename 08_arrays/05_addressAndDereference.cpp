#include <iostream>
using namespace std;

int main()
{
    int number = 10;

    int* ptr = &number;

    cout << "Value: " << number << endl;
    cout << "Address: " << &number << endl;
    cout << "Pointer stores: " << ptr << endl;
    cout << "Value using pointer: " << *ptr << endl;

    *ptr = 50;

    cout << "New value: " << number << endl;

    return 0;
}