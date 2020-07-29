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


ll dp[5001][5001];

ll one[5001], two[5001];

int main() {
				ll n;
				cin >> n;

				dp[0][0] = 1;
				one[0] = 1;
				for (int i = 1; i <= n; ++i) {
								char c;
								cin >> c;
								for (int j = 0; j <= i; ++j) {
												if (c == 's') {
																ll s;
																if (i & 1) s = one[i - 1] - (j - 1 >= 0 ? one[j - 1] : 0);
																else s = two[i - 1] - (j - 1 >= 0 ? two[j - 1] : 0);
																s = (((s % MOD) + MOD) % MOD);
																dp[i][j] = s;
												} else {
																if (j != 0) dp[i][j] = dp[i - 1][j - 1];
												}

												if (i & 1) two[j] = dp[i][j];
												else one[j] = dp[i][j];
												
												if (i & 1 && j > 0) two[j] = (two[j] + two[j - 1]) % MOD;
												else if (!(i & 1) && j > 0) one[j] = (one[j] + one[j - 1]) % MOD;
								}
				}
				ll ans = dp[n][0];
				cout << ans << endl;
}
