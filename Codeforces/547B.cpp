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

int main() {
		ll n;
		scanf("%I64d", &n);
		vl a(n);
		F0R(i, n) scanf("%I64d", &a[i]);


		vl l(n), r(n);

		stack<int> s;
		for (int i = 0; i < n; i++) {
				while (!s.empty() && a[s.top()] >= a[i]) {
						s.pop();
				}
				l[i] = (s.empty()) ? -1 : s.top();
				s.push(i);
		}
		while (!s.empty()) s.pop();

		for (int i = n - 1; i >= 0; i--) {
				while (!s.empty() && a[s.top()] >= a[i]) {
						s.pop();
				}
				r[i] = s.empty() ? n : s.top();
				s.push(i);
		}

		vl ans(n + 1, 0);
		for (int i = 0; i < n; i++) {
				ans[r[i] - l[i] - 1] = max(ans[r[i] - l[i] - 1], a[i]);
		}


		for (int i = n - 1; i >= 0; i--) {
				ans[i] = max(ans[i], ans[i + 1]);
		}

		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
		cout << endl;
}
