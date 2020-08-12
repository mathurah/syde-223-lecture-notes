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

