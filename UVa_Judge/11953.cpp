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
int z;

char grid[100][100];
bool visited[100][100];
ll N;

void ff(int r, int c, int key) {
	if (r < 0 || c < 0 || r >= N || c >= N) return;
	if (grid[r][c] != 'x' && grid[r][c] != '@') return;
	visited[r][c] = true;
	// 1 means vertical
	if (key == 1 || key == 3) {
		if (!visited[r-1][c]) ff(r - 1, c, 1);
		if (!visited[r+1][c]) ff(r + 1, c, 1);
	}
	if (key == 2 || key == 3) {
		if (!visited[r][c-1]) ff(r, c - 1, 2);
		if (!visited[r][c+1]) ff(r, c + 1, 2);
	}
}



int main() {
	ll T;
	cin >> T;

	while (T--) {
		cin >> N;
		F0R(i, N) {
			F0R(j, N) {
				cin >> grid[i][j];
			}
		}

		int cnt = 0;
		F0R(i, N) {
			F0R(j, N) {
				if (!visited[i][j] && grid[i][j] == 'x') {
					cnt++;
					ff(i, j, 3);
				}
			}
		}

		cout << "Case " << ++z << ": " << cnt << endl;
		memset(visited, false, sizeof(visited));

	}
	return 0;
}
