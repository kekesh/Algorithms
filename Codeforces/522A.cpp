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
 
const int MOD = 998244353; // 1000000007;  // 998244353
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

ll N;

vector<vi> AdjList(205);
ll dp[205];

ll dfs(int u, int p = -1) {		
		dp[u] = 1;
		F0R(i, (int) AdjList[u].size()) {
				int v = AdjList[u][i];
				if (v == p) continue;
				dp[u] = max(dp[u], 1 + dfs(v, u));
		}

		return dp[u];
}


int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N;

		unordered_map<string, int> nametoidx;
		unordered_map<int, string> idxtoname;
		int idx = 0;
		int src = 0;
		F0R(i, N) {
				string from, tmp, to;
				cin >> from >> tmp >> to;

				F0R(j, (int) from.size()) from[j] = tolower(from[j]);
				F0R(j, (int) to.size()) to[j] = tolower(to[j]);


				if (nametoidx.find(from) == nametoidx.end()) {
						if (from == "polycarp") src = idx;
						nametoidx[from] = idx;
						idxtoname[idx] = from;
						idx++;
				}

				if (nametoidx.find(to) == nametoidx.end()) {
						if (to == "polycarp") src = idx;
						nametoidx[to] = idx;
						idxtoname[idx] = to;
						idx++;
				}
				AdjList[nametoidx[from]].pb(nametoidx[to]);
				AdjList[nametoidx[to]].pb(nametoidx[from]);
		}
		dfs(src);
		cout << dp[src] << endl;
}
