## Algorithm Analysis 
- **Measure computer program performance**: Ideally, need to run real codes on target software and hardware platforms (**Actual** performance)
- In practice, need convinient and general estimation of actual performance (can be done with pseudocode before any software and hardware implementation) **Theoretical**

**Solution**: Algorithmic Analysis with big O notation.


## Time Complexity (Algorithmic Analysis)
- Focus on only the **major things** affecting performance rather than the minor things
1. Worst case, rather than the best case
2. When ``n`` approaching infinite, rather than the small n
3. Difference between orders of complexity, rather than the difference within the same order


### Example; Sequential Search (find the index in an arrray where the 1st value K is sotred)
- N: number of items/iterations 
- size of the input ``(n)`` is the size of an array ``(n = size )``
- best case, ``A[0] = K. ``
- average case, consider all different ``A[]`` with different k
- **worst case**, last item is K (or no K in array)
```cpp
int SequentialSearch(int A[], int size, int K) {
    for (int i = 0; i < size; i++>) {
        if (A[i] == K)
            return i; 
    }
    return -1; 
}

```

## N aproaching infinite
- In the **Sequential Search** example, time to compelte the search also depends on the input size N
- Assume the numebr of steps to completion as ``f(n)``
    - ``n`` is the size of the input

If we compare two algorithms, ``f1(n) = 1000``, ``f2(n) = n``
![](/images/orderofcomplexity.png)

``f2(n) and f5(n) = 0.5*n`` - minor differences, can ignore minor differences between each group

## Orders of Complexity 
- Group of "orders" or "familes" 
- When ``k`` is a constant
    - ``1, 1000, any k*1``
    - ``0.5*n, n, any k*n``
    - 0.005* n<sup>2</sup>. any k*n<sup>2</sup>

## Common Orders of Compelxity
**Time Complexity** | **Type** 
--- | --- 
``O(1)`` | Constant time| 
``O(log2(n))`` |Logarithmic time| 
``O(n)`` |Linear time| 
``O(n * log2(n))`` |Linearithmic Time| 
``O(n^2)`` |Quadratic time| 
``O(n^3)`` | Cubic time| 
``O(2^n)`` |Exponential time|
``O(n!)`` |Factorial time|

## Big-O Notation Properties
- Constant multipliers can be ignored

**Example**
``` cpp
n^2 = O(n^2)
2*n^2 = O(n^2)
99999999*n^2 = O(n^2)
```
- Exponential functions with different base values belong to different orders
    - Ex. ``O(2^n)`` and ``O(3^n)``are not the same orders. ``O(3^n)`` > ``O(2^n)``
- Polynomial functions is ``O(n^k)``, ``k`` is the largest power value
- The highest order component dominates Big ).
```cpp
n! + 5*3^n 500 * 2^n n^3 + 12n^2 +  99 = O(n!)``
```

## Big-O Notation Defined
- Formal math notation 
- A function ``f(n)`` is classified as ``O(g(n))`` if there exists two **positive constants** K and n- such that 
    - ``|f(n)| < K|g(n) | for all n > n0 ``
- Since algorithm steps cannot be negative, we often deal with ``f(n) < K*g(n), for all n > n0``
- ``f(n) is O(g(n))`` is sometimes written as ``f(n) = O(g(n))``
- Informally, this means "f us not much bigger than g"
    - f may be smaller than g
    - f may be simialr to g
- Don't care about small n. Let's talk big (n approaching infinite)
- As long as g is NOT *too much bigger* than f (finite constant ``K`` times bigger is OK), f belongs to the same group as g. 

## Practice of Algorithmic Analysis
- Usually, when we write ``f(n) = O(g(n))``, we mean f(n) has the same order of complexity as g(n) has
    - Although mathematically, this only means ``g(n) could have an order higher than f(n). OR they have the same order ``
- Answer with the lowest possible answer

**We want a tigheter upper bound**

## ``O(1)``

When code is simple, finite steps, they are all big O(n)

## In general, no recursion, no loop
- Ex. Sequentially implement list acces ``[i]`` item

- When pointer to the node is given: ``O(1)``
- Doubly-linked list deleted a node when a pointer to the node is given
    1. Bi-direction link the previous one and the next one
    2. Delete the current one
    3. Fixed steps, do not change with the size of the list
- Doubly linked list: insert a node when a pointer to the place is given
    1. Create new node, temp holding address
    2. Bi-direction link it between previous one and the current one 
### Example 1
```cpp
void LinkedList::insertFront(Node *newNode) {
    if (newNode ==NULL) {
        //check input
        cout << "Warning! insert Front has newNode == NULL" << endl; 
        return; 
    }
    if(head == NULL) {//special case: list is empty 
        head = newNode; 
    } else { //general case: list is not empty 
        newNode-> next = head; 
        head = newNode; 
    }
}

//constant steps 
```


