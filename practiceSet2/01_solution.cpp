#include <iostream>

using namespace  std;
int main() {
    int teaPacks;
    cout <<"How many packs of tea you want? : ";
    cin >>teaPacks;
    double pricePerPack;
    cout <<"Tell the price per pack : ";
    cin >>pricePerPack;
    //calculate total price
    double totalPrice;
    totalPrice = teaPacks * pricePerPack;
    
    //calculate the total tax
    double tax = totalPrice * 0.10;
    
    //calculate final cost
    double finalCost = totalPrice + tax;

    //Display result
    cout << "Total price : "<<totalPrice <<endl;
    cout << "Total (10%) : "<<tax<< endl;
    cout << "Final price : "<<finalCost<<endl;

    

   return 0;
}