#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 1. Basic Lambda

    auto greet = []()
    {
        cout << "Hello from Lambda!" << endl;
    };

    greet();


    // 2. Lambda with parameter

    auto square = [](int number)
    {
        return number * number;
    };

    cout << "\nSquare: "
         << square(5) << endl;


    // 3. Lambda with multiple parameters

    auto add = [](int a, int b)
    {
        return a + b;
    };

    cout << "Sum: "
         << add(10, 20) << endl;


    // 4. Lambda with vector + for_each

    vector<int> numbers = {
        10, 20, 30, 40, 50
    };

    cout << "\nNumbers: ";

    for_each(
        numbers.begin(),
        numbers.end(),
        [](int number)
        {
            cout << number << " ";
        }
    );


    // 5. Lambda as condition

    cout << "\nEven numbers: ";

    for_each(
        numbers.begin(),
        numbers.end(),
        [](int number)
        {
            if (number % 2 == 0)
            {
                cout << number << " ";
            }
        }
    );


    // 6. Capture by value [x]

    int multiplier = 5;

    auto multiply = [multiplier](int number)
    {
        return number * multiplier;
    };

    cout << "\n\nMultiply using captured value: "
         << multiply(10) << endl;


    // 7. Capture by reference [&x]

    int value = 10;

    auto changeValue = [&value]()
    {
        value = 100;
    };

    changeValue();

    cout << "Value after reference capture: "
         << value << endl;


    // 8. Capture all by value [=]

    int a = 10;
    int b = 20;

    auto sum = [=]()
    {
        return a + b;
    };

    cout << "\nSum using [=]: "
         << sum() << endl;


    // 9. Capture all by reference [&]

    int x = 10;
    int y = 20;

    auto changeValues = [&]()
    {
        x = 100;
        y = 200;
    };

    changeValues();

    cout << "x after [&]: " << x << endl;
    cout << "y after [&]: " << y << endl;


    // 10. Lambda with all_of

    vector<int> evenNumbers = {
        2, 4, 6, 8
    };

    bool allEven = all_of(
        evenNumbers.begin(),
        evenNumbers.end(),
        [](int number)
        {
            return number % 2 == 0;
        }
    );

    cout << "\nAll numbers even: "
         << boolalpha << allEven << endl;


    // 11. Lambda with any_of

    vector<int> mixedNumbers = {
        1, 3, 5, 8
    };

    bool anyEven = any_of(
        mixedNumbers.begin(),
        mixedNumbers.end(),
        [](int number)
        {
            return number % 2 == 0;
        }
    );

    cout << "Any number even: "
         << anyEven << endl;


    // 12. Lambda with none_of

    vector<int> oddNumbers = {
        1, 3, 5, 7
    };

    bool noneEven = none_of(
        oddNumbers.begin(),
        oddNumbers.end(),
        [](int number)
        {
            return number % 2 == 0;
        }
    );

    cout << "No number even: "
         << noneEven << endl;


    // 13. Lambda with sort

    vector<int> values = {
        50, 20, 40, 10, 30
    };

    sort(
        values.begin(),
        values.end(),
        [](int a, int b)
        {
            return a > b;
        }
    );

    cout << "\nDescending order: ";

    for (const auto& number : values)
    {
        cout << number << " ";
    }


    // 14. Immediate Lambda Execution

    int result = [](int number)
    {
        return number * 2;
    }(10);

    cout << "\n\nImmediate Lambda Result: "
         << result << endl;


    return 0;
}