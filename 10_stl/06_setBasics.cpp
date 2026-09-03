#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> rollNumbers = {40,37,27,27,11,11,94};
    rollNumbers.insert(11);
    rollNumbers.insert(82);

    cout<<"Roll numbers : ";
    for(const auto& roll : rollNumbers){
        cout<<roll<<" ";
    }
    cout<<"\nSize : "<<rollNumbers.size();
    int num;
    cout<<"\nEnter the number you want to find : ";
    cin>>num;
    if(rollNumbers.find(num) != rollNumbers.end()){
        cout<<"Number found";
    }else{
        cout<<"Nothing found";
    }
    return 0;
}