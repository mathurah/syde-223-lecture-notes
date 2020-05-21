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