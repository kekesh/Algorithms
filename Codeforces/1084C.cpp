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
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

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

int dp[100005][2];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		string s;
		cin >> s;
		int N = (int) s.size();
		int pref = 0;
		// dp[i][0] = # sequences ending at b at S[i].
		// dp[i][1] = # sequences terminating at a at S[i].

		ll onesum = 0;
		ll zerosum = 0;

		for (int i = 1; i <= N; i++) {
				if (s[i - 1] == 'a') {
						dp[i][0] = (dp[i][0] + dp[i - 1][0] + dp[i - 1][1] + 1) % MOD;
						dp[i][1] = dp[i - 1][1];
				} else if (s[i - 1] == 'b') {
						dp[i][0] = dp[i - 1][0];
						dp[i][1] = dp[i - 1][0];
				} else {
						dp[i][0] = dp[i - 1][0];
						dp[i][1] = dp[i - 1][1];
				}
		}
		cout << dp[N][0] % MOD << endl;
}
