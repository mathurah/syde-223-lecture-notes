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


