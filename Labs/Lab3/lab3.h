////////////////Information//////////////////
// Name: Michael Pena
// SID: 861167712
// Date: 21 April 2015
// Approach: Header file for lab 3
/////////////////////////////////////////////

#ifndef _LAB3_H_
#define _LAB3_H_

#include <iostream>
#include <stack>

using std::stack;
using std::cout;
using std::endl;

template <class T>
class TwoStackFixed {
private:
    T* array;
    int size;
    int maxtop;
    int stack1top;
    int stack2top;
    
public:
    TwoStackFixed(int size, int maxtop);
    void pushStack1(T value);
    void pushStack2(T value);
    T popStack1();
    T popStack2();
    bool isFullStack1();
    bool isFullStack2();
    bool isEmptyStack1();
    bool isEmptyStack2();
    void display();
};


//Constructor
template <class T>
TwoStackFixed<T>::TwoStackFixed(int size, int maxtop) {
    //If the maxtop is out of bounds compared to size, return with error
    if (maxtop < 0 || maxtop > size) {
        cout << "Error: Attempt to create TwoStackFixed variable with" 
        << " out of bounds maxtop" << endl;
        return;
    }
    //Otherwise establish the parameters
    this->size = size;
    array = new T[size];
    this->maxtop = maxtop;
    stack1top = -1;
    stack2top = size;
}

//pushStack1 will push a value onto stack 1
template <class T>
void TwoStackFixed<T>::pushStack1(T value) {
    //If stack overflow occurs, output error and exit
    if (stack1top+1 > maxtop) {
        cout << "Error: Overflow on stack1. Could not add to stack1: " <<
        value << endl;
        exit(1);
    }
    //Otherwise add the value to the stack
    stack1top += 1;
    array[stack1top] = value;
    //Then display
    display();
    
}

//pushStack2 will push a value onto stack 2
template <class T>
void TwoStackFixed<T>::pushStack2(T value) {
    //If stack overflow occurs, output error and exit
    if (stack2top-1 <= maxtop) {
        cout << "Error: Overflow on stack2. Could not add to stack2: " <<
        value << endl;
        exit(1);
    }
    //Otherwise add the value to the stack
    stack2top -= 1;
    array[stack2top] = value;
    //Then display
    display();
}

//popStack1 will pop a value off stack 1 and return it
template <class T>
T TwoStackFixed<T>::popStack1() {
    //If there is an underflow error, output an error message
    if (stack1top < 0) {
        cout << "Error: Underflow on stack1. Could not remove from stack1."
        << endl;
        exit(1);
    }
    //Otherwise pop the value off
    stack1top -= 1;
    return array[stack1top+1];
}

//popStack2 will pop a value off stack 2 and return it;
template <class T>
T TwoStackFixed<T>::popStack2() {
    //If there is an underflow error, output an error message
    if (stack2top >= size) {
        cout << "Error: Underflow on stack2. Could not remove from stack2."
        << endl;
        exit(1);
    }
    //Otherwise pop the value off
    stack2top += 1;
    return array[stack2top-1];
}

//isFullStack1 will return whether or not stack 1 is full
template <class T>
bool TwoStackFixed<T>::isFullStack1() {
    if (stack1top == maxtop) {
        return true;
    }
    return false;
}

//isFullStack2 will return whether or not stack 2 is full
template <class T>
bool TwoStackFixed<T>::isFullStack2() {
    if (stack2top-1 == maxtop) {
        return true;
    }
    return false;
}

//isEmptyStack1 returns whether or not stack 1 is empty
template <class T>
bool TwoStackFixed<T>::isEmptyStack1() {
    if (stack1top == -1) {
        return true;
    }
    return false;
}

//isEmptyStack2 returns whether or not stack 2 is empty
template <class T>
bool TwoStackFixed<T>::isEmptyStack2() {
    if (stack2top == size) {
        return true;
    }
    return false;
}

