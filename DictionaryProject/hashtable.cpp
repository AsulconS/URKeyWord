#include "hashtable.h"
template<typename K, typename V>
HashTable<K,V>::HashTable(const unsigned int &s)
    :hashTableSize(s)
{
    this->table=new Node<K,V> *[this->hashTableSize];
    for (int i=0;i<this->hashTableSize;++i) {
        *(table+i)=nullptr;
    }
}

template<typename K, typename V>
HashTable<K,V>::~HashTable()
{
    for (int i = 0; i < this->hashTableSize; ++i) {
        if(*(table+i)!=nullptr)
        {
            Node<K,V> *prevEntry=nullptr;
            Node<K,V> *entry=*(table+i);
            while (entry!=nullptr) {
                prevEntry=entry;
                entry=entry->getNextPtr();
                delete prevEntry;
            }
        }

    }
    delete[] table;
}

template<typename K, typename V>
void HashTable<K,V>::insert(K &key, const V & value)
{
    int hash=getHash(key)%hashTableSize;//get hash for string
    if(!table[hash])//if the table[index] is empty create new Node
    {
        table[hash]=new Node<K,V>(key,value);
        return;
    }
    Node<K,V> *temPtr=this->table[hash];//else create linkedlist in table[index]
    while (temPtr->getNextPtr()){
        temPtr=temPtr->getNextPtr();
    }
    temPtr->setNextPtr(new Node<K,V>(key,value));
}

template<typename K, typename V>
Node<K,V> * HashTable<K,V>::find(K &key)
{
    Node<K,V> *temPtr=this->table[this->getHash(key)%this->hashTableSize];
    if(temPtr->getKey()!=key)
    {
        while (temPtr->getKey()!=key) {//find key on linked list
            temPtr=temPtr->getNextPtr();
            if(temPtr->getNextPtr()==nullptr)
                break;
        }
    }
    return temPtr;
}

template<typename K, typename V>
bool HashTable<K,V>::isInHash(K &key)
{
    Node<K,V> *temPtr=this->table[this->getHash(key)%this->hashTableSize];
    if(temPtr->getKey()!=key)
    {
        while (temPtr->getKey()!=key) {//find key on linked list
            temPtr=temPtr->getNextPtr();
            if(temPtr->getNextPtr()==nullptr)
                return false;
        }
    }
    return true;
}
template<typename K,typename V>
int HashTable<K,V>::getHash(K &data)//get hash for only string data
{
    int hash=0;
    for (int i = 0; i < data.length(); ++i) {
        hash=(hash<<5)-hash+int(i);
    }
    return hash;
}

template<typename K, typename V>
unsigned int HashTable<K,V>::getHashTableSize() const
{
    return hashTableSize;
}
template<typename K, typename V>
void HashTable<K,V>::setHashTableSize(unsigned int value)
{
    hashTableSize = value;
}
