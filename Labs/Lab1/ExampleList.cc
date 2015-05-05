/////////Information/////////
//  Name: Michael Pena  
//  SID: 861167712      
//  Date: April 7, 2015 
//  Approach: Source file for
//    all functions in our
//    Lab1List class
/////////////////////////////
#include "Lab1List.h"
#include <iostream>

using namespace std;

//Default Constructor
Lab1List::Lab1List() {
    //set head and tail to be 0 as the list is empty
    head = 0;
    tail = 0;
}

//Constructor passing in a string of values entered in by the user
Lab1List::Lab1List(const std::string & data) {
    if (!data.empty()) {
        //Create a starting Node with the first character of the string
        char hold = data.at(0);
        Node* lead = new Node(hold);
        head = lead;
        tail = lead;
        
        //Loop until the string is completely changed into the linked list
        for(unsigned i = 1; i < data.size(); ++i) {
            hold = data.at(i);
            Node* adder = new Node(hold);
            tail->next = adder;
            tail = tail->next;
        }
    }
}

//Destructor
Lab1List::~Lab1List() {
    //Loop deleting each head until the list is empty
    while (head != 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    //Guards to ensure no dangling pointers
    head = 0;
    tail = 0;
}

//push pushes the val to the end of the list, creating a new node for it
void Lab1List::push(char val) {
    Node* temp = new Node(val);
    //If the list is empty, create a new node which head and tail point to
    if (head == 0) {
        head = temp;
        tail = temp;
        return;
    }
    //Otherwise add it to the end of the list
    tail->next = temp;
    tail = tail->next;
    tail->next = 0;
    return;
}

//Display function, displays each character separated by a space
void Lab1List::display() const {
    if (head != 0) {
        Node* iterator = head;
        //Basic loop to iterate through the list and output everything
        while (iterator != 0) {
            cout << iterator->data << " ";
            iterator = iterator->next;
        }
    }
    return;
}

//Rotate will rotate the list k times
void Lab1List::rotate(int k) {
    if (k == 0 || head == 0) {
        return;
    }
    //Create two temporary iterator nodes
    Node* newHead = head;
    Node* newTail = head;
    tail->next = head;
    //Loop until the destination is reached
    for (int i = 0; i < k; ++i,newHead = newHead->next) {
        newTail = newHead;
    }
    //Point our head and tail to the new head and new tail
    head = newHead;
    tail = newTail;
    tail->next = 0;
    return;
}

//Overloaded operator + will add a rotated list to the original,
//unrotated list and return a new dynamically allocated list
Lab1List & Lab1List::operator+(Lab1List & head2) {
    //Create new List and iterators for the two lists
    Lab1List* newList = new Lab1List();
    Node* iterator = this->head;
    Node* adder = head2.head;
    //Loop to fill the new list with the implicit list
    while (iterator != 0) {
        newList->push(iterator->data);
        iterator = iterator->next;
    }
    //Loop to now add values from the explicit list to our new list
    iterator = newList->head;
    while (adder != 0) {
        iterator->data += adder->data;
        iterator = iterator->next;
        adder = adder->next;
    }
    //return the new list
    return *newList;
}

