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

const int MOD = 1000000007;  // 998244353
const ll INF = 1e18;
const int MX = 35005;
const ld PI = 4 * atan((ld)1);

ll R, C;
char grid[60][60];

int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1};

void floodfill2(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C) return;
	if (grid[r][c] != 'X') return;
	grid[r][c] = '*';
	F0R(i, 4) floodfill2(r + dy[i], c + dx[i]);
}

void floodfill1(int r, int c, int& cnt) {
	if (r < 0 || c < 0 || r >= R || c >= C) return;

	if (grid[r][c] == 'X') {
		floodfill2(r, c);
		cnt++;
	}
	if (grid[r][c] != '*') return;
	grid[r][c] = '.';
	F0R(i, 4) floodfill1(r + dy[i], c + dx[i], cnt);
}




int main() {
	int j = 0;
	while (cin >> C >> R, R + C) {
		F0R(i, R) cin >> grid[i];
		vector<int> ans;

		F0R (i, R) {
			F0R(j, C) {
				if (grid[i][j] == '*') {
					int num = 0;
					floodfill1(i, j, num);
					ans.pb(num);
				}
			}
		}
		sort(ans.begin(), ans.end());
		cout << "Throw " << ++j << endl;
		F0R(i, ans.size()) {
			cout << ans[i];
			if (i != ans.size() - 1) cout << " ";
		}
		cout << "\n" << endl;
	}


}
