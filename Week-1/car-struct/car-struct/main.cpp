#include <iostream>
#include <string>
using namespace std;

struct Car {
    //all members are public by default
    int year;
    string brand;
    double price;
};

int main() {
    Car carInventory[100];

    //add car 1
    carInventory[0].year = 2002;
    carInventory[0].brand = "Honda";
    carInventory[0].price = 1000.00;

    //add car 2
    carInventory[1].year = 1984;
    carInventory[1].brand = "Porsche";
    carInventory[1].price = 40000.00;

    //print all
    cout<<"The first car is: " << carInventory[0].year << " " << carInventory[0].brand << ", price: " << carInventory[0].price<< endl;
    cout<<"The second car is: " << carInventory[1].year << " " << carInventory[1].brand << ", price: " << carInventory[1].price<< endl;

    return 0;
}
