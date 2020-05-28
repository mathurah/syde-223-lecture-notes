# Sequential List (array)


**Sequential List**: Continuous block of memory is allocated to store the data, and an indec is available to provide direct access to random data items

Data Members of a sequential list
- **Index**: an integer, usually starting from 0
- **Data**: stored as an array
- **Capacity**: the maximum number of elements that can be stored
- **Size**: The number of elements currently in the list. Knowing the size is important because any index position exceeding the current size does not store a valid data

This digure visualizes a sequential list with capacity 8 and size of 0. The sumbol # is used to represent invalid values.

![](/images/sequential-list-initial.png)

### Insert
```cpp
insert('c',0);
insert('b,0'); 
insert('a,0');
insert('k',1);
insert('z',0); 
insert('y',5); 
insert('m', 7); // this operation is rejected because of its exceeding tail position, which is index 6 at the moment
//Because we don't want to leave a gap in the array. If inserting at index 7, there will be a gap at index 6.
//After the insert, size will become 7. By default, the program will assume the 7th item is at index 6. But it will be #  a random value rather than the intended value.
```
The list is changed into this:
![](/images/sequential-list-after-insert.png)

### Remove
```cpp
remove(3); 
remove(0);
```
The list is changed into this. **Note that the items are shifted towards the front of the list. And there are no gaps left between elements**
(#y's represent invalid values left after the deletion)
![](/images/sequential-list-remove.png)

### Replace
```cpp
replace(2,'m'); 
```

The list is changed into this: 
![](/images/sequential-list-replace.png)

A sequential list could be implemented...
- **Fixed capacity**: basic array
- **Dynamic capacity**: dynamic array
    - When more storage space is needed, a new larger array can be created, and the data are copied into the new array