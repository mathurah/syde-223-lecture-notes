# Test Cases
**General Ideas**
- Write code to test the algorithm with some input values
- Output the results and see if they make sense.
- Also output the procedures and visualize them if it is helpful

## Which Parameter Values?
- If there are a finite number of input cases that can be tested in affordable itme, test them all
- Otherwise, select representative cases

## How to Select Representative Cases?
### Black-box approach
- They can be done without knowing/seeing the implementation of the code/function

**Method 1: By analyzing the characteristics of the input values**
- Analuze the range of input values
- Group them
- **Equivalence partioning**: Pick some values that represent each group
```cpp
f(int x) //negative, 0, positive
```
- **Boundary value analysis**: Pick some values that represent the boundaries between groups
``` cpp
listInsert(int value, int index); 
// indexes near the head, near the tail
```
**Method 2: By predicting in which cases the program may fail**
- **Destructive testing**: Test with invalid or unexpected inputs 
```cpp
// invalid year int values, divided by 0, square root of negative
```

## White-box approach
- Open-box testing

**Method 3: By understanding the code coverage**: 
- Select a variety of input cases to cover all different paths, conditions, and statements in the code

## Assertion
- Rather than manually inspecting the output, write assertion
``` cpp
#include <iostream>

// #define NDEBUG // #define NDEBUG before #include <assert.h> to disable assertion
#include <assert.h>

using namespace std;

int addPositiveNumbers(int val1, int val2) {
    //assume the input values should have been checked to only allow positive values

    // manually written for debug
    if (val1 <= 0 || val2 <= 0) cout << "Warning! addPositiveNumbers is taking invalid input." << endl;

    //using asert
    //assert(val1 > 0 && val2 > 0);     //terminates the program if the expression evaluates to 0 (false)

    return val1 + val2;
}

int main(){
    cout << addPositiveNumbers (5, 7) << endl;
    cout << addPositiveNumbers (-1, 7) << endl;
    cout << addPositiveNumbers (8, 7) << endl;
    cout << endl;

    cout << (addPositiveNumbers (5, 7) == 12) << endl;
    cout << (addPositiveNumbers (8, 7) == 12) << endl;

    assert(addPositiveNumbers(5, 7) == 12);  //terminates the program if the expression evaluates to 0 (false)

    return 0;
}
```