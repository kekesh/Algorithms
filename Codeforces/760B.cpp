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
 
const int MOD = 998244353; // 1000000007;  // 998244353
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

ll N, M, K;

inline long long gauss(int a, int b) {
		return (1ll * b * (b + 1))/2 - (1ll * (a - 1) * a)/2;
}

inline bool check(int v) {
		ll c1 = gauss(MAX(v - (K - 1), 0), v - 1);
		ll c2 = gauss(MAX(v - (N - K), 0), v - 1);
		return (M - c1 - c2 - v) >= 0;
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N >> M >> K;
		M -= N;

		int lo = 0, hi = 1e9 + 2;
		int ans = 0;
		while (lo <= hi) {
				int m = lo + (hi - lo)/2;
				if (check(m)) {
						lo = m + 1;
						ans = m;
				} else {
						hi = m - 1;
				}
		}
		cout << 1 + ans << endl;
}
