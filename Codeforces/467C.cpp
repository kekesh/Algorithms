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
 
const int MOD = 998244353;  /* 1000000007 */;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

ll n, m, k;
ll prefixes[5005];
bool vis[5001][5001];
ll dp[5001][5001];

ll solve(ll sum, ll idx, ll left) {
		if (idx >= n - m + 1) {
				return (left == 0 ? sum : -INF);
		}
		if (vis[idx][left]) {
				return dp[idx][left];
		}
		vis[idx][left] = true;
		return dp[idx][left] = 
				MAX(solve(sum, idx + 1, left), 
				   (left > 0 ? solve(sum, idx + m, left - 1) + prefixes[idx] : -INF));
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> n >> m >> k;
		vl p(n);
		F0R	(i, n) cin >> p[i];

		ll s = 0;
		for (int i = 0; i < m; ++i) {
				s += p[i];
		}
		prefixes[0] = s;
		for (int i = m; i < n; ++i) {
				s -= p[i - m];
				s += p[i];
				prefixes[i - m + 1] = s;
		}

		// dp[i][j] = max sum when last index we took was k

		ll ans = solve(0, 0, k);
		cout << ans << endl;
}
