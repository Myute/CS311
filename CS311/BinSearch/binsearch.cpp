using namespace std;
#include <iostream>

//--------------------------------------------
// CS311 Binary Search
// Your name: Kevyn Higbee
// Compiler: g++

// Run the demo program first and observe the results.
// All you need to do is one client file with the required function AND main.
// Complete the ** parts of binsearch.cpp
// Do not forget the required comments.
// --------------------------------------------

// x is the key that we are looking for in array L; first and last are slot numbers
int binarySearch(int L[], int x, int first, int last) 
{
  int mid;
  if(first > last) // check to see if we are in a valid space
    return -1;
  else
    {
      mid = (first+last)/2; // get middle index
      cout << "comparing against an element in slot" << mid << endl;
      if(L[mid]==x) return mid; // check against key
      else if(L[mid]>x) return binarySearch(L,x,first,mid-1); // check left subarray
      else if(L[mid]<x) return binarySearch(L,x,mid+1,last); // check right subarray
    }
}


int main()
{ 
  int A[10];
  int e;  // to look for this

  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A,e,0,9);

  if (respos == -1) cout << "Element not found" << endl; 
  else cout << "Found it in position " << respos+1 << endl;

}
