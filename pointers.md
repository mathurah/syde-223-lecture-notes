# Pointers

## Learning Questions
- What is a pointer in C ++? 
- What is a constructor in C++?

**Pointer** is a variable that stores the memory address of a variable.

A **memory address** is an integer
- Often expressed in hexadecimal (base 16)
*Ex. 0x9ffdec* (0x means following)

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


## What happens during new, delete, and p = NULL?

**New**: dynamic memory allocation, setting with a value

**Delete**: Does not delete the pointer itself, but behind the scenes it has marked the int memory free to use - **meaning of memory deallocation** 

**Memory deallocation**: 
- Just a marking of the purpose of the memory, it does NOT reset values at that address into 0.
- If no other variable or process has used that memory space, the old value remains there. 

**NULL**: Address is reset to nothing, dangling pointer issue is avoided. 

### Demo Code
```cpp
#include <iostream>

using namespace std;

int main () {

    int *p;

    cout<< "Step 1." << endl

        << "p is a pointer to int. p itself stays at address: " << &p << endl

        << "p initially stores no address, which is nullptr or NULL, value: "<< p << endl

        << "** Note that static memory allocation is used for p. **" << endl << endl;



    p = new int (10);

    cout<< "Step 2." << endl

        << "p still stays at address: " << &p << endl

        << "But now p stores an address returned by the new operator. This address is: "<< p << endl

        << "At this address " << p << ", there is an integer with value: " << *p << endl

        << "** Note that dynamic memory allocation is used for this integer. **" << endl

        << "** Do not confuse this with the fact that the pointer p is created by static memory allocation. **" << endl

        << "** C++ program uses different areas of the memory for statically allocated variables and dynamically allocated variables **" << endl

        << "** You can see that the two memory addresses are very different. **" << endl

        << endl;

    delete p;

    cout<< "Step 3." << endl

        << "p still stays at address: " << &p << endl

        << "p still stores the same address: "<< p << endl

        << "So, delete does not change the pointer itself. "<< endl

        << "But behind the scene, the program has marked the " << sizeof(int)

        << " bytes memory (for an int) at address " << p << " as free for others to use." << endl

        << "THIS is the meaning of memory de-allocation. " << endl

        << "Note that this memory de-allocation is just a marking of the purpose of the memory, it does NOT reset values at that address into 0." << endl

        << "If no other variable or process has used that memory space, the old value remains there." << endl

        << "That is why right now, immediately after delete p, you can still see the old int value there as: " << *p << endl

        << endl;

    p = NULL;

    cout<< "Step 4." << endl

        << "p still stays at address: " << &p << endl

        << "Now, the address stored in p has been reset to nothing, represented by "<< p << endl

        << "By doing so, the dangling pointer issue is avoided." << endl

        << endl;

    return 0;
}
```

**The memory address of the pointer is const, always, unless you release it from memory.**

> Like I put a Coca Cola in your cup, the Coca Cola can be changed with 7-Up, no problem, but your cup is always your cup, unless you smash it.

## -> Syntax
``->`` can be used as well to access class or struct members from a pointer of an object. 

### Demo Code
``` cpp
#include<iostream>
using namespace std;

class TestClass {
public:
    int i;
    void output (){  cout<< "test output i : " << i <<  endl;   };
};


int main()
{
    TestClass staticObject;
    TestClass *pointerToDynamicObject = new TestClass ();

    staticObject.i = 10;    //for object name, . dot syntax is used to access members
    staticObject.output();

    pointerToDynamicObject->i = 20; //for pointer name, -> syntax is used.
    pointerToDynamicObject->output();

    (*pointerToDynamicObject).i = 30;   //this also works, but less frequently used. Note that ( ) is needed.
    (*pointerToDynamicObject).output();

}
```

## Pointer Members
**Pointer members** are usually pointing to data with dynamically allocated memory. 
Generally speaking, you should remember to do the following things: 
-Manually delete them *(ex. de-allocate the memory)* in the destructor
- Manually implement deep copy in the copy constructor
- Manually implement deep copy in the assignment operator (=) overload

By default, the assignment operator (=) applied to an object does a shallow copy. Usually, a deep copy is what programmers need. 

``` cpp
#include <iostream>
using namespace std;

class MyClass{  // demo of a basic pattern of default constructor, copy constructor, assignment operator, and destructor
public: //set as public for easy demo
    // some pointers for data with dynamically allocated memory
    int *p;
    double *q;

public:
    MyClass();
    MyClass(const MyClass & other);     // copy constructor has no return value
    MyClass & operator = (const MyClass & other);   // will return a reference of this object itself
    ~MyClass();
};


MyClass::MyClass()      // overload default constructor
{
    //initialize data with dynamically allocated memory
    //e.g.,
    p = new int (10);
    q = new double (100.1);

    //print log if needed
    //e.g.,
    cout << "object of MyClass constructed by default constructor" << endl;

}
MyClass::MyClass(const MyClass & other)  // overload copy constructor, 'const' sets the reference to be read-only, avoid error
{
    //do a deep copy of all the data from inside of 'other'
    //note that we do not need to clear this object's existing data, because it is empty at this moment. this is different from overloading operator =
    //e.g., deep copying
    p = new int(* other.p);
    q = new double(* other.q);

    //print log if needed
    //e.g.,
    cout << "object of MyClass constructed by copy constructor" << endl;
}
MyClass & MyClass::operator = (const MyClass & other)   // overload operator = (assignment). the input is a reference
        // note that the return value is a reference, which will be used in such cases: obj1 = obj2 = obj3; which means obj1.operator=(  obj2.operator=( obj3  )   ); return value from  obj2.operator=( obj3 ) is needed.
{
    if(this != &other)  // 'this' is a pointer to the object itself (self address). &other is the address of 'other'. this condition checks if the same object is assigned to itself. Do nothing if obj = obj; is used.
    {
        //clear this object's existing dynamically allocated members, which should have been initialized by constructor
        //e.g.,
        delete p;
        delete q;

        //do a deep copy of all the data from inside of 'other'
        //e.g., deep copying
        p = new int(* other.p);
        q = new double(* other.q);
    }
    return *this;  // return the object itself. 'this' is pointer to self, so return *this as the object itself.
}
MyClass::~MyClass()     // overload destructor
{
    //clear this object's existing dynamically allocated members, which should have been initialized by constructor
    //e.g.,
    delete p;
    delete q;
    //setting to NULL is optional here

    //print log if needed
    //e.g.,
    cout << "object of MyClass destructed" << endl;
}

int main(){
    MyClass obj1;   //default constructor
    * obj1.p = 20;
    * obj1.q = 200.2;

    MyClass obj2 = MyClass( obj1 ); //copy constructor

    obj2 = obj2;    // operator =, this case will be taken care of by the line "if(this != &other)"
    //obj2.operator=(obj2);   // this is the same thing as the above line

    MyClass obj3, obj4;   //default constructor

    obj4 = obj3 = obj2;
    //obj4.operator=(  obj3.operator=( obj2  )   ); // this is the meaning of the above line

    cout << * obj1.p << ", " << * obj1.q << endl;
    cout << * obj2.p << ", " << * obj2.q << endl;
    cout << * obj3.p << ", " << * obj3.q << endl;
    cout << * obj4.p << ", " << * obj4.q << endl;

    return 0;
}
```

## Summary 
- Pointer: Variable that stores the memory address of a variable
- Constructor: A special kind of class member function automatically called when object is instantiated
