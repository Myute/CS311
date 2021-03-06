// CS311 - Priority Queue Implementation File
// Complete all ** parts and give good comments

// =================================================
// HW8 Priority Printer Queue 
// YOUR NAME: Kevyn Higbee
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  
	count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
void pqueue::insertjob(int j)
{
  // ** add the job j at the rear
	Q[count++] = j;
  trickleup(); // moves the job to the right place
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "printing: " << Q[0] <<endl;
  reheapify(); 
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ cout << "Jobs: " ;
  // ** loop to display jobs from slot 0 to slot count-1 horizontally
	for(int i = 0; i < count; i++)
		cout << Q[i]<< " ";
	cout << endl;
} 

// Utility functions follow: ------------------


// Purpose: to make the very last job trickle up to the right location 
void pqueue::trickleup()
{ 
	int tmp;
  int x = count-1;  // the very last job location
  // ** while x is > 0
	while(x>0)
	{
		if(Q[x] < Q[getParent(x)])
		{
			tmp = Q[x];
			Q[x] = Q[getParent(x)];
			Q[getParent(x)] = tmp;
		}
		x=getParent(x);
	}
  // compare Q[x] with the parent and if the parent is bigger swap & update x. Otherwise stop.
  //  You can call getParent to get the location of the parent

}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int child)
{  // ** return the parent location
  if(child==1)
    return 0;
	if(even(child))
		return child/2;
	else
		return child/2+1;
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; 
}


// Purpose: to reheapify the Pqueue after printing
void pqueue::reheapify()
{ 

  Q[0] = Q[count-1];  // move the last job to the front
  count--;
  int smaller, x = 0, tmp;
  // ** start at the root and repeat the following:
  while(x < count)
  {
	  smaller = getSmallerchild(x);
	  if(smaller > count)
		  return;
	  if(Q[smaller]<Q[x])
	  {
		  tmp = Q[x];
		  Q[x] = Q[smaller];
		  Q[smaller] = tmp;
	  }
	  x++;
  }
  
  // find the location of the smaller child if you have not fallen off the tree yet
  //  if the smaller child is smaller than the parent, swap
  //  else stop
}

// Purpose: to find the location of the smaller child
// where children at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{
// ** return the location of the smaller child
	int z = 2*i+1;
	
	if(Q[z] > Q[z+1])
		return z;
	else
		return z+1;
}


