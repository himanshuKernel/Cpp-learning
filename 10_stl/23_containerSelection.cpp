#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
    // 1. VECTOR
    vector<int> numbers = {10, 20, 30};

    cout << "Vector: ";
    for (const auto& number : numbers)
        cout << number << " ";

    cout << "\nIndex access: " << numbers[1];


    // 2. DEQUE
    deque<int> dq = {20, 30};

    dq.push_front(10);
    dq.push_back(40);

    cout << "\n\nDeque: ";
    for (const auto& number : dq)
        cout << number << " ";


    // 3. LIST
    list<int> values = {10, 20, 30};

    values.push_front(5);
    values.push_back(40);

    cout << "\n\nList: ";
    for (const auto& value : values)
        cout << value << " ";


    // 4. SET
    set<int> uniqueSorted = {
        40, 10, 20, 20, 30
    };

    cout << "\n\nSet: ";
    for (const auto& number : uniqueSorted)
        cout << number << " ";


    // 5. MULTISET
    multiset<int> duplicateSorted = {
        40, 10, 20, 20, 30
    };

    cout << "\n\nMultiset: ";
    for (const auto& number : duplicateSorted)
        cout << number << " ";


    // 6. UNORDERED SET
    unordered_set<int> fastLookup = {
        10, 20, 30, 40
    };

    if (fastLookup.find(30) != fastLookup.end())
        cout << "\n\n30 found in unordered_set";


    // 7. MAP
    map<int, string> students;

    students[103] = "Aman";
    students[101] = "Himanshu";
    students[102] = "Rahul";

    cout << "\n\nMap:\n";
    for (const auto& [roll, name] : students)
        cout << roll << " -> " << name << endl;


    // 8. MULTIMAP
    multimap<int, string> multipleStudents;

    multipleStudents.insert({101, "Himanshu"});
    multipleStudents.insert({101, "Rahul"});
    multipleStudents.insert({102, "Aman"});

    cout << "\nMultimap:\n";
    for (const auto& [roll, name] : multipleStudents)
        cout << roll << " -> " << name << endl;


    // 9. UNORDERED MAP
    unordered_map<int, int> frequency;

    frequency[10]++;
    frequency[20]++;
    frequency[10]++;

    cout << "\nUnordered Map:\n";

    for (const auto& [number, count] : frequency)
        cout << number << " -> " << count << endl;


    return 0;
}