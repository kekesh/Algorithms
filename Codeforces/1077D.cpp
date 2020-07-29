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

const ll sz = 2e8;

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll n, k;
		cin >> n >> k;
		vl a(n);
		map<int, int> m;
		F0R(i, n) cin >> a[i], m[a[i]]++;

		vector<pair<int, int>> vec;
		copy(m.begin(), m.end(), back_inserter<vector<pair<int, int>>>(vec));

		std::sort(vec.begin(), vec.end(),
			[](const pair<int, int>& l, const pair<int, int>& r) {
				if (l.second != r.second)
					return r.second < l.second;
				return r.first < l.first;
			});
		// binary search the number of times we can cut it out.


		ll lo = 1, hi = n;
		vl ans;
		while (lo <= hi) {
				ll mid = (lo + hi)/2;
//				cout << "Trying " << mid << " elements" << endl;

				ll s = 0;
				vl res;
				for (const auto&v : vec) {
//						cout << v.f << " occurs " << v.s << " times" << endl;
						ll delta = (v.s/mid);
						s += delta;
						if (delta == 0) {
								res.pb(v.f);
						}
						ll ub = MIN(k - res.size(), delta);
						for (int i = 0; i < ub; i++) {
								res.pb(v.f);
						}
						if (res.size() == k) {
								break;
						}
				}

				if (s >= k) {
//						cout << "Works" << endl;
						lo = mid + 1;
						ans = res;
				} else {
						hi = mid - 1;
				}
		}
		if (ans.empty()) {
				F0R(i, k) {
						cout << a[i] << " ";
				}
				cout << endl;
				return 0;
		}
		F0R(i, (int) ans.size()) cout << ans[i] << " ";
		cout << endl;

}
