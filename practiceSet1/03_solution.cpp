#include <iostream>
#include <string>

using namespace std;
int main(){
    string tea;
    cout <<"Enter your Favorite Tea : ";
    getline(cin,tea);
    
    int cups;
    cout <<"How many cups do you want : ";
    cin >>cups;

    cout <<"\nYou love "<<tea<<"! Enjoy your "<<cups<<" cups of tea!";




    return 0;
}