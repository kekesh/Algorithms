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
 
const int MOD = /* 998244353; */ 1000000007;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


ll a[200005];
ll dp[200005][2];

int main() {
		ll n, c;
		cin >> n >> c;
		vl a(n + 1), b(n + 1);
		F0R(i, n - 1) cin >> a[i];
		F0R(i, n - 1) cin >> b[i];
		dp[0][0] = 0;
		dp[0][1] = c;
		cout << 0;
		for (int i = 1; i <= n - 1; i++) {
//				cout << "i = " << i << endl;
//				cout << "a[i - 1] = " << a[i - 1] << " and b[i - 1] = " << b[i - 1] << endl;
				// dp[i][0] = minimum cost to be at floor i outside of an elevator.
				// dp[i][1] = minimum cost to be at floor i inside of an elevator.

				dp[i][0] = MIN(dp[i - 1][0] + a[i - 1], dp[i - 1][1] + b[i - 1]);
				dp[i][1] = MIN(dp[i - 1][1] + b[i - 1], MIN(dp[i - 1][0] + c + b[i - 1], dp[i][0] + c));

				cout << " " << MIN(dp[i][0], dp[i][1]);
		}
		cout << endl;
}
