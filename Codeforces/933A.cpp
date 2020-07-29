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


ll dp[5001][3];

int main() {
				ll n;
				cin >> n;
				vl A(n);
				F0R(i, n) cin >> A[i];
				ll ans = -INF;

				for (int i = 0; i < n; ++i) {
								// dp[i][0]
								dp[i][0] = 1;
								ll s = -INF;

								for (int j = 0; j < i; ++j) {
												if (A[j] <= A[i]) {
																s = MAX(dp[j][0], s);
												}
								}
								dp[i][0] = MAX(dp[i][0], 1 + s);

								// dp[i][1]
								// one flip: either flipped already or flipping now.

								dp[i][1] = -INF;
								dp[i][2] = -INF;
								for (int j = 0; j < i; ++j) {
												if (A[j] > A[i]) {
																// flip at index i
																dp[i][1] = MAX(dp[i][1], dp[j][0] + 1);
												}

												if (A[j] >= A[i]) {
																// already flipped(?)
																dp[i][1] = MAX(dp[i][1], dp[j][1] + 1);
												}
												if (A[j] < A[i]) {
																dp[i][2] = MAX(dp[i][2], dp[j][1] + 1);
												}
												if (A[j] <= A[i]) {
																dp[i][2] = MAX(dp[i][2], dp[j][2] + 1);
												}
								}
								ans = MAX(ans, MAX(dp[i][0], MAX(dp[i][1], dp[i][2])));
				}
				cout << ans << endl;
}
