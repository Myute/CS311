using namespace std;
#include <iostream>
#include <vector>

//--------------------------------------------
//CS311 Combine 
//Name: Kevyn Higbee
//Compiler: g++
//--------------------------------------------

// combines two sorted lists A and B into R.
// displays comparison every time it is done.
// The size of A and B are the same or A is 1 element shorter
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
  int i=0, j=0; // array indexing variables

  while((i<A.size())&&(j<B.size()))
    {
      // see which element is less and insert it into r vector
      cout << "comparison between " << A[i] << " and " << B[j] << endl;
      if(A[i] < B[j])
	{
	  R.push_back(A[i++]);
	}
      else
	{
	  R.push_back(B[j++]);
	}
    }
  // insert remaining elements from vector a
  while(i<A.size())
    R.push_back(A[i++]);
  // insert remaining elements from vector b
  while(j<B.size())
    R.push_back(B[j++]);
}


int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // number of elements in each of L1 and L2
  int e;  // to enter each element

  cout << "How many elements would you like to enter into each sublist?" << endl;
  cin >> N;

    cout << "Please enter elements of List1 in increasing order:"  << endl;
  for (int i = 1; i <=N; i++)
    {
        cout << "element :"; cin >> e;
	while(L1.size() > 0 && e < L1.back())
	  {
	    cout << "Please enter elements in increasing order: ";
	    cin >> e;
	  }
	L1.push_back(e);
    }

    cout << "Please enter elements of List2 in increasing order:"  << endl;
  for (int i = 1; i <=N; i++)
    {
        cout << "element :"; cin >> e;
        while(L2.size() > 0 && e < L2.back())
	  {
	    cout << "Please enter elements in increasing order:";
	    cin >> e;
	  }
	L2.push_back(e);
    }
  
  combine(L1,L2,L3);
  // call combine here to combine L1 and L2 into L3
  
  cout << "The combined list is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i] << " "; } cout << endl;

}// end of main
