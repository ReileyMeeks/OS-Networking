#include <iostream>
using namespace std;
//Reiley Meeks

int main() {
    //Int array, lentgh 4
    int my_ints [4];
    
    //Create pointer to array
    int *my_ptrs[4];
    
    //Add user defined ints
    for (int i = 0; i < 4; i++){
        cout << "Please enter a number: ";
        cin >> my_ints[i];
    }
	
	//Sort my_ints in accedning order
	for(int i = 0;i < 4; i++){	
		for(int j = i + 1; j < 4; j++){
			if(my_ints[i] > my_ints[j]){
				int temp  = my_ints[i];
				my_ints[i] = my_ints[j];
				my_ints[j] = temp;
			}
		}
	}
	
	//Accedning order for my_ptrs
    for(int i = 0 ; i < 4; i++) {
        my_ptrs[i] = &my_ints[i]; //my_ints index i value is givern to my_ptrs at index i
		
	}
	
	//Print the values 
	for(int i = 0; i < 4; i++){
	    cout << "Value of my_ptrs[" << i << "] = ";
	    cout << *my_ptrs[i] << endl; //prints value of my_ptrs at index i
	}
    
    return 0;
}