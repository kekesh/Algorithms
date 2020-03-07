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

bool visited[30005];

void dfs(ll &size, ll curr, const vector<vector<int>>& AdjList) {

	visited[curr] = true;

	F0R(i, AdjList[curr].size()) {
		if (!visited[AdjList[curr][i]]) {
		        size++;
	       		dfs(size, AdjList[curr][i], AdjList);
		}
	}

}

int main() {


	ll n, m;
	while (cin >> n >> m) {
		if (!n && !m) break;
		vector<vector<int>> AdjList(30005);

		F0R(i, m) {
			ll num;
			cin >> num;
			if (num == 0) break;
			ll fst;
			cin >> fst;
			F0R(j, num - 1) {
				ll nxt;
				cin >> nxt;
				AdjList[fst].pb(nxt);
				AdjList[nxt].pb(fst);
			}
		}
		/* Graph is constructed. */
		ll size = 1;
		memset(visited, false, sizeof(visited));
		dfs(size, 0, AdjList);
		cout << size << endl;
	}
	return 0;
}
