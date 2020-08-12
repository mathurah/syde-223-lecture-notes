#include<iostream>
#include<string>
#include<queue>
using namespace std;

//declaration
class BinarySearchTreeNode {
public:    //set as public for simplicity
    string value;//InfoClass info; //holds the data info
    int key;  // the key used for searching
    BinarySearchTreeNode *leftChild;  //points to left child
    BinarySearchTreeNode *rightChild; //points to right child

    BinarySearchTreeNode(int val, string str);
};


void printBFT(BinarySearchTreeNode* T); // breadth first print
void PreOrderPrint(BinarySearchTreeNode* T);  // recursive version.
void InOrderPrint(BinarySearchTreeNode* T);	// recursive version.
void PostOrderPrint(BinarySearchTreeNode* T);	// recursive version.

string Search (BinarySearchTreeNode* T, int K); //return the node with key K

// implementation
BinarySearchTreeNode::BinarySearchTreeNode(int val, string str) : key(val), value(str), leftChild(NULL),  rightChild(NULL) {
}


void printBFT(BinarySearchTreeNode* T){
    if(T == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    queue <BinarySearchTreeNode*> Q;
    Q.push(T);
    while (!Q.empty()) {
        BinarySearchTreeNode *P = Q.front();
        Q.pop();
        cout<<(P->key)<< "(" <<(P->value)   <<"), ";
        if (P->leftChild != NULL) Q.push(P->leftChild);
        if (P->rightChild != NULL) Q.push(P->rightChild);
    }
    cout << endl;
}

void PreOrderPrint(BinarySearchTreeNode* T){  // recursive version.
    if (T == NULL) return;
    cout<<(T->key)<< "(" <<(T->value)   <<"), "; // print root data or other processing
    PreOrderPrint(T->leftChild);
    PreOrderPrint(T->rightChild);
}
void InOrderPrint(BinarySearchTreeNode* T){	// recursive version.
    if (T == NULL) return;
    InOrderPrint(T->leftChild);
    cout<<(T->key)<< "(" <<(T->value)   <<"), "; // print root data or other processing
    InOrderPrint(T->rightChild);
}
void PostOrderPrint(BinarySearchTreeNode* T){	// recursive version.
    if (T == NULL) return;
    PostOrderPrint(T->leftChild);
    PostOrderPrint(T->rightChild);
    cout<<(T->key)<< "(" <<(T->value)   <<"), "; // print root data or other processing
}




string Search (BinarySearchTreeNode* T, int K){

/*  // recursive
	/////////////////////////////
	if(T == NULL) {
		return "Search failed. No such key."; 	//If T is NULL, the search has failed, so return NULL and terminate
	}

	// Compare the desired key value K with the key value of the current node KT
	if (  K == T->key ) return T->value;  //If K == KT, then return data value in T and terminate
	else if ( K < T->key) return Search( T->leftChild, K  ); //If K < KT, then continue search in the left subtree of T
	else return Search( T->rightChild, K  ); //If K > KT, then continue search in the right subtree of T
	/////////////////////////////
*/


    // iterative
    /////////////////////////////
    BinarySearchTreeNode* current_node = T;
    while (current_node != NULL) {
        if (current_node->key == K) return current_node->value;
        else if (K < current_node->key)
            current_node = current_node->leftChild;
        else current_node = current_node->rightChild;
    }
    return "Search failed. No such key.";
    /////////////////////////////
}


bool Insert(BinarySearchTreeNode **pT, BinarySearchTreeNode *N){
/////////////////////////////////
    BinarySearchTreeNode *T;
    T = *pT;

    // recursive version
    if(*pT == NULL) { //when input *pT is NULL, this is the root = NULL case, nothing in the tree.
        *pT = N; //If T is NULL, insert the node as the root of T, then return true and terminate
        //note, this is why we need the pointer to pointer **pT, to allow modification of the original root node.
        return true;
    }
    //Compare the desired key value KN with the key value of the current node KT
    if (N->key == T->key) {
        return false;  //If KN == KT, then return false and terminate
    }
    else if (N->key < T->key) {
        if(T->leftChild == NULL) {
            T->leftChild = N;
            return true;
        }
        else return Insert( &(T->leftChild),  N ); //If KN < KT, then continue insertion in the left subtree of T
    }
    else {
        if( T->rightChild == NULL) {
            T->rightChild = N;
            return true;
        }
        else return Insert( &(T->rightChild),  N ); 	//If KN > KT, then continue insertion in the right subtree of T
    }
    //may need to do size++ when this function is included in a class of BST
/////////////////////////////////
}




//main
int main(){
    BinarySearchTreeNode *root = new BinarySearchTreeNode(12, "A");
    root->leftChild = new BinarySearchTreeNode(6, "B");
    root->rightChild = new BinarySearchTreeNode(21, "C");

    root->leftChild->leftChild = new BinarySearchTreeNode(3, "D");
    root->leftChild->rightChild = new BinarySearchTreeNode(8, "E");

    root->rightChild->leftChild = new BinarySearchTreeNode(15, "F");
    root->rightChild->rightChild = new BinarySearchTreeNode(25, "G");

    root->leftChild->leftChild->rightChild = new BinarySearchTreeNode(5, "H");

    root->leftChild->rightChild->leftChild = new BinarySearchTreeNode(7, "I");
    root->leftChild->rightChild->rightChild = new BinarySearchTreeNode(10, "J");

    root->rightChild->leftChild->leftChild = new BinarySearchTreeNode(13, "K");

    root->rightChild->rightChild->leftChild = new BinarySearchTreeNode(22, "L");
    root->rightChild->rightChild->rightChild = new BinarySearchTreeNode(30, "M");

    printBFT(root);
    cout<<endl;

/*
    cout<< 18 <<" -> " <<Search(root, 18)<<endl;
    cout<< 12 <<" -> " <<Search(root, 12)<<endl;
    cout<< 15 <<" -> " <<Search(root, 15)<<endl;
    cout<< 30 <<" -> " <<Search(root, 30)<<endl;
    cout<<endl;
*/

    cout<<"(5, \"N\"): " << Insert(&root, new BinarySearchTreeNode(5, "N")  ) <<endl;
    printBFT(root);
    cout<<endl;


    cout<<"(4, \"N\"): " << Insert(&root, new BinarySearchTreeNode(4, "N")  ) <<endl;
    printBFT(root);
    PostOrderPrint(root);
    cout<<endl;

    //// extra tests
    cout<<endl;
    cout<<endl;
    BinarySearchTreeNode *root2 = NULL;
    printBFT(root2);

    cout<<"(55, \"X\"): " << Insert(&root2, new BinarySearchTreeNode(55, "X")  ) <<endl;
    printBFT(root2);
    cout<<endl;

    return 0;
}