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


int main() {
		ll N, M;
		cin >> N >> M;
		vector<vi> AdjList(N);
		if (M != N - 1) {
				cout << "NO" << endl;
				return 0;
		}

		F0R(i, M) {
				ll u, v;
				cin >> u >> v;
				AdjList[u - 1].pb(v - 1);
				AdjList[v - 1].pb(u - 1);
		}

		// check if it's connected.
		int num_vertices = 0;
		bool vis[N];
		memset(vis, false, sizeof(vis));

		stack<int> s;
		s.push(0);
		while (!s.empty()) {
				int u = s.top(); s.pop();
				if (!vis[u]) {
					vis[u] = true;
					num_vertices++;
					F0R(i, (int) AdjList[u].size()) {
							if (!vis[AdjList[u][i]]) {
									s.push(AdjList[u][i]);
							}
					}
				}
		}

		if (num_vertices == N) cout << "YES" << endl;
		else cout << "NO" << endl;
		
}
