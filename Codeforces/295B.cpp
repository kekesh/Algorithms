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
 
const int MOD = 998244353;  /* 1000000007 */;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

const int MAXN = 1e9 + 2;

ll d[502][502];
ll p[502];
int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		ll n;
		cin >> n;
		F0R(i, n) F0R(j, n) cin >> d[i][j];
		F0R(i, n) cin >> p[i];

		unordered_set<int> added;
		stack<ll> ss;
		for (int z = n - 1, k = p[z] - 1; z >= 0; --z, k = p[z] - 1) {
				ll s = 0;
				added.insert(k);
				for (int i = 0; i < n; ++i) {
						for (int j = 0; j < n; ++j) {
								d[i][j] = MIN(d[i][j], d[i][k] + d[k][j]);
								if (added.find(i) != added.end() && added.find(j) != added.end()) s += d[i][j];
						}
				}
				ss.push(s);
		}
		while (!ss.empty()) {
				cout << ss.top() << " ";
				ss.pop();
		}
		cout << endl;
}
