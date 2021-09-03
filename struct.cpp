#include <iostream>
#include <cmath>
using namespace std;
//Reiley Meeks

struct  CartesianCoordinate {
    float x;
    float y;
};

void calculateDistance(CartesianCoordinate * p_1, CartesianCoordinate * p_2) {
    //create result float
    float result;
    
    //create x1/y1 vars
    float x1 = p_1 -> x;
    float y1 = p_1 -> y;
    
    //create x2/y2 vars
    float x2 = p_2 -> x;
    float y2 = p_2 -> y;
    
    //solve the distance
    result = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "Your distance is: " << result << endl;
    
}

int main() {
    //create objects
    CartesianCoordinate p1;
    CartesianCoordinate p2;
    
    //create pointers
    CartesianCoordinate * pointer1;
    CartesianCoordinate * pointer2;
    
    //set pointers
    pointer1 = &p1;
    pointer2 = &p2;
    
    //ask user for p1 cords
    cout << "Enter x cord for p1: " << endl;
    ;cin >> p1.x;
    cout << "Enter y cord for p1: " << endl;
    ;cin >> p1.y;
    
    //ask user for p2 cords
    cout << "Enter x cord for p2: " << endl;
    ;cin >> p2.x;
    cout << "Enter y cord for p2: " << endl;
    ;cin >> p2.y;
    
    //pass pointers to function
    calculateDistance(pointer1, pointer2);
    
    return 0;
}
