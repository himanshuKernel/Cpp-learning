#include <iostream>
using namespace std;

int main()
{
    int numbers[5] = {10, 20, 30, 40, 50};

    int* ptr = numbers;

    cout << *ptr << endl;
    cout << *(ptr + 1) << endl;
    cout << *(ptr + 4) << endl;

    return 0;
}