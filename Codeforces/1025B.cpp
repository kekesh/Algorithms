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
		ll a, b, n;
		scanf("%I64d", &n);
		vpl others(n);
		F0R(i, n) scanf("%I64d %I64d", &others[i].f, &others[i].s);
		random_shuffle(others.begin(), others.end());
		a = others[0].f, b = others[0].s;

		set<int> div;
		for (int i = 1; i*i <= a || i * i <= b; ++i) {
				if (i * i <= a && a % i == 0) {
						div.insert(i);
						div.insert(a/i);
				}
				if (i * i <= b && b % i == 0) {
						div.insert(i);
						div.insert(b/i);
				}
		}

		for (const auto& v : div) {
				if (v == 1) continue;
				int i;
				for (i = 1; i < n; ++i) {
						if (others[i].f % v != 0 && others[i].s % v != 0) {
								break;
						}
				}

				if (i == n) {
						printf("%d\n", v);
						return 0;
				}
		}

		printf("%d\n", -1);
}
