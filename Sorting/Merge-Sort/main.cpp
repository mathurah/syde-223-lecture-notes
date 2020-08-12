#include <iostream>
using namespace std;

void MergeSort(int A[], int indexLeft, int indexRight);

void MergeSort(int A[], int indexLeft, int indexRight){
    ///////////////////////////////////////////
    //Input check. If any index < 0, or indexLeft >= indexRight, do nothing.
    if(indexLeft < 0 ||  indexRight < 0) return;
    if(indexLeft >= indexRight) return;

//	cout<< "MergeSort with " << indexLeft << ", " << indexRight << endl;

    //Find indexMiddle to divide the array into two parts.
    int indexMiddle = indexLeft + ( indexRight -  indexLeft ) / 2 ;  //e.g., 0, 1, 2, middle = 1;  0, 1, 2, 3, middle = 1

    //Recursively call MergeSort to sort the first half and the second half of the array.
    MergeSort(A, indexLeft, indexMiddle);
    MergeSort(A, indexMiddle + 1, indexRight);

    //Merge the first half and the second half back into a sorted order, from small to large values.
    int tempA [ indexRight - indexLeft + 1  ]; // to store the merged array
    int i = indexLeft, j = indexMiddle + 1; //i for left half array, j for right half array
    int k = 0; //k for temp array
    while(true){

        if( A[i] <= A[j] ) {
            tempA[k] = A[i];
            k++;
            i++;
        }
        else{
            tempA[k] = A[j];
            k++;
            j++;
        }


        if( i > indexMiddle ){
            //left half is done, place the remaining right half
            for( ; j <=  indexRight; j++, k++ ){
                tempA[k] = A[j];
            }
            break;
        }
        if( j > indexRight ){
            //right half is done, place the remaining left half
            for( ; i <=  indexMiddle; i++, k++ ){
                tempA[k] = A[i];
            }
            break;
        }
    }

    //copy tempA back into A
    for ( k = 0; k < indexRight - indexLeft + 1   ; k++ ){
        A[indexLeft + k] = tempA[k];
    }

//	for ( k = 0; k < indexRight - indexLeft + 1   ; k++ ){
//		cout<<  tempA[k] << ", ";
//	}
//	cout<<endl;

    ///////////////////////////////////////////
}


int main() {
    bool long_test = false;

    if (!long_test) {
        int array1[7] = {7, 1, 3, 5, 4, 6, 2};

        MergeSort(array1, 0, 6);

        //print sorted array
        for (int i = 0; i < 7; i++) {
            cout << array1[i] << ", ";
        }
        cout << endl;
    }
}