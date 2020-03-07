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
ll R, C;
int grid[201][201];
bool visited[201][201];

void mark(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C) return;
	cout << "Here when r = " << r << " and c = " << c << endl;
	visited[r][c] = true;
	if (r - 1 >= 0 && grid[r][c] == grid[r - 1][c] && !visited[r - 1][c]) mark(r - 1, c);
	if (r + 1 < R && grid[r + 1][c] == grid[r][c] && !visited[r + 1][c]) mark(r + 1, c);
	if (c - 1 >= 0 && grid[r][c - 1] == grid[r][c] && !visited[r][c - 1]) mark(r, c - 1);
	if (c + 1 < C && grid[r][c + 1] == grid[r][c] && !visited[r][c + 1]) mark(r, c + 1);
	grid[r][c] = INFTY;
}

void shiftdown() {

	F0R(j, C) {
		F0R(i, R) {
			if (i - 1 >= 0 && grid[i][j] == INFTY && grid[i - 1][j] != INFTY)  {
				swap(grid[i][j], grid[i - 1][j]);
				i-= 2;
			}
		}
	}
}

void shiftleft() {
	bool empty[201];
	F0R(j, C) {
		bool isempty = true;
		F0R(i, R) {
			if (grid[i][j] != INFTY) {
				isempty = false;
				break;
			}
		}
		empty[j] = isempty;
	}

	F0R(i, C - 1) {
		if (empty[i] && !empty[i + 1]) {
			F0R(j, R) {
				swap(grid[j][i], grid[j][i + 1]);
			}
			empty[i] = false;
			empty[i + 1] = true;
		}
	}
}



int main() {

	while (cin >> R >> C, R + C) {

		F0R(i, R) {
			F0R(j, C) {
				cin >> grid[i][j];
			}
		}
		ll x, y;

		F0R(i,R) {
		       F0R(j, C) {
		       		cout << grid[i][j] << " ";
		       }
	       		cout << endl;
		}
		while (cin >> x >> y, x + y) {
			mark(R - x, y - 1);
			cout << "Marking (" << R - x << "," << y - 1 << ")" << endl;
			shiftdown();
			shiftleft();

			F0R(i,R) {
			       F0R(j, C) {
			       		cout << grid[i][j] << " ";
			       }
	       			cout << endl;
			}
		}

		bool won = true;
		F0R(i, R) {
			F0R(j, C) {
				if (grid[i][j] != INFTY) won = false;
			}
		}

		if (won) cout << "Game Won." << endl;
		else {
			F0R(i, R) {
				F0R(j, C) {
					if (grid[i][j] == INFTY) cout << "  ";
					else cout << grid[i][j] << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}
