#include <iostream>

using namespace std;
int main()
{
    int teaBags;
    cout << "How many tea bags do you have ? : " ;
    cin >> teaBags;
    if (teaBags <= 20)
    {
        teaBags += 10;
    }
    cout << "Updated total tea bags : "<<teaBags;
    return 0;
}