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
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


ll lcm(ll a, ll b) {
		ll pr = 1ll * a * b;
		pr /= __gcd(a, b);
		return pr;
}


int main() {
		ll n;
		scanf("%I64d", &n);
		if (n == 1) {
				cout << 1 << endl;
				return 0;
		} else if (n == 2) {
				cout << 2 << endl;
				return 0;
		}
		ll ans = 0;
		for (int i = n; i >= 1; --i) {
				ll candidate = 1ll * i * (i - 1);
				for (int j = n - 2; j >= 0; --j) {
						if (__gcd((ll) j, candidate) == 1) {
								ans = MAX(1ll * candidate * j, ans);
								break;
						}
				}
		}
		printf("%I64d\n", ans);
}
