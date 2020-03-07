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

const string choices[] = {"Illegal state", "Illegal move", "Move not allowed", "Continue", "Stop"};
char board[8][8];

void process(int r, int c) {
	if (r >= 0 && r < 8 && c >= 0 && c < 8) {
		if (board[r][c] == '.') board[r][c] = '*';
	}
}

void king(int r, int c) {
	process(r - 1, c);
	process(r, c - 1);
	process(r, c + 1);
	process(r + 1, c);
}

void rook(int r, int c) {
	int rp = r - 1;
        int cp = c;

	while (rp >= 0 && board[rp][cp] == '.') {
		board[rp][cp] = '*';
		rp--;
	}
	rp = r + 1;
	while (rp < 8 && board[rp][cp] == '.') {
		board[rp][cp] = '*';
		rp++;
	}
	rp = r;
	cp++;
	while (cp < 8 && board[rp][cp] == '.') {
		board[rp][cp] = '*';
		cp++;
	}
	cp = c - 1;
	while (cp >= 0 && board[rp][cp] == '.') {
		board[rp][cp] = '*';
		cp--;
	}
}

/*
 * Pieces may not move diagonally. Oops.
 * void bishop(int r, int c) {
	int rp = r - 1;
	int cp = c - 1;
	while (rp >= 0 && cp >= 0 && board[rp][cp] == '.') {
		board[rp][cp] = '*';
		rp--;
		cp--;
	}

	rp = r + 1;
	cp = c + 1;
	while (rp < 8 && cp < 8 && board[rp][cp] == '.') {
		board[rp][cp] = '*';
		rp++;
		cp++;
	}
	rp = r + 1;
	cp = c - 1;
	while (rp < 8 && cp >= 0 && board[rp][cp] == '.') {
		board[rp][cp] = '*';
		rp++;
		cp--;
	}

	rp = r - 1;
	cp = c + 1;
	while (rp >= 0 && cp < 8 && board[rp][cp] == '.') {
		board[rp][cp] = '*';
		rp--;
		cp++;
	}
}*/

void queen(int r, int c) {
	rook(r, c);
//	bishop(r, c);
}


void reset(int k, int q) {
	F0R(i, 8) F0R(j, 8) board[i][j] = '.';
	board[k/8][k%8] = 'K';
	board[q/8][q%8] = 'Q';
}
int main() {
	ll k, q, qp;
	while (cin >> k >> q >> qp) {
		if (k == q) {
			cout << "Illegal state" << endl;
			continue;
		}

		 reset(k, q);
		 queen(q/8,q%8);
		 bool legalmove = (board[qp/8][qp%8] == '*' || board[qp/8][qp%8] == 'Q') && (qp != q);

		 if (!legalmove) {
			 cout << "Illegal move" << endl;
			 continue;
		 }

		 reset(k, q);
		 king(k/8, k%8);

		 bool allowed = !(board[qp/8][qp%8] == '*');


		 if (!allowed) {
			 cout << "Move not allowed" << endl;
			 continue;
		 }

		 q = qp;

		 reset(k, q);
		 queen(q/8,q%8);

		 unordered_set<int> queenspots;

		 F0R(i, 8) {
			 F0R(j, 8) {
				 if (board[i][j] == '*') queenspots.insert(i*8 + j);
			 }
		 }

		 reset(k, q);
		 king(k/8, k%8);

		 bool cancontinue = false;
		 F0R(i, 8) {
			 F0R(j, 8) {
				 if (board[i][j] == '*' && queenspots.count(i*8 + j) == 0) {
					 cancontinue = true;
					 break;
				 }
			 }
		 }

		 if (cancontinue) cout << "Continue" << endl;
		 else cout << "Stop" << endl;
	}
	return 0;
}
