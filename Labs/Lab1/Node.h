/////////Information/////////
//  Name: Michael Pena  
//  SID: 861167712      
//  Date: April 7, 2015 
//  Approach: Header file for
//    Node class which I made
//    as a struct to make
//    it easier for myself
/////////////////////////////
#ifndef _NODE_H_
#define _NODE_H_
#include <string>
using std::string;
struct Node {
    char data;
    Node* next;
    //Constructor making variable data passed in become our data and next
    //point to NULL
    Node(char data):data(data), next(0) {}
};


#endif