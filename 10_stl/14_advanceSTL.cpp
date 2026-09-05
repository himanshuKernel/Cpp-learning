#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    vector<int> numbers = {10,20,20,20,30,40};

    //lower bound 
    auto lower = lower_bound(numbers.begin(),numbers.end(),20);
    cout<<"Lower bound(20) : "<<*lower<<endl;

    //upper bound 
    auto upper = upper_bound(numbers.begin(),numbers.end(),30);
    cout<<"Upper bound(30) : "<<*upper<<endl;

    //equal range
    auto range = equal_range(numbers.begin(),numbers.end(),20);
    for(auto it = range.first; it != range.second;it++)
        cout<<*it<<" "<<endl;
    
    //all_of()
    vector<int> evenNumbers = { 2, 4, 6, 8};
    bool allEven = all_of(evenNumbers.begin(),evenNumbers.end(),[](int number){
        return number % 2 == 0;
    });
    cout << "\nAll numbers even: " <<boolalpha << allEven;
    
    //any_of()
    vector<int> mixedNumbers = {1,3, 5, 8};
    bool anyEven = any_of(mixedNumbers.begin(),mixedNumbers.end(),[](int number){
        return number % 2 == 0;
    });
    cout<<"\nAny number even : "<<anyEven;

    //none_of()
    vector<int> oddNumbers = {1, 3, 5, 7};
    bool noneEven = none_of(oddNumbers.begin(),oddNumbers.end(),[](int number){
        return number % 2 == 0;
    });
    cout<<"\nNone of number even : "<<noneEven;
    return 0;
}