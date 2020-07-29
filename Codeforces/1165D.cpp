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



int main() {
		ll t;
		scanf("%I64d", &t);
		while (t--) {
				ll n;
				scanf("%I64d", &n);
				vl a(n);
				F0R(i, n) cin >> a[i];
				sort(a.begin(), a.end());
				ll num = 1ll * a[0] * a.back();

				vl divs;
				for (ll i = 2; i * i <= num; ++i) {
						if (num%i == 0) {
								divs.pb(i);
								if (num/i != i) {
										divs.pb(num/i);
								}
						}
				}

				bool ok = (divs.size() == a.size());
				sort(divs.begin(), divs.end());
				for (int i = 0; i < (int) divs.size() && ok; ++i) {
						ok &= (divs[i] == a[i]);
				}
				if (!ok) printf("-1\n");
				else printf("%I64d\n", num);
		}
}
