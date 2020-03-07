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

char grid[10][10];
ll dfsnum[10][10];
ll mask;
bool escape;
int diff;

void dfs(int r, int c, int R, int C, int color) {
	if (r < 0 || c < 0 || r >= R || c >= C) {
		mask = color;
		escape = true;
		return;
	}
	if (dfsnum[r][c] != 0) {
		mask = dfsnum[r][c];
		diff = color - mask;
		return;
	}

	dfsnum[r][c] = color++;
	if (grid[r][c] == 'N') dfs(r - 1, c, R, C, color);
	else if (grid[r][c] == 'E') dfs(r, c + 1, R, C, color);
	else if (grid[r][c] == 'S') dfs(r + 1, c, R, C, color);
	else if (grid[r][c] == 'W') dfs(r, c - 1, R, C, color);
}

int main() {
	ll R, C, r, c;

	while (cin >> R >> C >> c) {
		if (R == 0 && C == 0 && c == 0) break;
		c--;
		F0R(i, R) {
			F0R(j, C) {
				cin >> grid[i][j];
			}
		}
		escape = false;
		memset(dfsnum, 0, sizeof(dfsnum));
		dfs(0, c, R, C, 1);
		if (escape) {
		       cout << mask - 1 << " step(s) to exit" << endl;
		} else {
		       cout << mask  - 1 << " step(s) before a loop of " << diff << " step(s)" << endl;
		}
	}

	return 0;
}
