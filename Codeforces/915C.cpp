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

ll have[10];
ll dp[20][2];
bool vis[20][2];
int digits;

ll solve(const vl& bd, ll num, int digit, bool flag) {
		if (digit == digits) {
				return num;
		}

		if (vis[digit][flag]) {
				return dp[digit][flag];
		}

		vis[digit][flag] = true;
		ll highest = flag ? 9 : bd[digit];
		ll lowest = (digit == 0 ? 1 : 0);
//		cout << "Digit " << digit << " has highest value " << highest << endl;
		ll mini = -INF;
		for (int i = highest; i >= lowest; i--) {
				if (have[i]) {
						ll new_num = num * 10 + i;
						bool new_flag = flag || i != highest;
						have[i]--;
						ll tmp = solve(bd, new_num, digit + 1, new_flag);
						mini = MAX(mini, tmp);
						have[i]++;
				}
		}
		return dp[digit][flag] = mini;
}


int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll a, b;
		cin >> a >> b;

		vl ad, bd;
		while (a) {
				ad.pb(a%10);
				have[a%10]++;
				a /= 10;
				digits++;
		}
		reverse(ad.begin(), ad.end());

		while (b) {
				bd.pb(b%10);
				b/= 10;
		}
		int need = ad.size() - bd.size();
		while (need > 0) {
				bd.pb(9);
				need--;
		}
		reverse(bd.begin(), bd.end());

		bool flag = false;
		if (bd.size() > ad.size()) flag = true;

		ll ans = solve(bd, 0, 0, flag);
		cout << ans << endl;
}
