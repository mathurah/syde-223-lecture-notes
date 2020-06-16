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

