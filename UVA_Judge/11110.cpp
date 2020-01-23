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
const int INFTY = 2147483643;
// Start of code.

int grid[100][100];
bool visited[100][100];
ll N;

const vector<int> dr = {1, 0, 0, -1};
const vector<int> dc = {0, -1, 1, 0};

int floodfill(int r, int c, int c1) {
	if (r < 0 || c < 0 || r >= N || c >= N) return 0;
	if (grid[r][c] != c1) return 0;
	visited[r][c] = true;
	grid[r][c] = INFTY;
	int ans = 1;
	F0R(i, 4) {
		if (!visited[r + dr[i]][c + dc[i]]) {
			ans += floodfill(r + dr[i], c + dc[i], c1);
		}
	}
	return ans;
}

int main() {

	while (cin >> N, N != 0) {
		getchar();
		memset(grid, 0, sizeof(grid));
		memset(visited, false, sizeof(visited));
		ll ctr = 0;
		F0R(i, N - 1) {
			ctr++;
			string line;
			getline(cin, line);
			istringstream iss(line);
			ll r, c;
			while (iss >> r >> c) {
				r--;
				c--;
				grid[r][c] = ctr;
			}
		}

		/* Done making grid. */
		int numCC = 0;
		bool isok = true;
		F0R(i, N) {
			F0R(j, N) {
				if (!visited[i][j]) {
					numCC++;
					int sz = floodfill(i, j, grid[i][j]);
					isok &= (sz == N);
				}
			}
		}
		if (isok == false || numCC != N) cout << "wrong" << endl;
		else cout << "good" << endl;
	}

	return 0;
}
