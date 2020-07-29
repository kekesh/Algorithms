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

ld E[100005];

ll query(ll l, ll r, ll p) {
		return MAX(r/p - (l + p - 1)/p + 1, 0);
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll n, p;
		cin >> n >> p;

		vpl a(n);
		for (int i = 0; i < n; ++i) {
				cin >> a[i].f >> a[i].s;
		}
		ld ans = 0;
		for (int i = 0; i < n; ++i) {
				int n1 = (((i - 1) % n) + n) % n;
				int n2 = (i + 1) % n;
				ld p1 = 1.0 * query(a[n1].f, a[n1].s, p)/(a[n1].s - a[n1].f + 1);
				ld p2 = 1.0 * query(a[n2].f, a[n2].s, p)/(a[n2].s - a[n2].f + 1);
				ld p3 = 1.0 * query(a[i].f, a[i].s, p)/(a[i].s - a[i].f + 1);
				E[i] += 2000.0 * (p3 + p1 * p2 - p1 * p2 * p3);
				E[i] += 1000.0 * (p1 * (1 - p2) * (1 - p3) + (1 - p1) * p2 * (1 - p3));
				ans += E[i];
		}
		cout << fixed << setprecision(15) << ans << endl;
}
