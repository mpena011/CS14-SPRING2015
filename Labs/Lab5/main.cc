////////////////Information//////////////////
// Name: Michael Pena
// SID: 861167712
// Date: May 12 2015
// Approach: main for lab 5
/////////////////////////////////////////////
#include "lab5.h"

using namespace std;

int main() {
    ////ex1
    cout << "Part 1" << endl;
    BST<int>* test = new BST<int>();
    test->insert(50);
    test->insert(20);
    test->insert(10);
    test->insert(40);
    test->insert(35);
    test->insert(45);
    test->insert(60);
    test->insert(70);
    test->displayMinCover();
    
    //ex2
    cout << "Part 2" << endl;
    int buffer[1000];
    test->findSumPath(test->root, 80, buffer);
    
    //ex3
    cout << "Part 3" << endl;
    map<int,int> m;
    test->vertSum(test->root, 0, m);
    
    return 0;
}