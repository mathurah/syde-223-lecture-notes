#include <iostream>
using namespace std;

void HeapSort(int A[], int size);
void ReheapDown(int elements[], int size, int index);
int Dequeue(int elements[], int size);


void ReheapDown(int elements[], int size, int index){  // with the array as an input, and with root index = 0
    ////////////////////////////////////////////////////////////////////
    //Or until reaching a leaf node (the bottom)
    if (2 * index + 2 > size) return;

    //	If there is any child of the new root,
    int chooseChild;

    // only one child, it must be the left child
    if (2 * index + 2 == size) chooseChild = 2 * index + 1;
    else { // two children, find the larger child. If same, e.g., prefer left.
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        if( elements[leftChild] >= elements[rightChild] ) chooseChild = leftChild;
        else chooseChild = rightChild;
    }


    if(elements[chooseChild] >= elements[index]){
        //If the child has a key larger than the node or same as the node, swap the node with that child.

        int temp = elements[chooseChild];
        elements[chooseChild] = elements[index];
        elements[index] = temp;

        ReheapDown(elements, size, chooseChild); //Continue re-heap downwards
    }

    //until that child is smaller.
    ////////////////////////////////////////////////////////////////////

}


int Dequeue(int elements[], int size){ //modified version for heap sort
    if(size == 0)  return -999;

    int temp = elements[0];

    // Copy last item into root
    elements[0] = elements[size-1];

    //size--;  size will be managed outside of this function.

    // Reheap the tree, size is reduced by 1
    ReheapDown(elements, size - 1, 0);

    return temp;
}


void HeapSort(int A[], int size){
    ///////////////////////////////////////////

    //Transform an array into a max-heap (heapify).
    //Iteratively visit the nodes from the branch node with the largest index value, reverse breath first order, back to the root node.
    //the last leaf node index is size - 1,
    //its parent is  floor( (size - 1 - 1)/2 ) = int  (size - 2)/2
    for(int i = (size - 2)/2  ; i >= 0; i--){
        //When visiting each node, call ReHeapDown function with the node index as input parameter.
        ReheapDown( A, size, i );
    }

    //Dequeue one by one to get a sorted order. store the sorted order in the same array. larger number in the end.
    for(int i = 0; i < size; i++){
        A[ size - 1 - i ] = Dequeue (A, size - i);
    }

    ///////////////////////////////////////////
}


int main() {
    bool long_test = false;

    if (!long_test) {
        int array1[7] = {7, 1, 3, 5, 4, 6, 2};

        HeapSort(array1, 7);

        //print sorted array
        for (int i = 0; i < 7; i++) {
            cout << array1[i] << ", ";
        }
        cout << endl;
    }
}