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



## Summary 
- Pointer: Variable that stores the memory address of a variable
- Constructor: A special kind of class member function automatically called when object is instantiated