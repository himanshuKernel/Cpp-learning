#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    unordered_set<int> rollNumbers;

    rollNumbers.insert(105);
    rollNumbers.insert(102);
    rollNumbers.insert(101);
    rollNumbers.insert(105); // Duplicate, ignored
    rollNumbers.insert(103);

    cout << "Roll numbers: ";

    for (const auto& rollNumber : rollNumbers)
        cout << rollNumber << " ";

    cout << "\nSize: " << rollNumbers.size();

    if (rollNumbers.find(103) != rollNumbers.end())
        cout << "\n103 found";

    cout << "\nCount of 105: " << rollNumbers.count(105);

    rollNumbers.erase(102);

    cout << "\n\nAfter erasing 102: ";

    for (const auto& rollNumber : rollNumbers)
        cout << rollNumber << " ";

    return 0;
}