#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    // 1. BASIC ITERATOR

    vector<int> numbers = { 10, 20, 30, 40, 50};

    auto it = numbers.begin();

    cout << "1. First element: " << *it << endl;


    // 2. MOVING ITERATOR USING ++

    ++it;

    cout << "2. After ++it: " << *it << endl;


    // 3. TRAVERSING USING ITERATOR

    cout << "3. Traversing: ";

    for (auto current = numbers.begin();current != numbers.end(); ++current)
        cout << *current << " ";
    
    cout << endl;
    


    // 4. MODIFYING ELEMENT THROUGH ITERATOR

    auto modifyIt = numbers.begin();
    *modifyIt = 100;

    cout << "4. After modification: ";

    for (const auto& number : numbers)
        cout << number << " ";

    cout << endl;


    // 5. RANDOM ACCESS ITERATOR

    auto position = numbers.begin();
    position = position + 2;

    cout << "5. Element after iterator + 2: "<< *position << endl;


    // 6. RANDOM ACCESS - MOVING BACKWARD

    position = numbers.end();

    --position;

    cout << "6. Last element using --: "<< *position << endl;


    // 7. cbegin() - CONST ITERATOR

    auto constIt = numbers.cbegin();

    cout << "7. First element using cbegin(): "<< *constIt << endl;

    // *constIt = 500;
    // ERROR: cbegin() gives a const iterator.


    // 8. advance()

    list<int> values = {10, 20, 30, 40, 50};

    auto listIt = values.begin();

    advance(listIt, 3);

    cout << "8. List element after advance(3): " << *listIt << endl;


    // 9. distance()

    auto first = numbers.begin();
    auto last = numbers.end();

    cout << "9. Number of elements: "<< distance(first, last) << endl;


    // 10. STL ALGORITHM + ITERATOR RANGE

    sort(numbers.begin(), numbers.end());

    cout << "10. After sort(): ";

    for (const auto& number : numbers)
        cout << number << " ";

    cout << endl;


    // 11. FIND USING ITERATOR

    auto findIt = find(numbers.begin(),numbers.end(), 30);

    if (findIt != numbers.end())
    {
        cout << "11. 30 found using iterator" << endl;
        cout << "    Value: " << *findIt << endl;
    }


    // 12. ITERATOR CATEGORY - VECTOR
    //     Random Access Iterator

    vector<int>::iterator vectorIt = numbers.begin();

    vectorIt = vectorIt + 2;

    cout << "12. Vector iterator + 2: "
         << *vectorIt << endl;


    // 13. ITERATOR CATEGORY - LIST
    //     Bidirectional Iterator

    list<int>::iterator anotherListIt = values.begin();

    ++anotherListIt;
    ++anotherListIt;

    cout << "13. List iterator after two ++: "
         << *anotherListIt << endl;

    --anotherListIt;

    cout << "    After --: "
         << *anotherListIt << endl;


    // 14. SET ITERATOR
    //     Bidirectional Iterator

    set<int> uniqueNumbers = {10, 20, 30, 40};

    auto setIt = uniqueNumbers.begin();

    cout << "14. Set first element: " << *setIt << endl;

    ++setIt;

    cout << "    After ++: "<< *setIt << endl;


    // 15. MAP ITERATOR
    //     Access using ->first and ->second

    map<int, string> students = {{101, "Himanshu"},{102, "Dhananjay"},{103, "Vansh"}};

    auto mapIt = students.begin();

    cout << "15. Map first entry: "<< mapIt->first<< " -> "<< mapIt->second << endl;


    // 16. ITERATOR + FIND

    auto studentIt = students.find(102);

    if (studentIt != students.end())
        cout << "16. Student found: " << studentIt->first << " -> " << studentIt->second << endl;
    


    return 0;
}