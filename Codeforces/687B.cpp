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


int lpf[1'000'005];
 
void dp() {
		for (ll i = 2; i <= 1'000'000; i++) {
				if (!lpf[i]) {
						lpf[i] = i;
						for (ll j = i * i; j <= 1'000'000; j += i) {
								if (!lpf[j]) {
										lpf[j] = i;
								}
						}
				}
		}
}

int main() {
		dp();
		ll n, k, x;
		scanf("%I64d %I64d", &n, &k);

		unordered_set<int> prime_powers;
		for (int i = 0; i < n; ++i) {
				scanf("%I64d", &x);
				while (x != 1) {
						ll pp = 1;
						ll pf = lpf[x];

						while (x % pf == 0) {
								pp *= pf;
								x /= pf;
								prime_powers.insert(pp);
						}
				}
		}

		bool ok = true;
		while (k != 1) {
				ll pp = 1;
				ll pf = lpf[k];
				while (k % pf == 0) {
						pp *= pf;
						k /= pf;
				}
				ok &= (prime_powers.find(pp) != prime_powers.end());
		}

		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;

}
