/*
 @file: pthreads_skeleton.cpp
 
 @author: student name1, student2@uncc.edu
 @author: student name2, student2@uncc.edu
 @author: student name3, student3@uncc.edu
 
 @description: A program that demonstrates processes.
 
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>

using namespace std;

//global int array
int userNums[10];

void* countNegatives(void *args){
   int negNums = 0;
   //find the negative nums, increment negNums with each negative number
   for(int i = 0; i < 10; i++){
      if(userNums[i] < 0){
         negNums++;
      }
   }
   cout << "Negative Nums: " << negNums;
   cout << endl << endl;
}

void* average(void *args){
   int currIndex = 0;
   int sum = 0;
   int avg = 0;
   int divide = 10;
   
   //get the sum of all number together
   for(int i = 0; i < 10; i++){
      currIndex = userNums[i];
      sum += currIndex;
   }
   //calculate the average and print
   avg = sum/divide;
   cout << "Your Average is: " << avg;
   cout << endl << endl;
}

void* reverse(void *args){
   //use nested for loop to create reversed array
   for(int i = 0; i < 10; i++){
      for(int j = i + 1; j < 10; j++){
         int temp  = userNums[i];
			userNums[i] = userNums[j];
			userNums[j] = temp;
      }
   }
   
   cout << "Your Array: ";
   //print out the reversed array
   for(int i = 0; i < 10; i++){
      cout << "[" << userNums[i] << "]" << " ";
   }
   cout << endl << endl;
}

// This function shows the skeleton that pthread 
// functions must adhere to. 
// Copy this skeleton for any pthread function 
// you need to define. 
// In the copy, modify the name of the function 
// and the function body as needed. 
void *routineName(void *arg)
{
   // TODO: Add code that implements
   //       the thread's functionality
   cout << "Thread is running..." << endl;
   return 0;
}


int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   pthread_t id;
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
   
   
   // TODO: Add code to perform any needed initialization
   //       or to process user input
   
   cout << "You will enter 10 numbers.";
   cout << endl;
   
   //grab the user numbers
   for (int i = 0; i < 10; i++){
        cout << "Please enter a number: ";
        cout << endl;
        cin >> userNums[i];
   }

   //negative numbers
   int a = pthread_create(&id, NULL, countNegatives, userNums);
   //average value
   int b = pthread_create(&id, NULL, average, userNums);
   //reverse the array
   int c = pthread_create(&id, NULL, reverse, userNums);
   
   // Create thread(s)
   // TODO: Modify according to assignment requirements
   rc = pthread_create(&id, NULL, routineName, NULL);

   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   

   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}
