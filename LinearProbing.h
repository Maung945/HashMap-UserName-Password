/**
* Project-Password-Username Implementation using Hash Map
* Linear Probing Method
* LinearProbing.h
* Copyright (c) 2022, Myo Aung.
*/

#ifndef LINEARPROBING_H_
#define LINEARPROBING_H_
#include <iostream>

using namespace std;

template <typename K, typename V>
class HashNode {
public:
    V value;
    K key;
    HashNode(K key, V value) {
        this->value = value;
        this->key = key;
    }
};

template <typename K, typename V>
class HashMap {
private:
    HashNode<K, V>** table;                     // hash element array
    int capacity;
    int size;                                   // current size
    HashNode<K, V>* dummy;                      // dummy node
   
public:
    HashMap();
    int hashCode(string);
    void insert(K, V);
    V erase(K);
    V find(K);
    void verify(string, string);
    int sizeofMap();
    bool isEmpty();
    void print();
};

template <typename K, typename V>
HashMap<K,V>::HashMap() {
    capacity = 20;                          // Initial capacity of hash array
    size = 0;
    table = new HashNode<K, V>*[capacity];
    for (int i = 0; i < capacity; i++) {     // Initialise all elements of array as NULL
        table[i] = NULL;
    }
    dummy = new HashNode<K, V>("x", "x");   // dummy node with value and key x
}

template <typename K, typename V>
int HashMap<K,V>::hashCode(string s) {
    long long sum = 0;
    long long ascii = 0;
    int power = s.length() - 1;
    for (int i = 0; i < s.length(); i++) {
        ascii = (long long)(s[i]);
        sum = sum + (ascii * (pow(1, power)));
        power--;
    }
    return (sum % 11);
}

template <typename K, typename V>
void HashMap<K, V>::insert(K key, V value) {
    HashNode<K, V>* temp = new HashNode<K, V>(key, value);
    int hashIndex = hashCode(key);                      
    while (table[hashIndex] != NULL && table[hashIndex]->key != key && table[hashIndex]->key != "x") {
        hashIndex++;                                    // find next free space
        hashIndex %= capacity;
    }

    if (table[hashIndex] == NULL || table[hashIndex]->key == "x") {  // if new node to be inserted, increase the current size
        size++;
    }
    table[hashIndex] = temp;
}

template <typename K, typename V>
V HashMap<K, V>::erase(K key) {
    int hashIndex = hashCode(key);                      // to find index for given key
    while (table[hashIndex] != NULL) {                    // finding the node with given key
        if (table[hashIndex]->key == key) {               // if node found
            HashNode<K, V>* temp = table[hashIndex];
            table[hashIndex] = dummy;                     // Insert dummy node here for further use
            size--;                                     // Reduce size
            return temp->value;
        }
        hashIndex++;
        hashIndex %= capacity;
    }
    return NULL;                                         // If not found return null
}

template <typename K, typename V>
V HashMap<K, V>::find(K key) {
    int hashIndex = hashCode(key);                       // Apply hash function to find index for given key
    int counter = 0;
    while (table[hashIndex] != NULL) {                        // int counter =0 // finding the node with given key
        if (counter++ > capacity)                           // to avoid infinite loop
            return " ";

        if (table[hashIndex]->key == key)                     // if node found return its value
            return table[hashIndex]->value;
        hashIndex++;
        hashIndex %= capacity;
    }
    return " ";                                            // If not found return null
}

template <typename K, typename V>
void HashMap<K, V>::verify(string userName, string passWord) {
    if (find(userName) == passWord) {
        cout << "Authorization successful!\n" << endl;
        return;
    }
    cout << "Authorization faliure!\n" << endl;
    return;
}

template <typename K, typename V>
int HashMap<K, V>::sizeofMap() {
    return size;
}

template <typename K, typename V>
bool HashMap<K, V>::isEmpty() {
    return size == 0;
}

template <typename K, typename V>
void HashMap<K, V>::print() {
    cout << "------------------------------" << endl;
    cout << "-- Linear Probing Method--" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < capacity; i++) {
        if (table[i] != NULL && table[i]->key != "x")
            cout << "[" << i << "]" << "[" << table[i]->key << ", " << table[i]->value << "]" << endl;
    }
    cout << "\n--------" << endl;
}

#endif // !LINEARPROBING_H_