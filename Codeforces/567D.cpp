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
		ll n, k, a, m;
		cin >> n >> k >> a >> m;
		vl moves(m);
		F0R(i, m) cin >> moves[i];

		int lo = 0, hi = m - 1;
		int ans = -1;
		while (lo <= hi) {
				int mid = lo + (hi - lo)/2;
//				cout << "Now looking at index: " << mid << " corresponding to value: " << moves[mid] << endl;

				bool ok[200001];
				memset(ok, true, n + 5);
				for (int i = 0; i <= mid; i++) {
						ok[moves[i]] = false;
				}

				int run = 0, cnt = 0;
				for (int i = 1; i <= n; i++) {
						if (ok[i]) {
								run++;
						} else {
								run = 0;
						}
						if (run == a) {
//								cout << "Placing a ship in [" << i - run + 1 << "," << i << "]" << endl;
								run = 0;
								i++;
								cnt++;
						}
				}
//				cout << "There are " << cnt << " valid placements" << endl;

				if (cnt < k) {
						// it works!
//						cout << "It works!" << endl;
						ans = mid + 1;
						// can we do better?
						hi = mid - 1;
				} else {
//						cout << "It doesn't work." << endl;
						// it doesn't work.
						lo = mid + 1;
				}
		}
		cout << ans << endl;
}

