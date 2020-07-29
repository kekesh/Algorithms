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

ll N, H, L, R;
long long dp[2001][2001];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N >> H >> L >> R;
		vector<ll> A(N + 1);
		for (int i = 1; i <= N; i++) cin >> A[i];

		for (int j = 1; j < H; j++) {
				dp[0][j] = -INF;
		}

		for (int i = 1; i <= N; i++) {
				for (int j = 0; j < H; j++) {
						// dp[i][j] = maximum good sleeps we can get after sleeping i times at time j.
						// dp[i][j] = MAX(dp[i - 1][j - (a[i] - 1)] + 1, dp[i - 1][j - a[i]] + 1)

//						int flag1 = (((((j - (A[i] - 1)) % H) + H) % H) <= R) && (((((j - (A[i] - 1)) % H) + H) % H) >= L);
//						int flag2 = (((((j - A[i]) % H) + H) % H) <= R) && (((((j - A[i]) % H) + H) % H) >= L);
						int flag1 = (j <= R && j >= L);
						int flag2 = flag1;
						dp[i][j] = MAX(
										dp[i - 1][(((j - (A[i] - 1)) % H) + H) % H] + flag1, 
										dp[i - 1][(((j - (A[i])) % H) + H) % H] + flag2
										);


//						if (dp[i][j] >= 1) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;

				}
		}

		ll ans = -INF;
		for (int j = 0; j < H; j++) ans = MAX(ans, dp[N][j]);
		cout << ans << endl;
}
