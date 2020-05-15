#include <iostream>
using namespace std;

int main() {
    int x, *p1, *p2;
    cout<< &x << endl;

    x = 10;
    p1 = &x;
    p2 = p1;

    cout<< *p1 << endl;
    cout<< p1 << endl;

    *p2 = 20;
    cout<< x << endl;

    cout<< sizeof(*p1) << endl; //size of the integer
    cout<< sizeof(p1) << endl; 

    return 0;
}
