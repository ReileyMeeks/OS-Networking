#include <iostream>
using namespace std;
//Reiley Meeks

void swapints(int& fInt, int& sInt);

int main() {
    //Ints
    int userNum1; //first user input
    int userNum2; //second user input
    
    //Pointers
    int *uN1Point = &userNum1; //userNum2 pointer
    int *uN2Point = &userNum2; //userNum1 pointer
    
    //ask user for input
    cout << "Please enter a int" << endl;
    ;cin >> userNum1; //get first user input
    
    cout << "Please enter another int" << endl;
    ;cin >> userNum2; //get second user input
    
    //print outputs of orginal values
    cout << "Original Val 1 is: " << userNum1 << endl;
    cout << "Original Val 2 is: " << userNum2 << endl;
    
    //perform the swap
    swapints(*uN1Point, *uN2Point);
    
    return 0;
}

//swap ints function
void swapints(int& fInt, int& sInt){
    int temp = fInt; //set first int to temp
    fInt = sInt; //set first int location to second int
    sInt = temp; //take first int val from temp, set to second int
    
    //print values
    cout << "New Val 1 is: " << fInt << endl;
    cout << "New Val 2 is: " << sInt << endl;
}
