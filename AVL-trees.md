## AVIL Trees
- Special BST that is kept **height balanced**
- The absolute difference in heights between the left and right subtrees is **less than or equal to 1** 
    - this property holds for every node!

## AVL Insert
1. Use the regular BST Insert operation, insert new Node N
2. Find out if any of N's ancestors is unbalanced. 
    - If not, jobt done and return. 
    - If so, find out the pointer to the unbalanced ancestor that is closest to N
3. Then re-balance the AVL tree using one of the four rotations, depending on the cases
    1. Single Right
    2. Single Left
    3. Left Right
    4. Right-Left

## Single Right Rotation