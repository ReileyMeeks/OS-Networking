//  Reiley Meeks, Christian Amidon
//  QuickSort_801149501.cpp
//
//  Created by Bahamon, Julio on 6/25/19.
//  UNC Charlotte
//  Copyright © 2019 Bahamon, Julio. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//  Declaring a new struct to store patient data
struct patient {
    int age;
    char name[20];
    float balance;
};

void display(patient list[]) {
    for(int i = 0; i < 6; i++){ //loops through the array
        cout << "Name: " << list[i].name << "   "; //prints name
        cout << "Age: " << list[i].age << "    "; //prints age
        cout << "Ballance Due: $" << list[i].balance << "   "; //prints ballance
        cout << endl;
    }
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY AGE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE AGE OF THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S AGE
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE

int compareAge(const void* a, const void* b){
	struct patient *id1 = (struct patient *)a; 
	struct patient *id2 = (struct patient *)b;

    //sort the age, yougest to oldest
	if (id1 -> age < id2 -> age) {
	    return -1;
	} else if(id1 -> age == id2 -> age) {
	    return 0;
	}
	return 1;
}



//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY BALANCE DUE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE BALANCE FOR THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S BALANCE
//       0 IF THE BALANCES ARE EQUAL
//       1 OTHERWISE

int compareBal(const void* a, const void* b){
	struct patient *id1 = (struct patient *)a; 
	struct patient *id2 = (struct patient *)b;

    //sort the balance, lowest to highest
	if (id1 -> balance < id2 -> balance) {
	    return -1;
	} else if(id1 -> balance == id2 -> balance) {
	    return 0;
	}
	return 1;
}


//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY NAME

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE NAME OF THE FIRST PATIENT GOES BEFORE
//         THE SECOND PATIENT'S NAME
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
//
//  HINT: USE THE strncmp FUNCTION
//  (SEE http://www.cplusplus.com/reference/cstring/strncmp/)

int compareName(const void* a, const void* b){
	struct patient *id1 = (struct patient *)a;
	struct patient *id2 = (struct patient *)b;
	const int result = strncmp(id1 -> name, id2 -> name, 100); //store value in result for sorting

    //sort the array
	if (result < 0) {
	    return -1;
	} else if(result == 0) {
	    return 0;
	}
	return 1;
}


//  The main program
int main()
{
    int total_patients = 6;
    
    //  Storing some test data
    struct patient patient_list[6] = {
        {25, "Juan Valdez     ", 1250},
        {15, "James Morris    ", 2100},
        {32, "Tyra Banks      ", 750},
        {62, "Maria O'Donell  ", 375},
        {53, "Pablo Picasso   ", 615},
        {21, "Reiley Meeks    ", 25} //My info
    };
    
    
    cout << "Patient List: " << endl;
    
    display(patient_list); //display the patients using display function
    
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    qsort(patient_list, total_patients, sizeof(struct patient), compareAge); //use compareAge funtion to sort
    
    cout << "Patient List - Sorted by Age: " << endl;
    
    display(patient_list); //print new sorted array
    
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    qsort(patient_list, total_patients, sizeof(struct patient), compareBal); //compare the ballance to sort
    
    cout << "Patient List - Sorted by Balance Due: " << endl;
    
    display(patient_list); //print newly sorted balance
    
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    qsort(patient_list, total_patients, sizeof(struct patient), compareName); //sort alphabetically 
    
    cout << "Patient List - Sorted by Name: " << endl;
    
    display(patient_list); //print new sorted array
    
    cout << endl;
    
    return 0;
}
