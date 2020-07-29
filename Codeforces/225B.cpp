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

ll F[1005];

int main() {
		ll s, k;
		cin >> s >> k;
		F[1] = 1;
		ll ubd = 1;
		for (int i = 2; i <= 1000; ++i) {
				ll ss = 0;
				ll bd = MAX(0, i - k);
				for (int j = i - 1; j >= bd; --j) {
						ss += F[j];
				}
				F[i] = ss;
				ubd = i;
				if (ss > 1e15) {
						break;
				}
		}

		vl res;

		while (s) {
				ll lo = 0, hi = ubd;
				ll r = -1;
				while (lo <= hi) {
						ll mm = (lo + hi)/2;
						if (F[mm] <= s) {
								r = mm;
								lo = mm + 1;
						} else {
								hi = mm - 1;
						}
				}
				res.pb(F[r]);
				s -= F[r];
		}

		if (res.size() == 1) res.pb(0);
		cout << (int) res.size() << endl;
		for (const auto& v : res) cout << v << " ";
		cout << endl;
}
