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

ll C[100005];
ll dp[100005][2];
ll N;
int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		vector<string> A;
		cin >> N;
		string s;
		F0R(i, N) cin >> C[i];
		F0R(i, N) cin >> s, A.pb(s);
		dp[0][1] = C[0];

		for (int i = 1; i < N; i++) {
				string prev = A[i - 1];
				string curr = A[i];
				
				string revcurr = A[i];
				string revprev = A[i - 1];
				reverse(revprev.begin(), revprev.end());
				reverse(revcurr.begin(), revcurr.end());

				dp[i][0] = INF;
				if (prev <= curr) dp[i][0] = MIN(dp[i][0], dp[i - 1][0]);
				if (revprev <= curr) dp[i][0] = MIN(dp[i][0], dp[i - 1][1]);


				// dp[i][1] 
				dp[i][1] = INF;
				if (prev <= revcurr) dp[i][1] = MIN(dp[i][1], C[i] + dp[i - 1][0]);
				if (revprev <= revcurr) dp[i][1] = MIN(dp[i][1], C[i] + dp[i - 1][1]);
		}
		ll ans = MIN(dp[N - 1][0], dp[N - 1][1]);
		if (ans == INF) cout << -1 << endl;
		else cout << ans << endl;
}
