#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include "node.h"
#include "fstream"
using namespace  std;
template<typename K,typename V>
class HashTable
{
public:
    HashTable(const unsigned int &);
    ~HashTable();
    void insert(K &,const V & );
    Node<K,V>* find(K &);
    int getHash(K &);
    unsigned int getHashTableSize() const;
    void setHashTableSize(unsigned int value);
    void createIndexFileFromHash();
    void setHashFronIndexFile();
    friend std::ostream & operator << (std::ostream &out,HashTable h)
    {
    }
private:
    unsigned int hashTableSize;
    Node<K,V> **table;
};
#endif // HASHTABLE_H
