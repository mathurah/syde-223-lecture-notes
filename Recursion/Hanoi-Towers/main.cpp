#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//////////////////
//declaration/////
//////////////////
const int PEG_CAPACITY = 10; //the capacity of each peg is static. assume it is enough.

//use a sequential list implementation to represent a peg
//the first element is at the bottom of the peg.
//the last element is on the top of the peg.
//each element is an int, meaning the size of each disk.
//disk size 0 means empty, no element.
class Peg{
public:
    string name;
    int capacity;
    int pegHeight; //how many non-empty elements in the peg
    int disks[PEG_CAPACITY];

    Peg(string str);
    bool initializePeg(int n); //put n disks on the peg.
    int popTopDisk(); //return the size of the top disk, remove the disk from the peg.
    void addTopDisk(int diskSize); //try to add a disk on top of the peg.
    string visualizePegLevel(int level);
    int peekTopDisk();
    int getContinuousGroupHeight(); // from top to bottom, 1, 2, 3, until the continuous series break, e.g., no 4, but directly 5, or reach the bottom.
};

class HanoiTowers{
public:
    Peg A, B, C;
    HanoiTowers(int n);
    void visualizeTowers();
    void moveRecursive(int n, Peg *currentPeg, Peg *targetPeg, Peg *sparePeg);
};

string intToString(int value); //utility function


//////////////////
//implementation//
//////////////////
Peg::Peg(string str) : name(str), capacity (PEG_CAPACITY), pegHeight (0) {
    for(int i = 0; i < PEG_CAPACITY; i++){
        disks[i] = 0;  //make all elements initially empty.
    }
}

bool Peg::initializePeg(int n){
    //assume the peg is empty, did not clear all elements here.
    if (n <= 0){
        cout<< "Error! n <= 0 in initializePeg." << endl;
        return false;
    }
    else if(n > capacity){
        cout<< "Error! n > capacity in initializePeg." << endl;
        return false;
    }
    else{
        int counter = n;
        for(int i = 0; i < n; i++){
            pegHeight++;
            disks[i] = counter;  //put largest disk at the bottom.
            counter--;
        }
        return true;
    }
}

int Peg::popTopDisk(){
    if(pegHeight == 0){
        cout<< "Error! popTopDisk has nothing to pop." <<endl;
        return 0;
    }
    else{
        int output = disks[pegHeight - 1];
        disks[pegHeight - 1] = 0;
        pegHeight--;
        return output;
    }
}

void Peg::addTopDisk(int diskSize){
    if(pegHeight == capacity){
        cout<< "Error! Peg is full. addTopDisk cannot add anything." <<endl;
        return;
    }
    else {
        //need to verify if it is legal to add.
        bool okToAddTop;
        if ( pegHeight == 0 ) okToAddTop = true;
        else if ( disks[pegHeight - 1] > diskSize ) okToAddTop = true;
        else okToAddTop = false;

        if (okToAddTop){
            disks[pegHeight] = diskSize;
            pegHeight++;
        }
        else {
            cout<< "Error! addTopDisk cannot add the disk." <<endl;
        }
    }

}

string Peg::visualizePegLevel(int level){
    //omit input validation here
    //return a string that visualizes the level from the Peg p.
    char spacePixel = (char)32; // space
    char solidPixel = (char)79; // O
    char pegPole = (char)124;   // |

    int diskSize = disks[level];
    string result = "";
    for(int i = 0; i<PEG_CAPACITY ; i++ ){
        if(i < PEG_CAPACITY-diskSize) result += spacePixel;
        else result += solidPixel;
    }
    if(diskSize == 0)result += pegPole;
    else result += intToString(diskSize);

    for(int i = 0; i<PEG_CAPACITY ; i++ ){
        if(i < diskSize) result += solidPixel;
        else 	result += spacePixel;
    }

    return result;
}

int Peg::peekTopDisk(){
    //return the size of the disk on top. return 0 if peg is empty.

    return disks[pegHeight - 1];
}

