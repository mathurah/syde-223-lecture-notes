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


