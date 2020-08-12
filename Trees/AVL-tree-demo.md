## Header file
```cpp
#ifndef SYDE223_A3_AVL_TREE_H
#define SYDE223_A3_AVL_TREE_H
#include "binary-search-tree.h"
#include <queue>
#include <stack>
using namespace std;
class AVLTree: public BinarySearchTree
{
public:
    // Overriden insert and remove functions
    // Do not modify these definitions

    //The AVL tree should be kept balanced after calling just insert or remove.
    bool insert(DataType val);
    bool remove(DataType val);

    // Define additional functions and attributes below if you need
    stack<Node*> getStack(DataType val); //Get the address of the node contianing a given value
    int getHeight(Node* node); //Gets maximum height of tree branching from given node
    bool balanced(Node* node); //Is the passed in node balacned?
    void RightRotate(Node** ptr, Node* grandparent);
    void LeftRotate(Node** ptr, Node* grandparent);
    void LeftRightRotate(Node** ptr, Node* grandparent);
    void RightLeftRotate(Node** ptr, Node* grandparent);

//    bool initial_insert(DataType val);
//    bool initial_remove(DataType val);
};

#endif //SYDE223_A3_AVL_TREE_H
```

### CPP File
```cpp
#include "avl-tree.h";
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
typedef BinarySearchTree::Node Node; //For my convenience


stack<Node*> AVLTree::getStack(DataType val) {
    Node* current = getRootNode();
    stack<Node*> nodes;

    while (current != NULL) { //loop through nodes along path to val
        nodes.push(current); //push node to stack
        (val > current->val) ? current = current-> right : current = current-> left; //pathfind
    }

    return nodes;
}

int AVLTree::getHeight(Node* node) { //recursive function which gets the height of the node (how many nodes lie on the longest path of the subtree)
    if (node == NULL) {return 0;} //base case
    else
    {
        return 1 + std::max(getHeight(node->left), getHeight(node->right)); //recursive case
    }
}

bool AVLTree::balanced(Node* node) { //checks whether subtree at node is balanced (difference between branch heights < 2)
    if (node == NULL) {return true;}
    return abs(getHeight(node->right) - getHeight(node->left)) > 1 ? false : true;
}

bool AVLTree::remove(DataType val) //remove a value and then balance
{
    bool result = BinarySearchTree::remove(val); //initial BST remove
    Node* root = getRootNode();
    Node** address = getRootNodeAddress();
    stack<Node*> nodes;
    Node* current;
    Node* parent;
    Node* grandparent= root;

    if(result) { //if initial removal successful
        if (root == NULL) {return true;} //nothing in tree
        nodes = getStack(val);//get the stack with root at bottom and parent to removed node at top
        while (grandparent != NULL && nodes.size() > 0) { //while there's a node in the stack
            grandparent = nodes.top(); //at first set the top node to grandparent
            nodes.pop();
            if (grandparent->left == NULL && grandparent->right == NULL) {
                //since the current grandparent has no children it actually isnt a grandparent, it's a grandchild
                current = grandparent;
                if (nodes.size() > 0) { //if current has parent (i.e stack not empty), set next node in stack to top
                    parent = nodes.top();
                    nodes.pop();
                } else { //else break out of this iteration of loop
                    continue;
                }
                if (nodes.size() > 0) {//if parent has a parent, set next node in stack to grandparent
                    grandparent = nodes.top();
                } else { //else continue
                    nodes.push(parent);
                    continue;
                }
                nodes.push(parent);
                //a bunch of cases where the current grandparent is only a parent; if posiible set parent = grandparent and current = grandparent higher height child otherwise continue
            } else if (grandparent->left != NULL && grandparent->right == NULL && grandparent->left->left == NULL && grandparent->left->right == NULL) { //
                current = grandparent->left;
                parent = grandparent;
                if (nodes.size() > 0) {
                    grandparent = nodes.top();
                } else {
                    continue;
                }
            } else if (grandparent->right != NULL && grandparent->left == NULL && grandparent->right->left == NULL && grandparent->right->right == NULL) {
                current = grandparent->right;
                parent = grandparent;
                if (nodes.size() > 0) {
                    grandparent = nodes.top();
                } else {
                    continue;
                }
            }
//            else if (grandparent->left->right == NULL && grandparent->left->left == NULL && grandparent->right->left == NULL && grandparent->right->right == NULL) {
//                current = grandparent->right;
//                parent = grandparent;
//                if (nodes.size() > 0) {
//                    grandparent = nodes.top();
//                } else {
//                    break;
//                }
//            }
            parent = getHeight(grandparent->left) > getHeight(grandparent->right) ? grandparent->left : grandparent->right; //change parent to higher height child of grandparent
            current = getHeight(parent->left) > getHeight(parent->right) ? parent->left : parent->right; //change current to higher height child of parent
            if (!balanced(grandparent)) { //call appropriate rotation if grandparent unbalanced
                if (grandparent->left == parent) {
                    if (parent->left == current) {
                        RightRotate(address, grandparent);
                    } else {
                        LeftRightRotate(address, grandparent);
                    }
                } else {
                    if (parent->left == current) {
                        RightLeftRotate(address, grandparent);
                    } else {
                        LeftRotate(address, grandparent);
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool AVLTree::insert(DataType val)
{ // works like the remove im too lazy to comment this
    bool result = BinarySearchTree::insert(val);
    Node* root = getRootNode();
    Node** address = getRootNodeAddress();
    stack<Node*> nodes;
    Node* current;
    Node* parent;
    Node* grandparent = root;
    if (root->val == val) {return true;}
    if (result) {
        nodes = getStack(val);
        while (grandparent != NULL && nodes.size() > 2) {
            current = nodes.top();
            nodes.pop();
            parent = nodes.top();
            nodes.pop();
            grandparent = nodes.top();
            nodes.pop();
            if (!balanced(grandparent)) {
                if (grandparent->left == parent) {
                    if (parent->left == current) {
                        RightRotate(address, grandparent);
                    } else {
                        LeftRightRotate(address, grandparent);
                    }
                } else {
                    if (parent->left == current) {
                        RightLeftRotate(address, grandparent);
                    } else {
                        LeftRotate(address, grandparent);
                    }
                }
            }
            nodes.push(grandparent);
            nodes.push(parent);
        }

        return true;
    }
    return false;
}


void AVLTree::RightRotate(Node** ptr, Node* grandparent) {

    Node* parent = grandparent->left;
    grandparent->left = parent->right;
    parent->right = grandparent;

    //Update root if necessary
    if (*ptr == grandparent) {
        *ptr = parent;
    }
    else {
        //Let grandparents parent take parent as the new child.

        //find 	grandparent's parent
        Node* current = *ptr;
        Node **ptrGrandparent = NULL;
        do{
            if(grandparent->val > current->val)  {
                ptrGrandparent = &current->right;
                current = current->right;
            }
            else if (grandparent->val < current->val) {
                ptrGrandparent = &current->left;
                current = current->left;
            }
        } while (current->val != grandparent->val);
        *ptrGrandparent = parent;
    }
}


void AVLTree::LeftRotate(Node** ptr, Node* grandparent){

    Node *parent = grandparent->right;
    grandparent->right = parent->left;
    parent->left = grandparent;

    //Update root if necessary
    if (*ptr == grandparent) {
        *ptr = parent;
    }
    else {
        //Let grandparent's parent take parent as the new child.

        //find grandparent's parent
        Node *current = *ptr;
        Node **ptrGrandparent = NULL;
        do{
            if(grandparent->val > current->val)  {
                ptrGrandparent = &current->right;
                current = current->right;
            }
            else if (grandparent->val < current->val) {
                ptrGrandparent = &current->left;
                current = current->left;
            }
        }
        while (current->val != grandparent->val);

        *ptrGrandparent = parent;
    }
}


void AVLTree::LeftRightRotate(Node** ptr, Node* grandparent) {
    Node *parent = grandparent->left;

    //Call single left rotation with input (parent)
    LeftRotate(ptr, parent);

    //Call single right rotation with input (grandparent)
    RightRotate(ptr, grandparent);
}


void AVLTree::RightLeftRotate(Node** ptr, Node* grandparent) {

    Node *parent = grandparent->right;

    //Call single right rotation with input (parent)
    RightRotate(ptr, parent);

    //Call single left rotation with input (grandparent)
    LeftRotate(ptr, grandparent);
}
```