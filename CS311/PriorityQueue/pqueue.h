// CS311
// - header file for priority printer queue
// - heaptree priority queue impleneted using an array
// DO NOT CHANGE THIS FILE!
// ---------------------------------------------

#include <iostream>
using namespace std;

class pqueue
{
  private:

  int Q[10];   // array holding jobs - only priority numbers are stored
  int count;   // how many jobs are in the array
               // jobs are in slots 0 through count-1

  // Utility functions
  void reheapify();  // reheapify after printing
      // - involves moving the last job to the front and trickling down
  int  getSmallerchild(int);  // return location of the smaller child
                  //- compares L and R children of the given location
  void trickleup();    // trickling up after adding at the rear
  int getParent(int);  // return the parent location given the child loc
  bool even(int);      // is the number even?  Needed to find the parent

public:
    pqueue();
    ~pqueue();
    void insertjob(int);  // supply the job priority number
    void printjob();      // print a job
    void displayAll();    // display all jobs

};
