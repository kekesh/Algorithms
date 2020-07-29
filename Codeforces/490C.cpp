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


ll binpow(ll a, ll b, ll m) {
		ll res = 1;
		a %= m;
		while (b) {
				if (b & 1) res = (res * a) % m;
				a = (a * a) % m;
				b >>= 1;
		}
		return res;
}

int main() {
		string s;
		ll a, b;
		cin >> s >> a >> b;

		ll prefix = (s[0] - '0') % a, suffix = 0;
		for (int i = 1; i < int(s.size()); ++i) {
				ll pw = s.size() - i - 1;
				ll temp = binpow(10, pw, b);
				temp = (temp * (s[i] - '0')) % b;
				suffix = (suffix + temp) % b;
		}


		for (int i = 1; i < (int) s.size(); ++i) {
				if (s[i] != '0' && prefix % a == 0 && suffix % b == 0) {
						cout << "YES" << endl;
						string s1 = s.substr(0, i);
						string s2 = s.substr(i, s.size() - i);
						cout << s1 << endl;
						cout << s2 << endl;
						return 0;
				}
				// add s[i] to prefix. remove from suffix. 
				prefix = (1ll * prefix * 10) % a;
				prefix = (prefix + (s[i] - '0')) % a;
				
				// remove s[i] from it.
				
				ll rem = binpow(10, s.size() - i - 1, b);
				rem = (1ll * rem * (s[i] - '0')) % b;
				suffix = (((suffix - rem) % b) + b) % b;
		}
		cout << "NO" << endl;
		return 0;
}
