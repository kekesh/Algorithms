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
typedef vector<int> vi;
typedef vector<ll> vl;
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
const ll MOD2 = 1e10;

ll lp[5000005];
ll dp[5000005];

void sieve() {
		for (int i = 2; i <= 5000002; i++) {
				if (!lp[i]) {
						for (int j = i; j <= 5000002; j += i) {
								if (!lp[j]) {
										lp[j] = i;
								}
						}
				}
		}

		dp[1] = 0;
		for (int i = 2; i <= 5000002; i++) {
				int num = i;
				int cnt = 0;
				while (num > 1) {
						cnt++;
						num /= lp[num];
				}
				dp[i] = cnt + dp[i - 1];
		}
}

int main() {
		int T;
		sieve();
		scanf("%d", &T);
		while (T--) {
				int a, b;
				scanf("%d%d", &a, &b);
				printf("%I64d\n", dp[a] - dp[b]);
		}
}
