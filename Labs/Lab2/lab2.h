///////////Information/////////////
// Name: Michael Pena
// SID: 861167712
// Date: 19 April 2015
///////////////////////////////////
#ifndef _LAB2_H_
#define _LAB2_H_

#include <forward_list>
#include <iostream>

using std::cout;
using std::endl;

template <typename T> struct Node {
    T data;
    Node* next;
    Node(T data) : data(data), next(0) {}
};


template <class T>
class List {
private:
    Node<T>* head;
    
public:
    List();
    void push_front(T data);
    void elementSwap(int pos);
    int size() const;
    void display() const;
};



//List default constructor
template <class T>
List<T>::List() {
    head = 0;
}

//push_front adds a value to the front of the list
template <class T>
void List<T>::push_front(T data) {
    Node<T>* temp = new Node<T>(data);
    temp->next = head;
    head = temp;
}

//elementSwap swaps the element at pos with the element at pos+1
template <class T>
void List<T>::elementSwap(int pos) {
    if (pos + 1 >= size() || pos < 0) {
        cout << "ERROR: Out of bounds call" << endl;
        return;
    }
    if (pos == 0) {
        Node<T>* newHead = head->next;
        head->next = head->next->next;
        newHead->next = head;
        head = newHead;
        return;
    }
    
    Node<T>* iterator = head;
    Node<T>* previous = head;
    for (int i = 0; i < pos; ++i,iterator = iterator->next);
    for (int i = 0; i < pos-1; ++i, previous = previous->next);
    Node<T>* switcher = iterator->next;
    iterator->next = switcher->next;
    switcher->next = iterator;
    previous->next = switcher;
    return;
}


//size returns the size of the list
template <class T>
int List<T>::size() const {
    int count = 0;
    Node<T>* iterator = head;
    while(iterator != 0) {
        ++count;
        iterator = iterator->next;
    }
    return count;
}

//simple display function
template <class T>
void List<T>::display() const {
    if (head == 0) {
        return;
    }
    Node<T>* iterator = head;
    while (iterator != 0) {
        cout << iterator->data << " ";
        iterator = iterator->next;
    }
    cout << endl;
}



//Exercise 3
//copies list L reversed onto the end of list P
template <typename Type>
void listCopy(std::forward_list<Type> L, std::forward_list<Type> & P) {
    //Check if P is empty, if so return L reversed
    if (P.empty()) {
        for (Type & it : L) {
            P.insert_after(P.before_begin(),it);
        }
        return;
    }
    //Otherwise find the last value and keep adding to after that for as
    //long as there is values in L
    auto PEnd = P.begin();
    auto PLast = PEnd;
    for (PEnd = P.begin(); PEnd != P.end(); ++PEnd) {
        PLast = PEnd;
    }
    for (Type & it : L) {
        P.insert_after(PLast, it);
    }
}



//Exercise 4
//Print the elements of L based on the numeric values of P as positions
template <typename Type>
void printLots(std::forward_list<Type> L, std::forward_list<int> P) {
    //Find the size of L and output a message if a value in P exceeds
    //That value in L, otherwise output the value normally
    auto iter = L.begin();
    int size = 0;
    for (iter = L.begin(); iter != L.end(); ++iter) {
        ++size;
    }
    //Loop through the position list P
    for (int & it : P) {
        //Output error if negative position is entered
        if (it < 0) {
            cout << endl << "ERROR: Out of bounds call on L with P value: "
            << it << endl;
            return;
        }
        //Output error if position greater than size is entered
        if (it >= size) {
            cout << endl << "ERROR: Out of bounds call on L with P value: " 
            << it << endl;
            return;
        }
        //Otherwise output the value
        auto iterator = L.begin();
        int i = 0;
        for (iterator = L.begin(), i = 0; i < it; ++i, ++iterator);
        cout << *iterator << " ";
    }
    cout << endl;
}


#endif