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

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll T;
		cin >> T;
		while (T--) {
				ll n;
				cin >> n;
				vl a(n + 1);
				vl dp(n + 1);
				vpl ranges(n + 1);

				F0R(i, n) cin >> a[i + 1];
				dp[1] = a[1];
				ranges[1] = mp(1, 1);

				for (int i = 2; i <= n; i++) {
						if (dp[i - 1] + a[i] >= a[i]) {
								/* It's better to extend. */
								dp[i] = dp[i - 1] + a[i];
								ranges[i] = ranges[i - 1];
								ranges[i].s++;
						} else {
								/* It's better to start over. */
								dp[i] = a[i];
								ranges[i] = mp(i, i);
						}
				}

				ll ans = -INF;
				set<int> s;
				for (int i = 1; i <= n; i++) {
						if (dp[i] > ans) {
								s.clear();
								assert(s.empty());
								s.insert(i);
								ans = dp[i];
						} else if (dp[i] == ans) {
								s.insert(i);
						}
				}
				ll sum = ans;
				for (const auto& candidate : s) {
						int start = ranges[candidate].f, end = ranges[candidate].s;
						ll mini = INF;
						for (int i = start; i <= end; i++) {
								mini = MIN(a[i], mini);
						}
						if (mini < 0 && start != end) sum = MAX(sum, ans - mini);
				}
				cout << sum << endl;
		}
}
