## Introduction to Tree Data Structure
Tree is a hierarchical data structure composed of nodes connected by edges 

![](/images/tree.png)
- Each node has two children, left child and right child
- Left child's value is always smaller than the parent's value
- Right child's value is always larger than the parent's value

**Tree can support faster search**
- Search in list is `O(n)`
- Trees - worst case could be `O(log n)`

## Binary Tree
- A finite set of nodes that is either empty or it consists of a root and **two** disjoint binary treets, `Tl` and `TR`

![](/images/binary-tree.png)

### Binary Tree Demo Code
``` cpp
#include<iostream>
#include <algorithm>    // std::max
using namespace std;

//declaration
class BinaryTreeNode {
public:    //set as public for simplicity
    char iData; //holds the data value at this tree node
    BinaryTreeNode *leftChild; //points to left child
    BinaryTreeNode *rightChild; //points to right child

    BinaryTreeNode(char data);
};

class BinaryTree{
public:    //set as public for simplicity
    BinaryTreeNode *root;

    // Returns the maximum depth of the tree. A tree with only the root node has a
    // depth of 0. When tree is empty, return -1.
    int depth();

};


//////////////////////////
int Height(BinaryTreeNode *T);
//////////////////////////


// implementation
BinaryTreeNode::BinaryTreeNode(char data) : iData(data), leftChild(NULL),  rightChild(NULL) {
}

int BinaryTree::depth(){
    /////////////////////
    Height(root);
    /////////////////////
}

//////////////////////////
int Height(BinaryTreeNode *T){
    if(T == NULL) return -1;
    else if (T->leftChild == NULL && T->rightChild == NULL) return 0;
    else {
        return 1 + max(Height(T->leftChild), Height(T->rightChild) );
    }
}
//////////////////////////


//main
int main(){
    BinaryTree tree;
    tree.root = NULL;

    cout<< tree.depth() << endl;

    tree.root = new BinaryTreeNode('H');

    cout<< tree.depth() << endl;

    tree.root->leftChild = new BinaryTreeNode('D');
    tree.root->rightChild = new BinaryTreeNode('K');

    tree.root->leftChild->leftChild = new BinaryTreeNode('B');
    tree.root->leftChild->rightChild = new BinaryTreeNode('F');

    tree.root->rightChild->leftChild = new BinaryTreeNode('J');
    tree.root->rightChild->rightChild = new BinaryTreeNode('L');

    tree.root->leftChild->leftChild->leftChild = new BinaryTreeNode('A');
    tree.root->leftChild->leftChild->rightChild = new BinaryTreeNode('C');

    tree.root->leftChild->rightChild->leftChild = new BinaryTreeNode('E');
    tree.root->leftChild->rightChild->rightChild = new BinaryTreeNode('G');

    tree.root->rightChild->leftChild->leftChild = new BinaryTreeNode('I');

    cout<< tree.depth() << endl;



    return 0;
}
```

![](/images/binary-tree-example.png)

- **Size of Tree** (total number of nodes): 12
- **Height of Tree** (max depth of its nodes): 13
    - It is also the length of the longest path frmo the root to a leaf node (counting the edges)

## Some Facts of Tree
- There is only one root node for the entire tree strucuture
- Each node has at once parent node. 
    - The root node has no parent
    - Other nodes must have one parent
- In a general tree, each node can have zero or more nodes as its children. 
- In binary tree, each node has at most two children
- If a node is not a root node, nor a leaf node, it must be a branch node
- If considering a branch node or a leaf node as the root node, then it starts a smaller tree (sub-tree)
- The root node is the ancestor of all the other nodes

## Binary Tree Traversal
- Print all the data, search for the existence of a value
    - Breadth-first
    - Depth-first
## Breadth-First Traversals (BFT)
- Also known as **level-based traversal**
- All nodes at level 0 are visited first
    - Then the nodes at level 1 are visited
    - Then the nodes at level 2 are visited
    ...
    - Finally, the nodes at the maximum level (tree height) are visited

Print output: everything in order

