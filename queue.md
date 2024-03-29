## Queue Abstract Data Type
**Queue**
- Only support insert from **one** end and remove from the **opposite** end 
- First in first out (FIFO)

## Major Variables
- Data item: (ex, `int`, `char`)
- Capacity
- Size
- **Head**: Reference to the front of the queue
- **Tail**: Reference to the rear of the queue

## Major Methods
- **Enqueue**: Inserts an item at the rear of the queue
- **Dequeue**: Removes an items from the front of the queue, and returns a reference to that item (`head`)
- **Peek**: Return a reference to the front item without removing the item from the queue

Enqueue from head end is `O(1)`, tail end is `O(1`
Dequeue from head end is `O(1)`, tail end is `O(n)`


### Queue Linked Implementation
```cpp
#include <iostream>
using namespace std;

class Queue{

    //class within class, Node is only used within Queue
    class Node{
    public:
        int data;
        Node *next;
        Node(int x);
    };

public: //public variables for this simple demo only.
    int capacity;  //let's set this capacity constant, since it is linked structure, may just use a vary large number such as max int INT_MAX.
    int size;
    Node *head;
    Node *tail;

public:
    Queue(int cap);
    ~Queue();

    void enqueue(int x);
    int dequeue();
    int peek();

    void print();
};

Queue::Node::Node(int x) : data(x), next(NULL){
    //TODO: validate input, especially when you have a special value for EMPTY Queue return constant
}

Queue::Queue(int cap): capacity(cap), size(0), head(NULL), tail(NULL){
    //TODO: validate input, e.g., 0 or negative cap.
}

Queue::~Queue(){// properly deallocated dynamic memory in the linked data structure.

    Node *temp = NULL;

    while(head != NULL){
        temp = head->next;
        delete head;
        head = temp;
    }

}

void Queue::enqueue(int x){
    //check if Queue is full
    if(size == capacity){
        cout<<"Queue is full! cannot enqueue." <<endl;
    }
    else{ // not full, can do
        ////////////////////////////////
        if(size == 0){ //special case
            head = new Node(x);
            tail = head;
        }
        else{ //enqueue from the tail
            Node *newNode = new Node(x);
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        ////////////////////////////////
    }
}

int Queue::dequeue(){
    //check if there is anything to dequeue
    if(size == 0){
        cout<<"Queue is empty! cannot dequeue." <<endl;
        return -999999; //EMPTY_VAL
    }
    else{ // dequeue from the head
        ///////////////////////////////
        int returnVal = head->data;
        if(size == 1){ //special case, only one item
            delete head;
            head = NULL;
            tail = NULL;
        }
        else{
            Node *nextNode = head->next;
            delete head;
            head = nextNode;
        }
        size--; //OR size = size - 1;
        return returnVal;
        ///////////////////////////////
    }
}

int Queue::peek(){
    //check if there is any node
    if(size == 0){
        cout<<"Queue is empty! nothing to peek." <<endl;
        return -9999;
    }
    else{
        return head->data;
    }
}

void Queue::print(){    // from head to tail, i.e., from front of queue to end of queue
    //check if there is anything to print
    if(size == 0){
        cout<<"Queue is empty! nothing to print." <<endl;
        return;
    }
    else{
        Node *p = head;
        while(p != NULL){
            cout<< p->data << ", ";
            p = p->next;
        }
        cout<<endl;
    }
}

int main(){
    Queue queue1(3);
    Queue *queue2 = new Queue(3);

    cout<<"Test 1: "<<endl;
    cout<<"Queue 1: "<<endl;
    queue1.print();
    cout<<"Queue 2: "<<endl;
    queue2->print();
    cout<<endl;



    cout<<"Test 2: "<<endl;
    queue1.enqueue(99);
    queue1.enqueue(88);
    queue1.enqueue(44);
    queue1.enqueue(22);

    cout<<"Queue 1: "<<endl;
    queue1.print();
    cout<<"Queue 2: "<<endl;
    queue2->print();
    cout<<endl;




    cout<<"Test 3: "<<endl;
    queue2->enqueue( queue1.dequeue() );
    queue2->enqueue( queue1.dequeue() );
    queue2->enqueue( queue1.dequeue() );

    cout<<"Queue 1: "<<endl;
    queue1.print();
    cout<<"Queue 2: "<<endl;
    queue2->print();
    cout<<endl;




    cout<<"Test 4: "<<endl;
    cout<<queue1.dequeue()<<endl;

    return 0;
}
```

## Queue Sequential Implementation
Which end to use as front and which end rear?
- Enqueue from `[0]` end is `O(n)`
- Enqueue from `[size - 1]` end is `O(1)` 
- Dequeue from `[0]` end is `O(n)`
- Dequeue from `[size -1]` is `O(1)`

