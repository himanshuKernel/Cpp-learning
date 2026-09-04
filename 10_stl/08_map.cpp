#include <iostream>
#include <map>

using namespace std;
int main(){
    map<int,string> students;
    students[101] = "Himanshu";
    students[102] = "Vansh";
    students[103] = "Dhananjay";

    cout<<"\nStudents  : ";
    for(const auto& student : students){
        cout<<"\n"<<student.first<<"->"<<student.second<<endl;
    
    }
    cout<<"\nStudent with roll 102 : "<<students[102]<<endl;

    if(students.find(101) != students.end())
        cout<<"Student found !";
    students.erase(103);
    cout<<"\nAfter removing roll 103 : "<<endl;
    for(const auto& student : students)
        cout<<"\n"<<student.first<<"->"<<student.second<<endl;
    
    students.insert({104,"Sumit"});
    students[105] = "Roushan";
    students.emplace(106,"Nihal");
    
    cout<<"\n"<<students[101]<<endl;
    cout<<students[105]<<endl;


    cout<<"\nStudents after adding more  : ";
    for(const auto& student : students)
        cout<<"\n"<<student.first<<"->"<<student.second<<endl;
    
     return 0 ;
}