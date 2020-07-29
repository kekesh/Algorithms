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
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<ld> vld;
typedef vector<pair<ll, ll>> vpl;

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
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


int color[200005];
int incheck[200005];
int outcheck[200005];

void dfs1(const vector<vector<ll>>& AdjList, int u, int p = -1) {
		int res = color[u];
		for (const auto& v : AdjList[u]) {
				if (v == p) continue;
				dfs1(AdjList, v, u);
				if (incheck[v] != res) {
						res = -1;
				}
		}
		incheck[u] = res;
}

void dfs2(const vector<vector<ll>>& AdjList, int u, int p = -1) {

		// can optimize


		// outcheck[v] = color that works for complement of subtree rooted at v.
		for (int i = 0; i < (int) AdjList[u].size(); ++i) {
				int v = AdjList[u][i];
				if (p == v) {
						continue;
				}

				outcheck[v] = color[u];

				if (outcheck[u] != color[u]) outcheck[v] = -1;

				if (outcheck[v] != -1) {
					for (int j = 0; j < (int) AdjList[u].size(); ++j) {
							int w = AdjList[u][j];
							if (w == p || w == v) continue;
							// w is a sibling of v.
							if (color[u] != incheck[w]) outcheck[v] = -1;
					}
				}
		}

		for (int i = 0; i < (int) AdjList[u].size(); ++i) {
				int v = AdjList[u][i];
				if (v == p) continue;
				dfs2(AdjList, v, u);
		}
}

void dfs3(const vector<vl>& AdjList, int u, int p = -1) {
		bool ok = (outcheck[u] != -1);

		for (int i = 0; i < (int) AdjList[u].size(); ++i) {
				int v = AdjList[u][i];
				if (v == p) continue;
				dfs3(AdjList, v, u);
				ok &= (incheck[v] != -1);
		}

		if (ok) {
				cout << "YES" << endl;
				cout << u + 1 << endl;
				exit(0);
		}


}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll n;
		cin >> n;
		vector<vl> AdjList(n);
		F0R(i, n - 1) {
				ll u, v;
				cin >> u >> v;
				u--, v--;
				AdjList[u].pb(v);
				AdjList[v].pb(u);
		}
		F0R(i, n) cin >> color[i];
		dfs1(AdjList, 0);
		outcheck[0] = color[0];
		dfs2(AdjList, 0);
		dfs3(AdjList, 0);
		cout << "NO" << endl;

/*		for (int i = 0 ; i < n; ++i) {
				cout << "incheck[" << i << "] = " << incheck[i] << endl;
				cout << "outcheck[" << i << "] = " << outcheck[i] << endl;
		}
*/
}
