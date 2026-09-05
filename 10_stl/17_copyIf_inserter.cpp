#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    // 1. copy_if() + back_inserter()
    //    Copy only even numbers

    vector<int> numbers = {
        10, 15, 20, 25, 30, 35, 40
    };

    vector<int> evenNumbers;

    copy_if(
        numbers.begin(),
        numbers.end(),
        back_inserter(evenNumbers),
        [](int number)
        {
            return number % 2 == 0;
        }
    );

    cout << "Even numbers: ";

    for (const auto& number : evenNumbers)
    {
        cout << number << " ";
    }


    // 2. copy_if() + back_inserter()
    //    Copy numbers greater than 25

    vector<int> greaterNumbers;

    copy_if(
        numbers.begin(),
        numbers.end(),
        back_inserter(greaterNumbers),
        [](int number)
        {
            return number > 25;
        }
    );

    cout << "\nGreater than 25: ";

    for (const auto& number : greaterNumbers)
    {
        cout << number << " ";
    }


    // 3. copy_if() + front_inserter()
    //    Insert selected elements at the front

    list<int> reversedNumbers;

    copy_if(
        numbers.begin(),
        numbers.end(),
        front_inserter(reversedNumbers),
        [](int number)
        {
            return true;
        }
    );

    cout << "\nUsing front_inserter: ";

    for (const auto& number : reversedNumbers)
    {
        cout << number << " ";
    }


    // 4. inserter()
    //    Insert selected elements at a specific position

    vector<int> data = {10, 20, 50, 60};

    auto position = data.begin() + 2;

    vector<int> valuesToInsert = {30, 40};

    copy(valuesToInsert.begin(),valuesToInsert.end(),
        inserter(data, position)
    );

    cout << "\nAfter inserter: ";

    for (const auto& value : data)
    {
        cout << value << " ";
    }


    // 5. copy_if() + inserter()
    //    Insert selected values at a position

    vector<int> source = {
        5, 10, 15, 20, 25, 30
    };

    vector<int> destination = {
        100, 200, 500, 600
    };

    auto insertPosition = destination.begin() + 2;

    copy_if(
        source.begin(),
        source.end(),
        inserter(destination, insertPosition),
        [](int number)
        {
            return number >= 15 && number <= 25;
        }
    );

    cout << "\ncopy_if + inserter: ";

    for (const auto& number : destination)
    {
        cout << number << " ";
    }


    return 0;
}