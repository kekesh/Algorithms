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


int main() {
	vector<vector<int>> AdjList(200005);
	ll x, n;
	cin >> n >> x;
	x--;
	F0R(i, n-1) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		AdjList[from].pb(to);
		AdjList[to].pb(from);
	}

	// run bfs from 0 and x
	vector<int> d0(n, INFTY);
	queue<int> q0;
	d0[0] = 0;
	q0.push(0);
	while (!q0.empty()) {
		int u = q0.front(); q0.pop();
		F0R(i, AdjList[u].size()) {
			int v = AdjList[u][i];
			if (d0[v] == INFTY) {
				d0[v] = d0[u] + 1;
				q0.push(v);
			}
		}
	}

	vector<int> dx(n, INFTY);
	queue<int> qx;
	dx[x] = 0;
	qx.push(x);
	while (!qx.empty()) {
		int u = qx.front(); qx.pop();
	//	cout << "Now processing " << u << endl;
		F0R(i, AdjList[u].size()) {
			int v = AdjList[u][i];
	//		cout << "Looking at neighbor " << v << endl;
			if (dx[v] == INFTY) {
				dx[v] = dx[u] + 1;
				qx.push(v);
			}
		}
	}
	/*
	cout << "Printing distances!" << endl;
	F0R(i, n) {
		cout << "Distance from 0 to " << i << " is " << d0[i] << endl;
	}

	F0R(i, n) {
		cout << "Distance from " << x << " to " << i << " is " << dx[i] << endl;
	} */

	int maxi = d0[x];

	F0R(i, n) {
		if (d0[i] > dx[i] && d0[i] > maxi) {
			maxi = d0[i];
//			cout << "Vertex " << i << endl;
		}
	}

	cout << maxi*2 << endl;
	return 0;
}
