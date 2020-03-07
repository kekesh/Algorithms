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

bool visited[501];
ll maxi;
int cnt;

void dfs(int u, const vector<vector<pair<int, int>>>& AdjList) {
	visited[u] = true;
	cnt++;
	F0R(i, AdjList[u].size()) {
		if (!visited[AdjList[u][i].first] && AdjList[u][i].second == maxi) {
			dfs(AdjList[u][i].first, AdjList);
		}
	}
}

int main() {
	ll N, M;
	while (cin >> N >> M) {
		if (N == 0 && M == 0) break;
		vector<vector<pair<int, int>>> AdjList(N);
		vector<int> maximums;
		maxi = -INF;
		F0R(i, M) {
			ll from, to, wt;
			cin >> from >> to >> wt;
			from--;
			to--;
			if (wt > maxi) {
				// only push back sources.
				AdjList.clear();
				maximums.clear();
				maxi = wt;
				maximums.pb(from);
			} else if (wt == maxi) {
				maximums.pb(from);
			}
			AdjList[from].pb(mp(to, wt));
			AdjList[to].pb(mp(from, wt));
		}
		ll ans = -1;
		F0R(i, maximums.size()) {
//			cout << "DFS from " << maximums[i] << endl;
			cnt = 0;
			if (!visited[maximums[i]]) dfs(maximums[i], AdjList);
			ans = MAX(ans, cnt);
//			memset(visited, false, sizeof(visited));
		}
		// at this point we have all possible sources in maximums.
		cout << ans << endl;
		memset(visited, false, sizeof(visited));
	}
	return 0;
}
