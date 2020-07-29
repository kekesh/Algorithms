#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>
 
using namespace std;


class Trie {
		public:		
			class TrieNode {
					public:
							TrieNode* next[26];
							bool end;
							
							TrieNode() {
									end = false;
									
									for (int i = 0; i < 26; i++) {
											next[i] = nullptr;
									}
							}

							~TrieNode() {
									for (int i = 0; i < 26; i++) {
											delete []next[i];
									}
							}
			};
	
			TrieNode *root;

			Trie() {
					root = new TrieNode();
			}
	
			void insert(string key) {
					cout << "Inserting " << key << endl;
					root = insertAux(root, key, 0);
			}


			void dfs(TrieNode *curr, string s = "") {
					if (!curr) return;
					if (curr->end) cout << s << endl;
					for (int i = 0; i < 26; i++) {
							if (curr->next[i]) {
									dfs(curr->next[i], s + (char) (i + 'a'));
							}
					}
			}

		private:
			TrieNode* insertAux(TrieNode *node, string key, int idx) {
					if (!node) node = new TrieNode();
					if ((int) key.size() == idx) node->end = true;
					else node->next[key[idx] - 'a'] = insertAux(node->next[key[idx] - 'a'], key, idx + 1);
					return node;
			}

};


int main() {
		Trie t;
		t.dfs(t.root);
}
