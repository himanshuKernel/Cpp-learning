#include <iostream>
using namespace std;

void message(int n)
{   // Base case
    if (n == 0)
    {
        return;
    }
    // Recursive case
    cout << "Hello" << endl;
    message(n - 1);
}

int main()
{
    message(5);

    return 0;
}