#include <iostream>
using namespace std;

int main(){
    int stock = 5,tea;  //(green + oolong) in stock
    cout <<"Enter tea type(1 = Green, 2 = Black, 4 = Oolong) : ";
    cin >> tea;

    if(tea !=1 && tea != 2 && tea !=4){
        cout <<"Invalid tea type";
    }
    else if (stock & tea){
        cout <<"Tea is available";
    }else {
        cout<< "Tea is not available";
    }
    
    return 0;
}