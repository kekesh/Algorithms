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
				ll t;
				cin >> t;
				while (t--) {
								str s;
								ll n, x;
								cin >> n >> x >> s;

								vl visits(2*n + 5);
								ll pos = n;

								F0R(i, n) {
												pos += (s[i] == '0' ? 1 : -1);
												visits[pos]++;
								}

								// "shift" to the right by n - 1.
								ll delta = pos - n;
								x += n;

								if (delta == 0 && x >= 0 && x < 2*n + 5) {
												// in bounds!
												if (visits[x] == 0) cout << 0 << endl;
												else cout << -1 << endl;
												continue;
								} else if (delta == 0) {
												cout << 0 << endl;
												continue;
								}

								// delta != 0
								if ((x < 0 && delta > 0) || (x >= 2*n+5 && delta < 0)) {
												cout << 0 << endl;
												continue;
								}


								ll ans = (x == n);

								// we'll eventually get there.
								// find the first time we're in the range.
								if (x < 0 && delta < 0) {

												x -= 1ll * delta * (x/delta);
								} else if (x >= 2*n + 5 && delta > 0) {
												x -= 1ll * delta * ((x - (1ll*2*n+5))/delta);
								}


								ll cnt = 0;
								while (x < 0 || x >= 2*n + 5) {
												x -= delta;
												cnt++;
								}
								assert(cnt <= 2);
								
								while (x >= 0 && x < 2*n + 5) {
												ans += visits[x];
												x -= delta;
								}
								cout << ans << endl;
				}
}
