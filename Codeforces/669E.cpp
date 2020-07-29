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
#include <map>

using namespace std;

typedef long long ll;

/* This implementation assumes one-based indexing. */
int maxi, maxt;

class FenwickTree2D {
		private:
				map<pair<int, int>, int> m;
		public:
				FenwickTree2D() {
						m.clear();
				}

				/* Update the element at position k by delta. */
				void update(int r, int c, long long delta) {
						int maxi = 1e9 + 5;
						for (int r_ = r; r_ < (int) maxi; r_ = r_ + (r_ & -r_)) {
							m[make_pair(r_, c)] += delta;
						}
				}

				/* Compute sum from (0, 0) to (r, c) inclusive. */
				long long sum(int r, int c) {
						long long s = 0;
						for (int r_ = r; r_ > 0; r_ = r_ - (r_ & (-r_))) {
							auto it = m.find(make_pair(r_, c));
							if (it != m.end()) {
								s += it->second;
							}
						}
						return s;
				}

				long long rangeQuery(int r1, int c1, int r2, int c2) {
					return (sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1));
				}
};

ll N;
vector<pair<pair<ll, ll>, ll>> queries;
set<int> t;
set<int> x;

int main() {
		cin >> N;
		FenwickTree2D ft;
		for (int i = 0; i < N; i++) {
//				ll ai, ti, xi;
//				cin >> ai >> ti >> xi;
//				queries.push_back(make_pair(make_pair(ti, xi), ai));
//				t.insert(ti);
//				x.insert(xi);
		}
/*
		int asdf = 1;
		for (auto v : t) {
				tmap[v] = asdf++;
		}
		maxt = asdf;
		asdf = 1;
		for (auto v : x) {
				xmap[v] = asdf++;
		}
*/
		for (int i = 0; i < N; i++) {
				ll ai, ti, xi;
				cin >> ai >> ti >> xi;
//				ll ai = queries[i].second;
//				ll ti = /* tmap[queries[i].first.first];  */ queries[i].first.first;
//				ll xi = /* xmap[queries[i].first.second]; */ queries[i].first.second;
				if (ai == 1) {
					ft.update(ti, xi, 1);
				} else if (ai == 2) {
						ft.update(ti, xi, -1);
				} else if (ai == 3) {
						cout << ft.sum(ti, xi) << endl;
				}
		}
}
