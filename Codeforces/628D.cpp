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

ll m, d;
string a, b;

ll dp[2005][2005][2];

ll count(const string& a, ll pos, ll residue, bool flag) {
		if (pos == (int) a.size()) {
				if (residue == 0) {
						return dp[pos][residue][flag] = 1;
				}
				return dp[pos][residue][flag] = 0;
		}
		// if pos is odd, then we can place it.
		if (dp[pos][residue][flag] != -1) {
				return dp[pos][residue][flag];
		}

		int limit = (flag ? 9 : a[pos] - '0');
		ll res = 0;
		for (int digit = 0; digit <= limit; digit++) {
				if (pos % 2 == 0 && digit == d) {
						continue;
				}
				if (pos & 1 && digit != d) {
						continue;
				}
				bool new_flag = flag;
				if (digit < limit) {
						new_flag = true;
				}
				int new_residue = (residue * 10 + digit) % m;
				res = (res + count(a, pos + 1, new_residue, new_flag)) % MOD;
		}
		return dp[pos][residue][flag] = res;
}

inline int check(const string& a) {
		ll sum = 0;
		for (int i = 0; i < (int) a.size(); i++) {
				if (i % 2 == 0 && (a[i] - '0') == d) {
					   return 0;
				} else if (i % 2 == 1 && (a[i] - '0') != d) {
						return 0;
				}
				sum = (sum * 10 + (a[i] - '0')) % m;
		}
		if (sum == 0) {
				return 1;
		}
		return 0;
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> m >> d >> a >> b;
		memset(dp, -1, sizeof(dp));
		ll c1 = count(b, 0, 0, false) % MOD;
		memset(dp, -1, sizeof(dp));
		ll c2 = count(a, 0, 0, false) % MOD;
		cout << ((c1 - c2 + check(a)) % MOD + MOD) % MOD << endl;
}