## Circular Array Implementation of Queue 
![](/images/circlequeue.png)
Need two index variables
- `iFront`: pointing to the front queue
- `iRear`: pointing to the location immediately after the rear
- Array that is both capaciy adjustable and circular, enqueue and dequeue cannot be at the same end

Initial state
- Size is 0
- Empty queue
- `iFront == iRear, both 0`
- Enqueue does not work if queue is full
- Enqueue at items `[iRear]`
- Dequeue at item `[iFront]`

## Queue Linked vs Sequential Implementation
**Method** | **Linked node Queue** | **Sequential List queue (if with adjustable capacity, circular array** 
--- | --- | --- 
**Enqueue** | Always `O(1)` | `O(1)` when within capacity, `O(n)` when need to increase capacity |
**Dequeue** | Always `O(1)` | `O(1)` when within capacity, `O(n)` when need to decrease capacity
**Peek** | `O(1)` | `O(1)`

### Sequential Demo
```cpp
#include <iostream>
using namespace std;

class Queue{  // implemented as a circular array

public: //public variables for this simple demo only.
    int capacity;  //let's use fixed capacity here, although you have learned how to implement adjustable capacity
    int size;
    int iFront;
    int iRear;
    int *items;

public:
    Queue(int cap);
    ~Queue();

    void enqueue(int x);
    int dequeue();
    int peek();

    void print();
};


Queue::Queue(int cap): capacity(cap), size(0), iFront(0), iRear(0){
    //TODO: validate input, e.g., 0 or negative cap.
}

Queue::~Queue(){// properly deallocated dynamic memory in the linked data structure.

    delete [] items;

}

void Queue::enqueue(int x){
    //check if Queue is full
    if(size == capacity){
        cout<<"Queue is full! cannot enqueue." <<endl;
        //return; //optional
    }
    else{ // not full, enqueue at iRear
        ////////////////////////////////




        ////////////////////////////////
    }
}

int Queue::dequeue(){
    //check if there is anything to dequeue
    if(size == 0){
        cout<<"Queue is empty! cannot dequeue." <<endl;
        return -999999; //EMPTY_VAL
    }
    else{ // dequeue from iFront
        ///////////////////////////////





        ///////////////////////////////
    }
}

int Queue::peek(){
    //check if there is any node
    if(size == 0){
        cout<<"Queue is empty! nothing to peek." <<endl;
        return -9999;
    }
    else{
        ///////////////////////////////


        ///////////////////////////////
    }
}

void Queue::print(){
    //check if there is anything to print
    if(size == 0){
        cout<<"Queue is empty! nothing to print." <<endl;
        return;
    }
    else{
        ///////////////////////////////




        ///////////////////////////////
        cout<<endl;
    }
}

int main(){
    Queue queue1(8);
    Queue *queue2 = new Queue(8);

    cout<<"Test 1: "<<endl;
    cout<<"Queue 1: "<<endl;
    queue1.print();
    cout<<"Queue 2: "<<endl;
    queue2->print();
    cout<<endl;



    cout<<"Test 2: "<<endl;
    queue1.enqueue(99);
    queue1.enqueue(88);
    queue1.enqueue(44);
    queue1.enqueue(22);

    cout<<"Queue 1: "<<endl;
    queue1.print();
    cout<<"Queue 2: "<<endl;
    queue2->print();
    cout<<endl;




    cout<<"Test 3: "<<endl;
    queue2->enqueue( queue1.dequeue() );
    queue2->enqueue( queue1.dequeue() );
    queue2->enqueue( queue1.dequeue() );

    cout<<"Queue 1: "<<endl;
    queue1.print();
    cout<<"Queue 2: "<<endl;
    queue2->print();
    cout<<endl;




    cout<<"Test 4: "<<endl;
    cout<<queue1.dequeue()<<endl;
    cout<<queue1.dequeue()<<endl;
    cout<<queue1.dequeue()<<endl;



    cout<<"Test 5: "<<endl;
    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);

    cout<<queue1.dequeue()<<endl;
    cout<<queue1.dequeue()<<endl;

    queue1.enqueue(4);
    queue1.enqueue(5);
    queue1.enqueue(6);

    cout<<queue1.dequeue()<<endl;
    cout<<queue1.dequeue()<<endl;

    queue1.enqueue(7);
    queue1.enqueue(8);
    queue1.enqueue(9);

    cout<<queue1.dequeue()<<endl;
    cout<<queue1.dequeue()<<endl;

    queue1.enqueue(10);
    queue1.enqueue(11);
    queue1.enqueue(12);

    cout<<"Queue 1: "<<endl;
    queue1.print();

    return 0;
}
```