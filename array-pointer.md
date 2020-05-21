# Arrays & Pointers
## Array variables as Pointers
An array variable refers to the first indexed variable in an array. 
### Example
```cpp
int a[3] = {10, 20, 30};
cout << a << endl; // the address of a[0], e.g., 0xffffcc14
cout << *a << endl; // the value of a[0], i.e., 10
```

Here, you can see that 'a' (not a[0]) can be treated as a pointer. 

Assume that there is alos a pointer, ``int *p;``; 

Then, ``p=a;`` is legal. It makes ``p`` pointing to the same place as 'a'. 

To access the three integers in the array, you can use ``p[0], p[1], p[2];`` which is equivalent to ``*p, *(p+1), *(p+2)``. 

However, ``a = p;`` is illegal because the array pointer ``'a'`` is a ``const pointer``. It's value cannnot be changed.

``'a'`` is the address of array ``a``, you cannot change an memory address of a variable. If you want to change the value, you can do ``*a = *p``




## Using new[] and delete[] operators for array

The ``new[]`` operator is used to dynamically allocate memory to a data object/item.
``` cpp
int *p = new int[4];
p[0] = 10;
p[1] = 20;
p[2] = 30;
p[3] = 40;
cout << p[0] << endl;
delete [] p;
p = NULL;
```

Alternatively, we can use this syntax in C++ to initialize a dynamic array
``` cpp
int *p {new int[4] {10, 20, 30, 40} };
```
As shown above, ``p`` is pointing to the first integer in the new array. 

After ``delete []p``, we should not forget to set p to ``NULL`` to avoid dangling pointers. 
```cpp
delete[]p;
```
## Illegal
`` delete[4]p;``

`` delete p;`` this is legal, but will only deallocate memory for ``p[0]`` the first element, without deallocating the rest in the array.

## Function returns a pointer to an array
A pointer to an array is especially useful when we want a function to return an array. 
### Demo code
```cpp
int *test(){
    int*p = new int[4];
    p[0] = 10; 
    p[1] = 20; 
    p[2] = 30; 
    p[3] = 40; 
    return p; 
}
```
Note that the array type is not allowed as a return-type of functions. 

**Be careful!**
Remember to use ``delete[]`` and set the pointer to ``NULL`` for the pointer that takes the return value from such function.
###Example
```cpp
int *a = test(); 
delete [] a; 
a = NULL; 
```