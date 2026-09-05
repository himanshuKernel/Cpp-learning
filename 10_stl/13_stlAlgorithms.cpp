#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> numbers = {
        50, 20, 40, 20, 10, 30
    };


    // 1. sort()

    sort(numbers.begin(), numbers.end());

    cout << "Sorted: ";

    for (const auto& number : numbers)
    {
        cout << number << " ";
    }


    // 2. reverse()

    reverse(numbers.begin(), numbers.end());

    cout << "\nReversed: ";

    for (const auto& number : numbers)
    {
        cout << number << " ";
    }


    // 3. find()

    auto it = find(
        numbers.begin(),
        numbers.end(),
        40
    );

    if (it != numbers.end())
    {
        cout << "\n40 found";
    }
    else
    {
        cout << "\n40 not found";
    }


    // 4. count()

    int frequency = count(
        numbers.begin(),
        numbers.end(),
        20
    );

    cout << "\nCount of 20: "
         << frequency;


    // 5. min_element()

    auto minIt = min_element(
        numbers.begin(),
        numbers.end()
    );

    cout << "\nMinimum: "
         << *minIt;


    // 6. max_element()

    auto maxIt = max_element(
        numbers.begin(),
        numbers.end()
    );

    cout << "\nMaximum: "
         << *maxIt;


    // 7. binary_search()

    // Binary search requires sorted data
    sort(numbers.begin(), numbers.end());

    if (binary_search(
            numbers.begin(),
            numbers.end(),
            30
        ))
    {
        cout << "\n30 found using binary search";
    }
    else
    {
        cout << "\n30 not found";
    }


    // 8. fill()

    vector<int> values(5);

    fill(
        values.begin(),
        values.end(),
        100
    );

    cout << "\nFilled vector: ";

    for (const auto& value : values)
    {
        cout << value << " ";
    }


    // 9. swap()

    int a = 10;
    int b = 20;

    swap(a, b);

    cout << "\nAfter swap:";
    cout << "\na = " << a;
    cout << "\nb = " << b;


    return 0;
}