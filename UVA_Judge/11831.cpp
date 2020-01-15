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

char grid[101][101];
const char dirs[4] = {'N', 'L', 'S', 'O'};

int main() {


	ll N, M, S;
	while (cin >> N >> M >> S, N + M + S) {
		ll row, col;
		int dir;
		F0R(i, N) {
			F0R(j, M) {
				cin >> grid[i][j];
				if (grid[i][j] != '.' && grid[i][j] != '*' && grid[i][j] != '#') {
					// robot
					row = i;
					col = j;
					if (grid[i][j] == 'N') dir = 0;
					else if (grid[i][j] == 'L') dir = 1;
					else if (grid[i][j] == 'S') dir = 2;
					else if (grid[i][j] == 'O') dir = 3;
				}
			}
		}

		string queries;
		ll cnt = 0;
		cin >> queries;
		for (char &c : queries) {
			if (c == 'D') dir = (dir + 1) % 4;
			else if (c == 'E') dir = ((dir - 1) % 4 + 4) % 4;
			else if (c == 'F') {
				if (dir == 0 && row > 0 && grid[row - 1][col] != '#') {
					if (grid[row - 1][col] == '*') cnt++;
					grid[row - 1][col] = '.';
					swap(grid[row - 1][col], grid[row][col]);
					row--;
				} else if (dir == 1 && col < M - 1 && grid[row][col + 1] != '#') {
					if (grid[row][col + 1] == '*') cnt++;
					grid[row][col + 1] = '.';
					swap(grid[row][col + 1], grid[row][col]);
					col++;
				} else if (dir == 2 && row < N - 1 && grid[row + 1][col] != '#') {
					if (grid[row + 1][col] == '*') cnt++;
					grid[row + 1][col] = '.';
					swap(grid[row + 1][col], grid[row][col]);
					row++;
				} else if (dir == 3 && col > 0 && grid[row][col - 1] != '#') {
					if (grid[row][col - 1] == '*') cnt++;
					grid[row][col - 1] = '.';
					swap(grid[row][col - 1], grid[row][col]);
					col--;
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}
