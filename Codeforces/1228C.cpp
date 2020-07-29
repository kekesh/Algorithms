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

ll modpow(ll a, ll b) {
		a %= MOD;
		ll res = 1;
		while (b) {
				if (b & 1) res = (res * a) % MOD;
				a = (a * a) % MOD;
				b >>= 1;
		}
		return res;
}

ll get(ll n, ll p) {
		ll c = p;
		ll res = 1;
		while (n/c != 0) {
				res = (res * modpow(p, n/c)) % MOD;
				if (c > 1e18/p) break;
				c *= p;
		}
		return res;
}




int main() {
		ll n, x;
		cin >> x >> n;

		vl pf;

		if (x % 2 == 0) {
				pf.pb(2);
				while (x % 2 == 0) x /= 2;
		}

		for (int i = 3; i * i <= x; i += 2) {
				if (x % i == 0) {
						pf.pb(i);
						while (x % i == 0) x /= i;
				}
		}
		if (x > 1) pf.pb(x);

		ll ans = 1;
		for (const auto& p : pf) {
				ll contrib = get(n, p);
				ans = (ans * contrib) % MOD;
		}
		cout << ans << endl;
}
