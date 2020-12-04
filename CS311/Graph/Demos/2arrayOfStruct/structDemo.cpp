// CS311 - Struct Demo : how to store and how to display
// an array of structs
// ------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

// student is a type of struct/record with 4 fields.
struct student
{
  string Name;
  char   Gender;
  string Major;
  int    Age;
};
// do not forget the semicolon


// function prototypes
void GatherData(student[], int);
void DisplayStudent(student[], int);


int main()
{
  // Local variables are MyClass and s

  student MyClass[10];  //MyClass array is an array of structs made up of students
  
  // Gather data on students. Max is 10 students.
  GatherData(MyClass, 10);
  // Display info on all students.
  for (int s=0; s < 10; s++)
      DisplayStudent(MyClass, s);

}// end of main

//Purpose: 
//  To fill the passed array with student data entered by the user
//  If the user quit before entering info for all 20 students
//  the reamining slots will be filled by defaults values.
//Parameters: Slist array to hold student data, size is the array size
//Algorithm:
//  Uses a while loop that stops as soon as the user enters Q or q
//  or the slot exceeds size-1.  For the rest, Default will be used.
void GatherData(student Slist[], int size)
{
  // local variables known only inside this function
  student Default = {"Smith", 'M', "CS", 20};
  int i = 0;  // slot counter
  char ans;   // user answer

    cout << "In function GatherData..." << endl;
    cout << "This function Gathers information for 20 students." << endl;
    cout << "If you quit the loop before you enter info for all students," << endl;
    cout << "the rest of students get the default values. " << endl;

  // while loop to enter data until the user types in N
  cout << "Enter any character other than Q or q to start:";
  cin >> ans;
  while (((ans != 'Q') && (ans != 'q')) && (i < size))
    {
      cout << "Enter the last name for student #" << i+1 << ": " ;
      cin >> Slist[i].Name;
      cout << "Enter the gender for student #" << i+1 << " (character M or F): " ;
      cin >> Slist[i].Gender;
      cout << "Enter the major for student #" << i+1 << ": " ;
      cin >> Slist[i].Major;
      cout << "Enter the age for student #" << i+1 << ": " ;
      cin >> Slist[i].Age;

      cout << "Enter Q or q to quit. Enter some other character to continue: ";
      cin >> ans;
      i++;  // go to the next slot
    }// end of while loop
  
  // i at this point is the number of students entered by the user
  // Fill with Default for the remaining students.
  for (int j = i; j < size; j++)
    {
      Slist[j] = Default;
    } //end of for loop
  
}//end of Gather Data


//Purpose: To display info of one student
//Parameters: 
//  Slist array holding student data, slot is where the given student
//  record is found
//Algorithm:  nicely formats with couts 
void DisplayStudent(student Slist[], int slot)
{

  cout << "Name: " << Slist[slot].Name << endl;
  cout << "Gender: " << Slist[slot].Gender << endl;
  cout << "Major: " << Slist[slot].Major << endl;
  cout << "Age: " << Slist[slot].Age << endl;
  cout << "------------------------------------" << endl;

}// end of DisplayStudent

