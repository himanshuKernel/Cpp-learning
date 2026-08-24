#include <iostream>
using namespace std;

float average(float a, float b, float c)
{
    return (a + b + c) / 3;
}

int main()
{
    float result = average(10, 20, 30);

    cout << "Average = " << result << endl;

    return 0;
}