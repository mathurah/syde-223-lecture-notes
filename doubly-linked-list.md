# Doubly Linked List
- Each node has two pointers, one pointing to the previous node, the other pointing to the next node
- In addition to the head pointer, a tail pointer is also needed to point to the last node

![](/images/doubly-linked-list.png)
- Allow iteration to move both forward and backwards

### Insert operations
```cpp
insert('c',0);
insert('b',0);
insert('a',0);
insert('k',1);
```

The resulting list will be 
like this: 
![](/images/double-link-list-insert.png)

### Remove
```cpp
remove(2);
remove(0);
```
The result will be this: 
![](/images/double-link-list-remove.png)

## Comparison between Singly-linked and Doubly-linked list
**Aspect** | **Singly-linked** | **Doubly-linked** |
--- | --- | --- 
**Iterate** | One way | Two ways
**Memory Overhead** | Less (one pointer per node)| More (two pointers per node)
**Remove the last node** | Slow (must iterate from the head until finding the previous node for properly setting its 'next' pointer)| Fast (can directly find the previous node using the 'prev' pointer)

- Can print lists in previous order easier

```cpp
```

- Assignment Part 2 (Insert front, insert tail, just call another function)
- Tail pointers help you reverse through the list

### Doubly Linked List Demo Code

#### Header File
```cpp
#ifndef SYDE223_A1_DOUBLY_LINKED_LIST_H
#define SYDE223_A1_DOUBLY_LINKED_LIST_H

class DoublyLinkedList {
public:
    // Can be seen outside as DoublyLinkedList::DataType
    typedef int DataType;

private:
    // Befriend so tests have access to variables.
	friend class DoublyLinkedListTest;
 
    // This type of list can basically grow as large as we want it to,
    // so we'll just pick an arbitrary large value as the capacity for
    // all lists of this type.
    static const unsigned int CAPACITY = 65536;

    // The node structure used for the DoublyLinkedList.
    struct Node {
        Node(DataType value);
        DataType value;
        Node* next;
        Node* prev;
    };

    // Private method to get the node at an index. This is optional, but you
    // will probably find it useful.
    Node* getNode(unsigned int index) const;

	// MEMBER VARIABLES
    // A pointer to the head node of the list.
    Node* head_;
    // A pointer to the tail node of the list.
    Node* tail_;
    // The number of elements in the list.
    unsigned int size_;
    
    // Copy constructor. Declared private so we don't misuse it.
    DoublyLinkedList(const DoublyLinkedList& rhs) {}
    // Assignment operator. Declared private so we don't misuse it.
    DoublyLinkedList& operator=(const DoublyLinkedList& rhs) {}

public:
	// CONSTRUCTOR/DESTRUCTOR
    // Create a new empty DoublyLinkedList.
    DoublyLinkedList();
    // Destroy this DoublyLinkedList, freeing all dynamically allocated memory.
    ~DoublyLinkedList();

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
    // returns the size of the list otherwise.
    unsigned int search(DataType val) const;
    // Prints all elements in the list to the standard output.
    void print() const;

	// MUTATORS
    // NOTE: all mutators for this class are boolean functions, returning
    // true if the call succeeds, and false if it fails
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
#### CPP File
```cpp
#include "doubly-linked-list.h"
#include <iostream>
#include <new>

