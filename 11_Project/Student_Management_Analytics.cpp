#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <tuple>
#include <utility>

using namespace std;

struct Student
{
    int id;
    string name;
    string department;
    int marks;
};

void displayStudent(const Student& student){
    cout << "\nID: " << student.id;
    cout << "\nName: " << student.name;
    cout << "\nDepartment: " << student.department;
    cout << "\nMarks: " << student.marks << endl;
}

void displayStudents(const vector<Student>& students){
    if (students.empty()){
        cout << "\nNo students found.";
        cout << "\nPlease use Option 1 to add a student first.\n";
        return;
    }

    cout << "\n--- All Students ---\n";

    for (const auto& student : students){
        displayStudent(student);
        cout << "-------------------\n";
    }
}

void addStudent(
    vector<Student>& students,
    unordered_map<int, Student>& studentData,
    unordered_set<int>& studentIDs,
    set<string>& departments,
    deque<string>& recentActivities,
    list<string>& activityHistory)
{
    Student student;

    cout << "\nEnter Student ID: ";
    cin >> student.id;

    if (studentIDs.count(student.id)){
        cout << "Student ID already exists.\n";
        return;
    }

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, student.name);

    cout << "Enter Department: ";
    getline(cin, student.department);

    cout << "Enter Marks: ";
    cin >> student.marks;

    if (student.marks < 0 || student.marks > 100){
        cout << "Marks must be between 0 and 100.\n";
        return;
    }

    students.push_back(student);
    studentData.insert({student.id, student});
    studentIDs.insert(student.id);
    departments.insert(student.department);

    string activity = "Student added: " + student.name;

    recentActivities.push_back(activity);

    if (recentActivities.size() > 5)
        recentActivities.pop_front();

    activityHistory.push_back(activity);

    cout << "\nStudent added successfully.\n";
}

void searchStudent(const unordered_map<int, Student>& studentData){
    // If no student has been added yet, tell the user what to do.
    if (studentData.empty()){
        cout << "\nNo students found.";
        cout << "\nPlease use Option 1 to add a student first.\n";
        return;
    }

    int id;

    cout << "\nEnter Student ID: ";
    cin >> id;

    auto it = studentData.find(id);

    if (it != studentData.end()){
        cout << "\nStudent Found:";
        displayStudent(it->second);
    }
    else{
        cout << "\nStudent not found.\n";
    }
}

void updateMarks(vector<Student>& students,unordered_map<int, Student>& studentData){
    // If no student exists, there is nothing to update.
    if (studentData.empty()){
        cout << "\nNo students found.";
        cout << "\nPlease use Option 1 to add a student first.\n";
        return;
    }

    int id;
    int newMarks;

    cout << "\nEnter Student ID: ";
    cin >> id;

    auto it = studentData.find(id);

    if (it == studentData.end()){
        cout << "Student not found.\n";
        return;
    }

    cout << "Enter new marks: ";
    cin >> newMarks;

    if (newMarks < 0 || newMarks > 100){
        cout << "Marks must be between 0 and 100.\n";
        return;
    }

    it->second.marks = newMarks;

    for (auto& student : students){
        if (student.id == id){
            student.marks = newMarks;
            break;
        }
    }

    cout << "\nMarks updated successfully.\n";
}

void deleteStudent(
    vector<Student>& students,
    unordered_map<int, Student>& studentData,
    unordered_set<int>& studentIDs)
{
    // If no student exists, there is nothing to delete.
    if (studentData.empty()){
        cout << "\nNo students found.";
        cout << "\nPlease use Option 1 to add a student first.\n";
        return;
    }

    int id;

    cout << "\nEnter Student ID: ";
    cin >> id;

    if (!studentIDs.count(id)){
        cout << "Student not found.\n";
        return;
    }

    students.erase(remove_if(students.begin(),students.end(),[id](const Student& student){
                return student.id == id;}), students.end());

    studentData.erase(id);
    studentIDs.erase(id);

    cout << "\nStudent deleted successfully.\n";
}

void showRanking(const vector<Student>& students){
    if (students.empty()){
        cout << "\nNo students available.";
        cout << "\nPlease use Option 1 to add a student first.\n";
        return;
    }

    vector<pair<int, int>> ranking;

    for (const auto& student : students)
        ranking.push_back({student.id, student.marks});


    sort(ranking.begin(),ranking.end(),[](const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        }
    );

    cout << "\n--- Student Ranking ---\n";

    for (int i = 0; i < ranking.size(); i++)
       cout << i + 1 << ". ID: " << ranking[i].first << " | Marks: " << ranking[i].second << endl;
    
}

