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