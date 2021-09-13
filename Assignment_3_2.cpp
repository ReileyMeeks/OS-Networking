// Reiley Meeks
//  Assignment_3_2.cpp
//  ITSC 3146
//
//  Created by Bahamon, Julio on 1/12/17.
//


/*
 @file Assignment_3_2.cpp
 @author student name, student@uncc.edu
 @author student name, student@uncc.edu 
 @author student name, student@uncc.edu
 @description: A program that works with Linux processes.
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <stdio.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include <fcntl.h>
#include "Processes.h"


using namespace std;


pid_t process_id;

/*
 * The starting point of the program.
 */
int main(void)
{
   // Call the user-defined function that retrieves the process ID
   cout << "Part 1: Working With Process IDs" << endl;
   cout << "Process ID: " << getpid() << endl;
   cout << endl << endl;
   
   
   // Call the user-defined function that creates a new process
   cout << "Part 2: Working With Multiple Processes" << endl;
   pid_t id = fork(); 
   pid_t *status = &id; //create pointer to id
   
   if(id == -1) { 
        std::cout << "Error creating process\n"; 
        
    } else if (id == 0) { 
        std::cout << "I’m a child process!\n"; 
        std::cout <<"I am bored of my parent, switching programs now \n";
        
        pid_t wait(*status); //declare wait to display when child prcosess finishes
        
        std::cout << "My child process just terminated! \n";
        
    } else { 
        std::cout << "I just became a parent!\n";
        
    } 
   cout << endl << endl;
   

   // Call the function that call an external OS command
   if (process_id != 0)
   {
      cout << "Part 3: Working With External Commands" << endl;
      char * args[3] = {(char * )"ls", (char * )"-l", NULL};
      
      pid_t id = fork(); 
      pid_t *status = &id; //create pointer to id
      
      //check the processes
      if(id == -1) { 
          std::cout << "Error creating process\n";  
          
      } else if (id == 0) {     
          // child process functionality                                               
          char* args[] = {"echo", "hello", NULL}; 
          execvp(args[0], args); 
          
          pid_t wait(*status); //declare wait
          
      } else { 
          std::cout << "I just became a parent!\n";                                              
        } 
      
      cout << endl;
   }

   
   return 0;
}
//end file


