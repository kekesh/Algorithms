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
char grid[50][100];
bool visited[50][100];
ll R, C;

int dr[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int asterickr, asterickc;

ofstream fout("output.out");
bool floodfill(int r, int c, char c1, char c2) {
	bool ans = false;
	if (r < 0 || c < 0 || r >= R || c >= C) return ans;

	if (grid[r][c] == '*') {
		ans = true;
		asterickr = r;
		asterickc = c;
	}

	if (grid[r][c] != c1 && grid[r][c] != '*') return ans;

	visited[r][c] = true;
	grid[r][c] = c2;

	F0R(i, 8) {
		if (!visited[r + dr[i]][c + dc[i]]) {
			ans |= floodfill(r + dr[i], c + dc[i], c1, c2);
		}
	}

	return ans;
}

int main() {
	ll T;
	cin >> T;
	getchar();
	while (T--) {
		memset(visited, false, sizeof(visited));
		string line;
		int i = 0;
		while (getline(cin, line)) {
			if (line.size() >= 1 && line[0] == '_') break;
			C = MAX(C, line.size());
			F0R(j, line.size()) grid[i][j] = line[j];
			i++;
		}
		R = i;
		F0R(i, R) {
			F0R(j, C) {
				if (grid[i][j] == ' ' && !visited[i][j]) {
					fout << "Floodfilling from (" << i << "," << j << ")" << endl;
					bool res = floodfill(i, j, ' ', '.');
					if (res) {
						fout << "Found asterick." << endl;
					} else {
						floodfill(i, j, '.', ' '); // backtrack.
					}
					fout << "Printing grid." << endl;

					F0R(x, R) {
						F0R(y, C) {
							fout << grid[x][y];
						}
						fout << endl;
					}

				}
			}
		}
	}
	return 0;
}
