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

unsigned long long A, B;
pl dp[65][2];
bool vis[65][2];
ll cnt;
pl dfs(ll pos, int carry, long long X, long long Y) {
		if (pos == 64 && carry == 0) {
				return mp(X, Y);
		} else if (pos == 64 && carry == 1) {
				return mp(LLONG_MAX, LLONG_MAX);
		}
		if (vis[pos][carry]) {
				return dp[pos][carry];
		}

		vis[pos][carry] = true;
//		cout << "pos = " << pos << " and x = " << X << " and y = " << Y << endl;
		vpl all;
		for (unsigned long long i = 0; i <= 1; i++) { // appending i to X
				for (unsigned long long j = 0; j <= 1; j++) { // appending j to Y
						if ((i + j + carry) % 2 != (A >> pos & 1)) {
								continue;
						}
						if ((i ^ j) != (B >> pos & 1)) {
								continue;
						}
						long long mask = (1LL << pos);
						long long newX = (X & ~mask) | ((i << pos) & mask);
						long long newY = (Y & ~mask) | ((j << pos) & mask);
						dfs(pos + 1, (i + j + carry)/2, newX, newY);
						all.pb(dfs(pos + 1, (i + j + carry)/2, newX, newY));
				}
		}
		if (all.empty()) {
				return dp[pos][carry] = mp(LLONG_MAX, LLONG_MAX);
		}
		sort(all.begin(), all.end());
		return dp[pos][carry] = all[0];
}
int main() {
		cin >> A >> B;
		pl res = dfs(0, 0, 0, 0);
		if (res.f == LLONG_MAX) {
				cout << -1 << endl;
				return 0;
		}
		cout << res.f << " " << res.s << endl;
}
