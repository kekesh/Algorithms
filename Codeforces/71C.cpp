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


vl divs(ll n) {
		vl res;
		for (int i = 1; i * i <= n; ++i) {
				if (n % i == 0) {
						res.pb(i);
						if (i != n/i) res.pb(n/i);
				}
		}
		return res;
}

int main() {
		ll n;
		scanf("%I64d", &n);
		auto pf = divs(n);
		vl a(n);
		F0R(i, n) scanf("%I64d", &a[i]);

		bool yes = false;
		for (const auto& p : pf) {
				if (p >= (n + 1)/2) continue;
				for (int i = 0; i < p; ++i) {
						if (a[i]) {
								int j = i;
								do {
										j = (j + p) % n;
								} while (a[j] && j != i);
								if (j == i) {
										yes = true;
										break;
								}
								
						}
						if (yes) break;
				}
		}
		if (yes) printf("YES\n");
		else printf("NO\n");
}
