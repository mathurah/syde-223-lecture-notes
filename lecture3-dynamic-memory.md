# Lecture 3 - Week 2

## Memory Allocation
- At the start of a program, the operating system assigns the program a memory pool (free space) to use. This memory pool is large, but not infinite.
- At the end of the program, this memory pool will be recollected/deallocated by the operating system for other programs to use

## Static Memory
- Variables defined without using the *new* operator
- Has lifetime within a scope
- At the end of the scope, the variable is **automatically** destroyed, and memory is automatically de-allocated for other thigns in the program to use. 

## Dynamic memory allocation
- Variables defined using the new operator
- Has lifetime with the entire program, or unitl user uses `delete` to manually de-allocate the moemory space.

## The New Operator
``` cpp
int *n;
n = new int(17); //Initializes *n to 17
```
- Allocate memory with the size of the mentioned type
- Return a **pointer** of the mentioned type
- The memory will not be automatically released/deallocated, until end of the program or user ``delete``

``` cpp
int *p1; 
p1 = new int;
//without initalization - not recommended.
//if cout << *p1; will get whatever was previously left there in the 4 bytes space. some unknown number.
```
- Can also initialize a class type
    - Construcrtor is called for new object
    - Can invoke different constructor with different arguments.
    ```cpp
    MyClass *mcPtr;
    mcPtr = new MyClass(32.0, 17); 
    ```

## Delete and Dangling Pointers
``delete p;``
- De-allocate the dynamic memory, which means future ``new`` operators will be able to allocaate the memory space
- But p still points there; called "dangling pointer"
- If p is then de-referenced using (*p), this leads to unpredictable results
- Avoid dangling pointers
    - Immediately assign pointer to NULL after delete
    ``` cpp
    delete p; 
    p = NULL; //0
    ```

### Demo Code
``` cpp
#include <iostream>
using namespace std;

int* testFunc3 (int a){ 	//return a pointer
    int *p1;  		//p1 is a local variable
    p1 = new int(a);  //the address returned by new will not be automatically collected after the end of this function scope
    //here, new operator allocates the memory dynamically/manually
    cout << "Inside testFunc3, int value: "<< *p1 << " is allocated memory at address: " << p1 << endl;
    return p1;   //here return the pointer, i.e., return the memory address value
}
//after the end of this scope, local variables are automatically deleted,

int main() { //main function also has its scope
    int *p;
    p = testFunc3(10);
    cout << "1 In main, p is pointing to int value: " << *p << " at address: " << p << endl << endl;

    p = testFunc3(20); 	//here, we lost track of the previous memory address. this is a bad practice.
    // Memory leak! 	//what is a better practice?
    cout << "2 In main, p is pointing to int value: " << *p << " at address: " << p << endl << endl;

    delete p;  //release/de-allocate the memory space pointed to by pointer p back to the pool (freespace).
    //p still stores the address at this time.
    cout << "3 In main, p is pointing to int value: " << *p << " at address: " << p << endl << endl;
    //undefined behaviour. the memory may be used by others.

    p = NULL;  // essentially change the memory address to zero. should do this immediately after delete p.
    cout << "4 Pointer p is set to " << p << endl;

    return 0;
}
//after the end of this scope, all variables are automatically removed.
//all memory addresses are released back to the operating system.
```

### Output
``` 
Inside testFunc3, int value: 10 is allocated memory at address: 0x7f8866c057d0
1 In main, p is pointing to int value: 10 at address: 0x7f8866c057d0

Inside testFunc3, int value: 20 is allocated memory at address: 0x7f8866c057e0
2 In main, p is pointing to int value: 20 at address: 0x7f8866c057e0

3 In main, p is pointing to int value: 20 at address: 0x7f8866c057e0 (still pointing to old address even when you deleted)

4 Pointer p is set to 0x0
```

### Further explanation
**Value is deallocated, but why does it still output?**
``` cpp
delete p;  //release/de-allocate the memory space pointed to by pointer p back to the pool (freespace).
    //p still stores the address at this time.
    cout << "3 In main, p is pointing to int value: " << *p << " at address: " << p << endl << endl;
    //undefined behaviour. the memory may be used by others.
```
- P is still pointing there, you have to assign it to null
- It just allows the memory to be used again, but doesn't physicall delete the value there, just says logically it's free to use
- If you print a random address there's always some garbage value

## Memory Leak
- It occurs when a piece (or pieces) of memory that was previously allocated by a programmer (using ``new``) is not properly de-allocated (using ``delete``). Even though the memory is no longer in use by the program, it is still "reserved"
- No variables can use that 

> Without ``delete``, no ``new`` operator can allocate the same address allocated by a previous ``new``
- If a program has a lot of memory that hasn't been de-allocated, it could slow down the performance
- If there's no memory left in the program it could cause the program to crash

### Demo Code
``` cpp
#include <iostream>
using namespace std;

int main() {
    //Warning! Don't try this on yor own computer. :)
    /*
    do {
        new double (10.0);
    } while (true);

    return 0;
    */

    for(int i = 0; i < 200000000 ; i++){
        new int (10);
    }

    return 0;
}
//At the end of the program, all memory addresses are de-allocated, including leaked memory, managed by the operating system.
```
- Very bad code, has no pointer
- Important to have pointer pointing to address in dynamic allocation!
- Remember to delete

## Destructors
- Performs the opposite function of a constructor
    - If the memory is **statically** allocated, it is called when the object's scope is closed
    - If the memory is **dynamically** allocated, it is called when explicitly ``delete``
- Destructor must be named the same as the class
    - Just with a ~ sign preceding its name
    ``` cpp
    Server(); //Constructor
    ~Server(); //Destructor
    ```
- Important rule: each class has only one destructor
- When an object's default destructor is caleld, it can only automatically de-allocate the object's member variables that are statically allocated 
- 

### Demo Code
``` cpp 
#include <iostream>

class MyClass {
public:
    MyClass() {std::cout <<"MyClass constructed\n";}
    ~MyClass() {std::cout <<"MyClass destroyed\n";}
};

class ClassWithPointer {
private:
    int i;
    int *ip;
    MyClass *cp;
public:
    ClassWithPointer();
    ~ClassWithPointer();
};

ClassWithPointer::ClassWithPointer() {
    i = 10;
    ip = new int(20);
    cp = new MyClass;
}

ClassWithPointer::~ClassWithPointer() {
    // without this code the destructor won't work?
    delete ip;
    ip = NULL; //not very necessary, because no code will use this pointer after this anyway
    delete cp;
    cp = NULL; //not very necessary, because no code will use this pointer after this anyway

}
int main () {

    ClassWithPointer testObj;

    return 0;
}
```

