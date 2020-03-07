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
const int MX = 35005;
const ld PI = 4 * atan((ld)1);
const int INFTY = 2147483643;

// Start of code.

ll dfs_num[10000], dfs_low[10000], parent[10000], num_children[10000], cnt[10000];
bool artpoint[10000];
ll dfs_counter;
vector<vi> AdjList;

void strongArtPoint(int u) {
	dfs_low[u] = dfs_num[u] = ++dfs_counter;

	F0R(i, AdjList[u].size()) {
		ll v = AdjList[u][i];
		if (dfs_num[v] == 0) {
			parent[v] = u;
			num_children[u]++;
			strongArtPoint(v);

			if (dfs_low[v] >= dfs_low[u]) {
				cnt[u]++;
				if (cnt[u] >= 2) artpoint[u] = true;
			}

			dfs_low[u] = MIN(dfs_low[u], dfs_low[v]);
		} else if (v != parent[u]) {
			dfs_low[u] = MIN(dfs_low[u], dfs_num[v]);
		}
	}
}



int main() {

	AdjList.pb({1, 4, 5});
	AdjList.pb({0, 2, 3});
	AdjList.pb({1});
	AdjList.pb({1});
	AdjList.pb({0});
	AdjList.pb({0});
	AdjList.pb({4});

	F0R(i, 7) {
		if (dfs_num[i] == 0) {
			ll root = i;
			strongArtPoint(i);
			artpoint[root] = (num_children[root] >= 3); // special case.
		}
	}


	F0R(i, 7) {
		if (artpoint[i]) {
			cout << i << " is a strong articulation point." << endl;
		}
	}

	return 0;
}
