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

int grid[100][100];
ll ans;
ll check(int n, int m) {
/*		cout << "Checking the following coloring: " << endl;
		for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
						cout << grid[i][j];
				}
				cout << endl;
		}
*/
		for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
						ll ones = 0, twos = 0;
						if (i - 1 >= 0) {
								if (grid[i - 1][j] == 1) {
										ones++;
								} else {
										twos++;
								}
						}
						if (i + 1 < n) {
								if (grid[i + 1][j] == 1) {
										ones++;
								} else {
										twos++;
								}
						}
						if (j - 1 >= 0) {
								if (grid[i][j - 1] == 1) {
										ones++;
								} else {
										twos++;
								}
						}
						if (j + 1 < m) {
								if (grid[i][j+1] == 1) {
										ones++;
								} else {
										twos++;
								}
						}

						if (grid[i][j] == 1 && ones > 1) {
								return 0;
						} else if (grid[i][j] == 2 && twos > 1) {
								return 0;
						}
				}
		}
		return 1;
}

void paint(int num, int n, int m) {
		if (num == n*m) {
				ans += check(n, m);
				return;
		}
		int r = num / m;
		int c = num % m;
		grid[r][c] = 1;
		paint(num + 1, n, m);
		grid[r][c] = 2;
		paint(num + 1, n, m);
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll n, m;
		cin >> n >> m;
		ll maxi = MAX(n, m);

		vl dp(maxi + 5);

		dp[0] = 2, dp[1] = 2;

		for (int i = 2; i <= maxi; ++i) {
				dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
		}
		ll ans = (dp[n] + dp[m]) % MOD;
		ans -= 2;
		ans = ((ans % MOD) + MOD) % MOD;
		cout << ans << endl;
}
