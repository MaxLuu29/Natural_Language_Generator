//  hashNode.cpp
//  Author: Max Luu

#include "hashNode.hpp"
hashNode::hashNode() {
    keyword = "";
    valuesSize = 0;
    currSize = 0;
    values = NULL;
    next = NULL;
}

hashNode::hashNode(string s) {
    srand((unsigned)time(NULL));
    keyword = s;
    valuesSize = 100;
    currSize = 0;
    values = new string[valuesSize];
    next = NULL;
    
}

hashNode::hashNode(string s, string v) {
    srand((unsigned)time(NULL));
    keyword = s;
    valuesSize = 100;
    currSize = 1;
    values = new string[valuesSize];
    values[0] = v;
    next = NULL;
}

void hashNode::addValue(string v) {
    if (currSize == valuesSize) {
        dblArray();
    }
    
    values[currSize] = v;
    currSize++;
}

void hashNode::dblArray() {
    valuesSize *= 2;
    string* arr = new string[valuesSize];
    for (int i = 0; i < valuesSize; i++) {
        values[i] = arr[i];
    }
    values = arr;
    
}

string hashNode::getRandValue() {
    if (currSize == 0) {
        return "";
    } else {
        int i;
        do {
            i = rand() % currSize;
        } while (values[i] == "");
        return values[i];
    }
}
