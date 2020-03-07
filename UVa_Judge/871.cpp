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

ll T;
ll R, C;
char grid[25][25];
bool visited[25][25];

const vector<int> dr = {-1, 0, 1, -1, 1, -1, 0, 1};
const vector<int> dc = {1, 1, 1, 0, 0, -1, -1, -1};


int ff(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C || visited[r][c]) return 0;
	if (grid[r][c] != '1') return 0;
	visited[r][c] = true;
	int ans = 1;
	F0R(i, 8) ans += ff(r + dr[i], c + dc[i]);
	return ans;
}

int main() {
	cin >> T;
	getchar(); getchar();
	while (T--) {
		string line;
		int ptr = 0;
		while (getline(cin, line)) {
			if (line.empty()) break;
			C = line.size();
			F0R(i, line.size()) {
				grid[ptr][i] = line[i];
			}
			ptr++;
		}
		R = ptr;
		ll ans = 0;
		F0R(i, R) {
			F0R(j, C) {
				if (!visited[i][j] && grid[i][j] == '1') {
					int tmp = ff(i, j);
					ans = MAX(ans, tmp);
				}
			}
		}
		memset(visited, false, sizeof(visited));
		cout << ans << endl;
		if (T) cout << endl;
	}
	return 0;
}
