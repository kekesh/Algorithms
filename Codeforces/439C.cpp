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
				ll n, p, k;
				cin >> n >> k >> p;

				vl a(n);
				vector<vector<int>> evens, odds;
				F0R(i, n) {
								cin >> a[i];
								if (a[i] & 1) odds.pb({i});
								else evens.pb({i});
				}

				int e = evens.size(), o = odds.size();

				// o is maximal and e is minimal
				// Go from (o, e) to (k - p, p) by applying:
				// 1) (o, e) += (-2, 1): requires two odd
				// 2) (o, e) += (0, -1): requires one odd and one even.
				// After n1, n2 operations:
				// (o, e) -> (o - 2n1, e + n1 - n2) = (k - p, p)
				// (n1, n2) = (1/2 * (o + p - k), 1/2 * (o - k - p) + e)

				int xnum = o + p - k, ynum = o - k - p;
				if (xnum < 0 || xnum % 2 != 0 || ynum % 2 != 0 || ynum/2 + e < 0) {
								cout << "NO" << endl;
								return 0;
				}

				int n1 = (o + p - k)/2, n2 = (o - p - k)/2 + e;
				int cur1 = o, cur2 = e;
				while (n1 + n2 > 0) {
								if (n1 > 0 && ((int) odds.size() > 2 || (odds.size() == 2 && n2 == 0))) {
												n1--;
												vector<int> merged;
												vector<int> temp = odds.back();
												for (const auto& v : temp) {
																merged.pb(v);
												}
												odds.pop_back();
												temp = odds.back();
												for (const auto& v : temp) {
																merged.pb(v);
												}
												odds.pop_back();
												evens.pb(merged);
								} else if (n2 > 0 && ((((int) odds.size() >= 1 && (int) evens.size() >= 1)) || ((int) evens.size() >= 2))) {
												if ((int) odds.size() >= 1 && (int) evens.size() >= 1) {
													vector<int> nums = evens.back();
													int oldsz = odds[0].size();
													for (int i = 0; i < (int) nums.size(); ++i) {
																	odds[0].pb(nums[i]);
													}
													evens.pop_back();
													n2--;
												} else {
																vector<int> nums = evens.back();
																for (const auto& v : nums) evens[0].pb(v);
																evens.pop_back();
																n2--;
												}
								} else {
												cout << "NO" << endl;
												return 0;
								}
//								cout << "o = " << odds.size() << " and e = " << evens.size() << endl;
				}


				cout << "YES" << endl;
				for (int i = 0; i < (int) odds.size(); ++i) {
								cout << odds[i].size();
								for (const auto& v : odds[i]) cout << " " << a[v];
								cout << endl;
				}

				for (int i = 0; i < (int) evens.size(); ++i) {
								cout << evens[i].size();
								for (const auto& v : evens[i]) {
												cout << " " << a[v];
								}
								cout << endl;
				}
}