//display function
template <class T>
void TwoStackFixed<T>::display() {
    for (int i = 0; i < stack1top+1; ++i) {
        cout << array[i] << " ";
    }
    for (int i = stack1top+1; i < stack2top; ++i) {
        cout << "  ";
    }
    for (int i = stack2top; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}


template <class T>
class TwoStackOptimal {
private:
    T* array;
    int size;
    int stack1top;
    int stack2top;
public:
    TwoStackOptimal(int size);
    void pushFlexStack1(T value);
    void pushFlexStack2(T value);
    T popFlexStack1();
    T popFlexStack2();
    bool isFullStack1();
    bool isFullStack2();
    bool isEmptyStack1();
    bool isEmptyStack2();
    void display();
};

//Constructor for TwoStackOptimal
template <class T>
TwoStackOptimal<T>::TwoStackOptimal(int size) {
    this->size = size;
    array = new T[size];
    stack1top = -1;
    stack2top = size;
}

//pushFlexStack1 pushes a value onto stack 1
template <class T>
void TwoStackOptimal<T>::pushFlexStack1(T value) {
    //Check for overflow, and exit if overflow occurs
    if (stack1top+1 > size) {
        cout << "Error: Overflow on stack1. Could not add to stack1: " <<
        value << endl;
        exit(1);
    }
    //Otherwise push the value on
    stack1top += 1;
    if (stack1top == stack2top) {
        stack2top += 1;
    }
    array[stack1top] = value;
    //Then display
    display();
}

//pushFlexStack2 pushes a value onto stack 2
template <class T>
void TwoStackOptimal<T>::pushFlexStack2(T value) {
    //Check for overflow, and exit if overflow occurs
    if (stack2top-1 < 0) {
        cout << "Error: Overflow on stack2. Could not add to stack2: " <<
        value << endl;
        exit(1);
    }
    //Otherwise push the value on
    stack2top -= 1;
    if (stack2top == stack1top) {
        stack1top -= 1;
    }
    array[stack2top] = value;
    //Then display
    display();
}

//popFlexStack1 pops a value off stack 1 and returns it
template <class T>
T TwoStackOptimal<T>::popFlexStack1() {
    //Ensure underflow does not occur, post an error message if so
    if (stack1top < 0) {
        cout << "Error: Underflow on stack1. Could not remove from stack1."
         << endl;
         exit(1);
    }
    //Otherwise pop the value off
    stack1top -= 1;
    return array[stack1top+1];
}

//popFlexStack2 pops a value off stack 2 and returns it
template <class T>
T TwoStackOptimal<T>::popFlexStack2() {
    //Ensure underflow does not occur, post an error message if so
    if (stack2top > size) {
        cout << "Error: Underflow on stack2. Could not remove from stack2."
        << endl;
        exit(1);
    }
    stack2top += 1;
    return array[stack2top-1];
}

//isFullStack1 will return whether or not stack 1 is full
template <class T>
bool TwoStackOptimal<T>::isFullStack1() {
    if (stack1top+1 == size || stack1top+1 == stack2top) {
        return true;
    }
    return false;
}

//isFullStack2 will return whether or not stack2 is full
template <class T>
bool TwoStackOptimal<T>::isFullStack2() {
    if (stack2top-1 == -1 || stack2top-1 == stack1top) {
        return true;
    }
    return false;
}

//isEmptyStack1 returns whether or not stack 1 is empty
template <class T>
bool TwoStackOptimal<T>::isEmptyStack1() {
    if (stack1top == -1) {
        return true;
    }
    return false;
}

//isEmptyStack2 returns whether or not stack 2 is empty
template <class T>
bool TwoStackOptimal<T>::isEmptyStack2() {
    if (stack2top == size) {
        return true;
    }
    return false;
}

//display function
template <class T>
void TwoStackOptimal<T>::display() {
    for (int i = 0; i < stack1top+1; ++i) {
        cout << array[i] << " ";
    }
    for (int i = stack1top+1; i < stack2top; ++i) {
        cout << "  ";
    }
    for (int i = stack2top; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}



//Ex3 Tower of Hanoi
template <typename T>
void showTowerStates(int n, stack<T> & A, stack<T> & B, stack<T> & C) {
    static stack<T>* address[3] = {&A, &B, &C};
    static char name[3] = {'A','B','C'};
    if (n == 0) {
        return;
    }
    int newPegA = -1;
    int newPegC = -1;
    for (int i = 0; i < 3; ++i) {
        if (&A == address[i]) {
            newPegA = i;
        }
        if (&C == address[i]) {
            newPegC = i;
        }
    }
    showTowerStates(n-1, A, C, B);
    T value = A.top();
    A.pop();
    C.push(value);
    cout << "Moved " << value << " from peg " << name[newPegA] << " to "
    << name[newPegC] << endl;
    showTowerStates(n-1,B,A,C);
    return;
}
#endif