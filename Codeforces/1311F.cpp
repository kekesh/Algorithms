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

const ll sz = 2e8;

map<ll, ll> fenwick1, fenwick2;

void insert(ll idx, ll delta, ll tree) {
		while (idx < sz) {
				if (tree == 1) fenwick1[idx] += delta;
				else fenwick2[idx] += delta;
				idx += (idx & -idx);
		}
}
ll query(ll idx, ll tree) {
		ll s = 0;
		while (idx > 0) {
				s += (tree == 1 ? fenwick1[idx] : fenwick2[idx]);
				idx -= (idx & -idx);
		}
		return s;
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);

		ll n;
		cin >> n;
		vpl p(n);
		set<ll> s;
		F0R(i, n) cin >> p[i].f, ++p[i].f;
		F0R(i, n) cin >> p[i].s, s.insert(p[i].s);

		unordered_map<ll, ll> mapper;
		ll to = 2;
		for (const auto& v : s) mapper[v] = to++;
		sort(p.begin(), p.end());
		ll ans = 0;
		for (int i = 0; i < n; i++) {
				insert(mapper[p[i].s], p[i].f, 1);
				insert(mapper[p[i].s], 1, 2);
				ll count = query(mapper[p[i].s], 2);
				ll summ = query(mapper[p[i].s], 1);
				ans += 1ll * count * p[i].f - summ;
		}
		cout << ans << endl;

}
