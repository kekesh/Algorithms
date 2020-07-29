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

struct operation {
		ll left, right, delta;
		operation(ll l, ll r, ll d) {
				left = l, right = r, delta = d;
		}
};

int main() {
		ll n, m, k;
		cin >> n >> m >> k;
		vl a(n);
		vl deltas(n, 0);
		F0R(i, n) cin >> a[i];

		vector<operation> ops;
		F0R(i, m) {
				ll a, b, c;
				cin >> a >> b >> c;
				ops.pb(operation(a, b, c));
		}

		vl count(m, 0);

		for (int i = 0; i < k; i++) {
				ll a, b;
				cin >> a >> b;
				a--;
				count[a]++;
				if (b < m) {
						count[b]--;
				}
		}

		for (int i = 1; i < m; i++) {
				count[i] += count[i - 1];
		}

		for (int i = 0; i < m; i++) {
				operation o = ops[i];
				deltas[o.left - 1] += 1ll * count[i] * o.delta;
				if (o.right < n) {
						deltas[o.right] -= 1ll * count[i] * o.delta;
				}
		}

		for (int i = 1; i < n; i++) {
				deltas[i] += deltas[i - 1];
		}
		for (int i = 0; i < n; i++) {
				cout << a[i] + deltas[i] << " ";
		}
		cout << endl;
}
