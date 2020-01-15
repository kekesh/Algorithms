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
const ll INFTY = 10e8;

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

// Start of code.

vector<vector<int>> AdjList(201);

int main() {
	ll V, E;
	while (cin >> V, V != 0) {
		vector<vector<int>> AdjList(201);
		cin >> E;
		F0R(i, E) {
			ll from, to;
			cin >> from >> to;
			AdjList[from].pb(to);
			AdjList[to].pb(from);
		}
		bool isBipartite = true;
		queue<int> q;
		vector<ll> color(V, INFTY);
		q.push(0);
		color[0] = 0;
		while (!q.empty() && isBipartite) {
			int u = q.front();
			q.pop();

			F0R(i, AdjList[u].size()) {
				if (color[AdjList[u][i]] == INFTY) {
					color[AdjList[u][i]] = 1 - color[u];
					q.push(AdjList[u][i]);
				} else if (color[AdjList[u][i]] == color[u]) {
					isBipartite = false;
					break;
				}
			}

		}

		if (isBipartite) cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;

	}

	return 0;
}
