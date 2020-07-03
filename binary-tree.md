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