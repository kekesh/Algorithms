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

// Start of code.

bool visited[10][10];
bool exitedblack;
bool exitedwhite;
char grid[10][10];


const vector<int> dr = {1, 0, 0, -1};
const vector<int> dc = {0, -1, 1, 0};


int ff(int r, int c) {
	if (r < 0 || c < 0 || r >= 9 || c >= 9) return 0;
	if (grid[r][c] == 'X') {
		exitedblack = true;
		return 0;
	} else if (grid[r][c] == 'O') {
		exitedwhite = true;
		return 0;
	}
	int ans = 1;
	visited[r][c] = true;
	F0R(i, 4) {
		if (!visited[r + dr[i]][c + dc[i]]) ans += ff(r + dr[i], c + dc[i]);
	}
	return ans;
}


int main() {
	ll T;
	cin >> T;
	while (T--) {
		int b = 0, w = 0;
		memset(visited, false, sizeof(visited));
		F0R(i, 9) {
			F0R(j, 9) {
				cin >> grid[i][j];
				if (grid[i][j] == 'X') b++;
				else if (grid[i][j] == 'O') w++;
			}
		}
		F0R(i, 9) {
			F0R(j, 9) {
				if (!visited[i][j] && grid[i][j] == '.') {
					exitedblack = exitedwhite = false;
					int sz = ff(i, j);
					if (exitedblack && !exitedwhite) b += sz;
					else if (exitedwhite && !exitedblack) w += sz;
				}
			}
		}

		cout << "Black " << b << " White " << w << endl;
	}
	return 0;
}
