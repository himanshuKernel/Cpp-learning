#include <iostream>
#include <string>
using namespace std;

void greet(string name)
{
    cout << "Hello, " << name << "!" << endl;
}

int main()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    greet(name);

    return 0;
}