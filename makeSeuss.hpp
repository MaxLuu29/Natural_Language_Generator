//  makeSeuss.hpp
//  Author: Max Luu

#ifndef makeSeuss_hpp
#define makeSeuss_hpp

#include "hashMap.hpp"
#include <iostream>
#include <fstream>
class makeSeuss {
    hashMap *ht;
    string fn;
    string newfile;
public:
    hashMap* getHashMap();
    makeSeuss(string file, string newf, bool h1, bool c1);
    void readFile();
    void writeFile();
    
};
#endif /* makeSeuss_hpp */
