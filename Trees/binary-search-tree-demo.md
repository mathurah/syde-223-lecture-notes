## Header File
```cpp
#ifndef SYDE223_A3_BINARY_SEARCH_TREE_H
#define SYDE223_A3_BINARY_SEARCH_TREE_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>

using std::vector;
using std::string;
using std::cout;

class BinarySearchTree {
public:
    // Can be seen externally as BinarySearchTree::DataType
    typedef int DataType;

    struct Node {
        // Sets the left and right children to NULL, and initializes val.
        Node(DataType newval);

        DataType val;  // Value of the node.
        Node* left;    // Pointer to the left node.
        Node* right;   // Pointer to the right node.
        int avlBalance;   // you may or may not use it for AVL trees (optional)
    };



private:
    friend class BinarySearchTreeTest;
    friend class AVLTreeTest;

    // Optional function that recursively gets the maximum depth for a given node.
    int getNodeDepth(Node* n) const;

    // Pointer to the root node of the tree.
    Node* root_;

    // Number of nodes in the tree.
    unsigned int size_;

    // Sets copy constructor and assignment operator to private.
    BinarySearchTree(const BinarySearchTree& other) {}
    BinarySearchTree& operator=(const BinarySearchTree& other) {}

public:
    // Default constructor to initialize the root.
    BinarySearchTree();
    // Destructor of the class BinarySearchTree. It deallocates the memory
    // space allocated for the binary search tree.
    ~BinarySearchTree();

    // Returns the number of nodes in the tree.
    unsigned int size() const;
    // Returns the maximum value of a node in the tree. You can assume that
    // this function will never be called on an empty tree.
    DataType max() const;
    // Returns the minimum value of a node in the tree. You can assume that
    // this function will never be called on an empty tree.
    DataType min() const;
    // Returns the maximum depth of the tree. A tree with only the root node has a
    // depth of 0. You can assume that this function will never be called on an
    // empty tree.
    unsigned int depth() const;
    // You can print the tree in whatever order you prefer. However, methods such
    // as in-order or level-order traversal could be the most useful for debugging.
    void print() const;
    // Returns true if a node with the value val exists in the tree; otherwise,
    // it returns false.
    bool exists(DataType val) const;
    // Returns a pointer to the root node
    Node* getRootNode();
    // Returns the root node pointer address
    Node** getRootNodeAddress();

    // Inserts the value val into the tree. Returns false if val already exists in
    // the tree, and true otherwise.
    bool insert(DataType val);
    // Removes the node with the value val from the tree. Returns true if successful,
    // and false otherwise.
    bool remove(DataType val);
    // Update the avlBalance starting at node n (optional)
    void updateNodeBalance(Node* n);

    struct cell_display {
        string   valstr;
        bool     present;
        cell_display() : present(false) {}
        cell_display(std::string valstr) : valstr(valstr), present(true) {}
    };

    using display_rows = vector< vector< cell_display > >;

    // The text tree generation code below is all iterative, to avoid stack faults.

    // get_row_display builds a vector of vectors of cell_display structs
    // each vector of cell_display structs represents one row, starting at the root
    display_rows get_row_display() const {
        // start off by traversing the tree to
        // build a vector of vectors of Node pointers
        vector<Node*> traversal_stack;
        vector< std::vector<Node*> > rows;
        if(!root_) return display_rows();

        Node *p = root_;
        const int max_depth = depth() + 1;
        rows.resize(max_depth);
        int depth = 0;
        for(;;) {
            // Max-depth Nodes are always a leaf or null
            // This special case blocks deeper traversal
            if(depth == max_depth-1) {
                rows[depth].push_back(p);
                if(depth == 0) break;
                --depth;
                continue;
            }

            // First visit to node?  Go to left child.
            if(traversal_stack.size() == depth) {
                rows[depth].push_back(p);
                traversal_stack.push_back(p);
                if(p) p = p->left;
                ++depth;
                continue;
            }

            // Odd child count? Go to right child.
            if(rows[depth+1].size() % 2) {
                p = traversal_stack.back();
                if(p) p = p->right;
                ++depth;
                continue;
            }

            // Time to leave if we get here

            // Exit loop if this is the root
            if(depth == 0) break;

            traversal_stack.pop_back();
            p = traversal_stack.back();
            --depth;
        }

        // Use rows of Node pointers to populate rows of cell_display structs.
        // All possible slots in the tree get a cell_display struct,
        // so if there is no actual Node at a struct's location,
        // its boolean "present" field is set to false.
        // The struct also contains a string representation of
        // its Node's value, created using a std::stringstream object.
        display_rows rows_disp;
        std::stringstream ss;
        for(const auto& row : rows) {
            rows_disp.emplace_back();
            for(Node* pn : row) {
                if(pn) {
                    ss << pn->val;
                    rows_disp.back().push_back(cell_display(ss.str()));
                    ss = std::stringstream();
                } else {
                    rows_disp.back().push_back(cell_display());
                }   }   }
        return rows_disp;
    }

    // row_formatter takes the vector of rows of cell_display structs
    // generated by get_row_display and formats it into a test representation
    // as a vector of strings
    vector<string> row_formatter(const display_rows& rows_disp) const {
        using s_t = string::size_type;

        // First find the maximum value string length and put it in cell_width
        s_t cell_width = 0;
        for(const auto& row_disp : rows_disp) {
            for(const auto& cd : row_disp) {
                if(cd.present && cd.valstr.length() > cell_width) {
                    cell_width = cd.valstr.length();
                }   }   }

        // make sure the cell_width is an odd number
        if(cell_width % 2 == 0) ++cell_width;

        // formatted_rows will hold the results
        vector<string> formatted_rows;

        // some of these counting variables are related,
        // so its should be possible to eliminate some of them.
        s_t row_count = rows_disp.size();

        // this row's element count, a power of two
        s_t row_elem_count = 1 << (row_count-1);

        // left_pad holds the number of space charactes at the beginning of the bottom row
        s_t left_pad = 0;

        // Work from the level of maximum depth, up to the root
        // ("formatted_rows" will need to be reversed when done)
        for(s_t r=0; r<row_count; ++r) {
            const auto& cd_row = rows_disp[row_count-r-1]; // r reverse-indexes the row
            // "space" will be the number of rows of slashes needed to get
            // from this row to the next.  It is also used to determine other
            // text offsets.
            s_t space = (s_t(1) << r) * (cell_width + 1) / 2 - 1;
            // "row" holds the line of text currently being assembled
            string row;
            // iterate over each element in this row
            for(s_t c=0; c<row_elem_count; ++c) {
                // add padding, more when this is not the leftmost element
                row += string(c ? left_pad*2+1 : left_pad, ' ');
                if(cd_row[c].present) {
                    // This position corresponds to an existing Node
                    const string& valstr = cd_row[c].valstr;
                    // Try to pad the left and right sides of the value string
                    // with the same number of spaces.  If padding requires an
                    // odd number of spaces, right-sided children get the longer
                    // padding on the right side, while left-sided children
                    // get it on the left side.
                    s_t long_padding = cell_width - valstr.length();
                    s_t short_padding = long_padding / 2;
                    long_padding -= short_padding;
                    row += string(c%2 ? short_padding : long_padding, ' ');
                    row += valstr;
                    row += string(c%2 ? long_padding : short_padding, ' ');
                } else {
                    // This position is empty, Nodeless...
                    row += string(cell_width, ' ');
                }
            }
            // A row of spaced-apart value strings is ready, add it to the result vector
            formatted_rows.push_back(row);

            // The root has been added, so this loop is finsished
            if(row_elem_count == 1) break;

            // Add rows of forward- and back- slash characters, spaced apart
            // to "connect" two rows' Node value strings.
            // The "space" variable counts the number of rows needed here.
            s_t left_space  = space + 1;
            s_t right_space = space - 1;
            for(s_t sr=0; sr<space; ++sr) {
                string row;
                for(s_t c=0; c<row_elem_count; ++c) {
                    if(c % 2 == 0) {
                        row += string(c ? left_space*2 + 1 : left_space, ' ');
                        row += cd_row[c].present ? '/' : ' ';
                        row += string(right_space + 1, ' ');
                    } else {
                        row += string(right_space, ' ');
                        row += cd_row[c].present ? '\\' : ' ';
                    }
                }
                formatted_rows.push_back(row);
                ++left_space;
                --right_space;
            }
            left_pad += space + 1;
            row_elem_count /= 2;
        }

        // Reverse the result, placing the root node at the beginning (top)
        std::reverse(formatted_rows.begin(), formatted_rows.end());

        return formatted_rows;
    }

    // Trims an equal number of space characters from
    // the beginning of each string in the vector.
    // At least one string in the vector will end up beginning
    // with no space characters.
    static void trim_rows_left(vector<string>& rows) {
        if(!rows.size()) return;
        auto min_space = rows.front().length();
        for(const auto& row : rows) {
            auto i = row.find_first_not_of(' ');
            if(i==string::npos) i = row.length();
            if(i == 0) return;
            if(i < min_space) min_space = i;
        }
        for(auto& row : rows) {
            row.erase(0, min_space);
        }   }

    // Dumps a representation of the tree to cout
    void Dump() const {
        const int d = depth() + 1;

        // If this tree is empty, tell someone
        if(d == 0) {
            cout << " <empty tree>\n";
            return;
        }

        // This tree is not empty, so get a list of node values...
        const auto rows_disp = get_row_display();
        // then format these into a text representation...
        auto formatted_rows = row_formatter(rows_disp);
        // then trim excess space characters from the left sides of the text...
        trim_rows_left(formatted_rows);
        // then dump the text to cout.
        for(const auto& row : formatted_rows) {
            std::cout << ' ' << row << '\n';
        }
    }
};

#endif //SYDE223_A3_BINARY_SEARCH_TREE_H
```

