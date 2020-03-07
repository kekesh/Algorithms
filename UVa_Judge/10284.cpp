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

string board[8][8];

void rook(int r, int c) {

	int startr = r + 1;
	int startc = c;
	while (startr < 8 && (board[startr][startc] == "-" || board[startr][startc] == "*")) {
		board[startr++][startc] = "*";
	}
	startr = r - 1;
	while (startr >= 0 && (board[startr][startc] == "-" || board[startr][startc] == "*")) {
		board[startr--][startc] = "*";
	}
	startr = r;
	startc = c + 1;

	while (startc < 8 && (board[startr][startc] == "-" || board[startr][startc] == "*")) {
		board[startr][startc++] = "*";
	}
	startc = c - 1;
	while (startc >= 0 && (board[startr][startc] == "-" || board[startr][startc] == "*")) {
		board[startr][startc--] = "*";
	}
}

void bishop(int r, int c) {

	int startr = r + 1;
	int startc = c + 1;

	while (startr < 8 && startc < 8 && (board[startr][startc] == "-" || board[startr][startc] == "*")) {
		board[startr++][startc++] = "*";
	}

	startr = r - 1;
	startc = c - 1;

	while (startr >= 0 && startc >= 0 && (board[startr][startc] == "-" || board[startr][startc] == "*")) {
		board[startr--][startc--] = "*";
	}

	startr = r - 1;
	startc = c + 1;

	while (startr >= 0 && startc < 8 && (board[startr][startc] == "-" || board[startr][startc] == "*")) {
		board[startr--][startc++] = "*";
	}

	startr = r + 1;
	startc = c - 1;

	while (startr < 8 && startc >= 0 && (board[startr][startc] == "-" || board[startr][startc] == "*")) {
		board[startr++][startc--] = "*";
	}
}

void queen(int r, int c) {
	bishop(r, c);
	rook(r, c);
}

void process(int r, int c) {
	if (r >= 0 && r < 8 && c >= 0 && c < 8 && (board[r][c] == "-" || board[r][c] == "*")) board[r][c] = "*";
}

void knight(int r, int c) {
	// knight attacks 8 spots
	// [r-2][c+1], [r-2][c-1], [r-1][c+2], [r-1][c-2]
	// [r+2][c+1], [r+2][c-1], [r+1][c+2], [r+1][c-2]
	process(r-2,c+1);
	process(r-2,c-1);
	process(r-1,c+2);
	process(r-1,c-2);
	process(r+2,c+1);
	process(r+2,c-1);
	process(r+1,c+2);
	process(r+1,c-2);
}

void pawn(int r, int c, char color) {
	// white goes towards decreasing row
	// attacks [r-1][c-1] and [r-1][c+1]
	if (color == 'W') {
		process(r-1, c-1);
		process(r-1,c+1);
	} else if (color == 'B') {
	// black goes towards increasing row.
	// attacks [r+1][c-1] and [r+1][c+1]
		process(r+1,c-1);
		process(r+1,c+1);
	}
}

void king(int r, int c) {
	process(r+1, c-1);
	process(r+1,c);
	process(r+1,c+1);
	process(r,c-1);
	process(r,c+1);
	process(r-1, c-1);
	process(r-1,c);
	process(r-1,c+1);
}

int main() {
	string line;
	while (getline(cin, line)) {
		istringstream ss(line);

		int curr_row = 0;
		int curr_col = 0;
		char nxt;
		while (ss >> nxt) {
			if (nxt == '/') {
				curr_col = 0;
				curr_row++;
				continue;
			} else {
				if (isdigit(nxt)) {
					F0R(j, nxt-'0') {
						board[curr_row][curr_col++] = "-";
					}
				} else {
					board[curr_row][curr_col++] = nxt;
				}
			}
		}


		F0R(i, 8) {
			F0R(j, 8) {
				if (board[i][j] == "b" || board[i][j] == "B") bishop(i, j);
				if (board[i][j] == "r" || board[i][j] == "R") rook(i, j);
				if (board[i][j] == "q" || board[i][j] == "Q") queen(i, j);
				if (board[i][j] == "p") pawn(i, j, 'B');
				if (board[i][j] == "P") pawn(i, j, 'W');
				if (board[i][j] == "N" || board[i][j] == "n") knight(i, j);
				if (board[i][j] == "K" || board[i][j] == "k") king(i, j);
			}
		}
		ll cnt = 0;
		F0R(i, 8) {
			F0R(j, 8) {
				cnt += (board[i][j] == "-") ? 1 : 0;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
