#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<string> customers = {"C001","C002","C003"};

    customers.push_front("C004");
    customers.push_back("C005");

    cout<<"Customers : ";
    for(const auto& customer : customers){
       cout<<customer<<" ";
    }

    cout<<"\nFirst customer : "<<customers.front();
    cout<<"\nLast customer : "<<customers.back();

    customers.pop_front();
    customers.pop_back();

    cout<<"\nAfter removing from both side : ";
    for(const auto& customer : customers){
        cout<<customer<<" ";
    }
    return 0;
}

