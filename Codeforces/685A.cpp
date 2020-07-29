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
 
const int MOD = 998244353;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


ll modpow(ll a, ll b) {
		ll res = 1;
		a %= MOD;
		while (b) {
				if (b & 1) {
						res = (a * res) % MOD;
				}
				a = (a * a) % MOD;
				b >>= 1;
		}
		return res;
}

bool conv(bitset<7>& bs, ll x, ll digits) {
		ll res = 0;
		ll idx = 1;
		ll cpy = x;
		while (x) {
				res += (x % 7) * idx;
				x /= 7;
				idx *= 10;
		}
		string ts = to_string(res);
		while (ts.size() < digits) {
				ts += "0";
		}

		for (int i = 0; i < (int) ts.size(); ++i) {
				if (bs[ts[i] - '0']) return false;
				bs[ts[i] - '0'] = true;
		}
//		cout << "Returning true" << endl;
		return true;
}

ll cnt(ll x) {
		ll res = 0;
		while (x) res++, x/= 7;
		return res;
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll n, m;
		cin >> n >> m;
		ld d1 = cnt(n - 1), d2 = cnt(m - 1);
		ll s = d1 + d2;

		if (s > 7) {
				cout << 0 << endl;
				return 0;
		}
		ll ans = 0;
		// 7! instead of 6!....
		for (int hours = 0; hours <= n - 1; ++hours) {
				bitset<7> used;
				if (conv(used, hours, d1)) {
						for (int minutes = 0; minutes <= m - 1; ++minutes) {
								bitset<7> copy = used;
								if (conv(copy, minutes, d2)) {
										ans++;
								}
						}
				}
		}
		cout << ans << endl;
		return 0;
}
