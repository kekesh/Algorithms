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


ll dp[101][1500];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int v1, v2, t, d;
		cin >> v1 >> v2 >> t >> d;

		F0R(i, 101) {
				F0R(j, 1500) {
						dp[i][j] = -INF;
				}
		}

		dp[1][v1] = v1;
//		cout << "BC: dp[1][" << v1 << "] = " << v1 << endl;

		for (int i = 2; i <= t; i++) {
//				cout << "When i = " << i << ", we're looping from j = " << v1 - (i - 1) * d << " to " << v1 + (i - 1) * d << endl;
				for (int j = v1 - (i - 1) * d; j <= v1 + (i - 1)*d; j++) {
						if (j < 0) continue;

						ll maxi = -1;
						for (int k = j - d; k <= j + d; k++) {
								if (k >= 0) maxi = MAX(maxi, dp[i - 1][k]);
						}

						dp[i][j] = j + maxi;
//						cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
				}
		}
		cout << dp[t][v2] << endl;
}
