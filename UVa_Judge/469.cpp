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
vector<vector<char>> grid(100, vector<char>(100));
ll N, M;

vector<int> dr = {1, 1, 1, 0, 0, -1, -1, -1};
vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

int floodfill(int r, int c, char c1, char c2) {
	if (r < 0 || c < 0 || r >= N || c >= M || grid[r][c] != c1) return 0;

	int ans = 1;
	grid[r][c] = c2;
	F0R(i, 8) {
		ans += floodfill(r + dr[i], c + dc[i], c1, c2);
	}
	return ans;
}

int main() {

	ll T;
	cin >> T;
	getchar();
	getchar();
	while (T--) {
		string line;
		grid.empty();
		N = M = 0;
		while (getline(cin, line)) {
			if (line[0] != 'L' && line[0] != 'W') break;
			M = line.size();
			istringstream iss(line);
			F0R(i, M) {
				iss >> grid[N][i];
			}
			N++;
		}
		char color = 'a';
		do {
			if (line.empty()) break;
			ll r, c;
			istringstream iss(line);
			iss >> r >> c;
			cout << floodfill(r - 1, c - 1, grid[r - 1][c - 1], color++) << endl;
		} while (getline(cin, line));

		if (T) cout << "\n";
	}
	return 0;
}
