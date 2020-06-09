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
- average cas, consider all different ``A[]`` with different k
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
    - n is the size of the input

If we compare two algorithms, ``f1(n) = 1000``, ``f2(n) = n``
![](/images/orderofcomplexity.png)

f2(n) and f5(n) = 0.5*n - minor differences, can ignore minor differences between each group

## Orders of Complexity 
- Group of "orders" or "familes" 
- When ``k`` is a constant
    - ``1, 1000, any k*1``
    - ``0.5*n, n, any k*n``
    - ``0.005* n<sup>2</sup>. any k*n<sup>2</sup>

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