//  hashNode.hpp
//  Author: Max Luu

#ifndef hashNode_hpp
#define hashNode_hpp

#include <stdio.h>
#include <string>
#include <time.h>
using namespace std;
class hashNode {
    friend class hashMap;
    string keyword;
    string *values;
    hashNode* next;
    int valuesSize;
    int currSize;
    
public:
    hashNode();
    hashNode(string s);
    hashNode(string s, string v);
    void addValue(string v);
    void dblArray();
    string getRandValue();
};


#endif /* hashNode_hpp */
