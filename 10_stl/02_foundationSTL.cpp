#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Container
    vector<int> numbers = {50, 20, 40, 10, 30};

    // Algorithm + Iterators
    sort(numbers.begin(), numbers.end());

    // Range-based loop
    for (const auto& number : numbers)
    {
        cout << number << " ";
    }

    return 0;
}