void resultSummary(const vector<Student>& students){
    if (students.empty()){
        cout << "\nNo students available.";
        cout << "\nPlease use Option 1 to add a student first.\n";
        return;
    }

    int totalMarks = accumulate(students.begin(),students.end(),0,
        [](int total, const Student& student){
            return total + student.marks;
        }
    );

    int passed = count_if(students.begin(),students.end(),[](const Student& student){
            return student.marks >= 40;
        }
    );

    int failed = students.size() - passed;

    double average =
        static_cast<double>(totalMarks) / students.size();

    tuple<int, int, double> summary(passed, failed, average);

    cout << "\n--- Result Summary ---\n";
    cout << "Passed: " << get<0>(summary) << endl;
    cout << "Failed: " << get<1>(summary) << endl;
    cout << "Average Marks: " << get<2>(summary) << endl;
}

void departmentAnalytics(const vector<Student>& students){
    // If there are no students, department analytics cannot be shown.
    if (students.empty()){
        cout << "\nNo students available.";
        cout << "\nPlease use Option 1 to add a student first.\n";
        return;
    }

    map<string, int> departmentCount;

    for (const auto& student : students)
        departmentCount[student.department]++;
    

    cout << "\n--- Department Analytics ---\n";

    for (const auto& department : departmentCount)
        cout << department.first<< " -> " << department.second << " students\n";
    
}

void showRecentActivities(const deque<string>& recentActivities){
    cout << "\n--- Recent Activities ---\n";

    if (recentActivities.empty()){
        cout << "No recent activities.";
        cout << "\nPlease use Option 1 to add a student first.\n";
        return;
    }

    for (const auto& activity : recentActivities)
        cout << "- " << activity << endl;

}

void showActivityHistory(const list<string>& activityHistory){
    cout << "\n--- Activity History ---\n";

    if (activityHistory.empty()){
        cout << "No activity history.";
        cout << "\nPlease use Option 1 to add a student first.\n";
        return;
    }

    for (const auto& activity : activityHistory)
        cout << "- " << activity << endl;
    
}

void showDepartments(const set<string>& departments){
    cout << "\n--- Departments ---\n";

    if (departments.empty()){
        cout << "No departments available.";
        cout << "\nPlease use Option 1 to add a student first.\n";
        return;
    }

    for (const auto& department : departments)
        cout << department << endl;
    
}

int main(){
    vector<Student> students;

    unordered_map<int, Student> studentData;
    unordered_set<int> studentIDs;

    set<string> departments;

    deque<string> recentActivities;
    list<string> activityHistory;

    int choice;

    // This message helps a first-time user understand where to start.
    cout << "============================================\n";
    cout << "       STUDENT MANAGEMENT SYSTEM\n";
    cout << "============================================\n";
    cout << "No students are added initially.\n";
    cout << "Please select Option 1 to add a student first.\n";
    cout << "After that, you can use the other options.\n";
    cout << "============================================\n";

    do{
        cout << "\n========== STUDENT MANAGEMENT ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Marks\n";
        cout << "5. Delete Student\n";
        cout << "6. Show Ranking\n";
        cout << "7. Result Summary\n";
        cout << "8. Department Analytics\n";
        cout << "9. Recent Activities\n";
        cout << "10. Activity History\n";
        cout << "11. Show Departments\n";
        cout << "0. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                addStudent(
                    students,
                    studentData,
                    studentIDs,
                    departments,
                    recentActivities,
                    activityHistory
                );
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                searchStudent(studentData);
                break;

            case 4:
                updateMarks(students, studentData);
                break;

            case 5:
                deleteStudent(
                    students,
                    studentData,
                    studentIDs
                );
                break;

            case 6:
                showRanking(students);
                break;

            case 7:
                resultSummary(students);
                break;

            case 8:
                departmentAnalytics(students);
                break;

            case 9:
                showRecentActivities(recentActivities);
                break;

            case 10:
                showActivityHistory(activityHistory);
                break;

            case 11:
                showDepartments(departments);
                break;

            case 0:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}

