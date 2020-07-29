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
 
const int MOD = /* 998244353; */ 1000000007;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


ll dp[100005][6];

int check(int num, int k) {
		unordered_set<int> primes;
		if (num % 2 == 0) {
				primes.insert(2);
		}
		while (num % 2 == 0) {
				num /= 2;
		}

		for (int i = 3; i * i <= num && (int) primes.size() <= k; i++) {
				if (num % i == 0) {
						while (num % i == 0) {
								num /= i;
						}
						primes.insert(i);
				}
		}
		if (num > 2) {
				primes.insert(num);
				num = 1;
		}
		return ((int) primes.size() == k);
}

void preprocess() {
		for (int i = 1; i <= 100002; i++) {
				dp[i][1] = dp[i - 1][1] + check(i, 1);
				dp[i][2] = dp[i - 1][2] + check(i, 2);
				dp[i][3] = dp[i - 1][3] + check(i, 3);
				dp[i][4] = dp[i - 1][4] + check(i, 4);
				dp[i][5] = dp[i - 1][5] + check(i, 5);
		}
}

int main() {
		preprocess();
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >> t;
		
		while (t--) {
				ll a, b, k;
				cin >> a >> b >> k;
				ll ans = dp[b][k] - dp[a - 1][k];
				cout << ans << endl;
		}
}
