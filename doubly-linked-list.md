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