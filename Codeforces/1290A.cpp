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
		ll t, n, m, k;
		cin >> t;

		while (t--) {
				cin >> n >> m >> k;
				vl a(n);
				F0R(i, n) cin >> a[i];
				ll ans = -INF;
				ll bd = MIN(k, m - 1);
				for (int left = bd, right = n - 1; left >= 0; left--, right--) {
						/* Anything between [left, right] is available. */
//						cout << "Starting interval: " << "[" << left << "," << right << "]" << endl;
//						cout << "[" << left << "," << right << "]" << endl;
						/* There are still m - k more to take. */

						ll gotgot = INF;
						for (int left_delta = m - bd - 1, right_delta = 0; left_delta >= 0; left_delta--, right_delta++) {
								int left_idx = left + left_delta;
								int right_idx = right - right_delta;

								int got = max(a[left_idx], a[right_idx]);
								gotgot = MIN(got, gotgot);
//								cout << "[" << left_idx << "," << right_idx << "]" << endl;

						}
						ans = MAX(gotgot, ans);
				}
				cout << ans << endl;
		}

}
