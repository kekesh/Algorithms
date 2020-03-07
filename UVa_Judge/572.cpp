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
bool visited[105][105];
char grid[105][105];
vector<int> dx = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> dy = {1, 1, 1, 0, 0, -1, -1, -1};
ll m, n;

void floodfill(int r, int c, char c1, char c2) {
	if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c]) return;
	if (grid[r][c] != c1) return;
	grid[r][c] = c2;
	visited[r][c] = true;

	F0R(i, 8) {
		floodfill(r + dx[i], c + dy[i], c1, c2);
	}
}

int main() {

	while (cin >> m >> n, m + n) {
		memset(visited, false, sizeof(visited));
		F0R(i, m) {
			cin >> grid[i];
		}
		ll numCC = 0;
		F0R(i, m) {
			F0R(j, n) {
				if (!visited[i][j] && grid[i][j] == '@') {
					numCC++;
					floodfill(i, j, '@', '*');
				}
			}
		}
		cout << numCC << endl;
	}

	return 0;
}
