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
		ll n, mod;
		cin >> n >> mod;
		vl a(n);
		F0R(i, n) cin >> a[i];

		ll lo = 0, hi = 1e7, ans = INF;
		while (lo <= hi) {
				ll m = (lo + hi)/2;
				bool ok = true;

				vl b = a;
				if (b[0] + m >= mod) {
						b[0] = 0;
				}
				for (int i = 1; i < n; i++) {
						if (b[i] + m >= mod) {
								ll maxiv = (b[i] + m) % mod;
								if (maxiv >= b[i - 1]) {
										b[i] = b[i - 1];
								}
						}
						if (b[i] < b[i - 1]) {
								b[i] += MIN(m, b[i - 1] - b[i]);
								if (b[i] < b[i - 1]) {
										ok = false;
										break;
								}
						}
				}
				if (ok) {
//						cout << "yes." << endl;
						hi = m - 1;
						ans = m;
				} else {
//						cout << "no." << endl;
						lo = m + 1;
				}
		}
		cout << ans << endl;

}
