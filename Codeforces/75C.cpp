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



int main() {
		ll a, b, n;
		cin >> a >> b >> n;
		vl adiv, bdiv;
		for (ll i = 1; i*i <= a; ++i) {
				if (a % i == 0) {
						adiv.pb(i);
						if (a/i != i) {
								adiv.pb(a/i);
						}
				}
		}
		for (ll i = 1; i * i <= b; ++i) {
				if (b % i == 0) {
						bdiv.pb(i);
						if (b/i != i) {
								bdiv.pb(b/i);
						}
				}
		}

		unordered_set<int> s;
		for (const auto& v : adiv) s.insert(v);

		vector<int> intersection;
		for (int i = 0; i < (int) bdiv.size(); ++i) {
				if (s.find(bdiv[i]) != s.end()) {
						intersection.pb(bdiv[i]);
				}
		}
		sort(intersection.begin(), intersection.end());
		while (n--) {
				ll lo, hi;
				cin >> lo >> hi;

				int lo_idx = 0, hi_idx = intersection.size() - 1;
				ll ans = -1;
				while (lo_idx <= hi_idx) {
						ll mid = lo_idx + (hi_idx - lo_idx)/2;
						if (intersection[mid] > hi) {
								hi_idx = mid - 1;
						} else if (intersection[mid] < lo) {
								lo_idx = mid + 1;
						} else {
								lo_idx = mid + 1;
								ans = mid;
						}
				}
				if (ans == -1) cout << -1 << endl;
				else cout << intersection[ans] << endl;
		}
}
