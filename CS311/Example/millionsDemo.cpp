// CS311 - demo on N^2 complexity
// How long does this take?
// N = 1 million and this is N^2
// Do not use Optimization
// -------------------------------------------------
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int a;
    cout << "begin at: " << time(0) << endl;
    
    for (int i = 1; i <= 1000000; i++)
    { a = i + 7; }
    
    cout << "The first for loop is done at: " << time(0) << endl;
    
    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = 1; j <= 1000000; j++)
        { 
	  a = i - j + 7;
	}
	if(i%100==0)
	  cout << "Completed inner loop for " << i << "th time.\n";
    }
    cout << "The second for loop is done at: " << time(0) << endl;
    
}
