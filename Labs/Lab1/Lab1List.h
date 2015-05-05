/////////Information/////////
//  Name: Michael Pena  
//  SID: 861167712      
//  Date: April 7, 2015 
//  Approach: Header File for
//    the Lab1List class
/////////////////////////////
#ifndef _LAB1LIST_H_
#define _LAB1LIST_H_
#include "Node.h"

class Lab1List {
protected:
    Node* head;
    Node* tail;
public:
    //Constructors & Destructor
    Lab1List(); //Default Constructor
    Lab1List(const std::string & data); //Constructor with a string passed in
    ~Lab1List();//Destructor
    //Functions
    void push(char val); //pushes a val to the end of the list
    void display() const; //prints the list
    void rotate(int k);//Rotate linked-list counter-clockwise k positions
    //Operator overloading
    //Adds original input list and rotated list
    Lab1List & operator+(Lab1List & head2);
};

#endif