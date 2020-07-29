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
 
const int MOD = /* 998244353; */ 1000000007;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

// a^b % MOD
ll binpow(ll a, ll b) {
		ll res = 1;
		while (b > 0) {
				if (b & 1) {
						res = (res * a) % MOD;
				}
				a = (a * a) % MOD;
				b >>= 1;
		}
		return res;
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll x, k;
		cin >> x >> k;
		if (x == 0) {
				cout << 0 << endl;
				return 0;
		}
		x %= MOD;

		// x + 2^k (if it doesn't eat anything)
		// x + 2^k - k (if it does eat all)
		// 

		ll ub = 1ll * x * binpow(2, k);
		ll lb = ub - binpow(2, k) + 1;
		lb *= 2, ub *= 2;
		ll ans = (lb + ub)/2;
		ans = (ans % MOD + MOD) % MOD;

//		while (lb < 0) lb += MOD;
//		while (ub < 0) ub += MOD;

//		ub = (((ub % MOD) + MOD) % MOD);
//		lb = (((lb % MOD) + MOD) % MOD);

		cout << ans << endl;
}
