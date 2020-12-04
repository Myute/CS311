// CS311 - Demo on file IO with a user input file name
// This makes sure it stops at the end of file 
// --------------------------------------------------------
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{ string name;
  int age;

  string fname;

    cout << "Enter a file name (note: in this example we use fileioinput.txt):" << endl;
  cin >> fname;

  ifstream fin (fname.c_str(), ios::in); // declare and open 

  while (fin >> name)
    {
      cout << name ;
      fin >> age;
      cout << age << endl;
    }

  fin.close();
}


