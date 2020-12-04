/**
 * File: slist.cpp
 * Date: 11/2/2018
 * Author: Kevyn Higbee
 * Class: CS311
 */
using namespace std;

#include "slist.h"
#include <iostream>

// Class Constructor
slist::slist()
{
  //  cout << "in slist constructor\n";
}

/**
 * returns index of element in list
 * if item not in list reutrns 0
 */
int slist::search(el_t key)
{
  Node* tmp = front;

  for(int i = 0; i < count; i++)
      if(tmp -> elem == key)
	return i;
      else
	tmp = tmp -> next;

  return 0;
}

/**
 * replaces the node with the passed index with the passed elem
 */
void slist::replace(el_t Elem, int I)
{
  Node* node = front;
  if(I <= 0 || I > count)
    throw OutOfRange();

  for(int i = 0; i < I; i++)
    node = node -> next;
  
  node -> elem = Elem;
}

/**
 * overloads the == operator, returns true if slists have same values
 */
bool slist::operator==(const slist& other)
{
  Node *myTmp = this->front, *otherTmp=other.front;

  if(other.count == this->count) // if lists are the same length, check all values to see if same
    while(myTmp) // only need to make sure one isnt null because lists are same length
      if(myTmp->elem==otherTmp->elem) // check if values of nodes are equal
	  {
	    myTmp = myTmp->next; // get next nodes if the current nodes are equal
	    otherTmp = otherTmp->next;
	  }
	else
	  return false; // values were found that arent the same value in the same position
  else
    return false; // if the lenghts arent the same the lists cannot be equal

  return true; // if we got to this point the lists are the same
}

