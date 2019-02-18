//  hashMap.cpp
//  Author: Max Luu

#include "hashMap.hpp"
#include <math.h>
hashMap::hashMap(bool hash1, bool coll1) {
    mapSize = 5;
    numKeys = 0;
    c1 = coll1;
    h1 = hash1;
    first = "";
    collisionct1 = 0;
    collisionct2 = 0;
    map = new hashNode*[mapSize];
    for (int i = 0; i < mapSize; i++) {
        map[i] = NULL;
    }
}

void hashMap::addKeyValue(string k, string v) {
    hashNode* h = new hashNode(k,v);
    
    if (((double)numKeys / mapSize) >= (double)7/10) { //check for load
        reHash();
    }
    int i = getIndex(k);
    if (map[i] == NULL) {
        map[i] = h;
        numKeys++;
    } else {
        if (c1) { //handle chaining
            collHash1(map[i],h);
        } else { //linear probing
            collHash2(i,h);
        }
    }
}

int hashMap::getIndex(string k) {
    int hashIndex;
    if (h1)
        hashIndex = (int)calcHash(k);
    else
        hashIndex = (int)calcHash2(k);
    
    return hashIndex;
}

int hashMap::calcHash(string k) {
    hash<string> hash_fn;
    size_t hash = hash_fn(k);
    return hash % mapSize;
}

int hashMap::calcHash2(string k) {
    unsigned long hash = 5381;
    
    for (int i = 0; i < k.length(); i++) {
        hash = hash * 33 + (unsigned int)k[i];
    }
    
    return hash % mapSize;
}

void hashMap::getClosestPrime() {
    int i = mapSize * 2 + 1;
    while (!isPrime(i)) {
        i++;
    }
    mapSize = i;
    
}
/*
 * isPrime(int x)
 * takes in an int x
 * returns whether or not x is prime
 */
bool hashMap::isPrime(int x) {
    bool flag = false;
    int i = 2;
    while (i < sqrt(x)) {
        if (x % i == 0) {
            flag = true;
            break;
        } else {
            flag = false;
        }
        i++;
    }
    
    if (flag == false && x > 1) {
        return true;
    } else {
        return false;
    }
}

void hashMap::reHash() {
    int oldMapSize = mapSize;
    getClosestPrime();
    hashNode** tmpMap = map;
    
    map = new hashNode*[mapSize];
    for (int i = 0; i < mapSize; i++) {
        map[i] = NULL;
    }
    numKeys = 0;
    collisionct1 = 0;
    collisionct2 = 0;
    
    for (int i = 0; i < oldMapSize; i++) {
        while (tmpMap[i] != NULL) {
            for (int j = 0; j < tmpMap[i]->currSize; j++) {
                addKeyValue(tmpMap[i]->keyword, tmpMap[i]->values[j]);
            }
            tmpMap[i] = tmpMap[i]->next;
        }
        delete tmpMap[i];
    }
    delete []tmpMap;
}
//chaining
void hashMap::collHash1(hashNode* i, hashNode* h) {
    if (i->next == NULL && i->keyword != h->keyword) {
        //add the node to the end of the linked list
        i->next = h;
        h->next = NULL;
        collisionct1++;
        numKeys++;
        return;
    } else if (i->keyword == h->keyword) {
        //add the keyvalue
        i->addValue(h->values[0]);
        delete h;
        return;
        
    } else collHash1(i->next, h);
}
//linear probing
void hashMap::collHash2(int i, hashNode* h) {
    int index = i;
    
    while (map[index] != NULL) {
        if (index >= mapSize - 1) {
            index = -1;
        } else if (map[index]->keyword == h->keyword)
            break;
        index++;
        collisionct2++;
        //numKeys++;
    }
    
    if (map[index] == NULL) {
        map[index] = h;
        numKeys++;
    } else {
        map[index]->addValue(h->values[0]);
        delete h;
    }
}

int hashMap::findKey(string k) {
    hashNode** tmp = map;
    bool flag = false;
    int index = getIndex(k);
    if (c1) {
        if (tmp[index] == NULL) {
            return -1;
        } else {
            while (tmp[index] != NULL) {
                if (tmp[index]->keyword == k) {
                    return index;
                }
                tmp[index] = tmp[index]->next;
            }
            return -1;
        }
    } else {
        if (tmp[index] == NULL) {
            return -1;
        } else {
            if (tmp[index]->keyword == k) {
                return index;
            }
            
            while (tmp[index]->keyword != k) {
                if (index >= mapSize - 1 && tmp[index]->keyword != k) {
                    index = 0;
                    flag = true;
                } else if (flag == true && index == getIndex(k)) {
                    return -1;
                } else if (tmp[index]->keyword == k) {
                    return index;
                } else {
                    index++;
                }
            }
            return index;
        }
    }
}

void hashMap::printMap() {
    if (mapSize == 0) {
        cout<<"empty hashMap"<<endl;
    } else {
        for (int i = 0; i < mapSize; i++) {
            if (map[i] == NULL) {
                cout<<i<<" empty"<<endl;
            } else {
                cout<<i<<" ";
                hashNode* ptr = map[i];
                while(ptr != NULL){
                    cout<<"| key: "<<ptr->keyword<<"| values: ";
                    for (int j = 0; j < ptr->currSize; j++) {
                        cout<<ptr->values[j]<<", ";
                    }
                    ptr = ptr->next;
                }
                cout<<endl;
            }
        }
    }
    cout<<"collision ct1: "<<collisionct1<<endl;
    cout<<"collision ct2: "<<collisionct2<<endl;
}

hashNode** hashMap::getMap() {
    return map;
}

int hashMap::getCollisionCt1() {
    return collisionct1;
}
int hashMap::getCollisionCt2() {
    return collisionct2;
}