DoublyLinkedList::Node::Node(DataType data):
        value(data), next(NULL), prev(NULL)
{
}
DoublyLinkedList::DoublyLinkedList()
        :head_(NULL), tail_(NULL), size_(0)
{
}
/*DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& list)
:size_(list.size_)
{
	if (list.empty())
		return;
	Node *tmp = new Node(list.head_->value);
	if (!tmp)
		throw("Allocation failed");
	head_ = tmp;
	//tail_ = tmp;
	Node *ln2 = list.head_->next;
	Node* ln1 = head_;
	while (!ln2)
	{
		tmp = new Node(ln2->value);
		if (!tmp)
			throw("Allocation failed");
		ln1 ->next = tmp;
		tmp->prev = ln1;
		ln1 = tmp;
		ln2 = ln2->next;
	}
	tail_ = ln1;
}*/
DoublyLinkedList::~DoublyLinkedList()
{
    while (head_)
    {
        Node* tmp = head_;
        head_ = head_->next;
        delete tmp;
    }
}
bool DoublyLinkedList::empty() const
{
    return size_ == 0;
}
unsigned int DoublyLinkedList::size() const
{
    return size_;
}
void DoublyLinkedList::print() const
{
    std::cout << "number of Data = " << size_ << std::endl;
    Node *tmp = head_;
    while (tmp)
    {
        std::cout << tmp->value << std::endl;
        tmp = tmp ->next;
    }
}
bool DoublyLinkedList::insert_front(DataType value)
{
    Node *nnd = new Node(value);
    if(!nnd)
        return false;
    if(!head_)
    {
        head_ = nnd;
        tail_ = nnd;
    }else
    {
        head_->prev = nnd;
        nnd->next = head_;
        head_ = nnd;
    }
    ++size_;
    return true;
}
bool DoublyLinkedList::remove_front()
{
    if (empty())
        return false;
    Node* tmp = head_;
    head_ = head_->next;
    delete tmp;
    --size_;
    if (head_)
    {
        head_->prev = NULL;
    }else
    {
        tail_ = NULL;
    }
    return true;
}
bool DoublyLinkedList::insert_back(DataType value)
{
    Node *nnd = new Node(value);
    if(!nnd)
        return false;
    if(!head_)
    {
        head_ = nnd;
        tail_ = nnd;
    }else
    {
        nnd->prev = tail_;
        tail_->next = nnd;
        tail_ = nnd;
    }
    ++size_;
    return true;
}
bool DoublyLinkedList::remove_back()
{
    if (empty())
        return false;
    Node* tmp = tail_;
    tail_ = tail_->prev;
    delete tmp;
    --size_;
    if (tail_)
    {
        tail_->next = NULL;
    }else{
        head_ = NULL;
    }
    return true;
}
bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    if (index == size())
    {
        return insert_back(value);
    }
    if (index > size_ || index < 0)
        return false;
    if (index == 0)
    {
        return insert_front(value);
    }
    else
    {
        Node* snd = getNode(index);
        Node *nnd = new Node(value);
        if (!nnd)
            return false;
        nnd -> prev = snd->prev;
        snd->prev->next = nnd;
        nnd->next = snd;
        snd->prev = nnd;
    }
    ++size_;
    return true;
}
bool DoublyLinkedList::remove(unsigned int index)
{
    if (index < 0 || index >= size())
        return false;
    if (index == 0)
    {
        return remove_front();
    }
    if(index == size()-1)
    {
        return remove_back();
    }

    Node* nd = getNode(index);
    nd->prev->next = nd->next;
    nd->next->prev = nd->prev;
    delete nd;
    --size_;
    return true;
}
unsigned int DoublyLinkedList::search(DataType value) const
{
    Node *nd = head_;
    unsigned int cnt = 0;
    while(nd)
    {
        if(nd->value == value)
            return cnt;
        ++cnt;
        nd = nd ->next;
    }
    return cnt;
}
DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    Node* nd = getNode(index);
    if (!nd)
        return tail_->value;
    return nd->value;
}
bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    DataType *curVal = &getNode(index)->value;
    if(!curVal)
        return false;
    *curVal = value;
    return true;
}
DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    Node* tmp = head_;
    unsigned int cnt = 0;
    while (cnt < index && tmp)
    {
        tmp = tmp->next;
        ++cnt;
    }
    /*if (tmp)
    tmp = tmp ->next;*/
    return tmp;
}
bool DoublyLinkedList::full() const
{
    return size() == CAPACITY;
}

```