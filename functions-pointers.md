## What happens in a function call without pointers? 
- **Definition of a function**: A function takes some inputs/arguments, runs its algorithms, and returns an output result. 
- Without using pointers, a called function will make copies of all the input arguments as local variables within it scope. 
- A function can use and modify the local variables, but such modification will not affect anything outside the scope of the function. 
- It may return a value, which will be assigned to a variable outside the function scope.

### Demo Code
``` cpp
#include <iostream>
using namespace std;

//return variable 'a' plus 1
int testFunc1 (int a){     //here, memory is statically allocated to 'a'
                  //'a' is a variable within the scope of testFunc1
   cout << endl << "Inside function, address of 'a': " << &a << endl;
   a++;
   return a;
}
//after the end of this scope, local variables are automatically removed.
//their memory space is automatically released back to the pool (free for other usage)

int main() { //main function also has its scope
   int x = 1, y = 10; //here, memory is statically allocated to x and y.
   cout << "Before function call: Value of x: "<< x << ".  Address of x: " << &x << endl;
   cout << "Before function call: Value of y: "<< y << ". Address of y: " << &y << endl;

   cout << endl;

    cout << "Function call with input (x): " << testFunc1 (x) << endl;
    cout << "Function call with input (y): " << testFunc1 (y) << endl;

   cout << endl;

    cout << "After function call: Value of x: "<< x << ".  Address of x: " << &x << endl;
    cout << "After function call: Value of y: "<< y << ". Address of y: " << &y << endl;

   return 0;
} //after the end of this scope, all variables are automatically removed.
```
### Output
```
Before function call: Value of x: 1.  Address of x: 0x7ffeedb8ea38
Before function call: Value of y: 10. Address of y: 0x7ffeedb8ea34

Function call with input (x): 
Inside function, address of 'a': 0x7ffeedb8e9cc
2
Function call with input (y): 
Inside function, address of 'a': 0x7ffeedb8e9cc
11

After function call: Value of x: 1.  Address of x: 0x7ffeedb8ea38
After function call: Value of y: 10. Address of y: 0x7ffeedb8ea34
```
- The values and addresses of x and y are not changed after the function call
- ``a`` is a local variable within the scope of testFunc1
- The memory allocated to ``a`` when calling ``testFunc1(x)`` is automatically released back to the pool after the function call, so the same memory (with the same address) can be used again, and allocated to ``a`` again, when calling ``testFunc1(y)``

## When using pointers
### Directly modify a variable in a called function
- Using pointers, a called function makes local variables that are copies of the pointers (addresses)
- As a result, algorithms inside the function will be able to directly access and modify the variables outside the scope of the function via the pointers, because these algorithms now know the address of the variables outside the function.
- Modificaation is done to the original variables outside the function scope. The effects remain after the end of the called function's scope.
- If we need a function to return more than one variable, we can use multiple pointers as input arguments, and assign the return values to the variables pointed by these pointers. In constrast, the return value of a function is usually limited to one variable

### Demo
``` cpp 
#include <iostream>

using namespace std;



//increase the first int by 1, the second int by 2

void testFun2(int *p1, int *p2){ // p1 and p2 are local variables

    cout << "p1 is pointing to an int at address: " << p1 << endl;

    cout << "p2 is pointing to an int at address: " << p2 << endl;



    (*p1)++; //note, since ++ has a higher priority than * operator, the ( ) is needed.

    *p2 = *p2 + 2;

} //p1 and p2 lifetime ends. memory space allocated to p1 and p2 is released.



int main() {

    int a = 1, b = 10;

    cout << "Before function call: Value of a: "<< a << ".   Address of a: " << &a << endl;

    cout << "Before function call: Value of b: "<< b << ".  Address of b: " << &b << endl;

    cout << endl;

    testFun2(&a, &b); //one function modified two variable values, without using any return value.
    cout << endl;

    cout << "After function call: Value of a: "<< a << ".   Address of a: " << &a << endl;

    cout << "After function call: Value of b: "<< b << ".  Address of b: " << &b << endl;

    return 0;

}
```