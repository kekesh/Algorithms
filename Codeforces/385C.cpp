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


long long fenw[10'000'005];

int lpf[10'000'005];
 
void dp() {
		for (ll i = 2; i <= 10'000'000; i++) {
				if (!lpf[i]) {
						lpf[i] = i;
						for (ll j = i * i; j <= 10'000'000; j += i) {
								if (!lpf[j]) {
										lpf[j] = i;
								}
						}
				}
		}
}
 

void update(int idx, int delta) {
		while (idx < 10'000'005) {
				fenw[idx] += delta;
				idx += idx & (-idx);
		}
}

long long query(ll idx) {
		long long s = 0;
		while (idx > 0) {
				s += fenw[idx];
				idx -= idx & (-idx);
		}
		return s;
}

int main() {
		dp();
		ll n, m;
		scanf("%I64d", &n);
		F0R(i, n) {
				ll x;
				scanf("%I64d", &x);
				while (x != 1) {
						ll pf = lpf[x];
						update(pf, 1);
						while (x % pf == 0) x /= pf;
				}
		}
		scanf("%I64d", &m);
		while (m--) {
				ll L, R;
				scanf("%I64d %I64d", &L, &R);
				L = MIN(L, 1e7 + 1);
				R = MIN(R, 1e7 + 1);
				ll ans = query(R) - query(L - 1);
				printf("%I64d\n", ans);
		}
}
