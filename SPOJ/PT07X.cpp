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
 
const int MOD = /* 1000000007; */  998244353;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);

int dp1[100005], dp2[100005];
vector<vi> AdjList(100005);

void dfs(int u, int p = -1) {
		dp1[u] = 1;
		F0R(i, (int) AdjList[u].size()) {
				int v = AdjList[u][i];
				if (v != p) {
						dfs(v, u);
						dp1[u] += MIN(dp2[v], dp1[v]); 
						dp2[u] += dp1[v];
				}
		}
}


int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		// dp1[v] = minimum vertex cover if we take v.
		// dp2[v] = minimum vertex cover if we don't take v.

		// dp1[v] = 1 + SUM over all children u of v of dp2[u]
		// dp2[v] = SUM over all neighbors u of v of dp1[u]

		// answer: MIN(dp1[1], dp2[1]).

		ll N;
		cin >> N;
		F0R(i, N - 1) {
				ll u, v;
				cin >> u >> v;
				AdjList[u].pb(v);
				AdjList[v].pb(u);
		}
		dfs(1);
		cout << MIN(dp1[1], dp2[1]) << endl;
}
