#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 1. Basic for_each() - Print every element

    vector<int> numbers = {10, 20, 30, 40, 50 };

    cout << "Numbers: ";

    for_each( numbers.begin(), numbers.end(), [](int number) {
            cout << number << " ";
        }
    );


    // 2. for_each() - Print only even numbers

    cout << "\nEven numbers: ";

    for_each( numbers.begin(),numbers.end(),[](int number) {
            if (number % 2 == 0)
            {
                cout << number << " ";
            }
        }
    );


    // 3. for_each() - Modify original elements
    //    Reference is required

    for_each( numbers.begin(), numbers.end(), [](int& number)
        {
            number = number * 2;
        }
    );

    cout << "\nAfter doubling: ";

    for (const auto& number : numbers)
        cout << number << " ";
    


    // 4. for_each() - Using captured variable

    int addition = 5;

    for_each(numbers.begin(), numbers.end(), [addition](int& number) {
            number = number + addition;
        }
    );

    cout << "\nAfter adding 5: ";

    for (const auto& number : numbers)
       cout << number << " ";
    


    // 5. for_each() with reference capture

    int count = 0;

    for_each(numbers.begin(),numbers.end(),[&count](int number){
            if (number > 20)
            {
                count++;
            }
        }
    );

    cout << "\nNumbers greater than 20: " << count;


    return 0;
}