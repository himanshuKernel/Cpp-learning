#include <iostream>
using namespace std;

void countDown(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << endl;
    countDown(n - 1);
}

int main()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    countDown(x);

    return 0;
}