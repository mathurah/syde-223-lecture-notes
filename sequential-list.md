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

## Difference between sequential vs Linked List Implementation
**Aspect** | **Sequential List** | **Linked List** |
--- | --- | --- 
**Memory Usage** | Less flexible | More flexible
**Memory Overhead** | Less | More due to pointers
**ith node access** | Faster | Slower (serial search)

### Sequential List Implementation 

#### Header
```cpp
#ifndef SYDE223_A1_SEQUENTIAL_LIST_H
#define SYDE223_A1_SEQUENTIAL_LIST_H

class SequentialList {
public:
	// Can be seen outside as SequentialList::DataType
	typedef int DataType;	

private:	
	// Befriend so tests have access to variables.
	friend class SequentialListTest;

	// MEMBER VARIABLES
	// A pointer to the block of memory allocated to store the list data.
	DataType *data_;
	// The capacity of the list
	// (i.e., the maximum number of items the list can store).
	unsigned int capacity_;
	// The number of used elements in data_.
	unsigned int size_;

	// Copy constructor. Declared private so we don't use it incorrectly.
	SequentialList(const SequentialList& rhs) {}
	// Assignment operator. Declared private so we don't use it incorrectly.
	SequentialList& operator=(const SequentialList& rhs) {}

public:
	// CONSTRUCTORS/DESTRUCTOR
	// Create a new SequentialList with the given number of elements.
	SequentialList(unsigned int cap);
	//Destroy this SequentialList, freeing all dynamically allocated memory.
	~SequentialList();

	// ACCESSORS
	// Returns the number of elements in the list.
	unsigned int size() const;
	// Returns the maximum number of elements the list can hold.
	unsigned int capacity() const;
	// Returns true if the list is empty, false otherwise.
	bool empty() const;
	// Returns true if the list is at capacity, false otherwise.
	bool full() const;
	// Returns the value at the given index in the list. If index is invalid,
	// return the value of the last element.
	DataType select(unsigned int index) const;
	// Searches for the given value, and returns the index of this value if found.
	// Returns the size of the list otherwise
	unsigned int search(DataType val) const;
	// Prints all elements in the list to the standard output.
	void print() const;

	// MUTATORS
	// Inserts a value into the list at a given index.
	bool insert(DataType val, unsigned int index);
	// Inserts a value at the beginning of the list.
	bool insert_front(DataType val);
	// Inserts a value at the end of the list.
	bool insert_back(DataType val);
	// Deletes a value from the list at the given index.
	bool remove(unsigned int index);
	// Deletes a value from the beginning of the list.
	bool remove_front();
	// Deletes a value at the end of the list.
	bool remove_back();
	// Replaces the value at the given index with the given value.
	bool replace(unsigned int index, DataType val);	
};
#endif
```

#### CPP
``` cpp
#include "sequential-list.h"
#include <iostream>
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
    capacity_ = cap;
    size_ = 0;
    data_ = new DataType[capacity_];

}

SequentialList::~SequentialList()
{
    delete [] data_;
    data_ = nullptr;
}

unsigned int SequentialList::size() const // const means you cannot change the value of the variable
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    return size() == 0;

}

bool SequentialList::full() const
{
    return size() == capacity();
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if (index < size()) {
        return data_[index];
    } else {
        return data_[size() - 1];
    }

}

unsigned int SequentialList::search(DataType val) const
{
    for (unsigned int i = 0; i < size(); i++) {
        if (data_[i] == val) {
            return i;
        }
    }
    return size();
}

void SequentialList::print() const
{
   if (size() > 0){
        for (unsigned i = 0; i < size(); i++) {
            cout << data_[i] << " ";
        }
    } else {
       cout << "There is nothing in the list." << endl;
   }
}

bool SequentialList::insert(DataType val, unsigned int index)
{  if (full() || index > size()) {
        return false;
    } else if (index < size()) {
        for (unsigned int i = (size() - 1); i > index; i--) {
            data_[i+1] = data_[i];
        }
        data_[index+1]=data_[index];
    }

    data_[index] = val;
    size_++;

    return true;
}

bool SequentialList::insert_front(DataType val)
{
    return insert(val, 0);
}

bool SequentialList::insert_back(DataType val)
{
    return insert(val, size());
}

bool SequentialList::remove(unsigned int index)
{
    //False: List is empty. index is greater than or equal to the size of the list
    if(empty() || index >=size()) {
        return false;
    } else if(index < size()) {
        for (unsigned int i = index; i < (size() -1); i++) {
            data_[i] = data_[i + 1];
        }
    }
    data_[size() -1] = NULL;
    size_--;
    return true;
}

bool SequentialList::remove_front()
{
    return remove(0);
}

bool SequentialList::remove_back()
{
    return remove((size()-1));
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if (index < size()){
        return data_[index] = val;
    } else {
        return false;
    }
}
```
