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
    queue <BinaryTreeNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        BinaryTreeNode *P = Q.front();
        Q.pop();
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