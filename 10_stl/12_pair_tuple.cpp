#include <iostream>
#include <utility>   // pair, make_pair
#include <tuple>     // tuple, get, tie, ignore

using namespace std;


// FUNCTION 1: Return a pair


pair<int, string> getStudentBasicInfo()
{
    return {101, "Himanshu"};
}



// FUNCTION 2: Return a tuple


tuple<int, string, double, char> getStudentDetails()
{
       return {101, "Himanshu", 8.5, 'A'};
}


int main()
{
    // 1. PAIR - Basic
    pair<int, string> student = {101, "Himanshu"};

    cout << "===== PAIR =====\n";

    cout << "Roll Number: "<< student.first << endl;

    cout << "Name: "<< student.second << endl;



    // 2. Changing pair values
    student.first = 102;
    student.second = "Rahul";

    cout << "\nAfter changing pair:\n";

    cout << student.first << " -> "<< student.second << endl;



    // 3. make_pair()
    auto product = make_pair( "Laptop", 75000);

    cout << "\n===== MAKE_PAIR =====\n";

    cout << "Product: "<< product.first << endl;

    cout << "Price: "<< product.second << endl;



    // 4. Pair with different data types
    pair<string, double> result = {"CGPA",8.5};

    cout << "\n===== DIFFERENT DATA TYPES =====\n";

    cout << result.first << ": "<< result.second << endl;



    // 5. Pair returned from function
    pair<int, string> basicInfo = getStudentBasicInfo();

    cout << "\n===== PAIR FROM FUNCTION =====\n";

    cout << basicInfo.first << " -> "<< basicInfo.second << endl;



     // 6. Structured Binding with pair
     //    C++17 feature


     auto [rollNumber, name] = basicInfo;

    cout << "\n===== STRUCTURED BINDING =====\n";

    cout << "Roll Number: "<< rollNumber << endl;

    cout << "Name: "<< name << endl;



    // 7. TUPLE - Basic


    tuple<int, string, double> studentData = {101,"Himanshu",8.5};

    cout << "\n===== TUPLE =====\n";

    cout << "Roll Number: "<< get<0>(studentData) << endl;

    cout << "Name: "<< get<1>(studentData) << endl;

    cout << "CGPA: "<< get<2>(studentData) << endl;



    // 8. Changing tuple values


    get<2>(studentData) = 9.0;

    cout << "\nAfter changing CGPA: "<< get<2>(studentData) << endl;



    // 9. Tuple with more different data types


    tuple<int, string, double, char> details = {101,"Himanshu",9.0,'A'};

    cout << "\n===== TUPLE WITH 4 VALUES =====\n";

    cout << "ID: "<< get<0>(details) << endl;

    cout << "Name: " << get<1>(details) << endl;

    cout << "CGPA: " << get<2>(details) << endl;

    cout << "Grade: "<< get<3>(details) << endl;



    // 10. make_tuple()


    auto employee = make_tuple(
        501,
        "Aman",
        45000.0
    );

    cout << "\n===== MAKE_TUPLE =====\n";

    cout << "ID: "<< get<0>(employee) << endl;

    cout << "Name: "<< get<1>(employee) << endl;

    cout << "Salary: "<< get<2>(employee) << endl;



    // 11. tie()
    //     Existing variables mein tuple unpack karna


    int id;
    string studentName;
    double cgpa;
    char grade;

    tie(id, studentName, cgpa, grade) = details;

    cout << "\n===== TIE =====\n";

    cout << "ID: " << id << endl;
    cout << "Name: " << studentName << endl;
    cout << "CGPA: " << cgpa << endl;
    cout << "Grade: " << grade << endl;



    // 12. tie() + ignore
    //     Kisi value ko skip karna


    int newId;
    double newCgpa;

    tie(newId, ignore, newCgpa, ignore) = details;

    cout << "\n===== TIE + IGNORE =====\n";

    cout << "ID: "<< newId << endl;

    cout << "CGPA: "<< newCgpa << endl;



     // 13. Structured Binding with tuple


    auto [id2, name2, cgpa2, grade2] = details;

    cout << "\n===== STRUCTURED BINDING + TUPLE =====\n";

    cout << "ID: " << id2 << endl;
    cout << "Name: " << name2 << endl;
    cout << "CGPA: " << cgpa2 << endl;
    cout << "Grade: " << grade2 << endl;



    // 14. Tuple returned from function


    auto studentDetails = getStudentDetails();

    cout << "\n===== TUPLE FROM FUNCTION =====\n";

    cout << "ID: "<< get<0>(studentDetails) << endl;

    cout << "Name: "<< get<1>(studentDetails) << endl;

    cout << "CGPA: "<< get<2>(studentDetails) << endl;
    cout<< "Grade: "<< get<3>(studentDetails) << endl;



     // 15. Best modern way:
     //     Function + Structured Binding


     auto [finalId, finalName, finalCgpa, finalGrade] = getStudentDetails();

    cout << "\n===== MODERN C++ STYLE =====\n";

    cout << "ID: " << finalId << endl;
    cout << "Name: " << finalName << endl;
    cout << "CGPA: " << finalCgpa << endl;
    cout << "Grade: " << finalGrade << endl;


    return 0;
}