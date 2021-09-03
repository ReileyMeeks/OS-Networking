#include <iostream>
using namespace std;

int main() {
    int userNums[10];
    
    for (int i = 0; i < 10; i++){
        cout << "Please enter a number: ";
        cin >> userNums[i];
    }
    
    for(int i = 10;i >= 0;i--) {
        cout << userNums[i]; 
        cout << endl;
    }
    
    for(int i = 0;i < 10; i++){	
        
		for(int j = i + 1; j < 10; j++){
		    
			if(userNums[i] > userNums[j]){
			    
				int temp  = userNums[i];
				userNums[i] = userNums[j];
				userNums[j] = temp;
			}
		}
	}
	
	cout << "Accending order: " << endl;
	for(int i = 0 ; i < 10; i++) {
		cout << userNums[i] << "\t";
	    cout << endl;
	}
	
    return 0;
}