### Demo Code: BFT Traversal
``` cpp
#include<iostream>
#include<queue>

using namespace std;

//declaration
class BinaryTreeNode {
public:    //set as public for simplicity
    char iData; //holds the data value at this tree node
    BinaryTreeNode *leftChild; //points to left child
    BinaryTreeNode *rightChild; //points to right child

    BinaryTreeNode(char data);
};

class BinaryTree{
public:    //set as public for simplicity
    BinaryTreeNode *root;

    // print all data values using Breadth-First Traversals (BFT)
    void printBFT();

};


// implementation
BinaryTreeNode::BinaryTreeNode(char data) : iData(data), leftChild(NULL),  rightChild(NULL) {
}

void BinaryTree::printBFT(){
    /////////////////////
    if(root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    queue <BinaryTreeNode*> Q; //stores binary tree node pointers
    Q.push(root);
    while (!Q.empty()) {
        BinaryTreeNode *P = Q.front(); //peek - storing the root node pointer now
        Q.pop(); //remove front node without returning it, equivalent to dequeue
        cout<< P->iData<<", ";
        if (P->leftChild != NULL) Q.push(P->leftChild);
        if (P->rightChild != NULL) Q.push(P->rightChild);
    }
    cout << endl;
    /////////////////////
}



//main
int main(){
    BinaryTree tree;
    tree.root = NULL;

    tree.printBFT();

    tree.root = new BinaryTreeNode('H');

    tree.printBFT();

    tree.root->leftChild = new BinaryTreeNode('D');
    tree.root->rightChild = new BinaryTreeNode('K');

    tree.root->leftChild->leftChild = new BinaryTreeNode('B');
    tree.root->leftChild->rightChild = new BinaryTreeNode('F');

    tree.root->rightChild->leftChild = new BinaryTreeNode('J');
    tree.root->rightChild->rightChild = new BinaryTreeNode('L');

    tree.root->leftChild->leftChild->leftChild = new BinaryTreeNode('A');
    tree.root->leftChild->leftChild->rightChild = new BinaryTreeNode('C');

    tree.root->leftChild->rightChild->leftChild = new BinaryTreeNode('E');
    tree.root->leftChild->rightChild->rightChild = new BinaryTreeNode('G');

    tree.root->rightChild->leftChild->leftChild = new BinaryTreeNode('I');

    tree.printBFT();


    return 0;
}
```

## Depth-First Traversals (DFT)
Three options to traverse 
![](/images/binary-tree-example.png)


**Pre-order**: Visit root, visit left subtree, and then visit right subtree 

`H D B A C F E G K J I L`

**In Order Traversal**: Visit ;eft subtree, visit root, and then visit right subtree

`A B C D E F G H I J K L`

**Post Order Traversal**: Visit left subtree, vist right subtree, and then visit root

`A C B E G F S I J L K H`


### Depth-First-Traversal Demo
```cpp
#include<iostream>
#include<stack>

using namespace std;

//declaration
class BinaryTreeNode {
public:    //set as public for simplicity
    char iData; //holds the data value at this tree node
    BinaryTreeNode *leftChild; //points to left child
    BinaryTreeNode *rightChild; //points to right child

    BinaryTreeNode(char data);
};

class BinaryTree{
public:    //set as public for simplicity
    BinaryTreeNode *root;

    // print all data values using Depth-First Traversals (DFT)
    void printDFT(); //this is the iterative version using stack.

};

void PreOrderPrint(BinaryTreeNode* T);  // recursive version.
void InOrderPrint(BinaryTreeNode* T);	// recursive version.
void PostOrderPrint(BinaryTreeNode* T);	// recursive version.

// implementation
BinaryTreeNode::BinaryTreeNode(char data) : iData(data), leftChild(NULL),  rightChild(NULL) {
}

void PreOrderPrint(BinaryTreeNode* T){  // recursive version.
/////////////////////////
    if (T == NULL) return;
    cout<<(T->iData)<<", "; // print root data or other processing
    PreOrderPrint(T->leftChild);
    PreOrderPrint(T->rightChild);
/////////////////////////
}
void InOrderPrint(BinaryTreeNode* T){	// recursive version.
/////////////////////////
    if (T == NULL) return;
    InOrderPrint(T->leftChild);
    cout<<(T->iData)<<", "; // print root data or other processing
    InOrderPrint(T->rightChild);
/////////////////////////
}
void PostOrderPrint(BinaryTreeNode* T){	// recursive version.
/////////////////////////
    if (T == NULL) return;
    PostOrderPrint(T->leftChild);
    PostOrderPrint(T->rightChild);
    cout<<(T->iData)<<", ";  // print root data or other processing
/////////////////////////
}


void BinaryTree::printDFT(){
    //this is the iterative version using stack.
    /////////////////////
    if(root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    stack<BinaryTreeNode *> S;
    S.push(root);
    while (S.empty() == false) {
        BinaryTreeNode *P = S.top();
        S.pop();
        cout<<(P->iData)<<", "; // print root data or other processing
        if (P->rightChild != NULL) S.push(P->rightChild);
        if (P->leftChild != NULL) S.push(P->leftChild);
    }
    cout << endl;
    /////////////////////
}



//main
int main(){
    BinaryTree tree;
    tree.root = NULL;

    tree.root = new BinaryTreeNode('H');

    tree.root->leftChild = new BinaryTreeNode('D');
    tree.root->rightChild = new BinaryTreeNode('K');

    tree.root->leftChild->leftChild = new BinaryTreeNode('B');
    tree.root->leftChild->rightChild = new BinaryTreeNode('F');

    tree.root->rightChild->leftChild = new BinaryTreeNode('J');
    tree.root->rightChild->rightChild = new BinaryTreeNode('L');

    tree.root->leftChild->leftChild->leftChild = new BinaryTreeNode('A');
    tree.root->leftChild->leftChild->rightChild = new BinaryTreeNode('C');

    tree.root->leftChild->rightChild->leftChild = new BinaryTreeNode('E');
    tree.root->leftChild->rightChild->rightChild = new BinaryTreeNode('G');

    tree.root->rightChild->leftChild->leftChild = new BinaryTreeNode('I');

    PreOrderPrint(tree.root);
    cout<<endl;

    InOrderPrint(tree.root);
    cout<<endl;

    PostOrderPrint(tree.root);
    cout<<endl;

    tree.printDFT();


    return 0;
}
```


