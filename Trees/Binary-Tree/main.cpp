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