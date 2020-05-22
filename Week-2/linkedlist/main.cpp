/* Basic operations for a Linked List of nodes*/
#include <iostream>
using namespace std;

struct Node {
    //public members by default in struct
    int data;
    Node *next;
    Node() : data(0), next(NULL) {}; // constructor with no input argument
    Node(int x) : data(x), next(NULL) {}; // constructor with one int argument
};

int main () {
    //Initialize a list with one node.
    Node *headNode = new Node(2);


    //Add a node to the end of the list
    headNode ->next = new Node(3);



    //Add a node at the front of the list.
//    headNode = new Node(1) - we cannot do this! or else we lose tracj
        Node *temp = new Node(1);
        temp ->next = headNode;
        headNode = temp;
        temp = nullptr;



    //Print data in all three nodes.
    cout << headNode->data << ", ";
    cout << headNode->next->data <<", ";
    cout << headNode->next->next->data <<endl;
    cout << endl;

    //Remove a node.
    //remove first node.
    temp = headNode;
    headNode = headNode->next;
    delete temp;
    temp = NULL; // removing the first node

    //Print data in all two nodes.
    cout<< headNode->data <<", ";
    cout<< headNode->next->data <<endl;
    cout<<endl;


    //Remove a node.
    //remove last node.
    temp = headNode;
    Node *temp2 = NULL;
    while(temp->next != NULL){
        temp2 = temp;
        temp = temp->next;
    }
    delete temp;
    temp = NULL;
    temp2->next = NULL;


    delete temp;
    temp = NULL;
    temp2->next = NULL; //the new tail

    //Print data in the only one node.
    cout<< headNode->data <<endl;
    cout<<endl;



    return 0;
}