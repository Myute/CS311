#include <iostream>

using namespace std;

int fib(int x)
{
  // cout << x << "+";
  if(x == 0 || x == 1)
    return 1;
  else
    return fib(x-1) + fib (x-2);

}

int main()
{
  int x;
  cin >> x;

  cout << "\n" << fib(x);
  return 0;
}