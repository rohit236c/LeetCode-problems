#include<bits/stdc++.h>
using namespace std;

// implementation of Trie.....
class node {
public:
	char c;
	map<int, node*>hashmap;
	bool isTerminal;
	node(char c) {
		this->c = c;
		isTerminal = false;
	}
};

class Trie {
private: node*root;
public:
	Trie() {
		root = new node('\0');
	}
	void insert(string str) {
		node*curNode = root;
		for (int i = 0; i < str.length(); i++) {
			char curChar = str[i];
			if (curChar->hashmap(curChar).count == 0) {
				node*newChar = new node(curChar);
				curNode->hashmap[curChar] = newChar;
				curNode = newChar;
			} else {
				curNode = curNode->hashmap[curChar];
			}
		}
		curNode->isTerminal = true;
	}
	node* search(string word) {
		node*temp = root;
		for (int i = 0; i < word.length(); i++) {
			char curChar = word[i];
			if (temp->hashmap[curChar].count == 1) {
				temp = temp->hashmap[curChar];
			} else {
				return NULL;
			}
		}
		return temp->isTerminal ? false : NULL : temp;
	}
};

// implementation of hashmap
template<typename T>
class node {
public:
	string key;
	node<T>*next;
	T value;
	node(string key, T value) {
		this->key = key;
		this->value = value;
	}
};

class Hashmap {
private:
	int cs;
	int ms;

	node** buckets;
	int hashFn(string key) {
		int L = key.length();
		int ans = 0 ;
		int p = 1; ///37^0 is 1 initially

		for (int i = 0; i < L; i++) {
			ans += key[L - i - 1] * p;
			p = p * 37;

			p %= ts;
			ans %= ts;
		}
		return ans;
	}
public:
	Hashtable(int ds = 7) {
		cs = 0;
		ms = ds;
		buckets = new node<T>*[ms];
		///Make all addresses as NULL
		for (int i = 0; i < ts; i++) {
			buckets[i] = NULL;
		}
	}
	void insert(string key, T value) {
		int i = hashFn(key);

		node<T>*temp = new node<T>(string, value);
		temp->next = buckets[i];
		buckets[i] = temp;
	}
	node* search(string key) {
		int i = hashFn(key);
		node<T>*currentNode = buckets[i];
		while (temp != NULL) {
			if (temp->key == key) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}


};



int main() {


	return 0;
}