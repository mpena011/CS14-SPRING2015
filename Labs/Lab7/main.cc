////////////////Information//////////////////
// Name: Michael Pena
// SID: 861167712
// Date: May 26 2015
// Approach: main for lab 7
/////////////////////////////////////////////
#include <set>
#include <unordered_set>
#include <chrono>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <ratio>
#include <iostream>

using namespace std;

int main() {
    //Establish variables, open files, create srand, and use chrono namespace
    srand(time(0));
    set<string> tree;
    unordered_set<string> table;
    vector<string> wordList;
    ifstream inFS("words.txt");
    ofstream outFS("data.txt");
    vector<double> times(4);
    //As long as the fine has not been completely read
    while (inFS.good()) {
        //Do this 10 times for each increase of 5000 words
        for (unsigned j = 0; j < 10; ++j) {
            string input;
            //Add to the vector of words
            for (unsigned i = 0; i < 5000; ++i) {
                inFS >> input;
                wordList.push_back(input);
            }
            //Randomize
            for (unsigned i = 0; i < wordList.size(); ++i) {
                unsigned random = rand() % wordList.size();
                swap(wordList.at(i),wordList.at(random));
            }
            //add n to the data
            outFS << wordList.size() << " ";
            //prepare for timing
            
            //Tree insert
            chrono::steady_clock::time_point treeIT1;
            treeIT1 = chrono::steady_clock::now();
            for (unsigned i = 0; i < wordList.size(); ++i) {
                tree.insert(wordList.at(i));
            }
            chrono::steady_clock::time_point treeIT2;
            treeIT2 = chrono::steady_clock::now();
            chrono::duration<double> treeITSpan = treeIT2 - treeIT1;
            times.at(0) = (times.at(0) + treeITSpan.count())/(j+1);
            outFS << times.at(0) << " ";
            
            //Table insert
            chrono::steady_clock::time_point tableIT1;
            tableIT1 = chrono::steady_clock::now();
            for (unsigned i = 0; i < wordList.size(); ++i) {
                table.insert(wordList.at(i));
            }
            chrono::steady_clock::time_point tableIT2;
            tableIT2 = chrono::steady_clock::now();
            chrono::duration<double> tableITSpan = tableIT2 - tableIT1;
            times.at(1) = (times.at(1) + tableITSpan.count())/(j+1);
            outFS << times.at(1) << " ";
            
            //Tree query
            chrono::steady_clock::time_point treeQT1;
            treeQT1 = chrono::steady_clock::now();
            for (unsigned i = 0; i < wordList.size(); ++i) {
                tree.find(wordList.at(i));
            }
            chrono::steady_clock::time_point treeQT2;
            treeQT2 = chrono::steady_clock::now();
            chrono::duration<double> treeQTSpan = treeQT2 - treeQT1;
            times.at(2) = (times.at(2) + treeQTSpan.count())/(j+1);
            outFS << times.at(2) << " ";
            
            //Table query
            chrono::steady_clock::time_point tableQT1;
            tableQT1 = chrono::steady_clock::now();
            for (unsigned i = 0; i < wordList.size(); ++i) {
                table.find(wordList.at(i));
            }
            chrono::steady_clock::time_point tableQT2;
            tableQT2 = chrono::steady_clock::now();
            chrono::duration<double> tableQTSpan = tableQT2 - tableQT1;
            times.at(3) = (times.at(3) + tableQTSpan.count())/(j+1);
            outFS << times.at(3);
            
            if (j != 9) {
                outFS << endl;
            }
            
            tree.clear();
            table.clear();
        }
    }
    inFS.close();
    outFS.close();
    
    return 0;
}

