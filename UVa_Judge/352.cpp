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
vector<vector<char>> grid(26, vector<char>(26));
bool visited[26][26];
ll N;
const vector<int> dr = {1, 1, 1, 0, 0, -1, -1, -1};
const vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

void floodfill(int r, int c) {
	if (r < 0 || c < 0 || r >= N || c >= N || grid[r][c] != '1') return;
	visited[r][c] = true;

	F0R(i, 8) {
		if (!visited[r + dr[i]][c + dc[i]]) {
			floodfill(r + dr[i], c + dc[i]);
		}
	}
}


int main() {
	int j = 0;
	while (cin >> N) {
		grid.empty();
		memset(visited, false, sizeof(visited));
		F0R(i, N) F0R(j, N) cin >> grid[i][j];

		ll num_cc = 0;
		F0R(i, N) {
			F0R(j, N) {
				if (grid[i][j] == '1' && !visited[i][j]) {
					floodfill(i, j);
					num_cc++;
				}
			}
		}
		cout << "Image number " << ++j << " contains " << num_cc << " war eagles." << endl;
	}
	return 0;
}
