#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, string> students;

    // Insert using []
    students[101] = "Himanshu";
    students[102] = "Vansh";
    students[103] = "Dhananjay";

    // Insert using insert()
    students.insert({104, "Roushan"});

    // Insert using emplace()
    students.emplace(105, "Sumit");

    cout << "Students:\n";

    for (const auto& student : students)
        cout << student.first << " -> " << student.second << endl;
    
        // Find
    if (students.find(103) != students.end())
        cout << "\n103 found";
    

    // Count
    cout << "\nCount of key 102: "<< students.count(102);

    // Access
    cout << "\nStudent 101: "<< students.at(101);

    // Erase
    students.erase(104);

    cout << "\n\nAfter erasing 104:\n";

    for (const auto& student : students)
        cout << student.first << " -> "
             << student.second << endl;
    

    cout << "\nSize: " << students.size();

    return 0;
}