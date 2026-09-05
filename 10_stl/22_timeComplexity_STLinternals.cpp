#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <deque>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    // 1. VECTOR
    vector<int> numbers = {10, 20, 30, 40, 50};

    cout << "Vector: ";
    for (const auto& number : numbers)
        cout << number << " ";

    cout << "\nVector access: " << numbers[2]; // O(1)
    cout << "\nVector size: " << numbers.size();
    cout << "\nVector capacity: " << numbers.capacity();


    // 2. DEQUE
    cout << "\n\nDeque:";

    deque<int> dq = {20, 30, 40};

    dq.push_front(10); // O(1)
    dq.push_back(50);  // O(1)

    cout << "\nFront: " << dq.front();
    cout << "\nBack: " << dq.back();


    // 3. LIST
    cout << "\n\nList:";

    list<int> values = {10, 20, 30, 40};

    values.push_front(5); // O(1)
    values.push_back(50); // O(1)

    cout << "\nList: ";

    for (const auto& value : values)
        cout << value << " ";


    // 4. SET
    cout << "\n\nSet:";

    set<int> uniqueNumbers = {40, 10, 30, 20, 20};

    uniqueNumbers.insert(50); // O(log n)

    cout << "\nSet: ";

    for (const auto& number : uniqueNumbers)
        cout << number << " ";

    if (uniqueNumbers.find(30) != uniqueNumbers.end())
        cout << "\n30 found"; // O(log n)


    // 5. MAP
    cout << "\n\nMap:";

    map<int, string> students;

    students[101] = "Himanshu";
    students[102] = "Rahul";
    students[103] = "Aman";

    cout << "\nStudents:\n";

    for (const auto& [roll, name] : students)
        cout << roll << " -> " << name << endl;


    // 6. UNORDERED_SET
    cout << "\nUnordered Set:";

    unordered_set<int> numbersSet = {
        10, 20, 30, 40, 50
    };

    if (numbersSet.find(30) != numbersSet.end())
        cout << "\n30 found"; // Average O(1)


    // 7. UNORDERED_MAP
    cout << "\n\nUnordered Map:";

    unordered_map<int, string> studentMap;

    studentMap[101] = "Himanshu";
    studentMap[102] = "Rahul";
    studentMap[103] = "Aman";

    cout << "\nStudents:\n";

    for (const auto& [roll, name] : studentMap)
        cout << roll << " -> " << name << endl;


    // 8. SORT
    cout << "\nSorting:";

    vector<int> marks = {
        50, 20, 40, 10, 30
    };

    sort(marks.begin(), marks.end()); // O(n log n)

    cout << "\nSorted: ";

    for (const auto& mark : marks)
        cout << mark << " ";


    // 9. LINEAR SEARCH
    cout << "\n\nLinear Search:";

    auto it = find(
        marks.begin(),
        marks.end(),
        30
    ); // O(n)

    if (it != marks.end())
        cout << "\n30 found";


    // 10. COMPLEXITY EXAMPLES
    cout << "\n\nComplexity Examples:";

    // O(n)
    for (int i = 0; i < numbers.size(); i++)
    {
        // One loop
    }

    // O(n^2)
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < numbers.size(); j++)
        {
            // Nested loop
        }
    }

    // O(n log n)
    sort(numbers.begin(), numbers.end());

    cout << "\nO(1)      -> Vector indexing";
    cout << "\nO(log n)  -> Set/Map operations";
    cout << "\nO(n)      -> Linear search";
    cout << "\nO(n log n)-> Sorting";
    cout << "\nO(n^2)    -> Nested loops";


    // 11. SIZE VS CAPACITY
    cout << "\n\nSize vs Capacity:";

    vector<int> data;

    data.reserve(100);

    cout << "\nAfter reserve(100):";
    cout << "\nSize: " << data.size();
    cout << "\nCapacity: " << data.capacity();

    data.resize(5);

    cout << "\n\nAfter resize(5):";
    cout << "\nSize: " << data.size();
    cout << "\nCapacity: " << data.capacity();


    return 0;
}