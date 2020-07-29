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


ll k, n, a, b;

void solve() {
		int lo = 0, hi = k;
		int ans = -1;
		while (lo <= hi) {
				int m = lo + (hi - lo)/2;
				int charge_left = k - a*m;
				int play_and_charge_turns = (charge_left % b == 0) ? charge_left/b - 1 : charge_left/b;

				if (charge_left > 0 && k - a*m - play_and_charge_turns * b > 0 && m + play_and_charge_turns >= n) {
						// It works!
//						cout << "It works!" << endl;
						lo = m + 1;
						ans = m;
				} else {
						hi = m - 1;
				}
		}
		cout << MIN(ans, n) << endl;
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll q;
		cin >> q;
		while (q--) {
				cin >> k >> n >> a >> b;
				solve();
		}
}
