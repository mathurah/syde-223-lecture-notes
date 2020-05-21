## Reference
**Reference** is an alternative name for an object. In the code below, r becomes another name of ``'a'``. 
``` cpp
int a = 5; 
int &r = a; 
```
Here, ``r`` can be considered as a macro for ``(*p)``, where p is a pointer to ``'a'``. 

### Demo Code
```cpp
#include <iostream>
using namespace std;
void swap1(int i, int j) // cannot swap because i and j are local copies inside this function
{
    int tmp = i;
    i = j;
    j = tmp;
}

void swap2(int *ip, int *jp) // can swap because ip and jp are pointers, pointing to the outside integers
{
    int tmp = *ip;
    *ip = *jp;
    *jp = tmp;
}

void swap3(int& i, int& j) // can swap because i and j are references, they are alternative names of the outside integers
{
    int tmp = i;
    i = j;
    j = tmp;
}

int main()
{

    int x = 10;
    int y = 20;
    swap1(x,y);
    cout << x << ", " << y << endl;

    swap2(&x,&y);
    cout << x << ", " << y << endl;

    swap3(x,y);
    cout << x << ", " << y << endl;
}
```
