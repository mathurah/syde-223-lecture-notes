## What is worst case time complexity? 
Focus on:
- Worst case (this list is not the average)
- When n is approaching infinity 
- Difference between orders of complexity<br/>

[More on Time Complexity](timecomplex.md)
![General Time Complexity](images/general-time-complexities.png)

## Sequential List (Array)
**Random Access ith item:** `O(1)`<br/>
**Search for target data value:** `O(n)`<br/>
**Insertion given index i:** `O(n)`<br/>
**Deletion given index i:** `O(n)`<br/>

## Doubly-Linked List
**Random Access ith item:** `O(n)`<br/>
**Search for target data value:** `O(n)`<br/>
**Insertion given index i:** `O(n)`<br/>
**Deletion given index i:** `O(n)`<br/>
**Insertion given pointer to the target place's node:** `O(1)`<br/>
**Deletion given pointer to the target node:** `O(1)`<br/>

## Singly-Linked List
**Random Access ith item:** `O(n)`<br/>
**Search for target data value:** `O(n)`<br/>
**Insertion given index i:** `O(n)`<br/>
**Deletion given index i:** `O(n)`<br/>
**Insertion given pointer to the target place's node:**` O(1)` <br/>
**Deletion given pointer to the target node:** `O(1)`<br/>

## Linked Stack 
**Push:** `O(1)`<br/>
**Pop:** `O(1)`<br/>
**Peek** `O(1)`<br/>

## Sequential Stack 
**Push within capacity:** `O(1)`<br/>
**Push when need to increase capacity:** `O(n)`<br/>
**Pop within capacity:** `O(1)`<br/>
**Pop when need to decrease capacity:** `O(n)`<br/>
**Peek** `O(1)`<br/>

## Linked Queue 
**Enqueue:**`O(1)`<br/>
**Dequeue:**`O(1)`<br/>
**Peek:**`O(1)`<br/>

## Sequential Array Queue 
**Enqueue within capacity:** `O(1)`<br/>
**Enqueue when need to increase capacity capacity:** `O(n)`<br/>
**Dequeue within capacity:** `O(1)`<br/>
**Dequeue when need to decrease capacity:** `O(n)`<br/>
**Peek:** `O(1)`<br/>

## Binary Search Tree
**Access:** `O(n)`<br/>
**Search:** `O(n)`<br/>
**Insert:** `O(n)`<br/>
**Delete:** `O(n)`<br/>
**Unbalanced tree:** `A tree of size n can grow in a straight line in the worst case scenario, where time complexity is O(n) as height = n-1`<br/>

## AVL Tree 
**Access:** `O(log(n))`<br/>
**Search:** `O(log(n))`<br/>
**Insert:** `O(log(n))`<br/>
**Delete:** `O(log(n))`<br/>

## Space Complexities 
Defn: Auxillary space is the extra space or temporary space used by an algorithm.<br/>
`O(n) for most, O(1) for bubble, selection ahd heap sort algorithms, and O(log(n) for quick sort algorithms.`

## Sorting Algorithms
**Bubble Sort:** `O(n^2)`<br/> 
**Selection Sort:** `O(n^2)`<br/> 
**Heap Sort:** `O(n(log(n)))`<br/> 
**Merge Sort:** `O(n(log(n)))`<br/> 
**Quick Sort:** `O(n^2)`<br/> 

## Hashing 
**Search:** `O(n)`
**Insertion:** `O(n)`
**Deletion:** `O(n)` 

=======


