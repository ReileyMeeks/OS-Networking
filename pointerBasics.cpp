#include <iostream>
using namespace std;
//Reiley Meeks

int main() {
    //Int var
    int myInt = 15;
    
    //myInt pointer
    int *myPointer;
    myPointer = &myInt;
    
    //Print values
    cout << "myInt location is: " << &myInt << '\n';
    cout << "Value of myPointer: " << myPointer << '\n';
    cout << "Value of myInt: " << myInt << '\n';
    cout << "myPointer value: " << *myPointer << '\n';
    
    //Create Line Space
    cout << '\n';
    
    //Change the value of myInt
    myInt = 10;
    
    //Print values
    cout << "myInt location is: " << &myInt << '\n';
    cout << "Value of myPointer: " << myPointer << '\n';
    cout << "Value of myInt: " << myInt << '\n';
    cout << "myPointer value: " << *myPointer << '\n';
    
    return 0;
}