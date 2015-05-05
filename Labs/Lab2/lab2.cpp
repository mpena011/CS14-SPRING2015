///////////Information/////////////
// Name: Michael Pena
// SID: 861167712
// Date: 19 April 2015
///////////////////////////////////
#include "lab2.h"

using namespace std;

bool isPrime(int i);
int primeCount(forward_list<int> lst);


int main() {
    //EX 1
    // forward_list<int> test = {3,4,5,6,7,8,9,11,13,17,19,23,29};
    // for (int & i : test) {
    //     cout << i << endl;
    // }
    // cout << "NUM OF PRIMES: " << primeCount(test) << endl;
    
    // //EX 2
    // List<int>* newList = new List<int>();
    // newList->push_front(5);
    // newList->push_front(4);
    // newList->push_front(3);
    // newList->push_front(2);
    // newList->push_front(1);
    // cout << "SIZE: " << newList->size() << endl;
    // newList->display();
    // newList->elementSwap(1);
    // newList->display();
    
    // //EX 3
    // forward_list<int> copier = {4,3};
    // forward_list<int> copied = {1,2};
    // cout << "COPIER: ";
    // for (int & i : copier) {
    //     cout << i << " ";
    // }
    // cout << endl << "COPIED: ";
    // for (int & i : copied) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // listCopy(copier, copied);
    // cout << "NEW COPIED: ";
    // for (int & i : copied) {
    //     cout << i << " ";
    // }
    // cout << endl;
    
    // //EX 4
    // forward_list<int> L = {1,2,3,4,5};
    // forward_list<int> P = {0,1,2,3,4,5};
    // printLots(L,P);
    
    
    return 0;
}

//Ex 1
//Helper function for PrimeCount, returns whether or not i is prime
bool isPrime(int i) {
    //If i is less than 2, return false
    if (i < 2) {
        return false;
    }
    //Otherwise loop until the value is determined a composite or not
    for (int j = 2; j < i; ++j) {
        if (i % j == 0) {
            return false;
        }
    }
    return true;
}


// //Counts the number of prime values in the list
int primeCount(forward_list<int> lst) {
    //if an empty list is entered, return 0
    if (lst.empty()) {
        return 0;
    }
    //Create a count
    int count = 0;
    //Check if the first value is prime, add 1 to the count
    if (isPrime(lst.front())) {
        ++count;
    }
    //Pop the front value off
    lst.pop_front();
    //Recursively call on the now smaller list, adding the returned values 
    //to count
    count += primeCount(lst);
    return count;
}
