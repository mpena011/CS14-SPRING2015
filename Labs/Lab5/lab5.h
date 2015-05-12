////////////////Information//////////////////
// Name: Michael Pena
// SID: 861167712
// Date: May 12 2015
// Approach: Header file for lab 5
/////////////////////////////////////////////
#ifndef _LAB5_H_
#define _LAB5_H_

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>

using namespace std;

#define nil 0

// #define Value int // restore for testing.
template < typename Value >
class BST {
    class Node { // binary tree node
    public:
        Value value;
        Node* left;
        Node* right;
        Node( const Value v = Value() ) : value(v), left(nil), right(nil){}
        Value& content() { return value; }
        bool isInternal() { return left != nil && right != nil; }
        bool isExternal() { return left != nil || right != nil; }
        bool isLeaf() { return left == nil && right == nil; }
        int height() {
            // returns the height of the subtree rooted at this node
            // FILL IN
            if(isLeaf()) {
                return 1;
            }
            int leftHeight = 1;
            int rightHeight = 1;
            if (left != nil) {
                leftHeight += left->height();
            }
            if (right != nil) {
                rightHeight += right->height();
            }
            if (leftHeight > rightHeight) {
                return leftHeight;
            } else {
                return rightHeight;
            }
        }
        int size() {
            // returns the size of the subtree rooted at this node,
            // FILL IN
            if (isLeaf()) {
                return 1;
            }
            int totalSize = 1;
            if (left != nil) {
                totalSize += left->size();
            }
            if (right != nil) {
                totalSize += right->size();
            }
            return totalSize;
        }
    }; // Node

    // const Node* nil; // later nil will point to a sentinel node.
 
public:
    int count;
    Node* root;
    list<Node*> verCov;
    int size() {
        // size of the overall tree.
        // FILL IN
        if (root == nil) {
            return 0;
        }
        return root->size();
    }
    bool empty() { return size() == 0; }
    void print_node( const Node* n ) {
        // Print the node’s value.
        // FILL IN
        if (n != nil) {
            cout << n.content();
        }
    }
    bool search ( Value x ) {
        // search for a Value in the BST and return true iff it was found
        // FILL IN
        if (root == nil) {
            return false;
        }
        if (root->content() == x) {
            return true;
        }
        Node* traverser = root;
        while (traverser != nil) {
            if (traverser->content() == x) {
                return true;
            }
            if (x > traverser->content()) {
                traverser = traverser->right;
            }
            if (x < traverser->content()) {
                traverser = traverser->left;
            }
        }
        return false;
    }
    void preorder()const {
        // Traverse and print the tree one Value per line in preorder.
        // FILL IN
        if (root == nil) {
            return;
        }
        // //FIXME 
        int treeSize = root->size();
        Node* traverser = root;
        list<Node*> tree;
        list<Node*> line;
        while (tree.size() != treeSize) {
            while (traverser != nil) {
                cout << traverser->content() << endl;
                line.push_back(traverser);
                tree.push_back(traverser);
                traverser = traverser->left;
            }
            traverser = line.back();
            line.pop_back();
            traverser = traverser->right;
        }
    }
    void postorder()const {
        // Traverse and print the tree one Value per line in postorder
        // FILL IN
        if (root == nil) {
            return;
        }
        list<Node*> storage;
        list<Node*> output;
        Node* traverser = root;
        storage.push_front(traverser);
        while (!storage.empty()) {
            traverser = storage.front();
            output.push_front(traverser);
            storage.pop_front();
            
            if (traverser->left != nil) {
                storage.push_front(traverser->left);
            }
            if (traverser->right != nil) {
                storage.push_front(traverser->right);
            }
        }
        
        while (!output.empty()) {
            cout << output.front()->content() << endl;
            output.pop_front();
        }
    }
    
    void inorder()const {
        // Traverse and print the tree one Value per line in inorder.
        // FILL IN
        if (root == nil) {
            return;
        }
        int treeSize = root->size();
        Node* traverser = root;
        list<Node*> output;
        list<Node*> tree;
        list<Node*> line;
        while (tree.size() != treeSize) {
            while (traverser != nil) {
                if (traverser->left == nil) {
                    output.push_back(traverser);
                }
                tree.push_back(traverser);
                line.push_back(traverser);
                traverser = traverser->left;
            }
            traverser = line.back();
            list<Node*> temp = line;
            line.pop_back();
            while (!temp.empty()) {
                if (traverser == temp.front()) {
                    bool addedAlready = false;
                    list<Node*> outputTemp = output;
                    while (!outputTemp.empty()) {
                        if (traverser == outputTemp.front()) {
                            addedAlready = true;
                        }
                        outputTemp.pop_front();
                    }
                    if (!addedAlready) {
                        output.push_back(traverser);
                    }
                }
                temp.pop_front();
            }
            traverser = traverser->right;
        }
        while (!output.empty()) {
            cout << output.front()->content() << endl;
            output.pop_front();
        }
    }
    Value& operator[] (int n) {
        // returns reference to the value field of the n-th Node.
        // FILL IN
        if (root == nil) {
            cout << "Error: Attempt to access value on empty tree" << endl;
            exit(1);
        }
        if (n >= root->size()) {
            cout << "Error: Attempt to Access out of bounds for " << n <<
            "-th Node" << endl;
            exit(1);
        }
        int treeSize = root->size();
        Node* traverser = root;
        list<Node*> output;
        list<Node*> tree;
        list<Node*> line;
        while (tree.size() != treeSize) {
            while (traverser != nil) {
                if (traverser->left == nil) {
                    output.push_back(traverser);
                }
                tree.push_back(traverser);
                line.push_back(traverser);
                traverser = traverser->left;
            }
            traverser = line.back();
            list<Node*> temp = line;
            line.pop_back();
            while (!temp.empty()) {
                if (traverser == temp.front()) {
                    bool addedAlready = false;
                    list<Node*> outputTemp = output;
                    while (!outputTemp.empty()) {
                        if (traverser == outputTemp.front()) {
                            addedAlready = true;
                        }
                        outputTemp.pop_front();
                    }
                    if (!addedAlready) {
                        output.push_back(traverser);
                    }
                }
                temp.pop_front();
            }
            traverser = traverser->right;
        }
        for (int i = 0; i < n; ++i) {
            output.pop_front();
        }
        return output.front()->content();
    }
    BST() : count(0), root(nil) {}
    void insert( Value X ) { root = insert( X, root ); }
    
