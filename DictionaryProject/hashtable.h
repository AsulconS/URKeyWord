#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
using namespace std;

template<class K, class V>
struct Nodo {
  K key;
  V val;
  unsigned int pos;
  Nodo(const K &k, const V &v,const unsigned int &p) : val(v), key(k),pos(p) {}
};

template<class T> struct myHash {
};

template<> struct myHash<string> {
  static size_t hashFunction(const string& s) {
    return std::hash<string>()(s);
  }
};

template<> struct myHash<int> {
  static size_t hashFunction(const int m) {
    return std::hash<int>()(m);
  }
};

template<class K, class V, class HashGenerator = myHash<K> >
class HashTable {
public:
  vector<vector<Nodo<K, V> > > table;
  HashTable(int size) {
    for(int i = 0; i < size; i++) {
      vector<Nodo<K, V> > v;
      table.push_back(v);
    }
  }
  ~HashTable() {}
  void set(const K &k, const V &v,const unsigned int &p) {
    Nodo<K, V> b(k, v,p);
    for(int i = 0; i < table[hash(k)].size(); i++)
      if(table[hash( k )][i].key == k) {
        table[hash(k)][i] = b;
        return;
      }
    table[hash(k)].push_back(b);
  }



  V get(const K &k) {
    for(int i = 0; i < table[hash(k)].size(); i++)
      if(table[hash(k)][i].key == k )
        return table[hash(k)][i].val;
  }
  bool exist(const K &k) {
    for(int i = 0; i < table[hash(k)].size(); i++)
      if(table[hash(k)][i].key == k)
        return true;
    return false;
  }
  size_t hash(const K &k) {
    return HashGenerator::hashFunction(k) % table.size();
  }

  void print(){
    for (int i = 0; i < table.size(); ++i){
      //cout << table[i].size() << endl;
      cout << i << " ";
      for (int j = 0; j < table[i].size(); ++j){
        cout << table[i][j].val << " - " << table[i][j].pos;
      }
      cout << endl;
    }
  }
};

#endif // HASHTABLE_H
