#include <iostream>
#include <set>

using namespace std;

int main(){
    multiset<int> marks = { 45, 67,32,88,88,21};
    marks.insert(16);

    cout<<"Marks : ";
    for(const auto& indMarks : marks){
        cout<<indMarks<<" ";
    }
    cout<<"\nNos of 88s : "<<marks.count(88);
    
    auto it = marks.find(88);

    if (it != marks.end())
    {
        marks.erase(it);
    }
    cout << "\nAfter removing one 88: ";
    for (const auto& mark : marks)
    {
        cout << mark << " ";
    }

  return 0;
}