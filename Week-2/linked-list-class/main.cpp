/* Basic Linked List class*/
#include <iostream>
using namespace std;

struct Node {     //in C++, a struct is a class that has all members public by default; otherwise same as class. often used to represent data members only, without method members.
    int data;   //every member is public by default in struct
    Node *next;
    Node() : data(0), next(NULL) {}; //it may have constructors too.
    Node(int x) : data(x), next(NULL) {};
};

//declaration
class LinkedListInt {
private:
    Node *head;

public:
    LinkedListInt(); //constructor
    void insertFront (Node* newNode);
    void removeTail ();
    void print() const;  // const function cannot change any value
};

//implementation
LinkedListInt::LinkedListInt() : head(NULL){
}

void LinkedListInt::insertFront (Node* newNode){
    if (newNode == NULL) {		//check input
        cout<<"Warning! insertFront has newNode == NULL." <<endl;
        return;
    }

    if (head == NULL) { 	//special case: list is empty
        head = newNode;
    } else { 					// general case: non-empty list
        newNode->next = head;
        head = newNode;
    }
}

void LinkedListInt::removeTail (){
    if (head == NULL) { // check for NULL value
        cout<<"Warning! head == NULL. Nothing to remove." <<endl;
        return;
    }

    if(head->next == NULL){  //speical case: list with only one node
        delete head;
        head = NULL;
    }
    else{	// list with two or more nodes
        Node* secondLast = head;
        while(secondLast->next->next != NULL){
            secondLast = secondLast->next;
        }
        delete secondLast->next;
        secondLast->next = NULL;
    }
}

void LinkedListInt::print () const {
    if (head == NULL) {
        cout<<"Warning! head == NULL. Nothing to print." <<endl;
        return; // check for NULL values
    }

    //list not empty
    cout << "("; // start
    Node* temp;
    temp = head;
    while (temp != NULL) { // iterate until NULL
        cout << "[" << temp->data << "]"; // print node value
        temp = temp->next;
        if (temp != NULL) cout << "->"; // print -> symbol between nodes, if there is a next one.
    }
    cout << ")\n"; // end

}

int main () {
    LinkedListInt *test = new LinkedListInt();
    test->print();

    test->insertFront(new Node(1));
    test->print();

    test->insertFront(new Node(2));
    test->print();

    test->insertFront(new Node(3));
    test->print();

    test->removeTail();
    test->print();

    test->removeTail();
    test->print();

    test->removeTail();
    test->print();




    Node *temp1 = new Node(4);
    test->insertFront(temp1);
    test->print();

    Node *temp2 = new Node(5);
    test->insertFront(temp2);
    test->print();

    delete test;

    cout<< temp1->data << endl;
    cout<< temp2->data << endl;



    return 0;
}