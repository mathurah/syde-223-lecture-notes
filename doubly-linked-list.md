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
