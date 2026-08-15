#include <iostream>

using namespace std;
int main()
{
    int teaCups, memberYear, discount;
    cout << "How many cups of tea do you want ? : ";
    cin >> teaCups;
    cout << "Since how many year ,you are our customer ? : ";
    cin >> memberYear;
    if (teaCups >= 12 || memberYear > 1)
    {
        cout << "You qualify for a discount !" << endl;
    }
    else
    {
        cout << "You do not qualify for a discount !" << endl;
    }

    return 0;
}