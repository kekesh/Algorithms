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
bool done[200005];
vector<vector<int>> AdjList(200005);
vector<unordered_set<int>> layers(200005);
int main() {
	ll N;
	cin >> N;

	F0R(i, N - 1) {
		ll from, to;
		cin >> from >> to;
		AdjList[from].pb(to);
		AdjList[to].pb(from);
	}

	vector<int> d(N + 1, INFTY);
	d[1] = 0;
	queue<int> q;
	q.push(1);
	int maxd = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : AdjList[u]) {
			if (d[v] == INFTY) {
				d[v] = d[u] + 1;
				maxd = MAX(maxd, d[v]);
				q.push(v);
			}
		}
	}


	F0R(i, N) {
		cout << "Distance to " << i+1 << " is " << d[i + 1] << endl;
	}

	F0R(i, N) {
		layers[d[i + 1]].insert(i + 1);
	}

	int curr_d = 0;
	bool isok = true;
	F0R(i, N) {
		int nxt;
		cin >> nxt;
		if (d[nxt] == curr_d && layers[d[nxt]].count(nxt)) {
			cout << nxt << " has distance " << curr_d << ". This is valid." << endl;
			layers[d[nxt]].erase(nxt);
			if (layers[d[nxt]].size() == 0) {
				cout << "All vertices with distance " << d[nxt] << " removed." << endl;
				done[curr_d++] = true;
			}
		} else {
			cout << "isok = false." << endl;
			isok = false;
			break;
		}
	}

	F0R(i, maxd) isok &= done[i];

	if (isok) cout << "Yes" << endl;
	else cout << "No" << endl;


	return 0;
}
