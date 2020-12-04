//CS311
//INSTRUCTION:
//Must use the provided HW5_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  control-K cuts and control-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW5 llist
//Your name: Kevyn Higbee
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

// CONSTRUCTOR
llist::llist()
{
  cout << "calling the llist constructor" << endl;

  // initialize list to empty
  front = NULL;
  rear = NULL;
  count = 0;
}

// DECONSTRUCTOR
llist::~llist() 
{ 
  el_t tmp;  // temp var to be used in deleteFront() calls
  cout << "calling the llist deconstructor" << endl;

  // delete every value in list
  while(!isEmpty())
    deleteFront(tmp);
}

/*
PURPOSE: Checks if there are any elements in the list. Returns a bool.
PARAMETER: none
*/
bool llist::isEmpty() 
{ 
  return ((count == 0)&&(!front)&&(!rear));
}

/*
PURPOSE: Displays every value in list, if list is empty, displays empty
PARAMETER: none
*/
void llist::displayAll() 
{ 
  Node *tmp = front;

  cout << "[ ";
  if(isEmpty())
    cout << "empty ";
  else
    for(int i = 0; i < count; i++)
      {
	cout << tmp -> elem << " ";
	tmp = tmp -> next;
      }
  cout << "]" << endl;
}

/*
PURPOSE: appends element to list
PARAMETER: elem to be appended
*/
void llist::addRear(el_t NewNum) 
{ 
  Node *current = NULL;

  if(!front)
    {
      addFront(NewNum); // if list is empty add element to front
    }
  else
    {
      current = rear;
      rear -> next = new Node;
      rear = rear -> next;
      rear -> elem = NewNum;
      count++;
    }
}

/*
PURPOSE: sets element to front of list
PARAMETER: elem for front of list
*/
void llist::addFront(el_t NewNum) 
{ 
  Node* oldFront = NULL;

  if(front)
    oldFront = front;

  front = new Node;
  front -> elem = NewNum;

  if(oldFront)
    front -> next = oldFront;
  else
    front -> next = NULL;

  if(!rear)
    rear = front;
  
  count++;
}

/**
 * PURPOSE: Remove and return by reference the front Node's value
 * PARAMETER: Element to receive front value
 **/
void llist::deleteFront(el_t& OldNum) 
{ 
  Node *tmp = NULL;;

  if(isEmpty())
    throw Underflow();
  
  OldNum = front -> elem;

  if(count == 1)
    {
      delete front;
      front = NULL;
      rear = NULL;
    }
  else
    {
      tmp = front -> next;
      delete front;
      front = tmp;
    }

  count--;
}

/*
PURPOSE: removes the last element of the list
PARAMETER: the address of the variable to receive the deleted value
*/
void llist::deleteRear(el_t& OldNum) 
{ 
  Node *tmp = NULL;

  if(isEmpty())
    throw Underflow();
  
  OldNum = rear -> elem;
  
  if(count == 1)
    {
      delete front;
      rear = NULL;
      front = NULL;
    }
  else
    {
      tmp = front;
      // get elem before rear
      while(tmp -> next != rear)
	tmp = tmp -> next;
      delete tmp -> next;
      rear = tmp;
    }
  
  count--;
}

/*
PURPOSE: deletes the Ith element in the list
PARAMETER: the elements place in the list, value to receive the deleted elem
*/
void llist::deleteIth(int I, el_t& OldNum) 
{ 
  Node *prev = NULL, *current = NULL;

  if(I > count || I < 1)
    throw OutOfRange(); 
  
  if(I == 1)
    deleteFront(OldNum);
  else if(I == count)
    deleteRear(OldNum);
  else
    {
      // initialize current at head of list
      current = front;
      // traverse to i'th position
      for(int i = I; i < count; i++)
	{
	  prev = current;
	  current = current -> next;
	}
      // delete i'th pointer and redirect connected nodes
      prev -> next = current -> next;
      OldNum = current -> elem; // give OldNum value of node to be deleted
      delete current;
      count--;
    }
  
}
/*
PURPOSE: inserts a value into the Ith position
PARAMETER: the index to be inserted at, the elem to be inserted into the list
*/
void llist::insertIth(int I, el_t newNum) 
{ 
  Node *prev = NULL, *current = NULL, *newNode = NULL;

  if(I > count+1 || I < 1)
    throw OutOfRange();
  
  if(I == 1)
    addFront(newNum);
  else if(I == count+1)
    addRear(newNum);
  else
    {
      current = front;
      for(int i = I; i < count; i++)
	{
	  prev = current;
	  current = current -> next;
	}
      newNode = new Node;
      newNode -> elem = newNum;
      newNode -> next = current;
      prev -> next = newNode;
      count++;
    }
}

/*
PURPOSE: copy constructor
PARAMETER: list to copy values of
*/
llist::llist(const llist& Original) 
{ 
  front = NULL;
  rear = NULL;
  count = 0;
  
  *this = Original;
}

/*
PURPOSE: overloaded assignment operator
PARAMETER: list to be copied
*/
llist& llist::operator=(const llist& OtherOne) 
{ 
  el_t tmp;
  Node *current = NULL;
  
  if(&OtherOne != this)
    {
      // empty this list
      while(!isEmpty())
	this -> deleteRear(tmp); // <- this isnt working a intended
      // copy OtherOne into this list
      current = OtherOne.front;

      for(int i = 0; i < OtherOne.count; i++)
	{
	  cout << "trying to insert " << current -> elem << endl;
	  this -> addRear(current -> elem);
	  current = current -> next;
	}
    }
  return *this;
}
