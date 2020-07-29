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

bitset<300> is_prime;
ll dp[200][20][2];

void sieve() {
		is_prime.flip();
		is_prime[0] = is_prime[1] = false;
		for (int i = 2; i < 300; i++) {
				if (is_prime[i]) {
						for (int j = i * i; j < 300; j += i) {
								is_prime[j] = false;
						}
				}
		}
}

ll count(const vl& a, int sum, int pos, bool flag) {
		if (pos == (int) a.size()) {
				if (is_prime[sum]) {
						return dp[sum][pos][flag] = 1;
				}
				return dp[sum][pos][flag] = 0;
		}
		if (dp[sum][pos][flag] != -1) {
				return dp[sum][pos][flag];
		}

		int limit = (flag ? 9 : a[pos]);
		ll res = 0;
		for (int digit = 0; digit <= limit; digit++) {
				bool new_flag = flag;
				if (digit < a[pos]) new_flag = true;
				res += count(a, sum + digit, pos + 1, new_flag);
		}
		return dp[sum][pos][flag] = res;
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		sieve();

		ll T;
		cin >> T;
		while (T--) {
				ll a, b;
				cin >> a >> b;
				vl av, bv;
				while (b) {
						bv.pb(b % 10);
						b /= 10;
				}
				a--;
				while (a) {
						av.pb(a % 10);
						a /= 10;
				}
				reverse(av.begin(), av.end());
				reverse(bv.begin(), bv.end());
				memset(dp, -1, sizeof(dp));
				ll c1 = count(bv, 0, 0, false);
				memset(dp, -1, sizeof(dp));
				ll c2 = count(av, 0, 0, false);
				cout << c1 - c2 << endl;
		}	
}
