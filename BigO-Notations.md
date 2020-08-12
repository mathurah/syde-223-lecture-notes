## What is worst case time complexity? 
Focus on:
- Worst case 
- When n is approaching infinity 
- Difference between orders of complexity
[More on Time Complexity](timecomplex.md)

## Sequential List (Array)
**Random Access ith item:** `O(1)`
**Search for target data value:** `O(n)`
**Insertion given index i:** `O(n)`
**Deletion given index i:** `O(n)`

## Doubly-Linked List
**Random Access ith item:** `O(n)`
**Search for target data value:** `O(n)`
**Insertion given index i:** `O(n)`
**Deletion given index i:** `O(n)`
**Insertion given pointer to the target place's node:** `O(1)`
**Deletion given pointer to the target node:** `O(1)`

## Singly-Linked List
**Random Access ith item:** `O(n)`
**Search for target data value:** `O(n)`
**Insertion given index i:** `O(n)`
**Deletion given index i:** `O(n)`
**Insertion given pointer to the target place's node:** `O(1)`
**Deletion given pointer to the target node:** `O(1)`

## Linked Stack 
**Push:** `O(1)` 
**Pop:** `O(1)`
**Peek** `O(1)`

## Sequential Stack 
**Push within capacity:** `O(1)`
**Push when need to increase capacity:** `O(n)`
**Pop within capacity:** `O(1)`
**Pop when need to decrease capacity:** `O(n)`
**Peek** `O(1)`

## Linked Queue 
**Enqueue:**`O(1)`
**Dequeue:**`O(1)`
**Peek:**`O(1)`

## Sequential Array Queue 
**Enqueue within capacity:**`O(1)`
**Enqueue when need to increase capacity capacity:**`O(n)`
**Dequeue within capacity:**`O(1)`
**Dequeue when need to decrease capacity:**`O(n)`
**Peek:**`O(1)`