    Node* insert( Value X, Node* T ) {
        // The normal binary-tree insertion procedure ...
        if ( T == nil ) {
            T = new Node( X ); // the only place that T gets updated.
        } else if ( X < T->value ) {
            T->left = insert( X, T->left );
        } else if ( X > T->value ) {
            T->right = insert( X, T->right );
        } else {
            T->value = X;
        }
        // later, rebalancing code will be installed here
        return T;
    }
    void remove( Value X ) { root = remove( X, root ); }
    Node* remove( Value X, Node*& T ) {
        // The normal binary-tree removal procedure ...
        // Weiss’s code is faster but way more intricate.
        if ( T != nil ) {
            if ( X > T->value ) {
                T->right = remove( X, T->right );
            } else if ( X < T->value ) {
                T->left = remove( X, T->left );
            } else {
                // X == T->value
                if ( T->right != nil ) {
                    Node* x = T->right;
                    while ( x->left != nil ) x = x->left;
                    T->value = x->value; // successor’s value
                    T->right = remove( T->value, T->right );
                } else if ( T->left != nil ) {
                    Node* x = T->left;
                    while ( x->right != nil ) x = x->right;
                    T->value = x->value; // predecessor’s value
                    T->left = remove( T->value, T->left );
                } else { // *T is external
                    delete T;
                    T = nil; // the only updating of T
                }
            }
        }
        // later, rebalancing code will be installed here
        return T;
    }
    void okay( ) { okay( root ); }
    void okay( Node* T ) {
        // diagnostic code can be installed here
        return;
    }
    void minCoverHelper(Node* n) {
        if (n == nil) {
            return;
        }
        if (n->left != nil) {
            minCoverHelper(n->left);
        }
        if (n->left != nil || n->right != nil) {
            if (n->left != nil) {
                if (n->left->isLeaf()) {
                    verCov.push_back(n);
                }
            }
            else if (n->right != nil) {
                if (n->right->isLeaf()) {
                    verCov.push_back(n);
                }
            }
        }
        if (n->right != nil) {
            minCoverHelper(n->right);
        }
        
    }
    void minCover() {
        if (root == nil) {
            return;
        }
        minCoverHelper(root->left);
        minCoverHelper(root->right);
    } 
    void displayMinCover() {
        minCover();
        list<Node*> output = verCov;
        while (!output.empty()) {
            cout << output.front()->content() << " ";
            output.pop_front();
        }
        cout << endl << verCov.size() << endl;
    }
    
    void findSumPath(Node* n, int sum, int buffer[]) {
        if (n == nil) {
            return;
        }
        if (n->content() == sum) {
            cout << n->content();
        }
        int treeSize = n->size();
        Node* traverser = n;
        list<Node*> tree;
        list<Node*> line;
        int i = 0;
        while (tree.size() != treeSize) {
            while (traverser != nil) {
                tree.push_back(traverser);
                line.push_back(traverser);
                buffer[i] = traverser->content();
                traverser = traverser->left;
                ++i;
            }
            int tempSum = 0;
            for (int j = 0; j < i; ++j) {
                tempSum += buffer[j];
            }
            if (tempSum == sum) {
                for (int k = i-1; k >= 0; --k) {
                    cout << buffer[k] << " ";
                }
                cout << endl;
                return;
            }
            
            traverser = line.back();
            line.pop_back();
            if (traverser->isLeaf()) {
                --i;
            }
            traverser = traverser->right;
            
        }
        cout << "0" << endl;
    }
    
    void vertSum(Node* node, int hd, map<int, int>& m) {
        if (node == nil) {
            return;
        }
        pair<map<int,int>::iterator, bool> ret = m.insert(pair<int,int>
            (hd, node->content()));
        if (!ret.second) {
            int sum = node->content() + m[hd];
            m[hd] = sum;
        }
        vertSum(node->left, hd-1, m);
        vertSum(node->right, hd+1, m);
        if (node == root) {
            vertSumOutput(m);
        }
    }
    void vertSumOutput(map<int, int> & m) {
        int lowest = 0;
        int highest = 0;
        for (map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
            if (it->first < lowest) {
                lowest = it->first;
            }
            if (it->first > highest) {
                highest = it->first;
            }
        }
        for (int i = lowest; i <= highest; ++i) {
            int sum = 0;
            for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
                if (it->first == i) {
                    sum += it->second;
                }
            }
            cout << sum << " ";
        }
        cout << endl;
    }
    
}; // BST




#endif