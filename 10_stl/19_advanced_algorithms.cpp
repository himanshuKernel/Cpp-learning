#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 1. lower_bound()

    vector<int> marks = {10, 20, 20, 20, 30, 40, 50};

    auto lower = lower_bound( marks.begin(),marks.end(),20);

    cout << "lower_bound(20): " << *lower << endl;


    // 2. upper_bound()

    auto upper = upper_bound(marks.begin(), marks.end(), 20);

    cout << "upper_bound(20): "<< *upper << endl;


    // 3. equal_range()

    auto range = equal_range(marks.begin(),marks.end(), 20);

    cout << "equal_range(20): ";

    for (auto it = range.first;it != range.second; ++it)
        cout << *it << " ";
    

    cout << endl;


    // 4. all_of()

    vector<int> numbers = { 10, 20, 30, 40, 50};

    bool allPositive = all_of(numbers.begin(), numbers.end(),[](int number){
            return number > 0;
        }
    );

    cout << "All numbers positive: "<< boolalpha << allPositive << endl;


    // 5. any_of()

    bool hasEvenNumber = any_of(numbers.begin(),numbers.end(), [](int number){
            return number % 2 == 0;
        }
    );

    cout << "At least one even number: "<< hasEvenNumber << endl;


    // 6. none_of()

    bool noNegative = none_of(numbers.begin(), numbers.end(), [](int number){
            return number < 0;
        }
    );

    cout << "No negative numbers: " << noNegative << endl;


    return 0;
}