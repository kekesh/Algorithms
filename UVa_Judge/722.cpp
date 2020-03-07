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
ll R, C;
char dy[] = {1, 0, 0, -1};
char dx[] = {0, -1, 1, 0};

int floodfill(int r, int c, char c1, char c2) {
	if (r < 0 || c < 0 || r >= R || c >= C) return 0;
	if (grid[r][c] != c1) return 0;
	grid[r][c] = c2;
	int ans = 1;
	F0R(i, 4) ans += floodfill(r + dy[i], c + dx[i], c1, c2);
	return ans;
}


int main() {
	ll M;
	cin >> M;
	while (M--) {
		int i, j;
		cin >> i >> j;
		string line;
		getchar();
		R = C = 0;
		while (getline(cin, line)) {
			if (line.empty()) break;
			C = line.size();
			F0R(z, C) grid[R][z] = line[z];
			R++;
		}
		cout << floodfill(i - 1, j - 1, grid[i - 1][j - 1], '*') << endl;
		if (M) cout << endl;
	}
	return 0;
}
