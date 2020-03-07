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
char grid[3][3];

// returns true if c won.
bool check(char c) {
	// existence
	bool exists = (grid[0][0] == c && grid[0][1] == c && grid[0][2] == c);
       	exists |= (grid[1][0] == c && grid[1][1] == c && grid[1][2] == c);
	exists |= (grid[2][0] == c && grid[2][1] == c && grid[2][2] == c);
       	exists |= (grid[0][0] == c && grid[1][0] == c && grid[2][0] == c);
	exists |= (grid[0][1] == c && grid[1][1] == c && grid[2][1] == c);
	exists |= (grid[0][2] == c && grid[1][2] == c && grid[2][2] == c);
	exists |= (grid[0][0] == c && grid[1][1] == c && grid[2][2] == c);
	exists |= (grid[2][0] == c && grid[1][1] == c && grid[0][2] == c);

	//unique
/*	char cp = c == 'X' ? 'O' : 'X';
	bool uc = (grid[0][0] == cp && grid[0][1] == cp && grid[0][2] == cp);
       	uc |= (grid[1][0] == cp && grid[1][1] == cp && grid[1][2] == cp);
	uc |= (grid[2][0] == cp && grid[2][1] == cp && grid[2][2] == cp);
       	uc |= (grid[0][0] == cp && grid[1][0] == cp && grid[2][0] == cp);
	uc |= (grid[0][1] == cp && grid[1][1] == cp && grid[1][2] == cp);
	uc |= (grid[0][2] == cp && grid[1][2] == cp && grid[2][2] == cp);
	uc |= (grid[0][0] == cp && grid[1][1] == cp && grid[2][2] == cp);
	uc |= (grid[2][0] == cp && grid[1][1] == cp && grid[0][2] == cp); */

	return exists;
}

int main() {
	ll T;
	cin >> T;

	while (T--) {
		F0R(i, 3) cin >> grid[i];

		ll os, xs;
		os = xs = 0;
		F0R(i, 3) {
			F0R(j, 3) {
				if (grid[i][j] == 'X') xs++;
				else if (grid[i][j] == 'O') os++;
			}
		}
		ll moves = xs + os;
		if (moves & 1 && xs - 1 == os) {
			// x won
			bool xwon = check('X');
			bool owon = check('O');
			bool valid = true;
			if (xwon && owon) valid = false;
			if (owon) valid = false;
			if (valid) cout << "yes" << endl;
			else cout << "no" << endl;
		} else if (moves % 2 == 0 && xs == os) {
			// o won because they went most recently
			bool xwon = check('X'), owon = check('O');
			bool valid = true;
			if (xwon && owon) valid = false;
			if (xwon) valid = false;
			if (valid) cout << "yes" << endl;
			else cout << "no" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}
