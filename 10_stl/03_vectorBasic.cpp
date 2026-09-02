#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
   vector<int> numbers = {50,40,30,70,90};
   //add element to last
   numbers.push_back(95);

   //display vector
   cout<<"Vector : ";
   for(const auto& number : numbers){
    cout<<number<< " ";
   }

   cout<< "\nSize : "<<numbers.size();

   //first and last element
   cout<<"\nFirst element : "<<numbers.front();
   cout<<"\nLast element : "<<numbers.back();

   //Short in Decending 
   sort(numbers.begin(),numbers.end(),greater<int>());

   cout<<"\nDecending order : ";
   for(const auto& number : numbers){
      cout<<number<<" ";
   }

   //remove last element
   numbers.pop_back();
   cout<<"\nAfter pop back : ";
   for(const auto& number : numbers){
      cout<<number<<" ";
   }

   return 0;
}