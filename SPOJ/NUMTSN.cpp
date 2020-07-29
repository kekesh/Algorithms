#include <assert.h>
#include <math.h>
#include <complex>
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
 
const int MOD = 1000000007;  // 998244353;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);

ll dp[52][52][52][2][2];

// d1 = 6 - 3, d2 = 9 - 6, bool flag2 = at least one 3

ll count(const string &a, ll pos, ll d1, ll d2, bool flag2, bool flag) {
		if (pos == (int) a.size()) {
				if (flag2 && d1 == 0 && d2 == 0) {
						return dp[pos][d1][d2][flag2][flag] = 1;
				}
				return dp[pos][d1][d2][flag2][flag] = 0;
		}

		if (dp[pos][d1][d2][flag2][flag] != -1) {
				return dp[pos][d1][d2][flag2][flag];
		}

		ll ans = 0;
		ll limit = (flag ? 9 : a[pos] - '0');

		for (int digit = 0; digit <= limit; digit++) {
				bool new_flag = flag;
				int new_d1 = d1, new_d2 = d2;
				bool new_flag2 = flag2;

				if (digit < limit) {
						new_flag = true;
				}

				if (digit == 3) {
						new_flag2 = true;
				}

				if (digit == 3) {
						new_d1--;
				} else if (digit == 6) {
						new_d1++;
						new_d2--; // 9 - 6
				} else if (digit == 9) {
						new_d2++;
				}
				ans = (ans + count(a, pos + 1, new_d1, new_d2, new_flag2, new_flag)) % MOD;
		}
		return dp[pos][d1][d2][flag2][flag] = ans;
}

inline int check(const string &a) {
		int c1 = count(a.begin(), a.end(), '3');
		int c2 = count(a.begin(), a.end(), '6');
		int c3 = count(a.begin(), a.end(), '9');
		return (c1 >= 1 && c1 == c2 && c2 == c3);
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		ll T;
		cin >> T;
		while (T--) {
				string a, b;
				cin >> a >> b;
				memset(dp, -1, sizeof(dp));
				ll c1 = count(b, 0, 0, 0, false, false);
				memset(dp, -1, sizeof(dp));
				ll c2 = count(a, 0, 0, 0, false, false);

				cout << (((c1 - c2 + check(a)) % MOD) + MOD) % MOD << endl;
		}
}
