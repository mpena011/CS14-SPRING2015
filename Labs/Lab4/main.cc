////////////////Information//////////////////
// Name: Michael Pena
// SID: 861167712
// Date: 21 April 2015
// Approach: Main/test harness file for lab 4
/////////////////////////////////////////////
#include "lab4.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Error: please input an argument integer \"k\"." << endl;
        cout << "Ex: " << argv[0] << " 9 " << endl;
        exit(1);
    }
    CoPrimePairs test;
    int k = atoi(argv[1]);
    
    ////Ex 1
    // test.preorder(k);
    
    ////Ex 2
    // test.postorder(k);
    
    ////Ex 3
    //test.inorder(k);
    
    return 0;
}
