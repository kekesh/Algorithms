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

ll N, K;
ll ways[2001][2001];

vi divisors(int n) {
		vector<int> ans;
		for (int i = 1; i <= sqrt(n); i++) {
				if (n % i == 0) {
						if (n / i == i) {
								ans.pb(i);
						} else {
								ans.pb(i);
								ans.pb(n / i);
						}
				}
		}
		return ans;
}

int main() {
		cin >> N >> K;

		for (int i = 1; i <= N; i++) {
				ways[1][i] = 1;
		}


		for (int j = 1; j <= N; j++) {
				vi div = divisors(j);
				for (int i = 2; i <= K; i++) {
						ll s = 0;

						for (auto k : div) {
								s = (s + ways[i - 1][k]) % MOD;
						}

						ways[i][j] = (ways[i][j] + s) % MOD;
				}
		}
						/*
		for (int i = 2; i <= K; i++) {
				for (int j = 1; j <= N; j++) {
						ll s = 0;

						vi div = divisors(j);
						for (auto k : div) {
								s = (s + ways[i - 1][k]) % MOD;
						}
						// this part can be done in O(1) time.
//						for (int k = 1; k <= j; k++) {
//								if (j % k == 0) {
//										s = (s + ways[i - 1][k]) % MOD;
//								}
//						}

						ways[i][j] = (ways[i][j] + s) % MOD;
				}
		}
		*/

		ll ans = 0;
		for (int i = 1; i <= N; i++) {
				ans = (ans + ways[K][i]) % MOD;
		}
		cout << ans << endl;
}
