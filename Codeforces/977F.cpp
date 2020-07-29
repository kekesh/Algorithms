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

vl a(200005);
map<int, int> m;
vl dp(200005);
vl p(200005);

void construct(int pos) {
		if (p[pos] == pos) {
				cout << pos;
				return;
		} else if (a[p[pos]] + 1 == a[pos]) {
				construct(p[pos]);
				cout << " " << pos;
		} else {
				// not part of the sequence
				construct(p[pos]);
		}
}

int main() {
		ll n;
		cin >> n;
		dp[0] = 0;

		ll best = -INF, idx = 0;
		for (int i = 1; i <= n; i++) {
				cin >> a[i];
				dp[i] = 1;
				p[i] = i;

				if (m.find(a[i] - 1) != m.end()) {
						int idx = m[a[i] - 1];
						if (dp[i] < dp[idx] + 1) {
								p[i] = idx;
								dp[i] = dp[idx] + 1;
						}
				}
				m[a[i]] = i;
				if (dp[i] > best) {
						best = dp[i];
						idx = i;
				}
		}
		cout << dp[idx] << endl;
		construct(idx);
		cout << endl;
}
