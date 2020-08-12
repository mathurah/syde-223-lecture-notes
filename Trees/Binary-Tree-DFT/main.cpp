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