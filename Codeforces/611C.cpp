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
typedef vector<int> vi;

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
const ld PI = 4 * atan((ld)1);

ll R, C, q;

char grid[501][501];
int ways[501][501][2];
int prefix[501][501][2];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> R >> C;

		F0R(i, R) { 
				F0R(j, C) {
						cin >> grid[i][j];
				}
		}

		ways[0][0][0] = ways[0][0][1] = 0;


		for (int i = 1; i < C; i++) {
				if (grid[0][i - 1] == '.' && grid[0][i] == '.') {
						ways[0][i][0] = 1;
				}
		}

		for (int i = 1; i < R; i++) {
				if (grid[i - 1][0] == '.' && grid[i][0] == '.') {
						ways[i][0][1] = 1;
				}
		}
		// [0] = horizontal
		// [1] = vertical
		for (int i = 1; i < R; i++) {
				for (int j = 1; j < C; j++) {
						if (grid[i][j - 1] == '.' && grid[i][j] == '.') {
								ways[i][j][0] = 1;
						}

						if (grid[i][j] == '.' && grid[i - 1][j] == '.') {
								ways[i][j][1] = 1;
						}
				}
		}

		prefix[0][0][0] = prefix[0][0][1] = 0;

		for (int i = 1; i < R; i++) {
				prefix[i][0][1] = prefix[i - 1][0][1] + ways[i][0][1];
		}

		for (int i = 1; i < C; i++) {
				prefix[0][i][0] = prefix[0][i - 1][0] + ways[0][i][0];
		}

		for (int i = 1; i < R; i++) {
				for (int j = 1; j < C; j++) {
						prefix[i][j][0] = ways[i][j][0] + prefix[i - 1][j][0] + prefix[i][j - 1][0] - prefix[i - 1][j - 1][0]; 
						prefix[i][j][1] = ways[i][j][1] + prefix[i - 1][j][1] + prefix[i][j - 1][1] - prefix[i - 1][j - 1][1];
				}
		}


		cin >> q;

		F0R(i, q) {
				ll r1, c1, r2, c2;
				cin >> r1 >> c1 >> r2 >> c2;
				r1--;
				c1--;
				r2--;
				c2--;

				c1 = c1 + 1;
				long long ans = prefix[r2][c2][0];
				if (c1 - 1 >= 0) ans -= prefix[r2][c1 - 1][0];
				if (r1 - 1 >= 0) ans -= prefix[r1 - 1][c2][0];
				if (r1 - 1 >= 0 && c1 - 1 >= 0) ans += prefix[r1 - 1][c1 - 1][0];
				c1 = c1 - 1;

				r1 = r1 + 1;
				ans += prefix[r2][c2][1];
				if (c1 - 1 >= 0) ans -= prefix[r2][c1 - 1][1];
				if (r1 - 1 >= 0) ans -= prefix[r1 - 1][c2][1];
				if (r1 - 1 >= 0 && c1 - 1 >= 0) ans += prefix[r1 - 1][c1 - 1][1];
				r1 = r1 - 1;
				cout << ans << endl;
		}


}
