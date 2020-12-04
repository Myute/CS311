// CS311
// HW 10 Client File

// ================================================
// HW#: HW10 dgraph client
// Name: Kevyn Higbee
// File type:  hw10client.cpp
// ================================================

#include <iostream>
#include "dgraph.h"
#include "stack.h"

void stackFunc(char, dgraph&, stack&);

int main()
{
    int visit = 1;
    char c = 'A';
    stack s;
    dgraph d;

    d.fillTable();
    cout << "Filled the Table" << endl;
    d.displayGraph();
    s.push(c);

    while(!s.isEmpty())
    {
        s.pop(c);
        cout << "Removing " << c << " from stack\n" << "\tVisiting " << c << " as " << visit << endl;

        if(!d.isMarked(c))
            d.visit(visit++, c);
        
        stackFunc(c, d, s);
        cout << "Stack:\n";
        s.displayAll();
        cout << endl;
        d.displayGraph();
    }
}

void stackFunc(char c, dgraph& d, stack& s)
{
    char tmp;
    slist adjacent = slist(d.findAdjacency(c));
    tmp = ' ';
    adjacent.displayAll();
    while(!adjacent.isEmpty())
    {
        adjacent.deleteRear(tmp);
        if(!d.isMarked(tmp))
        {
            s.push(tmp);
            cout << "pushed " << tmp << ".\n";
        }
    }
}