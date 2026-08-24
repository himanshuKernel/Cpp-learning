#include <iostream>
#include <string>
using namespace std;

void introduce(string name, int age)
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}

int main()
{
    string name;
    int age;
    cout << "Enter your name and age: ";
    cin >> name >> age;

    introduce(name, age);

    return 0;
}