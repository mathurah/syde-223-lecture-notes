# Lecture 2 - Week 1

## Learning Questions
- What is a poiinter in C ++? 
- What is a constructor in C++?

**Pointer** is a variable that stores the memory address of a variable.

A **memory address** is an integer
- Often expressed in hexadecimal (base 16)
*Ex. 0x9ffdec* (0x means followin)

### Declaration 
``` cpp 
int *p1; 
double *p2; 
myClass *p3' 
```

### Address-of operator & 
``` cpp
[data type] x; 
[data type] *p; 
p = &x; 
```

Different methods:
``` cpp
int *p; 
int * p; 
int* p; 
```

### Dereference operator *
Output the value of operator

```cpp
cout << *p << endl;
```

### Demo Code  - Week 1 Pointer
``` cpp
#include <iostream>
using namespace std;

int main() {
	int x, *p1, *p2;
	cout<< &x << endl; //getting the address of integer x

	x = 10; //assigns a value of x
	p1 = &x; //assigns p1 as the address of variable x
	p2 = p1; //same address - same address x 

	cout<< *p1 << endl; //getting the value (10)
	cout<< p1 << endl; //output is the address

	*p2 = 20;
	cout<< x << endl; //output is 20

   cout<< sizeof(*p1) << endl; //size of integer
   cout<< sizeof(p1) << endl; //size of pointer address

   //integers are 4 bytes! 
   //addresses are long ints which are 8 bytes

	return 0;
}
```

## Pointers to Pointers
- Since a pointer itself is stored somewhere in the memory, it also has its own memory address
- Pointers to pointers have to have two stars
- **ipp will return the integer value stored at the pointer of the pointer


### Pointer to Pointer Demo
``` cpp
#include <iostream>
using namespace std;

int main(){
    int i = 5, j = 6, k = 7;
    int *ip1 = &i;
    int *ip2 = &j;
    cout << ip1 <<endl; //0xfffffc0c &i 
    cout << ip2 <<endl;  //0xfffffc08

    int **ipp; //pointer to another pointer
    ipp = &ip1;  //0xfffffc0c

    cout << **ipp <<endl; //output the value of i, which is 5

    *ipp = ip2; //changing the address to the same as ip2
	cout << **ipp <<endl; //outputs j=6

    *ipp = &k;
	cout << **ipp <<endl;

    return 0;
}
```

## Why Pointers? 
- Support data structures such as linked list
- Allow a called function to manipulate the input variable
- Direct memory access and manipulation

## Constructors
- A special kind of class member function
    - Automatically called when object is instantiated
    - Must be public
    - If no constructor is defined by the user, the system will create a default constructor, which sets data members to their default values
- Difference from other regular member functions: 
    - They must have the **same name as the class**
    - They **cannot return a value; not even void**

### Constructor Demo
```cpp
#include <iostream>

//declaration
class MonthAndDay {
private:
    int month;
    int day;
    void checkDate(); //check if the date is valid.
public:
    MonthAndDay(); // overload constructor with no argument condition  //note: no return value not even void
    MonthAndDay(int monthValue); //overload 1 int condition
    MonthAndDay(int monthValue, int dayValue); //overload 2 int condition
    void output();  //note: require return value such as void
};

//implementation
MonthAndDay::MonthAndDay() { //if no arg. set to Jan 1.
    month = 1;
    day = 1;
    checkDate(); //don't need, we know it is valid.
}
MonthAndDay::MonthAndDay(int monthValue){
    month = monthValue;
    day = 1;
    checkDate();
}
MonthAndDay::MonthAndDay(int monthValue, int dayValue) : month(monthValue), day(dayValue){
    //can directly set the values after the : symbol
    checkDate();
}
void MonthAndDay::checkDate(){
    if((month < 1) || (month > 12)){
        std::cout<<"Illegal month value!\n";
    }
    if((day < 1) || (day > 31)){
        std::cout<<"Illegal day value!\n";
    }
    //of course, a better way is
    //to check day depending on month, e.g., no Feb.30.
}
void MonthAndDay::output(){
    std::cout<<"Month: "<<month<<", Day: "<<day<<std::endl;
}


//main function
int main() {
    MonthAndDay date1; // call default constructor, don't use ()
    MonthAndDay date2(5);
    MonthAndDay date3(2,21);
    date1.output();
    date2.output();
    date3.output();

    //date1.MonthAndDay();  //ILLEGAL!

    MonthAndDay date4(12,33);
    MonthAndDay date5(-1,99);

    return 0;
}
```

## Why use constructors?
- Initialize member variables of an object. Simplify the procedure
- Add code to validate the entered initila values
- Other actions (ex. print to system log when an object is instantiated)

## Summary 
- Pointer: Variable that stores the memory address of a variable
- Constructor: A special kind of class member function automatically called when object is instantiated