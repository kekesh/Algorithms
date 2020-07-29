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
const ll MOD2 = 1e10;

ll lp[200'005];

void preprocess() {
		for (int i = 2; i <= 200002; i++) {
				if (!lp[i]) {
						for (int j = i; j <= 200002; j += i) {
								if (!lp[j]) lp[j] = i;
						}
				}
		}
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		preprocess();
		ll N;
		cin >> N;
		map<ll, vector<ll>> m;
		for (int i = 0; i < N; i++) {
				map<ll, ll> temp;
				ll x;
				cin >> x;
				while (x > 1) {
						ll p = lp[x];
//						cout << p << endl;
						temp[p]++;
						x /= p;
				}
				for (const auto&pp : temp) {
						m[pp.f].pb(pp.s);
				}
		}

		ll prod = 1;
		for (const auto& pp : m) {
				if (pp.s.size() == N - 1) {
						vector<ll> v = pp.s;
						sort(v.begin(), v.end());
						prod *= pow(pp.f, v[0]);
				} else if (pp.s.size() == N) {
						vl v = pp.s;
						sort(v.begin(), v.end());
						prod *= pow(pp.f, v[1]);
				}
		}
		cout << prod << endl;
		
}
