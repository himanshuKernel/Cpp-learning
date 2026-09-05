#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    int marks;
};

int main()
{
    // 1. Create students

    vector<Student> students = {
        {"Himanshu", 85},
        {"Rahul", 92},
        {"Aman", 78},
        {"Rohan", 88},
        {"Karan", 95}
    };

    cout << "Original Students:\n";

    for (const auto& student : students)
    {
        cout << student.name << " -> "
             << student.marks << endl;
    }


    // 2. Sort by marks

    sort(
        students.begin(),
        students.end(),
        [](const Student& a, const Student& b)
        {
            return a.marks < b.marks;
        }
    );

    cout << "\nSorted by marks:\n";

    for (const auto& student : students)
    {
        cout << student.name << " -> "
             << student.marks << endl;
    }


    // 3. Find first student with marks > 90

    auto foundStudent = find_if(
        students.begin(),
        students.end(),
        [](const Student& student)
        {
            return student.marks > 90;
        }
    );

    if (foundStudent != students.end())
    {
        cout << "\nFirst student above 90: "
             << foundStudent->name << endl;
    }


    // 4. Count students with marks >= 80

    int count = count_if(
        students.begin(),
        students.end(),
        [](const Student& student)
        {
            return student.marks >= 80;
        }
    );

    cout << "Students with marks >= 80: "
         << count << endl;


    // 5. Add 5 marks to everyone

    for_each(
        students.begin(),
        students.end(),
        [](Student& student)
        {
            student.marks += 5;
        }
    );

    cout << "\nAfter adding 5 marks:\n";

    for (const auto& student : students)
    {
        cout << student.name << " -> "
             << student.marks << endl;
    }


    // 6. Create vector containing only marks

    vector<int> marks;

    transform(
        students.begin(),
        students.end(),
        back_inserter(marks),
        [](const Student& student)
        {
            return student.marks;
        }
    );

    cout << "\nMarks vector:\n";

    for (const auto& mark : marks)
    {
        cout << mark << " ";
    }


    // 7. Lowest and highest marks

    auto minStudent = min_element(
        students.begin(),
        students.end(),
        [](const Student& a, const Student& b)
        {
            return a.marks < b.marks;
        }
    );

    auto maxStudent = max_element(
        students.begin(),
        students.end(),
        [](const Student& a, const Student& b)
        {
            return a.marks < b.marks;
        }
    );

    cout << "\n\nLowest marks: "
         << minStudent->name << " -> "
         << minStudent->marks << endl;

    cout << "Highest marks: "
         << maxStudent->name << " -> "
         << maxStudent->marks << endl;


    // 8. Calculate total marks

    int totalMarks = accumulate(
        students.begin(),
        students.end(),
        0,
        [](int total, const Student& student)
        {
            return total + student.marks;
        }
    );

    cout << "\nTotal marks: "
         << totalMarks << endl;


    // 9. Remove students with marks < 85

    students.erase(
        remove_if(
            students.begin(),
            students.end(),
            [](const Student& student)
            {
                return student.marks < 85;
            }
        ),
        students.end()
    );

    cout << "\nAfter removing students with marks < 85:\n";

    for (const auto& student : students)
    {
        cout << student.name << " -> "
             << student.marks << endl;
    }


    // 10. Partition: marks >= 90 first

    auto middle = partition(
        students.begin(),
        students.end(),
        [](const Student& student)
        {
            return student.marks >= 90;
        }
    );

    cout << "\nAfter partition (90+ first):\n";

    for (const auto& student : students)
    {
        cout << student.name << " -> "
             << student.marks << endl;
    }


    // 11. Map: roll number -> Student

    map<int, Student> studentMap;

    studentMap[101] = {"Himanshu", 90};
    studentMap[102] = {"Rahul", 97};
    studentMap[103] = {"Aman", 83};

    cout << "\nStudent Map:\n";

    for (const auto& [rollNumber, student] : studentMap)
    {
        cout << rollNumber << " -> "
             << student.name << " -> "
             << student.marks << endl;
    }

    return 0;
}