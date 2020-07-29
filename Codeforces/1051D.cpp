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
 
const int MOD = /* 1000000007; */  998244353;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);


// dp[i][j][a][b] = # ways to color a 2xi grid with j components with top/bottom black if their bits are on.
ll dp[1001][2001][4];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll N, K, M;
		cin >> N >> K;
		dp[1][1][0] = 1;
		dp[1][1][3] = 1;
		dp[1][2][1] = 1;
		dp[1][2][2] = 1;

		for (int i = 2; i <= N; i++) {
				for (int j = 1; j <= K; j++) {
						dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % MOD;
						dp[i][j][1] = (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j - 2][2] + dp[i - 1][j - 1][3]) % MOD;
						dp[i][j][2] = (dp[i - 1][j - 1][0] + dp[i - 1][j - 2][1] + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % MOD;
						dp[i][j][3] = (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j][3]) % MOD;
				}
		}

		ll ans = 0;
		for (int i = 0; i <= 3; i++) ans = (ans + dp[N][K][i]) % MOD;
		cout << ans << endl;
}
