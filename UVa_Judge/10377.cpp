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

// Start of code.

char grid[60][60];
const char dirs[4] = {'N', 'E', 'S', 'W'};

int main() {
	ll T;
	cin >> T;
	while (T--) {
		ll R, C;
		cin >> R >> C;
//		cout << "K" << endl;
		F0R(i, R) {
			getchar();
			F0R(j, C) {
				char c = getchar();
				grid[i][j] = c;
			}
		}
		ll r, c;
		int ind = 0;
		cin >> r >> c;
		r--;
		c--;
//		cout << "Done with numbers." << endl;
		assert(grid[r][c] == ' ');
		char q;
		while (cin >> q, q != 'Q') {
//			cout << "Q = " << q << endl;
			if (q == 'R') {
				ind = (ind + 1) % 4;
//				cout << "Now facing " << dirs[ind] << endl;
			} else if (q == 'L') {
				ind = ((ind - 1) + 4) % 4;
//				cout << "Now facing " << dirs[ind] << endl;
			} else if (q == 'F') {
				if (ind == 0 && r > 0 && grid[r - 1][c] != '*') {
				       r--;
				} else if (ind == 1 && c < C - 1 && grid[r][c + 1] != '*') {
					c++;
				} else if (ind == 2 && r < R - 1 && grid[r + 1][c] != '*') {
					r++;
				} else if (ind == 3 && c > 0 && grid[r][c - 1] != '*') {
					c--;
				}
			}
//			cout << "(" << r << "," << c << ")" << endl;
		}
		cout << r + 1 << " " << c + 1 << " " << dirs[ind] << endl;
		if (T) cout << endl;
	}
	return 0;
}
