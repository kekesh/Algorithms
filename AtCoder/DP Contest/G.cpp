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
const ld PI = 4 * atan((ld)1);


ll N, M;
bool vis[100005];
vi toposort;
vector<vi> AdjList(100005);

void dfs(int u) {
		vis[u] = true;
		F0R(i, (int) AdjList[u].size()) {
				int v = AdjList[u][i];
				if (!vis[v]) dfs(v);
		}
		toposort.pb(u);
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N >> M;

		F0R(i, M) {
				ll u, v;
				cin >> u >> v;
				AdjList[u-1].pb(v-1);
		}
		F0R(i, N) {
				if (!vis[i]) dfs(i);
		}

		reverse(toposort.begin(), toposort.end());

		vector<ll> d(N, -INF);

		ll ans = 0;
		for (int i = 0; i < N; i++) {
				int u = toposort[i];
				if (d[u] == -INF) {
						d[u] = 0;
				}
				for (auto v : AdjList[u]) {
					d[v] = MAX(d[v], d[u] + 1);
					ans = MAX(ans, d[v]);
				}
		}
		cout << ans << endl;

}
