#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

int main()
{
    // 1. Sum of numbers

    vector<int> numbers = {10, 20, 30, 40, 50};

    int sum = accumulate(
        numbers.begin(),
        numbers.end(),
        0
    );

    cout << "Sum: " << sum << endl;


    // 2. Product of numbers

    vector<int> values = {2, 3, 4, 5};

    int product = accumulate(
        values.begin(),
        values.end(),
        1,
        [](int result, int number)
        {
            return result * number;
        }
    );

    cout << "Product: " << product << endl;


    // 3. Custom operation - subtract

    int result = accumulate(
        numbers.begin(),
        numbers.end(),
        100,
        [](int result, int number)
        {
            return result - number;
        }
    );

    cout << "Subtraction result: " << result << endl;


    // 4. String concatenation

    vector<string> words = {
        "C++", "is", "powerful"
    };

    string sentence = accumulate(
        words.begin(),
        words.end(),
        string(""),
        [](string result, const string& word)
        {
            if (!result.empty())
            {
                result += " ";
            }

            result += word;

            return result;
        }
    );

    cout << "Sentence: " << sentence << endl;


    return 0;
}