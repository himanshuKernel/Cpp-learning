#include <iostream>

using namespace std;
int main(){
    float price;
    cout <<"Enter the base price of the tea : ";
    cin >>price;
    float newPrice;
    newPrice = price * 1.10;
    int roundedTeaPrice = (int)(newPrice + 0.5);
    cout <<"The new price of the tea after 10% increase is : "<<roundedTeaPrice;

    return 0;
}