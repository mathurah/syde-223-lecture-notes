# Sorting
**The Sorting Problem**
- Given an unordered collection of data elements, arrange them into an ordered collection that is sorted in 
    - Ascending/increasing order, or
    - Descending/decreasing order

## Bubble Sort Algorithm
- Use a flag to store if any swap is done in the last iteration
- Use a temp variable for swapping
- First loop, leep repeating until no swap was made in the last iteration
- Second loop, iterate from the first element to the last unsorted element (first iteration starts from `0` to `n-2`)
    - Each time, if `element[i]` is larger than `element[i+1]`, swap them and mark swapped = true
- at the end of each loop, set the last element as sorted

### Bubble Sort Demo
```cpp
#include <iostream>
using namespace std;

void BubbleSort(int A[], int size);
void BubbleSort(int A[], int size){
    ///////////////////////////////////////////

    //use a flag to store if any swap is done in the last iteration
    bool swapped;

    //use a temp variable for swapping
    int temp;

    //first loop, keep repeating until no swap was made in the last iteration.
    do{
        //set swapped to false
        swapped = false;

        //second loop, iterate from the first element to the last unsorted element (first iteration starts from 0 to size - 2)
        //each time, if element[i] is larger than element[i + 1], swap them, and mark the swapped = true
        for(int i = 0; i < size - 1; i++){
            if (A[i] > A[i+1]) {
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                swapped = true;
            }
        }
        //at the end of each first loop, set the last element as sorted.
        size--;
    }while (swapped);

    ///////////////////////////////////////////
}


int main()
{
    bool long_test = false;

    if(!long_test){
        int array1[7] = {7, 1, 3, 5, 4, 6, 2 };

        BubbleSort(array1, 7);

        //print sorted array
        for (int i = 0; i < 7; i++ ){
            cout<< array1[i] <<", " ;
        }
        cout<<endl;
    }
    else{
        
    }



    return 0;
}
```