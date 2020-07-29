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
 
typedef string str;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define trav(a, x) for (auto &a : x)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"
 
const int MOD = 1000000007;  // 998244353
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);

class Trie {
		public:
			class TrieNode {
					public:
						TrieNode *next[2];
						int count;

						TrieNode() {
								next[0] = next[1] = nullptr;
								count = 0;
						}
	
						TrieNode(bool e) {
								next[0] = next[1] = nullptr;
								count = 0;
						}
			};

			TrieNode *root;
			
			Trie() {
					root = new TrieNode();
			}

			void remove(int v) {
					string s = "";

					for (int i = 31; i >= 0; i--) {
							if (v & (1 << i)) {
									s += "1";
							} else {
									s += "0";
							}
					}

					auto curr = root;

					for (int i = 0; i < (int) s.size(); i++) {
							if (!curr->next[s[i] - '0']) {
									break;
							}
							curr = curr->next[s[i] - '0'];
							curr->count--;
					}
			}

			void insert(int v) {
					string s = "";

					for (int i = 31; i >= 0; i--) {
							if (v & (1 << i)) {
									s += "1";
							} else {
									s += "0";
							}
					}

					TrieNode *curr = root;

					for (int i = 0; i < (int) s.size(); i++) {
							if (!curr->next[s[i] - '0']) {
									curr->next[s[i] - '0'] = new TrieNode();
							}
							curr = curr->next[s[i] - '0'];
							curr->count++;
					}
			}

			unsigned long long query(int v) {
					string s = "";

					for (int i = 31; i >= 0; i--) {
							if (v & (1 << i)) {
									s += "1";
							} else {
									s += "0";
							}
					}

					auto trav = root;
					unsigned long long ans = 0;
					for (int i = 0; i < (int) s.size(); i++) {
							char comp = (s[i] == '1') ? '0' : '1';
							int lookingfor = comp - '0';
							if (trav->next[lookingfor] && trav->next[lookingfor]->count > 0) {
									trav = trav->next[lookingfor]; 
									ans += (1 << (31 - i));
							} else {
									trav = trav->next[1 - lookingfor];
							}
					}
					return ans;
			}

};

ll q;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		Trie t;
		t.insert(0);
		cin >> q;
		F0R(i, q) {
				char query;
				ll num;
				cin >> query >> num;

				if (query == '+') {
						t.insert(num);
				} else if (query == '-') {
						t.remove(num);
				} else {
						cout << t.query(num) << endl;
				}
		}
}
