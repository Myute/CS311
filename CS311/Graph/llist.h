//CS311
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW5 llist
// Your name: Kevyn Higbee
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef char el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t elem;   // elem is the element stored
  Node *next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *front;       // pointer to the front node
  Node *rear;        // pointer to the rear node
  int  count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  // returns if list is empty
  bool isEmpty();
    
  // displays list contents
  void displayAll();

  // adds element to front of list
  void addFront(el_t);
    
  // appends elem to list
  void addRear(el_t);

  // removes elem from front of list
  void deleteFront(el_t&);
    
  // removes elem from end of list
  void deleteRear(el_t&);
    
  // removes Ith item in list
  void deleteIth(int, el_t&);

  // inserts elem at Ith index in list
  void insertIth(int, el_t);

  //Copy Constructor to allow pass by value and return by value
  llist(const llist&);
  
  //Overloading of = 
  llist& operator=(const llist&); 

};
