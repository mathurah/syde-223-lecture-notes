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
    // Memory leak! 	//what is a better practice? //not able to deallocate the variable above
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