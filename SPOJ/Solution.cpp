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


bool vis[50005];
ll N, K;
vector<vi> AdjList(50001);
ll in[50001][501];
ll out[50001][501];
long long ans = 0;

void dfs(int u, int p = -1) {
		vis[u] = true;
		in[u][0] = 1;
		int num_children = 0;
		F0R(i, (int) AdjList[u].size()) {
				int v = AdjList[u][i];
				if (!vis[v]) {
						dfs(v, u);
						num_children++;
						for (int k = 1; k <= K; k++) {
								in[u][k] += in[v][k - 1];
						}
				}
		}
		ll sub = 0;

		ans += in[u][K];
		ans += sub;
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N >> K;
		F0R(i, N - 1) {
				ll u, v;
				cin >> u >> v;
				AdjList[u - 1].pb(v - 1);
				AdjList[v - 1].pb(u - 1);
		}
		// in[v][k] = # vertices in the subtree rooted at v whose distance equals k away from v.
		// in[v][k] = SUM over all u of in[u][k - 1]

		// out[v][k] = # vertices NOT in the subtree rooted at v whose distance equals k away from v.
		// out[v][k] = (in[parent[v]][K - 1] 

		dfs(0);
		cout << ans << endl;
}
