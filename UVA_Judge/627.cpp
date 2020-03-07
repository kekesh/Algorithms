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
ll N;

//ofstream fout("output.out");
void print_path(int from, int to, vector<int>& parent) {

	if (to == from) {
		cout << from + 1;
		return;
	}
	print_path(from, parent[to], parent);
	cout << " " << to + 1;
//	cout << to << endl;
}

void solve(int from, int to, vector<vi>& AdjList) {
	queue<int> q;
	vector<int> d(N, INFTY);
	vector<int> parent(N, INFTY);
	d[from] = 0;
	q.push(from);
	bool done = false;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		F0R(i, AdjList[u].size()) {
			int v = AdjList[u][i];
			if (d[v] == INFTY) {
				d[v] = d[u] + 1;
				parent[v] = u;
				q.push(v);
				if (v == to) done = true;
			}
		}
		if (done) break;
	}

	if (done) {
//		cout << "Printing path." << endl;
		print_path(from, to, parent);
		cout << endl;
	} else {
		cout << "connection impossible" << endl;
	}
}


int main() {

	while (cin >> N) {
		cout << "-----" << endl;
		vector<vi> AdjList(N);

		F0R(i, N) {
			string line;
			cin >> line;
			istringstream iss(line);
			int from, to;
			char dummy;
			iss >> from;

			while (iss >> dummy >> to) {
				AdjList[from - 1].pb(to - 1);
//				cout << "(" << (from - 1) << "," << (to - 1) << ")" << endl;
			}
		}
		ll m;
		cin >> m;
		F0R(i, m) {
			ll from, to;
			cin >> from >> to;
			from--;
			to--;
			solve(from, to, AdjList);
		}
	}

	return 0;
}
