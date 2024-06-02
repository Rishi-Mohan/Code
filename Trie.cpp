/*
    author: Rishi Mohan Jha
    created_at: 14-06-2023  02:50 PM
*/

#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

#define ll     long long
#define ff     first
#define ss     second
#define pb     push_back
#define sz(x)  ((int)(x).size())
#define all(a) (a).begin(),(a).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

struct Node {
	Node *links[26];
	bool flag = false;

	bool containsKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}

	Node *get(char ch) {
		return links[ch - 'a'];
	}

	void setEnd() {
		flag = true;
	}

	bool isEnd() {
		return flag;
	}
};

class Trie {
private:
	Node* root;
public:
	Trie() {
		root = new Node(); // creating new node for the root
	}

	void insert(string word) {
		Node *node = root; // taking reference of the root node which is starting node 
		for (auto ch : word) {
			if (!node->containsKey(ch)) { // checking if already reference of current char exists or not
				node->put(ch, new Node()); // if not exist then creating a new reference for the current character
			}
			node = node->get(ch); // taking the reference of the current character and move the node to the reference of that node
		}
		node->setEnd(); // set true the flag for the last character
	}

	bool search(string word) {
		Node *node = root;
		for (auto ch : word) {
			if (!node->containsKey(ch)) // if reference of current character is not exist then return 0
				return 0;
			node = node->get(ch);
		}
		return node->isEnd(); // if flag is true then the whole word itself exists
	}

	bool startsWith(string word) {
		Node *node = root;
		for (auto ch : word) {
			if (!node->containsKey(ch))
				return 0;
			node = node->get(ch);
		}
		return 1; // last character of prefix exists in the one of the path
	}
};

/*
	1. insert
	2. search word
	3. search prefix
*/
void Solve() {
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	// cin >> T;
	while (T--) Solve();


#ifndef ONLINE_JUDGE
	// cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
}
