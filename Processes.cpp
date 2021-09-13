//
//  Processes.cpp
//  ITSC 3146
//
//  Created by Bahamon, Julio on 1/12/17.
//


/*
 @file Processes.cpp
 @author student name, student@uncc.edu
 @author student name, student@uncc.edu
 @author student name, student@uncc.edu
 @description: <ADD DESCRIPTION>
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */


#ifndef Processes_cpp
#define Processes_cpp

#include "Processes.h"


using namespace std;


// Part 1: Working With Process IDs
pid_t getProcessID(void)
{
   getpid();
   
   return -1;
}


// Part 2: Working With Multiple Processes
string createNewProcess(void)
{
   pid_t id = fork();
   
   // DO NOT CHANGE THIS LINE OF CODE
   process_id = id;
   
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
}


// Part 3: Working With External Commands"
void replaceProcess(char * args[])
{
   // Spawn a process to execute the user's command.
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
}

#endif /* TestProg_cpp */
