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


char grid[5][5];
int j;
int main() {

	string line;
	bool first = true;
	while (getline(cin, line), line != "Z") {
		if (!first) cout << endl;

		first = false;
		F0R(i, line.size()) grid[0][i] = line[i];
		FOR(i, 1, 5) {
			getline(cin, line);
			F0R(j, line.size()) {
				grid[i][j] = line[j];
			}
		}

		int r, c;
		r = c = -1;
		F0R(i, 5) {
			F0R(j, 5) {
				if (grid[i][j] == ' ') {
					r = i;
					c = j;
				}
			}
		}
		bool valid = true;
		char nxt;
		while (cin >> nxt, nxt != '0') {
			if (!valid) continue;
			if (nxt == 'A') {
				/* above. */
				if (r == 0) valid = false;
				else {
					swap(grid[r][c], grid[r - 1][c]);
					r--;
				}
			} else if (nxt == 'B') {
				if (r == 4) valid = false;
				else {
					swap(grid[r][c], grid[r + 1][c]);
					r++;
				}
			} else if (nxt == 'L') {
				if (c == 0) valid = false;
				else {
					swap(grid[r][c], grid[r][c - 1]);
					c--;
				}
			} else if (nxt == 'R') {
				if (c == 4) valid = false;
				else {
					swap(grid[r][c], grid[r][c + 1]);
					c++;
				}
			}
			/*
			cout << endl;
			cout << "Resulting Grid:" << endl;
			F0R(x, 5) {
				F0R(y, 5) {
					cout << grid[x][y] << " ";
				}
				cout << endl;
			}
			*/
		}
		cout << "Puzzle #" << ++j << ":" << endl;
		if (valid) {
			F0R(i, 5) {
				F0R(j, 5) {
					cout << grid[i][j];
					if (j != 4) cout << " ";
				}
				cout << endl;
			}
		} else {
			cout << "This puzzle has no final configuration." << endl;
		}
		getchar();
	}
	return 0;
}
