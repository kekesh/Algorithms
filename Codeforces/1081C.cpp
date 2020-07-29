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
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




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
 
const int MOD = 1000000007;  // 998244353
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);


ll dp[2001][2001];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll N, K, M;
		cin >> N >> M >> K;

		// let dp[i][j] be the number of ways to paint the first i bricks with j bricks different
		// than the brick on its immediate left.

		// dp[i][j] = dp[i - 1][j] * m + dp[i - 1][j - 1] * (m - 1)

		// dp[0][j] = 1;

		for (int j = 0; j <= K; j++) {
				dp[0][j] = 1;
		}

		for (int i = 1; i <= N; i++) {
				for (int j = 0; j < i; j++) {
						if (i == 1) {
								dp[i][j] = M;
								continue;
						}  else {
								dp[i][j] = dp[i - 1][j];
						}
						if (j - 1 >= 0)	dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (M - 1)) % 998244353;
				}
		}
		cout << dp[N][K] << endl;
}
