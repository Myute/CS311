//CS311 
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application
//Your name: Kevyn Higbee
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: **
//Algorithm: **
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char
	 
	 // if item is an opperand
	 if((item>=48)&&(item<=57))
	   postfixstack.push(item-48); // subtract 48 to get correct int value
	    else
	      {
		switch(item)
		  {
		  case '+':  // perform addition operation
		    postfixstack.pop(box1);
		    postfixstack.pop(box2);
		    postfixstack.push(box1+box2);
		    break;

		  case '-':  // perfirm subtraction operation
		    postfixstack.pop(box1);
		    postfixstack.pop(box2);
		    postfixstack.push(box2-box1);
		    break;

		  case '*':  // perform multiplication operation
		    postfixstack.pop(box1);
		    postfixstack.pop(box2);
		    postfixstack.push(box1*box2);
		    break;

		  default:  // item in stack is not accounted for
		    throw "Invalid item (bad operand or operator)";
		    break;
		  }
	      }

	 postfixstack.displayAll();  // display contents of stack

       } // this closes try
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{ 
	  // stack is full, display error then quit program
	  cout << "Stack Overflow (too many operands)" << endl; 
	  exit(1);
	}
      catch (stack::Underflow)
	{ 
	  // overaccessing stack, display error then quit program
	  cout << "Stack Underflow (not enough operands)" << endl; 
	  exit(1);  
	}
      catch (char const* errormsg ) // for invalid item case
	{
	  // unhandled expression, display error then quit
	  cout << errormsg << endl; 
	  exit(1); 
	}

      // go back to the loop after incrementing i

     i++;
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
  postfixstack.pop(box1);
  cout << "Result is: " << box1 << "." << endl;

 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.
  if(!postfixstack.isEmpty())
    {
      cout << "Incomplete Expression" << endl;
      postfixstack.clearIt();
      exit(1);
    }

}// end of the program
