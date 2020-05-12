#include <iostream>
#include <string>
using namespace std;

struct Car {
    //all members are public by default
    int year;
    string brand;
    double price;
};

class CarRecord {
    //all members are private by default
    Car carInventory[100];
    int size = 0;

public:
    void addCar (int year, string brand, double price);
    void printAll ();
};

void CarRecord::addCar(int year, string brand, double price) {
    carInventory[size].year = year;
    carInventory[size].brand = brand;
    carInventory[size].price = price;
    size++;
}

void CarRecord::printAll() {
    for (int i = 0; i < size; i++){
        cout<<"Car #" << i << ": " << carInventory[i].year << " " << carInventory[i].brand << ", price: " << carInventory[i].price<< endl;
    }
}



int main() {
    CarRecord inventory;

    //add car 1
    inventory.addCar(2002, "Honda", 1000.00);

    //add car 2
    inventory.addCar(1984, "Porsche", 40000.00);

    //print all
    inventory.printAll();

    return 0;
}
