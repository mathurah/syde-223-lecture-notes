# Lecture 1 - Week 1

**Algorithm**: Finite sequence of unambigious instructions performed to achieve a goal or compute a desired result. 

Each algorithm is not a solution, but instead a precisely defined **procedure** for deriving solutions. 

**Each algorithm should specify each of the following:**
- Name and purpose
- Input and output
- Unambigously specified finite sequence of steps
- Termination condition or terminating state

Write the code to return the sum of 1, 2, 3, ...n 

### For Loop Version
``` cpp
#include <iostream>
using namespace std;

int main() {
    int n =4; //can change the value of n here, define an integer
    int result = 0; //to store the result, initial value is zero
    
    
    for (int i=1; i<=n; i++){ //For each integer from 1 to n, add their values to result
        result = result +i;
    }
    return 0;

    cout << "The result is:" << result << endl; //Output the value of result
}
```

### Switch Case Version
``` cpp
#include <iostream>
int main() {
    int n = 4; 		// can change the value of n here.
    int result = 0; 	// to store the result, initial value is zero.
    // Unambiguously specified finite sequence of steps below

    switch (n){
        case 0: result = 0;
            break;
        case 1: result = 1;
            break;
        case 2: result = 3;
            break;
        case 3: result = 6;
            break;
        case 4: result = 10;
            break;
        default:
            std::cout<<"Error! I did not consider this yet. "<<std::endl;
            break;
    }

    std::cout<<"The result is: "<<result<<std::endl;
    return result;
}
```

### Math Equation Version
``` cpp
#include <iostream>
int main() {
    int n = 4; 		// can change the value of n here.
    int result = 0; 	// to store the result, initial value is zero.
    // Unambiguously specified finite sequence of steps below

    result = n * (n+1) / 2;

    std::cout<<"The result is: "<<result<<std::endl;
    return result;
}
```

**Data Structure**: A coherent organization of related data items for efficient storage and usage, and methods that operate on the data items. 

## Car Struct 
``` cpp
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
```

**What's the problem with procedure based programming?** - not well organized, data is not protected, okay for a small project in which you're the only user. 

Every other function can directly access and modify other variables in structures. 

## Procedure Oriented Programing
- All data items and structures are public
- A procedure using fucntions to process the data
- They may be accidentally affected
- Big problem when many programmers working on the same project

## Object Oriented Programming
- Allows a data structure's members to be private
- Methods(functions) that operate on these data items are includewd within the data structure
- Users of the data structure use the public methods to achieve their goals, without accidentally affecting the priate data items in any bad ways
- This is called **encapsulation**
```cpp
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
```

## Class and Object
In object oriented programming,
- a class represents a **kind** of objectsl it is a **template** for creating instances of specific objects; it is an **abstraction** of the things that are common to the kind of objects.
- an **object** represents an indivdual and specific item; it is an **instance** of the general class

## Summary
**Algorithm**: Sequence of clear instructions to achieve a goal

**Data Structure**: Data items and related methods about the same object. 