# Stack and Queue

## Queue
> First in, first out

**Examples**
- A database server receiving multiple requests/commands from multiple clients
- Waiting in line

## Stack 
>> Last in, First Out

**Examples**
- Hanoi tower disks
- Action equence for undo
- Waiting in line
- Peek is like select of a linked list


## Comparing different data structures
**List**
- Supports any position insert and remove

**Stack**
- Only sypport insert and remove from the **same end**
- Last in first out (LIFO)

**Queue**
- Only support insert from **one** end and remove from the **opposite** end 
- First in first out (FIFO)

## Stack Abstract Data Type
![](/images/stack.png)
 **Major Variables**
 - Data item (ex. ``int``, ``char``)
 - Capacity
 - Size

 **Major Methods**
 - **Push:** Insert an item at the top of the stack
 - **Pop**: Removes an item from the top of the stack, and returns a reference to that item
 - **Peek:** returns a reference to the top item without removing the item from the stack

 ## Implementation 
 1. Through linked list
    - Insert, remove, peek at front is ``O(1)``
    - Insert, remove, or peek at end is ``O(n)``
 2. Arrays

## Compare Linked List and Linked Stack

**Linked List** | **Linked Stack** 
--- | --- 
`InsertFirst` |` Push`
`DeleteFirst` and return it | Pop
`SelectFirst `| Peek
Access or replace other than the first item allowed  | Not allowed

### Stack Linked Implementation
```cpp
#include <iostream>
using namespace std;

class Stack{

    //class within class, Node is only used within Stack
    class Node{
    public:
        int data;
        Node *next;

        Node(int x);
    };

public: //public variables for this simple demo only.
    int capacity;  //let's set this capacity constant, since it is linked structure, may just use a vary large number such as max int INT_MAX.
    int size;
    Node *top;  //pointer to the top node

public:
    Stack(int cap);
    ~Stack();

    void push(int x);
    int pop();
    int peek();

    void print();
};

Stack::Node::Node(int x) : data(x), next(NULL){
    //TODO: validate input, especially when you have a special value for EMPTY STACK return constant
}

Stack::Stack(int cap): capacity(cap), size(0), top(NULL){
    //TODO: validate input, e.g., 0 or negative cap.
}

Stack::~Stack(){// properly deallocated dynamic memory in the linked data structure.
    Node *next;
    while(top != NULL){
        next = top->next;
        delete top;
        top = next;
    }
}

void Stack::push(int x){ //just like InsertFirst in linked List
    //check if stack is full
    if(size >= capacity){
        cout<<"stack is full! cannot push." <<endl;
        return;
    }
    else{ // not full, can push
        //check if top pointer is empty.
        if(top == NULL){
            top = new Node(x);
        }else{
            Node *newNode = new Node(x);
            newNode->next = top;
            top = newNode;
        }
        size++;
    }
}

int Stack::pop(){ //like Linked List DeleteFirst and return data
    //check if there is anything to pop
    if(size <= 0){ //or top == NULL
        cout<<"stack is empty! cannot pop." <<endl;
        return -9999;  //EMPTY STACK return constant
    }
    else{
        Node *returnNode = top;
        top = top->next;

        //may return the data or the node, in this demo, just return the data
        int returnInt = returnNode->data;
        delete returnNode;
        returnNode = NULL; // optional
        size--;

        return returnInt;
    }
}

int Stack::peek(){ // like SelectFirst in linked list
    //check if there is any node
    if(top == NULL){ //or size <= 0 or size == 0
        cout<<"stack is empty! nothing to peek." <<endl;
        return -9999;  // EMPTY STACK return constant
    }
    else{
        return top->data;
    }
}

void Stack::print(){
    //check if there is anything to print
    if(top == NULL){ //or size <= 0 or size == 0
        cout<<"stack is empty! nothing to print." <<endl;
        return;
    }
    else{
        Node *p = top;
        while(p != NULL){
            cout<< p->data << endl;
            p = p->next;
        }
        cout<<endl;
    }
}

int main(){
    Stack st1(3);
    Stack *pst2 = new Stack(3);

    cout<<"Test 1: "<<endl;
    cout<<"stack 1: "<<endl;
    st1.print();
    cout<<"stack 2: "<<endl;
    pst2->print();
    cout<<endl;



    cout<<"Test 2: "<<endl;
    st1.push(99);
    st1.push(88);
    st1.push(44);
    st1.push(22);

    cout<<"stack 1: "<<endl;
    st1.print();
    cout<<"stack 2: "<<endl;
    pst2->print();
    cout<<endl;




    cout<<"Test 3: "<<endl;
    pst2->push( st1.pop() );
    pst2->push( st1.pop() );
    pst2->push( st1.pop() );

    cout<<"stack 1: "<<endl;
    st1.print();
    cout<<"stack 2: "<<endl;
    pst2->print();
    cout<<endl;




    cout<<"Test 4: "<<endl;
    cout<<st1.pop()<<endl;


    return 0;
}
```

