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


bool visited[101];
bool first;


void dfs(int src, int& sz, const vector<vector<ll>>& AdjList) {
	if (!first) {
		visited[src] = true;
		sz++;
	}
	first = false;
	F0R(i, AdjList[src].size()) {
		int v = AdjList[src][i];
		if (!visited[v]) dfs(v, sz, AdjList);
	}

}

int main() {

	ll N;
	while (cin >> N, N != 0) {
		vector<vector<ll>> AdjList(101);
		ll from;
		while (cin >> from, from != 0) {
			from--;
			ll to;
			while (cin >> to, to != 0) {
				to--;
				AdjList[from].pb(to);
		//		cout << "(" << from << "," << to << ")" << endl;
			}
		}
		ll Q;
		cin >> Q;
//		cout << "Q = " << Q << endl;
		F0R(i, Q) {
			// for each query
			int sz = 0, src;
			cin >> src;
			src--;
			first = true;
			dfs(src, sz, AdjList);
			cout << N - sz;
			if (N - sz) cout << " ";
			int ctr = 0;
			F0R(j, N) {
				if (!visited[j]) {
					cout << j + 1;
					ctr++;
					if (ctr != N - sz) cout << " ";
				}
			}
			cout << endl;
			memset(visited, false, sizeof(visited));
		}
	}

	return 0;
}