int Peg::getContinuousGroupHeight(){
    if (pegHeight == 0) return 0;
    int diskSizeCounter = 1;
    int result = 0;
    for(int i = pegHeight - 1; i>=0; i--  ){
        if( this->disks[i] == diskSizeCounter ) {
            result++;
            diskSizeCounter++;
        }
        else break;
    }
    return result;
}

HanoiTowers::HanoiTowers(int n) : A("A") , B("B") , C("C") {
    A.initializePeg(n);
}

void HanoiTowers::visualizeTowers(){
    //make the first line of A B C.
    string strA(PEG_CAPACITY, ' ');
    cout<< strA << A.name << strA << strA << B.name << strA << strA << C.name<< endl;

    //print each line
    for(int i = PEG_CAPACITY-1; i>=0; i--){
        //creat a line of string from each row of the three pegs
        cout<< A.visualizePegLevel(i);
        cout<< B.visualizePegLevel(i);
        cout<< C.visualizePegLevel(i) << endl;
    }
    cout<< endl;
}


//////////////////////////////////////////
//Hanoi Tower solution, recursive.
//3 Peg parameters
void HanoiTowers::moveRecursive(int n, Peg *currentPeg, Peg *targetPeg, Peg *sparePeg){
    cout<< "Call moveRecursive. Move " << n << " disks from " << currentPeg->name << " to " << targetPeg->name << " with help from " << sparePeg->name << endl;

    //////////////////////////////////////////
    //////////////////////////////////////////
    //////////////////////////////////////////

    if(n <= 0) return;  // invalid case

    //ending case
    if (n == 1){
        targetPeg->addTopDisk( currentPeg->popTopDisk() );
        visualizeTowers();
        //system("PAUSE");
        system("read -p 'Press Enter to continue...' var");
    }
    else{
        //step 1
        moveRecursive(n-1, currentPeg, sparePeg, targetPeg);
        //step 2
        moveRecursive(1, currentPeg, targetPeg, sparePeg);
        //step 3
        moveRecursive(n-1, sparePeg, targetPeg, currentPeg);
    }



    //////////////////////////////////////////
    //////////////////////////////////////////
    //////////////////////////////////////////
}


string intToString(int value)
{
    ostringstream oss;
    oss << value;
    return oss.str();
}




