#include <iostream>
#include <map>

using namespace std;
int main(){
    multimap<int,string> students;
    students.insert({101,"Himanshu"});
    students.insert({102,"Vansh"});
    students.insert({104,"Dhananjay"});
    students.emplace(101,"Roushan");

    cout<<"Students : "<<endl;
    for(const auto& student : students)
        cout<<student.first<<"->"<<student.second<<endl;
    
    cout<<"\nNos of students with key 101 : "<<students.count(101);
    cout<<"\nValues for key 101 : "<<endl;
    auto range = students.equal_range(101);
    for(auto it= range.first; it != range.second;++it)
        cout<<it->second<<endl;

    return 0;
}