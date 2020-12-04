//CS311 dgraph.cpp
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW9-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW9 dgraph
// Name: Kevyn Higbee
// File Type: dGraph.cpp
//========================================================

using namespace std;

#include <iostream>
#include "dgraph.h"
#include <fstream>
#include <iomanip>

dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0
{
    countUsed = 0;
  for(int i = 0; i < SIZE; i++)
    {
        Gtable[i].vertexName = ' ';
        Gtable[i].visit = 0;
    }
}
dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{

}
void dgraph::fillTable()  // make sure to read from table.txt file
{
    // open file
    ifstream fin;
    fin.open("table.txt");

    char x;

    // read data
    while(fin >> Gtable[countUsed].vertexName)
    {
        // read degree
        fin >> Gtable[countUsed].outDegree;
        // read adjacencies
        for(int i = 0; i < Gtable[countUsed].outDegree; i++)
        {
            fin >> x;
            Gtable[countUsed].adjacentOnes.addRear(x);
        }
        countUsed++;
    }

}
void dgraph::displayGraph() // make sure to display
// in a really nice format -- all columns
{
  for(int i = 0; i < countUsed; i++)
    {
        if(Gtable[i].vertexName != ' ')
        {
            cout << Gtable[i].vertexName << " " << Gtable[i].outDegree << "\t" << Gtable[i].visit << " ";
            Gtable[i].adjacentOnes.displayAll();
            cout << endl;
        }
    }
}
int dgraph::findOutDegree(char V)// throws exception
// does not use a loop
{
    return Gtable[V-65].outDegree;
}
slist dgraph::findAdjacency(char V)// throws exception
// does not use a loop
{
    return Gtable[V-65].adjacentOnes;
}

void dgraph::visit(int order, char V)
{
    if(V-65 >= countUsed) throw BadVertex();
    else Gtable[V-65].visit = order;
}

bool dgraph::isMarked(char V)
{
    return (Gtable[V-65].visit > 0);
}