////////
//main//
////////
int main(){
    int testCaseN = 5;
    HanoiTowers towersProblem(testCaseN);
    towersProblem.visualizeTowers();

    //solving with recursive version

	towersProblem.moveRecursive(testCaseN, &towersProblem.A, &towersProblem.C, &towersProblem.B);
	cout << "recursive version DONE" << endl;


/*

    //solving with iterative version

	int step = 0;
	Peg *disk1CurrentPeg = &towersProblem.A; //the smallest disk, disk#1 starts on Peg A.
	Peg *theOtherPeg1 = &towersProblem.B;
	Peg *theOtherPeg2 = &towersProblem.C;

	Peg *finalTargetPeg = &towersProblem.C;

	while(step < 999999 ){  //prevent error causing infinite loop
		step++;
		Peg *moveDiskFromThisPeg = NULL;
		Peg *moveDiskToThisPeg = NULL;

		//////////////////////////////////////
		// implement iterative solution here.
		//////////////////////////////////////

		if(step%2 == 1){ //odd step, always move disk#1
			moveDiskFromThisPeg = disk1CurrentPeg;

			//check the state of the other two pegs
			if(theOtherPeg1->pegHeight == 0 && theOtherPeg2->pegHeight == 0 ){
				//when the other two are both empty
				if(disk1CurrentPeg->getContinuousGroupHeight()%2 == 1){ // odd continuous group, move disk1 to target peg
					moveDiskToThisPeg = finalTargetPeg;
				}
				else{ // even continuous group, move disk1 to spare peg.
					if(theOtherPeg1 != finalTargetPeg) moveDiskToThisPeg = theOtherPeg1;
					else moveDiskToThisPeg = theOtherPeg2;
				}
			}
			else if (theOtherPeg1->pegHeight == 0 || theOtherPeg2->pegHeight == 0){
				//when only one of the other two pegs is empty

				if(disk1CurrentPeg->getContinuousGroupHeight()%2 == 1){ // odd continuous group, move disk1 to non empty peg
					if(theOtherPeg1->pegHeight != 0) moveDiskToThisPeg = theOtherPeg1;
					else moveDiskToThisPeg = theOtherPeg2;
				}
				else {// even continuous group, move disk1 to the empty peg
					if(theOtherPeg1->pegHeight == 0) moveDiskToThisPeg = theOtherPeg1;
					else moveDiskToThisPeg = theOtherPeg2;
				}

			}
			else {
				//when both the other two pegs are not empty

				if(disk1CurrentPeg->getContinuousGroupHeight()%2 == 1){ // odd continuous group, move disk1 to the peg with the smaller disk on top
					if(theOtherPeg1->peekTopDisk() < theOtherPeg2->peekTopDisk()) moveDiskToThisPeg = theOtherPeg1;
					else moveDiskToThisPeg = theOtherPeg2;
				}
				else{ //even continuous group, move disk1 to the peg with the larger disk on top
					if(theOtherPeg1->peekTopDisk() > theOtherPeg2->peekTopDisk()) moveDiskToThisPeg = theOtherPeg1;
					else moveDiskToThisPeg = theOtherPeg2;
				}

			}

		}
		else{ //even step, always move the other movable disk that is smaller in size.
			//the movable disk is not size 1, so it cannot go the the current disk1 peg.
			int size1 = theOtherPeg1->peekTopDisk();
			int size2 = theOtherPeg2->peekTopDisk();

			if( size1 == 0 && size2 > 0 ) {
				moveDiskFromThisPeg = theOtherPeg2;
				moveDiskToThisPeg = theOtherPeg1;
			}
			else if (size1 > 0 && size2 == 0) {
				moveDiskFromThisPeg = theOtherPeg1;
				moveDiskToThisPeg = theOtherPeg2;
			}
			else if(  size1 < size2 ) {
				moveDiskFromThisPeg = theOtherPeg1;
				moveDiskToThisPeg = theOtherPeg2;
			}
			else if(  size2 < size1 ) {
				moveDiskFromThisPeg = theOtherPeg2;
				moveDiskToThisPeg = theOtherPeg1;
			}
			else {
				//this should not happen.
				cout<< "implement iterative solution error." <<endl;
				return -1;
			}
		}

		//////////////////////////////////////
		//////////////////////////////////////
		//////////////////////////////////////

		//do the move, and update peg pointers related to the disk#1 if necessary.
		if(moveDiskFromThisPeg != NULL && moveDiskToThisPeg != NULL){
			moveDiskToThisPeg->addTopDisk(  moveDiskFromThisPeg->popTopDisk()  );

			if(disk1CurrentPeg == moveDiskFromThisPeg){//if disk1 is involved in the moving
				disk1CurrentPeg = moveDiskToThisPeg;

				if(theOtherPeg1 == moveDiskToThisPeg) theOtherPeg1 = moveDiskFromThisPeg;
				else theOtherPeg2 = moveDiskFromThisPeg;
			}

			moveDiskFromThisPeg = NULL;
			moveDiskToThisPeg = NULL;
		}

		towersProblem.visualizeTowers();

		//check for completion
		if(disk1CurrentPeg == finalTargetPeg && theOtherPeg1->pegHeight == 0 && theOtherPeg2->pegHeight == 0){
			cout << "iterative version DONE" << endl;
			break;
		}

		//system("PAUSE");
		system("read -p 'Press Enter to continue...' var");
	}

	////////
	//////// end of iterative version.

*/


    return 0;
}

