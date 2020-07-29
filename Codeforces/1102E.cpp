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
 
const int MOD = 998244353;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


ll modpow(ll a, ll b) {
		ll res = 1;
		a %= MOD;
		while (b) {
				if (b & 1) {
						res = (a * res) % MOD;
				}
				a = (a * a) % MOD;
				b >>= 1;
		}
		return res;
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll n;
		cin >> n;
		vl a(n);

		F0R(i, n) cin >> a[i];

		map<int, int> firsts, lasts;

		for (int i = 0, j = n - 1; i < n; ++i, --j) {
				if (firsts.find(a[i]) == firsts.end()) {
						firsts[a[i]] = i;
				}
				if (lasts.find(a[j]) == lasts.end()) {
						lasts[a[j]] = j;
				}
		}
		vpl intervals;
		set<int> used;
		for (int i = 0; i < n; ++i) {
				if (used.find(a[i]) == used.end()) {
						intervals.pb({firsts[a[i]], lasts[a[i]]});
//						cout << "[" << firsts[a[i]] << "," << lasts[a[i]] << "]" << endl;
				}
				used.insert(a[i]);
		}

		// merge
		sort(intervals.begin(), intervals.end());
		vpl merged;
		pl current_interval = {intervals[0].f, intervals[0].s};
		for (int i = 1; i < (int) intervals.size(); ++i) {
				int start = intervals[i].f, end = intervals[i].s;
				if (start <= current_interval.s) {
						current_interval.s = MAX(current_interval.s, end);
				} else {
						merged.pb(current_interval);
						current_interval = {start, end};
				}
		}
		merged.pb(current_interval);

/*		cout << "Printing merged." << endl;
		for (int i = 0; i < (int) merged.size(); ++i) {
				cout << merged[i].f << "," << merged[i].s << endl;
		}
*/
//		if (a[0] == 107897) cout << "sdfsdfsdfsdf: " << merged.size() << endl;
		ll pw = merged.size();
		ll ans = modpow(2, pw - 1);
		cout << ans << endl;



}