## CPP File
```cpp
#include "binary-search-tree.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;

BinarySearchTree::Node::Node(DataType newval)
{
    left = NULL;
    right = NULL;
    val = newval;
}

int BinarySearchTree::getNodeDepth(Node* n) const
{
    //if the root does not exist, return 0
    if (!root_)
        return 0;

    int depth = -1;


    queue<BinarySearchTree::Node*> queue_nodes;
    queue_nodes.push(root_);
    //checks if node_queue (which stores the next level) is empty
    while (!queue_nodes.empty()) {
        unsigned long size = queue_nodes.size();
        //loops for an entire
        while (size--) {
            BinarySearchTree::Node* cur_node = queue_nodes.front();
            queue_nodes.pop();
            //adds to queue to prep for new level
            if (cur_node->left)
                queue_nodes.push(cur_node->left);
            if (cur_node->right)
                queue_nodes.push(cur_node->right);
        }
        //increments height when a "level" of the tree is complete
        ++depth;
    }

    return depth;

}
 
/*
int BinarySearchTree::getNodeDepth(Node* n) const
{
    //starting value is 0
    int depth = 0;
    //on an empty tree
    if (n == NULL)
    {
        depth = - 1;
        return  depth;
    }
    else if (n->left == NULL && n->right == NULL)
    {
        depth = 0;
        return 0;
    }

    else
    {
        //traverse through all the levels
        depth= 1 + std::max(getNodeDepth(n->left), getNodeDepth(n->right));
        return depth;
    }


}
*/

BinarySearchTree::BinarySearchTree()
{
    size_ = 0;
    root_ = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    if (!root_)
        return;

    // Goes through every node
    queue<BinarySearchTree::Node*> queue_nodes;
    queue_nodes.push(root_);
    while (!queue_nodes.empty()) {
        BinarySearchTree::Node* cur_node = queue_nodes.front();
        queue_nodes.pop();
        if (cur_node->left)
            queue_nodes.push(cur_node->left);
        if (cur_node->right)
            queue_nodes.push(cur_node->right);
        delete cur_node;
    }

}


unsigned int BinarySearchTree::size() const
{
    return size_;
}

BinarySearchTree::DataType BinarySearchTree::max() const
{
    if (root_ == NULL)
    {
        return -1;

    }

    Node* parent = root_;
    // for max always traverse right find the last node
    while (parent->right)
    {
        parent = parent->right;

    }

    return parent->val;
}


BinarySearchTree::DataType BinarySearchTree::min() const
{
    if (root_ == NULL)
    {
        return -1;

    }
    else
    {
        Node* parent = root_;
        // for max always traverse left find the last node
        while (parent->left)
        {
            parent = parent->left;

        }

        return parent->val;

    }

}


unsigned int BinarySearchTree::depth() const
{
    return  getNodeDepth(root_);
}

void BinarySearchTree::print() const
{
    Node* current = root_;
    Node* prev;

    while (current != NULL) {
        if (current->left == NULL) {
            cout << current->val << " ";
            current = current->right;
        } else {
            prev = current->left;
            while (prev->right != NULL && prev->right != current) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = current;
                current = current->left;
            } else {
                prev->right = NULL;
                cout << current->val << " ";
                current = current->right;
            }
        }
    }
    cout << endl;
}

bool BinarySearchTree::exists(DataType val) const
{
    if (!root_)
        return false;

    Node* parent = root_;

    while (parent != NULL) {
        if (val == parent->val)
            return true;
        if (val < parent->val)
            parent = parent->left;
        else
            parent = parent->right;
    }
    return false;

}


BinarySearchTree::Node* BinarySearchTree::getRootNode()
{
    return root_;
}

BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress()
{
    return &root_;
}
bool BinarySearchTree::insert(DataType val)
{
    size_++;
    if (root_ == NULL) {root_ = new Node(val); return true;}
    Node* current = root_;
    Node* prev;
    while (current != NULL) {
        if (current->val == val) {return false;}
        prev = current;
        current = (val > current->val) ? current-> right : current-> left;
    }
    (val > prev->val) ? prev->right = new Node(val) : prev->left = new Node(val);
    return true;
}

//General cases to consider for remove:
/*
Deleting a node without any child: simply delete it;
Deleting a node with one child: delete it and replace it with its child;
Deleting a node with two child: delete it and replace is with its predecessor.
bool BinarySearchTree::remove(DataType val)
*/

bool BinarySearchTree::remove(DataType val)

{
    // case 1: deleting a node without any child, delete it
    if (root_ == NULL)
    {
        return false;
    }

    //case 2: deleting a node with one child: delete it and replace it with its child
    Node* parent_node = root_;
    Node* previous_node = NULL;
    Node* replace = NULL;
    Node* grandparent = NULL;
    while (parent_node) {
        if (parent_node->val != val) {
            previous_node = parent_node;
            if(val > parent_node->val) {
                parent_node = parent_node -> right;
            }
            else {
                parent_node = parent_node->left;
            }
        }
         else {
            size_--;
            if (previous_node == NULL) {
                if (root_->left == NULL) {
                    root_ = root_->right;
                } else if (root_->right == NULL) {
                    root_ = root_->left;
                } else {
                    replace = parent_node->left;
                    while (replace->right != NULL) {
                        grandparent = replace;
                        replace = replace->right;
                    }
                    root_ = replace;
                    if (grandparent != NULL)
                    {
                        grandparent->right = replace->left;
                    }
                    if (parent_node->left != replace)
                    {
                        replace->left = parent_node->left;
                    }
                    replace->right = parent_node->right;

                }
                parent_node = NULL;
                delete parent_node;

            } else if (parent_node->right == NULL || parent_node->left == NULL) {
                if (previous_node->left == parent_node) {
                    if(parent_node->right==NULL) {
                        previous_node->left = parent_node->left;
                    }
                    else {
                        previous_node->left = parent_node->right;
                    }
                } else {
                    if(parent_node->right==NULL) {
                        previous_node->right = parent_node->left;
                    }
                    else{
                        previous_node->right = parent_node->right;
                    }
                }

                parent_node = NULL;
                delete parent_node;
            } else {
                replace = parent_node->left;
                while (replace->right != NULL) {
                    grandparent = replace;
                    replace = replace->right;
                }
                if (grandparent != NULL) {
                    grandparent->right = replace->left;
                }
                if(previous_node->right == parent_node) {
                    previous_node->right = replace;
                }
                else {
                    previous_node->left = replace;
                }
                if (parent_node->left != replace) {
                    replace->left = parent_node->left;}
                replace->right = parent_node->right;
                parent_node = NULL;
            }
            return true;
        }
    }
    return false;
}
```