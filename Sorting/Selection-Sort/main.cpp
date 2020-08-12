#include <iostream>
using namespace std;

void SelectionSort(int A[], int size);
void SelectionSort(int A[], int size){
    ///////////////////////////////////////////

    int min_index;
    int temp;
    //First loop, repeat n - 1 times (from 0 to n - 2)
    for (int i = 0; i < size - 1; i++){ // i < size  also works, but waste some computation.
        //Second loop, find the minimal value from the remaining unsorted elements.
        min_index = i;
        for(int j = i + 1; j < size; j++){ // j = i also works, but waste some computation.
            if(A[j] < A[min_index]) min_index = j;
        }
        //Swap that minimum element with the first of the unsorted elements.
        if(min_index != i) { // save some computation by first checking if it is self
            temp = A[min_index];
            A[min_index] = A[i];
            A[i] = temp;
        }
    }

    ///////////////////////////////////////////
}


int main() {
    bool long_test = false;

    if (!long_test) {
        int array1[7] = {7, 1, 3, 5, 4, 6, 2};

        SelectionSort(array1, 7);

        //print sorted array
        for (int i = 0; i < 7; i++) {
            cout << array1[i] << ", ";
        }
        cout << endl;
    }

}