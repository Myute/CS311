// CS311 - Demo on file IO with a user input file name
// This program is similar to fileioDemo.cpp but uses array of structs
// --------------------------------------------------------
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct member
{
    string name;
    int    age;
};

const int SIZE = 3;

int main()
{
  
    member mArray[3];

    string fname;

    cout << "Enter a file name (note: in this example we use fileioinput.txt):" << endl;
    cin >> fname;

    ifstream fin (fname.c_str(), ios::in); // declare and open

    int i = 0;
    
    while (fin >> mArray[i].name && i<3)
    {
      cout << mArray[i].name ;
      fin >> mArray[i].age;
      cout << mArray[i].age << endl;
        i++;
    }

  fin.close();
}


