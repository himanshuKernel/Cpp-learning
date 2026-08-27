#include <iostream>
using namespace std;

int main()
{
    int* number = new int;

    *number = 100;

    cout << "Value: " << *number << endl;

    delete number;

    return 0;
}