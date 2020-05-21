# Pointers

## Learning Questions
- What is a poiinter in C ++? 
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

## Summary 
- Pointer: Variable that stores the memory address of a variable
- Constructor: A special kind of class member function automatically called when object is instantiated