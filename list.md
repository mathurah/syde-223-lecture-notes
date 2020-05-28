# List ( ADT)

**List**: A series of data items placed in an order.

List is an Abstract Data Type. 

**ADT** is the abstract representation of the characteristics and behavior of data structures.
- ADT does not specify how the data structures are implemented or coded; it only describes its behavior from the point of view of a user, such as possible data items and possible operations on the data. 
- In contrast, data structures are concrete implementation of ADT

## Typical operations on data stored in a list:
### Insert
```cpp 
void insert(DataType value, int position); 
```
- Inserts value into the list as a position
- All of the data previously at the position and after it, if any, re shifted toward the end of list by one.
- May use a pointer to a node as input. The node should not previously belong to the list.
    - *Special cases: first, last*

### Remove
``` cpp
void remove(int position); 
```
- Removes data from the list at a given position 
- All of the existing data after position is moved towards the list front by one.
- May use a pointer to a Node as input. The node should previously belong to the lsit.
    - *Special cases: first, last*

### Select
```cpp
DataType select(int position); 
```
- Returns the value stored at a given position
- **Special cases: first, last**

### Replace
``` cpp
void replace(int position, DataType value);
``` 
- Replaces the value stored at a given position wiht the value
- Alternatively, may use a pointer to a Node as input. The node should not previously belong to the list.
    - **Special cases**: first, last

### Get Size
```cpp
int size(); 
```
- Returns the number of elemenets in the list. 
- Note: this is not the capacity of the lsit (ex. max possible size)

## Different ways that a list ADT can be implemented as data structures: 
- Array (sequential list)
- Singly-linked list
- Doubly-linked list