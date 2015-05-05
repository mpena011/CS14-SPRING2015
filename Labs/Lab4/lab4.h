////////////////Information//////////////////
// Name: Michael Pena
// SID: 861167712
// Date: 21 April 2015
// Approach: Header file for lab 4
/////////////////////////////////////////////
#ifndef _LAB4_H_
#define _LAB4_H_

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using std::cout;
using std::endl;
using std::pair;

typedef pair<int,int> Entry;
class priority_queue {
public:
    vector<Entry> entries;
    Entry& front() { return entries.back(); }
    void pop() { entries.pop_back(); }
    void push( Entry e ) { 
        entries.push_back( e );
        for ( int i = entries.size()-1; i != 0; --i ) {
            int sum1 = entries[i].first + entries[i].second;
            int sum2 = entries[i-1].first + entries[i-1].second;
            if ( sum1 < sum2 ) break;  
            // replace this comparison with code for comparing int pairs.
            swap(entries[i], entries[i-1]);
        }
        for (int i = entries.size()-1; i != 0; --i) {
            int sum1 = entries[i].first + entries[i].second;
            int sum2 = entries[i-1].first + entries[i-1].second;
            if (sum1 == sum2) {
                if (entries[i].first > entries[i-1].first) {
                    swap(entries[i], entries[i-1]);
                }
            }
        }
    }
};

class CoPrimePairs {
public:
    void preorder(int k);
    void postorder(int k);
    void inorder(int k);
    void preOrderRecursive(int m, int n, int k);
    void postOrderRecursive(int m, int n, int k);
    void inOrderRecursive(int m, int n, int k, priority_queue & List);
};


//Prints the pairs whose sum is less than k in pre order
void CoPrimePairs::preorder(int k) {
    //Using recursive function we can solve for it
    preOrderRecursive(2,1,k);
    preOrderRecursive(3,1,k);
}

//Helper function for preorder
void CoPrimePairs::preOrderRecursive(int m, int n, int k) {
    //As long as m + n are less than k, continue recursively outputting pairs
    if (m + n < k) {
        cout << m << " " << n << endl;
        preOrderRecursive(2*m - n, m, k);
        preOrderRecursive(2*m + n, m, k);
        preOrderRecursive(m + 2*n, n, k);
    }
    return;
}

//Prints the pairs whose sum is less than k in post order
void CoPrimePairs::postorder(int k) {
    postOrderRecursive(2,1,k);
    postOrderRecursive(3,1,k);
}

//Helper function for postorder
void CoPrimePairs::postOrderRecursive(int m, int n, int k) {
    if (m + n < k) {
        postOrderRecursive(2*m - n, m, k);
        postOrderRecursive(2*m + n, m, k);
        postOrderRecursive(m + 2*n, n, k);
        cout << m << " " << n << endl;
    }
    return;
}

//Prints te pairs whose sum is less than k in order
void CoPrimePairs::inorder(int k) {
    priority_queue list;
    if (k > 3) {
        pair<int,int> temp (2,1);
        list.push(temp);
    }
    if (k > 4) {
        pair<int,int> temp (3,1);
        list.push(temp);
    }
    if (k > 3) {
        inOrderRecursive(2,1,k,list);
    }
    if (k > 4) {
        inOrderRecursive(3,1,k,list);
    }
    while (list.entries.size() != 0) {
        cout << list.front().first << " " << list.front().second << endl;
        list.pop();
    }
}

//Helper function for inorder
void CoPrimePairs::inOrderRecursive(int m, int n, int k, priority_queue& List){
    if (m + n < k) {
        if ((2*m - n) + m < k) {
            cout << "Pushing back : " << 2*m - n << " " << m << endl;
            pair<int,int> temp(2*m - n,m);
            List.push(temp);
        }
        if ((2*m + n) + m < k) {
            cout << "Pushing back : " << 2*m + n << " " << m << endl;
            pair<int,int> temp(2*m + n,m);
            List.push(temp);
        }
        if ((m + 2*n) + n < k) {
            cout << "Pushing back : " << m + 2*n << " " << n << endl;
            pair<int,int> temp(m + 2*n,n);
            List.push(temp);
        }
        if (2*m - n < k) {
            inOrderRecursive(2*m - n, m, k, List);
        }
        if (2*m + n < k) {
            inOrderRecursive(2*m + n, m, k, List);
        }
        if (m + 2*n < k) {
            inOrderRecursive(m + 2*n, n, k, List);
        }
    }
}




#endif