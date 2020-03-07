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
bool vis[10000];
vector<int> s;
vector<vi> AdjList;
void toposort(int u) {
	vis[u] = true;

	F0R(i, AdjList[u].size()) {
		int v = AdjList[u][i];
		if (!vis[v]) {
			toposort(v);
		}
	}
	s.pb(u);
}


int main() {

	AdjList.pb({1, 2});
	AdjList.pb({2});
	AdjList.pb({3});
	AdjList.pb({});
	ll V = AdjList.size();

	vector<ll> d(V, -INFTY);
	toposort(0);
	reverse(s.begin(), s.end());

	ll root = s[0];
	d[root] = 0;

	F0R(i, V) {
		ll u = s[i];
		for (auto v : AdjList[u]) {
			if (d[v] < d[u] + 1) {
				d[v] = d[u] + 1;
			}
		}
	}

	F0R(i, V) {
		cout << "Longest path from root to " << i << " is " << d[i] << endl;
	}




	return 0;
}