## ``O(n)``
- One loop, repeated ``A*N``times

Examples: 
- Sequential list search for a given value
- Linked list search for a given value

How many steps? ``(an + b)`` steps (worst case)
- ``b``: outside loop, constant steps

### Example 2
```cpp
Node *ListSearch(Data Item value, Node *head) {
    Node* tempNode = headl 
    while(tempNode ! = NULL) {
        if (tempNode -> data == value) {
            return tempNode; 
        }
        tempNode = tempNode -> next; 
    }
    return NULL; 
}
```



### Example 3 
```cpp
for (int i = 1; i <=n; i+ =10) {
    //some O(1) steps here within the loop
} 
// some O(1) steps
```
- Loop for about ``n/10`` times

## Nested Loops
- If each loop is repeated ``a*n`` times, ``a`` is some constant
- And there are ``k`` levels of nested loops, then it is:

O(n<sup>k</sup>)

### Example 4
``` cpp
for (int i = 1; i <= i; i+=1) {
    for (int j = 1; j <=n; j+=2) {
        //some O(1) steps
    }
    //some O(1) steps
} 
```
- 1st loop, repeated ``(n)`` times
- In each 1st loop repetition, 2nd loop (nested) has: ``(an + b)`` steps

Total: ``(an + b)*n + c = an^2`` (fix this after looking at sliedes)

### Example 5
``` cpp
for (int i = 1; i <= i; i+=1) {
    for (int j = 1; j <=n; j+=2) {
        for
    }
    //some O(1) steps
} 
```

## O(Log N)
- Are all the same order of complexity, difference is just a constant
### Example 6
```cpp
for (int i = 1; i<n; i*=2) {
    //some O(1) steps
}
 ```
 = (a log<sub>2</sub>n + b) steps: worst case
 O(log<sub>2</sub>n)

 What if it is ``i*=3``?

 O(log<sub>3</sub>n)

## If each time of repetition has different steps
- Count the steps and add them togetehr
- Ex. a loop, repeat ``n`` times, in the ``ith`` reptition, it requires ``i`` steps

Total steps = 1 + 2 + 3 + ... + n = >

- Analyze code/pseudocode to determine


## When no recursion
- For each part of code with loops, find out the the total number of steps within the loop. All constants can be represented as: ``a, b, c``
- Get the total steps of this code, highest order of the equation

### Example

1. Some nested loop, resulting in O(n<sup>3</sup>)
2. Some function call, resulting in (On)
3. Some O(1)
4. Some O(log n)

Highest one is O(n<sup>3</sup>)

### Example 7
```cpp 
int factorialRecusrive (int n) {
    if (n<0) {
        cout << "warning!" <<endl ;
        return 0;
    } else if (n == 0)
        return 1; 
    else {
        return (n*factorialRecursive(n-1)); 
    }
}
```
- ``T(n)`` represents the total steps needed for input 
- ``T(n) = T(n -1) + a``: recurrence relation
- ``T(0) = b``: ending case

``T(n) = T(n-1) = a``

``= (T(n-2) + a) + a``

``= ((T(n-3)+ a)+ a) + a``

...
``= T(n-k) + k*a ``

When k = n, we reach the ending case
``T(n) = T(O) + n*a = b + a*n``, 
that is **O(n)**

### Factorial Recursive - O(N)
```cpp
int factorialNonRecursive(int n) {
    //non recursive version, need to use a loop

    if (n < 0) {
        cout <<"Warning! Factorial can only take non-negative input!" << endl; 
        return 0; 
    }
    if (n == 0) return 1; 

    int result = 1; 
    for (int i = 1; i <= n; ) {
        result = result *i; 
    }

    return result; 
}

```
### Example 8 - Fibonacci Recursive
``` cpp
int fibonnaciRecursive (int n) {
    if (n < 0) {
        cout << "Warning! Input <0." <<endl; 
        return 0; 
    } 
    else if (n == 0) return 0; 
    else if (n ==1) return 1; 
    else return fibonnaciRecursive(n-1) + fibbonacciRecursive(n-2); 
}
```
- ``T(n) = T(n-1) + T(n-2) + a ``: Reccurence relation


## Main rules - How time scales with respect to different variables
1. Different steps get added 
2. Drop constants. Just want to know how it scales (linearly, quadratically, etc.)
3. Different inputs = different variables
    - O(N<sup>2</sup>) -> O(a * b)
4. Drop non dominant terms


Useful website: https://developerinsider.co/big-o-notation-explained-with-examples/