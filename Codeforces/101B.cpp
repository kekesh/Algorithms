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

const int MAXN = 1e9 + 2;

ll n, m, k;

bool cmp(const pl& lhs, const pl& rhs) {
		return lhs.s < rhs.s;
}	

map<ll, ll> fenwick;

void update(ll idx, ll val) {
		while (idx < MAXN) {
				fenwick[idx] = (fenwick[idx] + val) % MOD;
				idx += (idx & -idx);
		}
}

ll query(ll idx) {
		ll s = 0;
		while (idx > 0) {
				s = (s + fenwick[idx]) % MOD;
				idx -= (idx & -idx);
		}
		return s;
}

ll rangeQuery(ll L, ll R) {
		ll s = (((query(R) - query(L - 1)) % MOD) + MOD) % MOD;
		return s;
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> n >> m, n++;
		vpl routes(m);
		F0R(i, m) cin >> routes[i].f >> routes[i].s, ++routes[i].f, ++routes[i].s;
		sort(routes.begin(), routes.end(), cmp);

		// dp[k] = # ways to get to k.
		// for each range [L, R], we do dp[R] += dp[R - 1] + dp[R - 2] + ... + dp[L]
		// perform range queries with a fenwick tree
		update(1, 1);
		for (const auto& pp : routes) {
			ll diff = rangeQuery(pp.f, pp.s - 1);
			update(pp.s, diff);
		}
		ll ans = rangeQuery(n, n);
		cout << ans << endl;
}

// check 998244353 vs 1e9 + 7
