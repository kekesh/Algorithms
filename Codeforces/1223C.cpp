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


int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll Q;
		cin >> Q;
		while (Q--) {
				ll N;
				cin >> N;
				vl P(N + 1, 0);
				vl mul(N + 1, 0);
				F0R(i, N) cin >> P[i + 1];
				ll x, a, y, b, k;
				cin >> x >> a >> y >> b >> k;

				for (int i = 0; i < N; i++) {
						if ((1 + i) % a == 0) {
								mul[i] += x;
						}
						if ((1 + i) % b == 0) {
								mul[i] += y;
						}
				}

				sort(P.begin(), P.end(), greater<int>());
				int lo = 1, hi = N;
				int ans = -1;
				while (lo <= hi) {
						int m = lo + (hi - lo)/2;
						vl copy = mul;
						sort(copy.begin(), copy.begin() + m, greater<int>());
						ll s = 0;


						for (int i = 0; i < m; i++) {
								s += copy[i] * P[i];
						}
						s /= 100;

						if (s >= k) {
								ans = m;
								hi = m - 1;
						} else {
								lo = m + 1;
						}
				}
				cout << ans << endl;

		}
}
