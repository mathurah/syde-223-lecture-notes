/*some basic operations for the class of doubly linked list*/
#include <iostream>
using namespace std;
typedef int DataType;

struct Node {
    DataType data;
    Node *prev; // a pointer pointing to the previous node in the list
    Node *next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {};
};

class DoublyLinkedList{
    Node *head = nullptr;
    Node *tail = nullptr;   // a pointer pointing to the last node in the list
    //size, omitted

public:
    void insert(DataType value, int position);
    void replace(int position, DataType value);
    void remove(int position);
    void print(); // print all elements in the list
    void printReverse(); // print all elements in the list in reverse order
    //overload destructor, omitted
    //overload copy constructor, omitted
    //overload assignment operator =, omitted

};

void DoublyLinkedList::insert(DataType value, int position) {
    //step 1. check position validity, compare with 0 and size,
    //if not valid, quit, report error, or force into a valid value
    ////omitted in this demo, assuming it is valid

    //step 2. create new node
    Node *newNode = new Node(value);

    //step 3. if special case, when position = 0
    //insert as the new head
    //3.1 when head == nullptr, or size == 0
    //the newNode will become the new head and the new tail
    //3.2 when size > 0, (position = 0)
    //insert at the head position
    //// actual code omitted


    //step 4. when size > 0, position = size
    //insert at the end of the list, the node will become the new tail
    //// actual code omitted

    //step 5. when size > 0, position > 0,  position < size
    //insert in the middle of the list
    //iterate through the list to find the position
    //with an additional pointer for the address of the previous node
    //may iterate from head to tail, in a way same as in singly linked list
    //may also iterate from tail to head.
    //alternatively, in a slightly improved version, may check if position is closer to head or tail,
    // then iterate from the closer end.
    //// actual code omitted
    Node *previous = head;
    Node *current = head->next;


    //step 6. insert the node between previous and current (assume previous is closer to head)
    // properly link prev and next pointers
    //// actual code omitted

}

void DoublyLinkedList::replace(int position, DataType value) {
    //may iterate from head to tail, in a way same as in singly linked list
    //may also iterate from tail to head.
    //alternatively, in a slightly improved version, may check if position is closer to head or tail,
    // then iterate from the closer end.

    //step 1. check position validity, compare with 0 and size,
    //if not valid, quit, report error, or force into a valid value
    ////omitted in this demo, assuming it is valid

    //step 2. iterate a pointer to the position
    //// actual code omitted

    //step 3. replace the value
    //// actual code omitted

}

void DoublyLinkedList::remove(int position) {
    //step 1. check position validity, compare with 0 and size,
    //if not valid, quit, report error, or force into a valid value
    ////omitted in this demo, assuming it is valid

    //step 2.1 special case, if position == 0, remove head
    //if this is also the tail, properly set tail pointer
    //use a temp pointer
    //properly set the pointers, don't forget setting head pointer
    //deallocate node memory
    //// actual code omitted


    //step 2.2, special case, if position == size - 1, remove tail
    //use a temp pointer
    //properly set the pointers, don't forget setting tail pointer
    //deallocate node memory
    //// actual code omitted


    //step 3. to prepare for removing a node in the middle of the list, find the pointer to the location
    //may iterate from head to tail, in a way same as in singly linked list
    //may also iterate from tail to head.
    //alternatively, in a slightly improved version, may check if position is closer to head or tail,
    // then iterate from the closer end.
    //// actual code omitted

    Node *previous = head;
    Node *current = head->next;


    //step 4. after finding the proper pointers after iteration
    // remove the node and properly link the remaining nodes.
    //// actual code omitted

}

void DoublyLinkedList::print() {
    if (head == nullptr) {
        return;
    }
    //print all nodes
    Node *temp = head;
    while (temp != nullptr) {
        cout<< temp->data << "->";
        temp = temp->next;
    }
    cout<< endl;
}

void DoublyLinkedList::printReverse() {
    if (tail == nullptr) {
        return;
    }
    //print all nodes in reverse order
    Node *temp = tail;
    while (temp != nullptr) {
        cout<< temp->data << "->";
        temp = temp->prev;
    }
    cout<< endl;
}


int main () {
    DoublyLinkedList myList;
    myList.insert(2, 0);
    myList.insert(4, 1);
    myList.insert(1, 0);
    myList.insert(5, 3);
    myList.insert(3, 2);
    myList.print();             //1->2->3->4->5->
    myList.printReverse();      //5->4->3->2->1->

    myList.remove(0);
    myList.remove(3);
    myList.remove(1);
    myList.print();             //2->4->
    myList.printReverse();      //4->2->

    return 0;
}