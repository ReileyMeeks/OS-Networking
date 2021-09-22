//Reiley Meeks
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


// This function shows the skeleton that pthread 
// functions must adhere to. 
// Copy this skeleton for any pthread function 
// you need to define. 
// In the copy, modify the name of the function 
// and the function body as needed. 

const char* my_messages[4] = {"English: Hello!", 
	"French: Bonjour!", "Spanish: Hola!", 
	"German: Guten Tag!" };
	
const int n = 4; //creaet a constant for number of elemnts
	
void *printMessage(void *iNum){
   int index = *((int*) iNum); //get the true value of iNUm and pass it to index
   
   cout << my_messages[index]; //print out the index 
   cout << endl;
   
   return 0;
}

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
   pthread_t thread[n]; //create array of pthread_t
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
   
   // TODO: Add code to perform any needed initialization
   //       or to process user input

   // Create thread(s)
   // TODO: Modify according to assignment requirements
   
   int tmp_arg[n]; //create a temporary array of constant n
   //for loop to create processes
   for(int i = 0; i < n; i++){
      tmp_arg[i] = i; //set the temp array values to i
      //creaet the threads
      int result = pthread_create(&thread[i], NULL, printMessage, static_cast<void*>(&tmp_arg[i]));
   }
   
   rc = pthread_create(&id, NULL, routineName, NULL);

   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   

   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}
