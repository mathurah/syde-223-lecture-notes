#include <iostream>
#include <string>
using namespace std;

const int CAPACITY = 2000; //in this simple demo, fixed capacity is used.

// declaration and definition

class Node { // the node
public: 	//set public for simplicity
    int idNumber;
    string idName;
    string emailAddress;
    // ... ... other attributes

    Node *next;

    Node(int num, string name, string email):  idNumber(num), idName(name), emailAddress(email) , next (NULL) {};
};


class HashTable {

public:  	//set public for simplicity
    Node **table;  //to be pointed to the array of listed lists

    //in this simple demo, fixed capacity is used. size of current number of items is not tracked.

    HashTable() {
        table = new Node*[CAPACITY];

        for (int i = 0; i < CAPACITY; i++)
            table[i] = NULL;
    }


    ~HashTable() {
        for (int i = 0; i < CAPACITY; i++)
            if (table[i] != NULL) {
                Node *prevNode = NULL;
                Node *temp = table[i];
                while (temp != NULL) {
                    prevNode = temp;
                    temp = temp->next;
                    delete prevNode;
                }
            }
        delete[] table;
    }

    int hashFunction (string str){
        int length = str.length();
        int sum = 0;
        for (int i=0; i < length; i++)  sum = sum + (int)str[i];   //str[i] gets the ith char in the string

        if(sum < 0) sum = -1 * sum; //	(if sum exceeds the max int, it will become negative, then just change it to positive.)

        return sum % CAPACITY;
    }


    Node* search(string name) {

        int hashIndex = hashFunction ( name );

        if (table[hashIndex] == NULL)   return NULL;
        else {
            Node *temp = table[hashIndex];
            while (temp != NULL && temp->idName != name) temp = temp->next;
            if (temp == NULL) return NULL;
            else              return temp;
        }
    }



    void insert(int num, string name, string email) {
        if (  search (name) ) {
            cout << "cannot insert when the same key exists." << endl;
        }

        int hashIndex = hashFunction ( name );

        if (table[hashIndex] == NULL) table[hashIndex] = new Node(num, name, email);

        else {
            Node *temp = table[hashIndex];
            while (temp->next != NULL) temp = temp->next;
            temp->next = new Node(num, name, email);
        }

        // here could increase size by one and check if size is too large for adjustable capacity.
        // e.g., when size reaches 75% of capacity, double the capacity.
    }

    void remove(string name) {
        if (  search (name) == NULL ) {
            cout << "cannot remove when the key does not exist." << endl;
        }
        int hashIndex = hashFunction ( name );

        if (table[hashIndex] != NULL) {
            Node *prevNode = NULL;
            Node *temp = table[hashIndex];

            // find the target
            while (temp->idName != name && temp->next != NULL) {
                prevNode = temp;
                temp = temp->next;
            }

            // temp should be the target now.
            if (temp->idName == name) {
                if (prevNode == NULL) { //it is the first node
                    Node *nextNode = temp->next;
                    delete temp;
                    table[hashIndex] = nextNode;
                } else { // it is not the first node
                    Node *nextNode = temp->next;
                    delete temp;
                    prevNode->next = nextNode;
                }
            }
        }
        // here could do size--, and check if size is too small for adjustable capacity.
        // e.g., when size is less than 20% of capacity, reduce capacity by half.
    }

};


int main()
{
    HashTable h;

    h.insert(1000101, "jacob",  "jacob23@uw.ca");
    h.insert(2001201, "shawn",  "shawn3@uw.ca");
    h.insert(3003121, "max",  "maxmax@uw.ca");
    h.insert(3004578, "grace",  "grace2@uw.ca");
    h.insert(2001234, "andrew",  "andrew@uw.ca");
    h.insert(5201863, "peter",  "peterw2@uw.ca");
    h.insert(3005831, "emily",  "emily3@uw.ca");
    h.insert(2203234, "mary",  "mary87@uw.ca");


    cout<< h.hashFunction( "jacob" ) << endl;
    cout<< h.hashFunction( "shawn" ) << endl;
    cout<< h.hashFunction( "max" ) << endl;
    cout<< h.hashFunction( "grace" ) << endl;
    cout<< h.hashFunction( "andrew" ) << endl;
    cout<< h.hashFunction( "peter" ) << endl;
    cout<< h.hashFunction( "emily" ) << endl;
    cout<< h.hashFunction( "mary" ) << endl;

    h.insert(1000101, "jacob",  "jacob23@uw.ca");
    h.remove("jack");

    Node* result;
    result = h.search("grace");
    cout<< result->idNumber << ", "<< result->idName << ", "<<  result->emailAddress << endl;

    return 0;
}

