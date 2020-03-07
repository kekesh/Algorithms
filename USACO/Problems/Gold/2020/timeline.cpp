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
typedef vector<pi> vii;
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
ifstream fin("timeline.in");
ofstream fout("timeline.out");

vector<vector<pair<int, int>>> AdjList(100005);
vi pos(100005);
bool vis[100005];
ll N, M, C;
stack<int> toposort;

void dfs(int src) {
	vis[src] = true;
	F0R(i, AdjList[src].size()) {
		int v = AdjList[src][i].first;
		if (!vis[v]) {
			dfs(v);
		}
	}
	toposort.push(src);
}



int main() {
	fin >> N >> M >> C;

	FOR(i, 1, N + 1) {
		fin >> pos[i];
		AdjList[0].pb(mp(i, -pos[i]));
	}





	F0R(i, C) {
		ll from, to, w;
		fin >> from >> to >> w;
		AdjList[from].pb(mp(to, -w)); /* Negate edge weights. */
	}

	dfs(0);
	vector<int> topo;
	while (!toposort.empty()) {
		int u = toposort.top(); toposort.pop();
		topo.pb(u);
//		cout << u << " ";
	}
	/* Toposort is complete. */

	vector<ll> d(N + 1, INFTY);
	d[0] = 0;
	F0R(i, topo.size()) {
		int u = topo[i];

		for (auto p : AdjList[u]) {
			int v = p.first;
			int w = p.second; /* Edge weight. */
			if (w + d[u] < d[v]) {
				d[v] = w + d[u];
			}
		}
	}
//	cout << "printing" << endl;
	F0R(i, d.size() - 1) {
		fout << -d[i + 1] << endl;
	}

	// longest path in DAG




	//


	return 0;
}
