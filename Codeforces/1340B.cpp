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
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<ld> vld;
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
 
const int MOD = 998244353;  /* 1000000007 */;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

const string nums[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
bitset<2005> possible[2005];

int ev(const str& a, const str& b) {
		int c = 0;
		for (int i = 0 ; i < (int) a.size(); ++i) {
				if (a[i] == '1' && b[i] == '0') return -1;
				c += (a[i] == '0' && b[i] == '1');
		}
		return c;
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll n, k;
		cin >> n >> k;
		vs a(n);
		F0R(i, n) cin >> a[i];
		possible[n][0] = true;

		for (int i = n - 1; i >= 0; --i) {
				str s = a[i];
				bitset<7> temp(s);
				for (int digit = 0; digit <= 9; ++digit) {
						// we can take this digit. what's the cost?
						int cost = ev(s, nums[digit]);
						if (cost == -1) continue;
						possible[i] |= (possible[i + 1] << cost);
				}
		}

		if (!possible[0][k]) {
				cout << -1 << endl;
				return 0;
		}

		int left = k;
		string ans;
		for (int pos = 0; pos < n; ++pos) {
				for (int digit = 9; digit >= 0; --digit) {
						str s = a[pos];
						int cost = ev(s, nums[digit]);
						if (cost == -1) continue;
						if (left - cost >= 0 && possible[pos + 1][left - cost]) {
								left -= cost;
								ans += to_string(digit);
								break;
						}
				}
		}
		cout << ans << endl;

}
