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
ll N;
char grid[51][51];

void reverse(char mat[51]) {
	int i = 0;
	int j = N - 1;
	while (i < j) {
		swap(mat[i], mat[j]);
		i++;
		j--;
	}
}


void rotate() {
	F0R(i, N) {
		FOR(j, i + 1, N) {
			swap(grid[i][j], grid[j][i]);
		}
		reverse(grid[i]);
	}
}

int main() {
	while (cin >> N, N != 0) {
		F0R(i, N) {
			F0R(j, N) {
				grid[i][j] = '0';
			}
		}
		int player = 0;
		int winner = -1;
		int turn = 0;
		int endturn = -1;
		unordered_set<string> banned;
		string line;
		getchar();
		F0R(z, 2*N) {
			getline(cin, line);
			istringstream iss(line);
			turn++;
			ll r, c;
			char state;
			iss >> r >> c >> state;
			if (state == '+') {
				grid[r - 1][c - 1] = '1';
			} else if (state == '-') {
				grid[r - 1][c - 1] = '0';
			}
			/* check validity. */
			string s = "";
			F0R(i, N) {
				F0R(j, N) {
					s += grid[i][j];
				}
			}
			if (banned.find(s) != banned.end() && winner == -1 && endturn == -1) {
				// banned
				endturn = turn;
				if (player == 0) winner = 1;
				else if (player == 1) winner = 0;
			} else {
			}
			F0R(i, 4) {
				banned.insert(s);
				rotate();
				s = "";
				F0R(i, N) {
					F0R(j, N) {
						s += grid[i][j];
					}
				}
			}
			player = (player + 1) % 2;
		}
		if (winner == -1) {
			cout << "Draw" << endl;
		} else {
			cout << "Player " << winner + 1 << " wins on move " << endturn << endl;
		}

	}

	return 0;
}
