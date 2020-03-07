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

char board[8][8];
bool whiteunderattack;
bool blackunderattack;

void process(int r, int c, char color) {
	if (r >= 0 && r < 8 && c >= 0 && c < 8) {
		if (board[r][c] == 'K' && color == 'B') {
			whiteunderattack = true;
		}
		else if (board[r][c] == 'k' && color == 'W')  {
			blackunderattack = true;
		}
		else if (board[r][c] == '.' || board[r][c] == '*') {
			board[r][c] = '*';
		}
	}
}

void knight(int r, int c, char color) {
	// knight attacks [r-1][c-2], [r-1][c+2], [r-2][c-1], [r-2][c+1]
	// knight attacks [r+1][c-2], [r+1][c+2], [r+2][c-1], [r+2][c+1]
	process(r-1,c-2, color);
	process(r-1,c+2, color);
	process(r-2,c-1, color);
	process(r-2,c+1, color);
	process(r+1,c-2, color);
	process(r+1,c+2, color);
	process(r+2,c-1, color);
	process(r+2,c+1, color);
}

void bishop(int r, int c, char color) {
	int rp = r - 1;
	int cp = c - 1;

	// top left
	while (rp >= 0 && cp >= 0 && (board[rp][cp] == '.' || board[rp][cp] == '*' || board[rp][cp] == 'k' || board[rp][cp]     == 'K')) {
		process(rp, cp, color);

		if (board[rp][cp] == 'k' || board[rp][cp] == 'K') break;
		rp--;
		cp--;
	}
	rp = r + 1;
	cp = c + 1;
	// bottom right
	while (rp < 8 && cp < 8 && (board[rp][cp] == '.' || board[rp][cp] == '*' || board[rp][cp] == 'k' || board[rp][cp]     == 'K')) {
		process(rp, cp, color);
		if (board[rp][cp] == 'k' || board[rp][cp] == 'K') break;
		rp++;
		cp++;
	}
	rp = r - 1;
	cp = c + 1;
	// top right
	while (rp >= 0 && cp < 8 && (board[rp][cp] == '.' || board[rp][cp] == '*' || board[rp][cp] == 'k' || board[rp][cp]     == 'K')) {
		process(rp, cp, color);

		if (board[rp][cp] == 'k' || board[rp][cp] == 'K') break;
		rp--;
		cp++;
	}
	// bottom left
	rp = r + 1;
	cp = c - 1;
	while (rp < 8 && cp >= 0 && (board[rp][cp] == '.' || board[rp][cp] == '*' || board[rp][cp] == 'k' || board[rp][cp]     == 'K')) {
		process(rp, cp,color);

		if (board[rp][cp] == 'k' || board[rp][cp] == 'K') break;
		rp++;
		cp--;
	}
}


void rook(int r, int c, char color) {
	// vertical to bottom
	int rp = r + 1;
	int cp = c;
	while (rp < 8 && (board[rp][cp] == '.' || board[rp][cp] == '*' || board[rp][cp] == 'k' || board[rp][cp]     == 'K')) {
		process(rp,cp,color);

		if (board[rp][cp] == 'k' || board[rp][cp] == 'K') break;
		rp++;
	}
	rp = r - 1;
	while (rp >= 0 && (board[rp][cp] == '.' || board[rp][cp] == '*' || board[rp][cp] == 'k' || board[rp][cp] == 'K')) {
		process(rp,cp,color);

		if (board[rp][cp] == 'k' || board[rp][cp] == 'K') break;
		rp--;
	}
	rp = r;
	cp = c + 1;
	while (cp < 8 && (board[rp][cp] == '.' || board[rp][cp] == '*' || board[rp][cp] == 'k' || board[rp][cp]     == 'K')) {
		process(rp, cp, color);

		if (board[rp][cp] == 'k' || board[rp][cp] == 'K') break;
		cp++;
	}
	cp = c - 1;
	while (cp >= 0 && (board[rp][cp] == '.' || board[rp][cp] == '*' || board[rp][cp] == 'k' || board[rp][cp]     == 'K')) {
		process(rp, cp, color);

		if (board[rp][cp] == 'k' || board[rp][cp] == 'K') break;
		cp--;
	}
}

void queen(int r, int c, char color) {
	rook(r,c, color);
	bishop(r,c, color);
}

void king(int r, int c, char color) {
	process(r-1,c-1,color);
	process(r-1,c,color);
	process(r-1,c+1,color);
	process(r,c-1,color);
	process(r,c+1,color);
	process(r+1,c-1,color);
	process(r+1,c,color);
	process(r+1,c+1,color);
}

void pawn(int r, int c, char color) {
	if (color == 'W') {
		process(r-1, c-1, color);
		process(r-1, c+1, color);
	} else if (color == 'B') {
		process(r+1, c-1, color);
		process(r+1, c+1, color);
	}
}


int main() {
	int game = 0;
	while (!cin.eof()) {

		blackunderattack = whiteunderattack = false;
		bool alldots = true;
		F0R(i, 8) {
			F0R(j, 8) {
				cin >> board[i][j];
				if (board[i][j] != '.') alldots = false;
			}
		}
		if (alldots) {
			exit(0);
		}

		F0R(i, 8) {
			F0R(j, 8) {
				if (board[i][j] == 'p') pawn(i,j,'B');
				else if (board[i][j] == 'P') pawn(i,j,'W');
				else if (board[i][j] == 'N') knight(i, j, 'W');
				else if (board[i][j] == 'n') knight(i, j, 'B');
				else if (board[i][j] == 'b') bishop(i, j, 'B');
				else if (board[i][j] == 'B') bishop(i, j, 'W');
				else if (board[i][j] == 'r') rook(i, j, 'B');
				else if (board[i][j] == 'R') rook(i, j, 'W');
				else if (board[i][j] == 'q') queen(i, j, 'B');
				else if (board[i][j] == 'Q') queen(i, j, 'W');
				else if (board[i][j] == 'k') king(i, j, 'B');
				else if (board[i][j] == 'K') king(i, j, 'W');
			}
		}

		cout << "Game #" << ++game << ": ";

		string ans = blackunderattack ? "black king is in check." : (whiteunderattack ? "white king is in check." : "no king is in check.");

		cout << ans << endl;
	}

	return 0;
}
