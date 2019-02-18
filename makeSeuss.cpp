//  makeSeuss.cpp
//  Author: Max Luu

#include "makeSeuss.hpp"
makeSeuss::makeSeuss(string f1, string f2, bool h1, bool c1) {
    ht = new hashMap(h1,c1);
    newfile = f2;
    fn = f1;
    readFile();
    writeFile();
}

void makeSeuss::readFile() {
    ifstream infile(fn.c_str(),ios::in); //open file
    string key = "";
    string value = "";
    infile>>key;
    ht->first = key;
    while (infile >> value) {
        cout<<key<<": "<<value<<endl;
        ht->addKeyValue(key,value);
        key = value;
        value = "";
    }
    ht->addKeyValue(key,value);
    cout<<endl;
    infile.close();
    //cout<<"collision 1: "<<ht->getCollisionCt1()<<"\n";
    //cout<<"collision 2: "<<ht->getCollisionCt2()<<"\n";
}
void makeSeuss::writeFile() {
    ofstream outfile(newfile.c_str(),ios::out);
    
    outfile<<ht->first<<" ";
    string key = "";
    string value = ht->map[ht->getIndex(ht->first)]->getRandValue();
    int ct = 0;
    int len = 0;
    while (ct < 500 && value != "") {
        key = value;
        outfile<<key<<" ";
        if (len == 11) {
            outfile << "\n";
            len = 0;
        }
        
        else len++;
        value = ht->map[ht->getIndex(key)]->getRandValue();
        ct++;
        
    }
    outfile.close();
    cout<< "collision 1: " << ht->getCollisionCt1() << "\n";
    cout<< "collision 2: " << ht->getCollisionCt2() << "\n";
}

hashMap* makeSeuss::getHashMap() {
    return ht;
}
