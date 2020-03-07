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
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;

typedef pair<int, int> pi;
const ll INFTY = 10e8;

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

const int MOD = 1000000007;  // 998244353
const ll INF = 1e18;
const int MX = 35005;
const ld PI = 4 * atan((ld)1);


ll grid[3][3];

bool isok(ll x) {
	if (x == 0) return grid[0][1] == 1;
	if (x == 1) return grid[0][0] == 1;
	if (x == 2) return grid[1][0] == 1;
	if (x == 3) return grid[2][0] == 1;
	if (x == 4) return grid[2][1] == 1;
	if (x == 5) return grid[2][2] == 1;
	if (x == 6) return grid[1][2] == 1;
	if (x == 7) return grid[0][2] == 1;
}

int main() {

	ll x, y, d;
	while (cin >> x, x != -1) {
		cin >> y >> d;
		ll xp, yp, state;
		grid[1][1] = 0;
		F0R(i, 8) {
			cin >> xp >> yp >> state;
			grid[2 - (yp - y + 1)][xp - x + 1] = state;
		}
		ll ans = (d + 5) % 8;
		while (!isok(ans)) {
			ans = (ans + 1) % 8;
		}
		cout << ans << endl;
	}
	return 0;
}
