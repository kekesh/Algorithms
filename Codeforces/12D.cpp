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

typedef long long ll;


struct lady {
		ll a, b, c;
};

/* This implementation assumes one-based indexing. */
class FenwickTree {
		private:
				int size;
				vector<long long> tree;
		public:
				/* Initialize a Fenwick Tree with a user-provided capacity. */
				FenwickTree(int size) {
						assert(size >= 0);
						this->size = size;
						tree.resize(size + 1, 0);
						tree[0] = 0;
				}

				/* Update the element at position k by delta. */
				void update(int k, long long delta) {
						while (k < size) {
								tree[k] = max(tree[k], delta);
								k += (k & -k);
						}
				}

				/* Compute SUM[1, k] */
				long long query(int k) {
						long long s = -1;
						while (k > 0) {
								s = max(s, tree[k]);
								k -= (k & -k);
						}
						return s;
				}

				friend ostream &operator<<(ostream &output, const FenwickTree &ft) {
						for (int i = 1; i < ft.size; i++) {
								output << ft.tree[i] << " ";
						}
						return output;
				}
};

ll N;


bool cmp(const lady& lhs, const lady& rhs) {
		return rhs.a < lhs.a;
}


set<int> s;
unordered_map<int, int> m;

int main() {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cin >> N;
		vector<lady> lst(N);
		for (int i = 0; i < N; i++) cin >> lst[i].a;
		for (int i = 0; i < N; i++) cin >> lst[i].b;
		for (int i = 0; i < N; i++) cin >> lst[i].c;

		sort(lst.begin(), lst.end(), cmp);
		set<int> s;

		for (int i = 0; i < N; i++) s.insert(lst[i].b);
		int asdf = 1;
		for (auto v : s) m[v] = asdf++;

		for (int i = 0; i < N; i++) lst[i].b = m[lst[i].b];


		FenwickTree ft(500001);
		vector<lady> toinsert;
		int ans = 0;
		for (int i = 0; i < N; i++) {
				// how many ladys in our fenwick tree have y > curry and z > currz?
				// what's the best z we can get in the interval [y + 1, max]?
				if (lst[i].c < ft.query(N - lst[i].b)) {
						ans++;
				}
				toinsert.push_back(lst[i]);


				if (i < N - 1 && lst[i].a != lst[i + 1].a) {
					for (auto v : toinsert) {
						ft.update(N - v.b + 1, v.c);
					}
					toinsert.clear();
				}
		}

		cout << ans << endl;
}
