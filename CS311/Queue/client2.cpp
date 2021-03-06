//CS311
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match hw2queueDemo.out

//=========================================================
//HW#: HW2 queue
//Your name: Kevyn Higbee
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: display all permutations of strings consisting of the letters 'A' 'B' 'C'
//Algorithm: **
int main()
{ 
  queue q;      // queue object
  string str1;  // temporary string for holding temp values
  
// enqueue inital values to queue
  q.enqueue("A");
  q.enqueue("B");
  q.enqueue("C");
  
  // try catch 
  try
    {
      // indefinite loop to enqueue string variations
      while(true)  //  the loop will exit when an Overflow error has been thrown
	{
	  q.dequeue(str1);
	  q.enqueue(str1+"A");
	  q.enqueue(str1+"B");
	  q.enqueue(str1+"C");
	}
    }
  catch(queue::Underflow)
    {
      // this shouldn't happen with what we are doing
    }
  catch(queue::Overflow)
    {
      q.displayAll();
      cout << "The Queue has overflowed." << endl;
    }
}

