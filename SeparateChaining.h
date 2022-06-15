/**
* Project-Password-Username Implementation using Hash Map
* Separate Chaining Method
* SeparateChaining.h
* Copyright (c) 2022, Myo Aung.
*/

#ifndef SEPARATECHAINING_H_
#define SEPARATECHAINING_H_
#include <iostream>
#include <list>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

class Pair {
public:
	string key, value;
	Pair(string u, string p) : key(u), value(p){}
};

class Hash {
private:
	int buckets;
	list<Pair>* table;

public:
	Hash();
	int hashFunction(string);
	void put(string, string);
	string find(string);
	void verify(string, string);
	void print();
	int size();
};

Hash::Hash() {
	buckets = 11;
	table = new list<Pair>[buckets];
}

int Hash::hashFunction(string s) {
	long long sum = 0;
	long long ascii = 0;
	int power = s.length()- 1;
	for (int i = 0; i < s.length(); i++) {
		ascii = (long long)s[i];
		sum = sum + (ascii * (pow(1, power)));
		power--;
	}
	return (sum % 11);
}

void Hash::put(string key, string value) {
	int index = hashFunction(key);
	table[index].push_back(Pair(key, value));
	return;
}

string Hash::find(string s) {
	int index = hashFunction(s);
	list<Pair>::iterator itr;
	for (itr = table[index].begin(); itr != table[index].end(); itr++) {
		if (itr->key == s) {
			return itr->value;
		}
	}
	return "";
}

void Hash::verify(string userName, string passWord) {
	if (find(userName) == passWord) {
		cout << "Authorization successful!\n" << endl;
		return;
	}
	cout << "Authorization faliure!\n" << endl;
	return;
}

int Hash::size() {
	int count = 0;
	list<Pair>::iterator itr;
	for (int i = 0; i < buckets; i++) {
		for (itr = table[i].begin(); itr != table[i].end(); itr++) {
			count++;
		}
	}
	return count;
}
void Hash::print() {
	cout << "------------------------------" << endl;
	cout << "-- Separate Chaining Method--" << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < buckets; i++) {
		cout << "|" << setw(2) << i << " |";
		list<Pair>::iterator itr;
		for (itr = table[i].begin(); itr != table[i].end(); itr++) {
			if (itr == itr) {
				cout << " -> ";
			}
			cout << "["  << itr->key << ", " << itr->value << "]";
		}
		cout << endl;
	}
	cout << "\n--------" << endl;
}

#endif // !SEPARATECHAINING_H_