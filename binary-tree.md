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
```cpp
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

- **Size of Tree** (total number of nodes): 12
- **Height of Tree** (max depth of its nodes): 13
    - It is also the length of the longest path frmo the root to a leaf node (counting the edges)

