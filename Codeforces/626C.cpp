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
		ll n, m;
		cin >> n >> m;
		ll lo = 0, hi = 6'000'000;
		ll ans = INF;
		while (lo <= hi) {
				ll trying = (lo + hi)/2;
				ll sixes = trying/6;
				ll threes = trying/3 - sixes;
				ll twos = trying/2 - sixes;

				bool ok = false;
				ok |= (twos >= n && threes >= m);
				ok |= (twos < n && threes >= m && twos + sixes >= n);
				ok |= (twos >= n && threes < m && threes + sixes >= m);
				ok |= (twos < n && threes < m && (n - twos + m - threes) <= sixes);

				if (!ok) {
						lo = trying + 1;
				} else {
						// it works.
						// twos >= n && threes >= m.
						hi = trying - 1;
						ans = trying;
				}
		}
		cout << ans << endl;


}
