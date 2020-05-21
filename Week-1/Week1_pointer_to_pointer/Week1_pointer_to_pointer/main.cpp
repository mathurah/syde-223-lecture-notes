#include <iostream>
using namespace std;

int main(){
    int i = 5, j = 6, k = 7;
    int *ip1 = &i;
    int *ip2 = &j;
    cout << ip1 <<endl;
    cout << ip2 <<endl;

    int **ipp;
    ipp = &ip1;

    cout << **ipp <<endl;

    *ipp = ip2;
    cout << **ipp <<endl;

    *ipp = &k;
    cout << **ipp <<endl;

    return 0;
}
