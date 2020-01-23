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

ll R, C;
char grid[50][50];
bool visited[50][50];
int ans;
const vector<int> dr = {1, 0, 0, -1};
const vector<int> dc = {0, -1, 1, 0};


void floodfill(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return;
       	if (grid[r][c] == '#' || grid[r][c] == 'T') return;
	if (grid[r][c] == 'G') ans++;
	visited[r][c] = true;

	F0R(i, 4) {
		if (grid[r + dr[i]][c + dc[i]] == 'T') return;
	}

	F0R(i, 4) {
		if (!visited[r + dr[i]][c + dc[i]]) floodfill(r + dr[i], c + dc[i]);
	}

}


int main() {
	while (cin >> C >> R) {
		ll r, c;
		memset(visited, false, sizeof(visited));
		F0R(i, R) {
			F0R(j, C) {
				cin >> grid[i][j];
				if (grid[i][j] == 'P') {
					r = i;
					c = j;
				}
			}
		}
		ans = 0;
		floodfill(r, c);
		cout << ans << endl;
	}
	return 0;
}
