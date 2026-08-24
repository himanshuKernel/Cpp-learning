#include <iostream>
using namespace std;

int main()
{
    auto add = [](int a, int b)
    {
        return a + b;
    };

    cout << add(10, 20) << endl;

    return 0;
}