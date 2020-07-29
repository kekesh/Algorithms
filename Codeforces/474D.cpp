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


ll Q, K;
unsigned long long dp[100005];
unsigned long long prefix[100005];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> Q >> K;
		dp[0] = 1;

		for (int i = 1; i <= 100000; i++) {
				dp[i] = dp[i - 1];
				if (i - K >= 0) dp[i] = (dp[i] + dp[i - K]) % MOD;
		}

		prefix[0] = dp[0];
		for (int i = 1; i <= 100000; i++) {
				prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
		}

		while (Q--) {
				ll a, b;
				cin >> a >> b;
				ll lhs = prefix[b];
				ll rhs = prefix[a - 1];
				cout << ((lhs - rhs) % MOD + MOD) % MOD << endl;
		}
}
