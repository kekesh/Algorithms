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

typedef pair<int, int> pi;

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

// Start of code.

class UF {
	private:
		vector<long long> rank, parent; 

	public:
		UF(const int n) {
			rank.resize(n + 1);
			parent.resize(n + 1);
			iota(parent.begin(), parent.end(), 0);
		}

		int findSet(const int u) {
			return (u == parent[u] ? u : parent[u] = findSet(parent[u]));
		}

		bool inSameSet(const int u, const int v) {
			return findSet(u) == findSet(v);
		}

		int merge(const int u, const int v) {
			int p1 = findSet(u), p2 = findSet(v);
			if (p1 == p2) return 0;
			if (rank[p1] > rank[p2]) {
				parent[p2] = p1;
			} else {
				parent[p1] = p2;
				rank[p2] += (rank[p1] == rank[p2]);
			}
			return 1;
		}
};

int main() {
	long long t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		int num_cc = 0;
		int maxi = -1, mini = n + 1;
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			maxi= max(maxi, x); mini = min(mini, x);
			if (maxi == i + 1 && mini == 1) {
				num_cc++;
			}
		}
		cout << num_cc << endl;
	}
}
