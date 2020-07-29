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
 
const int MOD = 998244353;  /* 1000000007 */;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

bool can[11][1 << 10];
pl P[11][1 << 10];
char cs[11][1 << 10];

void solve() {
		ll n, m;
		cin >> n >> m;
		vector<string> a(n);
		F0R(i, n) cin >> a[i];
		memset(can, false, sizeof(can));

		can[0][0] = true;
		P[0][0] = {-1, -1};
		for (int i = 1; i <= m; ++i) {
				for (int j = 0; j < (1 << n); ++j) {
						if (can[i - 1][j]) {
//								cout << "Transitioning from can[" << i - 1 << "][" << j << "]" << endl;
								set<char> can_take;
								for (const auto& s : a) {
										can_take.insert(s[i - 1]);
								}

								for (const auto& c : can_take) {
//										cout << c << " is a possible character we can take" << endl;
										int mask = 0;
										for (int str = 1; str <= n; ++str) {
												if (a[str - 1][i - 1] != c) {
														mask |= (1 << (str - 1));
												}
										}
										if ((j & mask) == 0) {
//												cout << "can[" << i << "][" << bitset<1>(j | mask) << "] = true" << endl;
												can[i][j | mask] = true;
												cs[i][j | mask] = c;
												P[i][j | mask] = {i - 1, j};
										}
								}
						}
				}
		}
		pl pos = {m, -1};
		string ans;
		for (int j = 0; j < (1 << n); ++j) {
				if (can[m][j]) {
						pos.s = j;
						break;
				}
		}
		if (pos.s == -1) {
				cout << -1 << endl;
				return;
		}

		while (pos.f != 0 || pos.s != 0) {
				ans += cs[pos.f][pos.s];
				pos = P[pos.f][pos.s];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		// dp[i][j] = true if we can get to i with state j.
		// P[i][j] = parent array
		ll t;
		cin >> t;
		while (t--) {
				solve();
		}
}
