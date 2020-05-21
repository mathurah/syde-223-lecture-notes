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