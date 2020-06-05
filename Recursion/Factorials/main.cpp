#include <iostream>
using namespace std;

int factorialNonRecursive (int n);
int factorialRecursive (int n);


int factorialNonRecursive (int n){
    //non recursive version. need to use a loop
    cout<< "Calling factorialNonRecursive." <<endl;

    if(n < 0) {
        cout<< "Warning! Factorial can only take non-negative input!" <<endl;
        return 0;
    }

    if (n == 0) return 1;

    int result = 1;
    for(int i = 1; i <= n; i++){
        result = result * i;
    }


    return result;
}


int factorialRecursive (int n){
    //break it down into N * factorialRecursive(n-1)
    cout<< "Calling factorialRecursive." <<endl;

    if(n < 0) {
        cout<< "Warning! Factorial can only take non-negative input!" <<endl;
        return 0;
    }
    else if (n == 0) return 1;
    else 	return ( n * factorialRecursive (n-1)  );

}


int main() {

    //test cases
/*
	cout << factorialNonRecursive (-1) <<endl;
	cout << factorialNonRecursive (0) <<endl;
	cout << factorialNonRecursive (1) <<endl;
	cout << factorialNonRecursive (4) <<endl;
	cout << factorialNonRecursive (10) <<endl;
	cout << factorialNonRecursive (100) <<endl;
	cout << "===============================" <<endl;
*/

/*
	cout << factorialRecursive (-1) <<endl;
	cout << factorialRecursive (0) <<endl;
	cout << factorialRecursive (1) <<endl;
	cout << factorialRecursive (4) <<endl;
	cout << factorialRecursive (10) <<endl;
	cout << factorialRecursive (100) <<endl;
	cout << "===============================" <<endl;
*/


    return 0;
}