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
 
const int MOD = 998244353;  /* 1000000007 */;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

pl dp[200][1001];

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll n;
		cin >> n;
		vpl a(n + 1);

		for (int j = 1; j <= 1000; ++j) dp[0][j].f = dp[0][j].s = INF;

		// dp[i][j], j = sum of width of horizontal books
		for (int i = 1; i <= n; ++i) {
				ll ti, wi;
				cin >> ti >> wi;

				for (int j = 0; j <= 1000; ++j) {
						dp[i][j].f = dp[i][j].s = INF;
						if (j - wi >= 0) {
								dp[i][j].f = dp[i - 1][j - wi].f;
								if (dp[i - 1][j - wi].f >= j) {
										dp[i][j].s = dp[i - 1][j - wi].f;
								} else if (dp[i - 1][j - wi].s >= j) {
										dp[i][j].s = dp[i - 1][j - wi].s;
								}
						}
						if (dp[i - 1][j].f + ti >= j) {
								dp[i][j].s = MIN(dp[i][j].s, dp[i - 1][j].f + ti);
						} else if (dp[i - 1][j].s + ti >= j) {
								dp[i][j].s = MIN(dp[i][j].s, dp[i - 1][j].s + ti);
						}
						dp[i][j].f = MIN(dp[i][j].f, dp[i - 1][j].f + ti);
				}
		}

		ll ans = INF;
		for (int j = 0; j <= 1000; ++j) {
				if (j <= dp[n][j].s) ans = MIN(ans, dp[n][j].s);
		}
		cout << ans << endl;
}
