#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> numbers = {40,25,35,11};
    numbers.push_back(30);
    numbers.push_front(50);

    cout<<"List : ";
    for (const auto& number : numbers){
        cout<<number<<" ";
    }
    //remove first and last element
    numbers.pop_front();
    numbers.pop_back();

    //remove a specific value
    numbers.remove(35);

    //sort
    numbers.sort();

    cout<<"\nAfter operations : ";
    for(const auto& number : numbers){
        cout<<number<<" ";
    }

    return 0;

}