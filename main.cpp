//  main.cpp
//  Author: Max Luu

#include <iostream>
#include "hashNode.hpp"
#include "hashMap.hpp"
#include "makeSeuss.hpp"
int main(int argc, const char* argv[]) {
    makeSeuss book = makeSeuss("DrSeuss.txt", "HashFunction2-Collision2", false, false);
    makeSeuss book2 = makeSeuss("DrSeuss.txt", "HashFunction1-Collision1", true, true);
    makeSeuss book3 = makeSeuss("DrSeuss.txt", "HashFunction1-Collision2", true, false);
    makeSeuss book4 = makeSeuss("DrSeuss.txt", "HashFunction2-Collision1", false, true);

    cout<<"HashFunction2-Collision2"<<endl;
    book.getHashMap()->printMap();

    cout<<"HashFunction1-Collision1"<<endl;
    book2.getHashMap()->printMap();

    cout<<"HashFunction1-Collision2"<<endl;
    book3.getHashMap()->printMap();

    cout<<"HashFunction2-Collision1"<<endl;
    book4.getHashMap()->printMap();

    return 0;
}