## Stack Sequential Implementation 
- Which end to use as the top of the stack? ``Index size -1``

### Example Code
```cpp
#include <iostream>
using namespace std;

class Stack{

public: //public variables for this simple demo only.

    int init_capacity;   //set with the constructor
    int current_capacity;
    //in this case, let's allow the capacity to change.
    //we will increase current_capacity when size is too large,
    //and decrease current_capacity when size is too small.

    int size;
    int *items;  //pointer to an array, which will be created with new operator

public:
    Stack(int cap);
    ~Stack();

    void push(int x);
    int pop();
    int peek();

    void print();
};


Stack::Stack(int cap): init_capacity(cap), current_capacity(cap), size(0), items(new int[cap]){
    //TODO: validate input, e.g., 0 or negative values
}


Stack::~Stack(){
    delete [] items;
}

void Stack::push(int x){
    //check if stack is full
    if(size == current_capacity){
        cout<<"stack cap is reached, double its size." <<endl;
        int *newItems = new int [2*current_capacity];
        current_capacity = 2*current_capacity;
        //copy all items to the new array
        for(int i = 0; i < size; i++){ //loop for n = size times.
            newItems[i] = items[i];
        }
        int *temp = items;
        items = newItems;
        delete [] temp;
    }
    // not full now, can push

    //TODO: implement push

}

int Stack::pop(){
    //check if there is anything to pop
    if(size == 0){
        cout<<"stack is empty! cannot pop." <<endl;
        return -9999;   // example EMPTY RETURN value
    }
    else{
        //TODO: implement pop


        //TODO: check if size is too small, e.g., size < current_capacity / 4
        //      if so, reduce current_capacity by half (round to integer).

        //TODO: return value
    }
}

int Stack::peek(){
    //check if there is any item
    if(size == 0){
        cout<<"stack is empty! nothing to peek." <<endl;
        return -9999;   // example EMPTY RETURN value
    }
    else{
        //TODO: return value
    }
}

void Stack::print(){
    //check if there is anything to print
    if(size == 0){
        cout<<"stack is empty! nothing to print." <<endl;
        return;
    }
    else{
        for(int i = size - 1; i >= 0; i--){ //loop for n = size times.
            cout<<items[i]<< endl;
        }
        cout<<endl;
    }
}

int main(){
    Stack st1(3);
    Stack *pst2 = new Stack(3);

    cout<<"Test 1: "<<endl;
    cout<<"stack 1: "<<endl;
    st1.print();
    cout<<"stack 2: "<<endl;
    pst2->print();
    cout<<endl;



    cout<<"Test 2: "<<endl;
    st1.push(99);
    st1.push(88);
    st1.push(44);
    st1.push(22);

    cout<<"stack 1: "<<endl;
    st1.print();
    cout<<"stack 2: "<<endl;
    pst2->print();
    cout<<endl;




    cout<<"Test 3: "<<endl;
    pst2->push( st1.pop() );
    pst2->push( st1.pop() );
    pst2->push( st1.pop() );

    cout<<"stack 1: "<<endl;
    st1.print();
    cout<<"stack 2: "<<endl;
    pst2->print();
    cout<<endl;




    cout<<"Test 4: "<<endl;
    cout<<st1.pop()<<endl;
    cout<<st1.pop()<<endl;
    cout<<st1.pop()<<endl;

    return 0;
}
```



## Stack Linked vs Sequential Implementation

**Method** | **Linked Stack** | **Sequential List** (with adjustable capacity)
--- | --- | --- 
`Push` | Always `O(1)` | `O(1)` when within capacity, `O(n)` when need to increase capacity
`Pop`| Always `O(1)` | `O(1)` when within capacity, `O(n)` when need to decrease capactiy
`Peek`| `O(n)` | `O(1)`

``pst2 -> print(); ``

Push - sometimes doubling the capcity if you need more space

## Midterm
- 2 hours, two sections 
- 3 days of time window, can do two hours consectivel
- True/False, multiple choice, fill in the blanks
- Fill in the blanks 