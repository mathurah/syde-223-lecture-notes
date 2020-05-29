#include <iostream>
using namespace std;
typedef int DataType;

struct Node {
    DataType data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {};
};

class LinkedList{
    Node *head = nullptr;
    //size, omitted

public:
    void insert(DataType value, int position);
    void replace(int position, DataType value);
    void remove(int position);
    void print(); // print all elements in the list
    //overload destructor, omitted
    //overload copy constructor, omitted
    //overload assignment operator =, omitted

};

void LinkedList::insert(DataType value, int position) {
    //step 1. check position validity, compare with 0 and size,
    //if not valid, quit, report error, or force into a valid value
    //omitted in this demo, assuming it is valid

    //step 2. create new node
    Node *newNode = new Node(value);

    //step 3. if special case, when position = 0
    //insert as the new head
    //3.1 when head == nullptr, or size == 0
    if (position == 0) {
        if (head == nullptr) {
            head = newNode;
            return;
        } else {
            //3.2 when size > 0
            newNode->next = head;
            head = newNode;
            return;
        }
    }
    //step 4. when position > 0, size > 0
    //iterate through the list to find the position
    //with an additional pointer for the address of the previous node
    Node *previous = head;
    Node *current = head->next;
    int i = 1;
    while (i < position) {
        previous = current;
        current = current->next;
        if (current == nullptr)
            break;
        i++;
    }

    //step 5. insert the node between previous and current
    newNode ->next = current;
    previous-> next = newNode;

}

void LinkedList::replace(int position, DataType value) {
    //step 1. check position validity, compare with 0 and size,
    //if not valid, quit, report error, or force into a valid value
    //omitted in this demo, assuming it is valid

    //step 2. iterate a pointer to the position
    Node *current = head;
    int i = 0;
    while (i < position){
        current = current -> next;
        if(current == nullptr)
            break; //reach the end
        i++;
    }


    //step 3. replace the value
    current -> data = value;



}

void LinkedList::remove(int position) {
    //step 1. check position validity, compare with 0 and size,
    //if not valid, quit, report error, or force into a valid value
    //omitted in this demo, assuming it is valid

    //step 2. special case, if position == 0, remove head
    if(position ==0){
        Node *temp = head;
        head = head ->next;
        delete temp;
        temp = nullptr;
        return;
    }
    //step 3. iterate a pointer to the position
    //and another pointer for the node address previous of it
    Node *previous = head;
    Node *current = head-> next;

    int i = 1;
    while (i < position){
        previous = current;
        current = current -> next;
        if(current == nullptr)
            break; //reach the end
        i++;
    }


    //step 4. remove the node and properly link the remaining nodes.
    previous -> next = current -> next;
    delete current;
    current = nullptr;
}

void LinkedList::print() {

    //return if list is empty
    if (head == nullptr) {
        return;
    }

    //print all nodes
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;

}


int main () {
    LinkedList myList;
    myList.insert(2, 0);
    myList.insert(4, 1);
    myList.insert(1, 0);
    myList.insert(5, 3);
    myList.insert(3, 2);
    myList.print();

    myList.replace(2, 33);
    myList.print();

    myList.remove(3);
    myList.remove(0);
    myList.print();

    return 0;
}