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


ll dp[20][20][2];
ll cnt;
ll count(const vl& a, ll pos, ll nonzero, bool flag) {
		if (pos == (int) a.size()) {
				if (nonzero <= 3) {
						return dp[pos][nonzero][flag] = 1;
				}
				return dp[pos][nonzero][flag] = 0;
		}
		if (dp[pos][nonzero][flag] != -1) {
				return dp[pos][nonzero][flag];
		}
		int limit = (flag ? 9 : a[pos]);
		ll res = 0;
		for (int digit = 0; digit <= limit; digit++) {
				bool new_flag = flag;
				ll new_nonzero_count = nonzero;
				if (digit < limit) new_flag = true;
				if (digit != 0) new_nonzero_count++;
				res += count(a, pos + 1, new_nonzero_count, new_flag);
		}
		return dp[pos][nonzero][flag] = res;
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll T;
		cin >> T;
		while (T--) {
				ll L, R;
				cin >> L >> R;
				vl Rd, Ld;
				while (R) {
						Rd.pb(R % 10);
						R /= 10;
				}
				L--;
				while (L) {
						Ld.pb(L % 10);
						L /= 10;
				}
				reverse(Rd.begin(), Rd.end());
				reverse(Ld.begin(), Ld.end());
				memset(dp, -1, sizeof(dp));
				ll c1 = count(Rd, 0, 0, false);
				memset(dp, -1, sizeof(dp));
				ll c2 = count(Ld, 0, 0, false);
				cout << c1 - c2 << endl;
		}
}