### Pre Order Traversal Using Stack (non) recursive
- Algorithm: PreOrder Using Stack (iterative
- Input: Binary Tree Node
- Output: Preorder traversal of the tree order data
``` cpp
void PreOrderUsingStack (BinaryTreeNode *T) {

  Stack S;

  S.push(T);

  while (!S.isEmpty()) {

     BinaryTreeNode *P = S.pop();

  Visit(P->data); // print root data or other processing

  if (P->rightChild != NULL) S.push(P->rightChild);

  if (P->leftChild != NULL) S.push(P->leftChild);

  }

}
```

## Binary Search Tree (BST)
- A binary tree
- Each node has a key value K (ex. student ID)
- For each node, all keys in its left subtree are smaller than the node's key value
- For each node, all keys in its right subtree are larger than the node's key value
![](/images/binary-search-tree-K.png)

### Binary Search Tree Implementation
```cpp
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

 // recursive
	/////////////////////////////
	if(T == NULL) {
		return "Search failed. No such key."; 	//If T is NULL, the search has failed, so return NULL and terminate
	}

	// Compare the desired key value K with the key value of the current node KT
	if (  K == T->key ) return T->value;  //If K == KT, then return data value in T and terminate
	else if ( K < T->key) return Search( T->leftChild, K  ); //If K < KT, then continue search in the left subtree of T
	else return Search( T->rightChild, K  ); //If K > KT, then continue search in the right subtree of T
	/////////////////////////////


/*
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

    */
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
    PreOrderPrint(root);
    cout<<endl;

    InOrderPrint(root);
    cout<<endl;

    PostOrderPrint(root);
    cout<<endl;
    */

    cout<< 18 <<" -> " <<Search(root, 18)<<endl;
    cout<< 12 <<" -> " <<Search(root, 12)<<endl;
    cout<< 15 <<" -> " <<Search(root, 15)<<endl;
    cout<< 30 <<" -> " <<Search(root, 30)<<endl;

    return 0;
}
```

## Searching Using BST (Recursive)
```cpp
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

 // recursive
	/////////////////////////////
	if(T == NULL) {
		return "Search failed. No such key."; 	//If T is NULL, the search has failed, so return NULL and terminate
	}

	// Compare the desired key value K with the key value of the current node KT
	if (  K == T->key ) return T->value;  //If K == KT, then return data value in T and terminate
	else if ( K < T->key) return Search( T->leftChild, K  ); //If K < KT, then continue search in the left subtree of T
	else return Search( T->rightChild, K  ); //If K > KT, then continue search in the right subtree of T
	/////////////////////////////


/*
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

    */
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
    PreOrderPrint(root);
    cout<<endl;

    InOrderPrint(root);
    cout<<endl;

    PostOrderPrint(root);
    cout<<endl;
    */

    cout<< 18 <<" -> " <<Search(root, 18)<<endl;
    cout<< 12 <<" -> " <<Search(root, 12)<<endl;
    cout<< 15 <<" -> " <<Search(root, 15)<<endl;
    cout<< 30 <<" -> " <<Search(root, 30)<<endl;

    return 0;
}
```
## Searching Using BST (Recursive)
```cpp
BSTNodeInfo Search(BSTNODE *T, int K)
```
- If `T` is `NULL` ths search has failed, so return `NULL` and terminate
- Compare the desired key value `K` with the key value of the current node `Kt`
- If `K == Kt` then return T node info and terminante
- If `K < Kt` then return T node info and terminante
- If `K > Kt`, then contnue search in the right subtree of T

## Searching Using BST (Iterative)
```cpp
Search(T, K)
```
- **Input**: BST node `T`, key value `K`
- **Output**: If a node with key value `K` is foundm return the node info; otherwise, return `NULL`

```cpp
BSTNodeInfo Search(T, K){
    current_node = T; 
    while(current_node is not NULL){
        if (current_node.key ==  K) return current_node info
        else if  (key < current_node.key)
            current_node = current_node.left
        else (key > current_node.key)
            current_node = current_node.right

    }
    return nothing found
}
```

## Inserting Nodes into BST
```cpp
bool Insert(BSTNode **pT, BSTNode *N)
```
- If `T` is `NULL`, insert the node as the root of `T`, then return `true` and terminate
- Compare the desired value `KN` with the key value of the current node `KT`
- If `KN == KT`, then return false and terminate
- If `KN < KT` then continue insertion in the left subtree of T
- If `KN > KT`, then continue insertion in the right subtree of T

### Demo Code, Binary Seart Tree: Insert
```cpp
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
```

## Deleting a Node from BST
```cpp
bool Delete(BSTNode **pT, key of BSTNode D:)
```
- Find `D` in `T` (similar to Search)
- If `D` cannot be found, return `false`
- If `D` is **found**, do the following: 
    1. If D is in a leaf node in T(no child), remove it, return `true` and terminante
    2. If D has **only one** child, cut D from the tree, and link D's parent directly to D's only child
    3. If D has **two child nodes**, replace the valeus with the predecessor (or successor), delete the predecessor (or successor) respectively, and then return true and terminate
        - **Predecessor:** Maximum value in the left subtree
        - **Sucessor*: Smallest value in the right subtree

### Demo: Binary Search Tree - Delete
```cpp
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



bool Delete(BinarySearchTreeNode **pT, int K){
/////////////////////////////////
    BinarySearchTreeNode *T;
    T = *pT;

    //Find D in T (similar to Search)
    BinarySearchTreeNode* current_node = T;
    BinarySearchTreeNode* parent_node = NULL;
    bool isLeftChild = false;
    bool found = false;
    while (current_node != NULL) {
        if (current_node->key == K) {
            found = true;
            break;
        }
        else if (K < current_node->key){
            parent_node = current_node;
            current_node = current_node->leftChild;
            isLeftChild = true;
        }
        else {
            parent_node = current_node;
            current_node = current_node->rightChild;
            isLeftChild = false;
        }
    }

    //If D cannot be found, return false
    if(found == false) return false;

    //If D is found, then do the following:
    //If D is a leaf node in T (no child), remove it, then return true and terminate
    if(current_node->leftChild == NULL && current_node->rightChild == NULL ){
        //a special case it that if current_node is the root node
        if(current_node == T){
            delete *pT;
            *pT = NULL;
            return true;
        }

        //if it is not the root node.
        delete current_node;
        if(isLeftChild) parent_node->leftChild = NULL;
        else parent_node->rightChild = NULL;
        return true;
    }



    //If D has only one child node, cut D from the tree, and link D's parent directly to D's only child.
    if(current_node->leftChild != NULL && current_node->rightChild == NULL){ // left child is not empty, right child is empty
        if(isLeftChild) parent_node->leftChild = current_node->leftChild;
        else parent_node->rightChild = current_node->leftChild;
        delete current_node;
        return true;
    }
    else if (current_node->leftChild == NULL && current_node->rightChild != NULL) { // right child is not empty, left child is empty
        if(isLeftChild) parent_node->leftChild = current_node->rightChild;
        else parent_node->rightChild = current_node->rightChild;
        delete current_node;
        return true;
    }
/*	//alternatively, in this way, we don't need the parent node pointer
	//If D has only one child node, swap with the child node, delete the child node, then return true and terminate
	if(current_node->leftChild != NULL && current_node->rightChild == NULL){ // left child is not empty, right child is empty
		current_node->key = current_node->leftChild->key;
		current_node->value = current_node->leftChild->value;
		BinarySearchTreeNode *temp = current_node->leftChild;
		current_node->leftChild = temp->leftChild;
		current_node->rightChild = temp->rightChild;
		delete temp;
		return true;
	}
	else if (current_node->leftChild == NULL && current_node->rightChild != NULL) { // right child is not empty, left child is empty
		current_node->key = current_node->rightChild->key;
		current_node->value = current_node->rightChild->value;
		BinarySearchTreeNode *temp = current_node->rightChild;
		current_node->leftChild = temp->leftChild;
		current_node->rightChild = temp->rightChild;
		delete temp;
		return true;
	}
*/




    //If D has two child nodes, swap the values with the predecessor (or successor), delete the predecessor (or successor) respectively, and then return true and terminate
    if(current_node->leftChild != NULL && current_node->rightChild != NULL ){
        //Successor is the smallest value in the right subtree
        //find successor
        BinarySearchTreeNode *successor = current_node->rightChild;
        isLeftChild = false;  // at the first step, successor is the right child of its parent.

        BinarySearchTreeNode *successor_parent = current_node;

        while(successor->leftChild != NULL){
            successor_parent = successor;
            successor = successor->leftChild;
            isLeftChild = true;
        }

        current_node->key = successor->key;
        current_node->value = successor->value;


        //here, in fact, should also check if successor is a leaf node or a branch node with only one child.
        // successor must have leftchild empty; because if it is not empty, should have used the leftchild as successor

        //if it is the leaf node
        if(successor->rightChild == NULL ){
            if(isLeftChild)	successor_parent->leftChild = NULL;
            else 			successor_parent->rightChild = NULL;
        }
        else {  //if it is the branch node. its right child is not empty
            if(isLeftChild)	successor_parent->leftChild = successor->rightChild;
            else 			successor_parent->rightChild = successor->rightChild;

        }
        delete successor;
        return true;
    }


    //may need to do size-- when this function is included in a class

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

    cout<<"insert (5, \"N\"): " << Insert(&root, new BinarySearchTreeNode(5, "N")  ) <<endl;
    printBFT(root);
    cout<<endl;


    cout<<"insert (4, \"N\"): " << Insert(&root, new BinarySearchTreeNode(4, "N")  ) <<endl;
    printBFT(root);
    PostOrderPrint(root);
    cout<<endl;
    cout<<endl;



    cout<<"delete tests" << endl;
    InOrderPrint(root);
    cout<<endl;
    cout<<"delete 7: " << Delete(&root, 7)  <<endl;
    InOrderPrint(root);
    cout<<endl;

    cout<<"delete 3: " << Delete(&root, 3)  <<endl;
    InOrderPrint(root);
    cout<<endl;

    cout<<"delete 21: " << Delete(&root, 21)  <<endl;
    InOrderPrint(root);
    cout<<endl;

    cout<<"delete 21: " << Delete(&root, 21)  <<endl;
    InOrderPrint(root);
    cout<<endl;

    cout<<"delete 22: " << Delete(&root, 22)  <<endl;
    InOrderPrint(root);
    cout<<endl;

    cout<<"delete 25: " << Delete(&root, 25)  <<endl;
    InOrderPrint(root);
    cout<<endl;

    cout<<"delete 30: " << Delete(&root, 30)  <<endl;
    InOrderPrint(root);
    cout<<endl;


    cout<<endl;
    cout<<endl;

    BinarySearchTreeNode *root1 = NULL;

    cout<<"(1, \"a\"): " << Insert(&root1, new BinarySearchTreeNode(1, "a")  ) <<endl;
    InOrderPrint(root1);
    cout<<endl;

    cout<<"delete 1: " << Delete(&root1, 1)  <<endl;
    InOrderPrint(root1);
    cout<<endl;




    return 0;
}
```

## BST: Balance
**Balanced**: The absolute difference in heights between the left and right subtrees is **less than or equal to 1**


## BST Time Complexity
- Search, Insert and Delete: `O(height)`
- When both left subtree and right subtree are in a balanced shape - time complexity is `O(log n)`
- Worst case time complexity: `O(n)`


