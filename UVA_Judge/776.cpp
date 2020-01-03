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
string grid[501][501];
bool visited[501][501];
ll R, C;

int dr[] = {1, 0, 0, -1, 1, 1, -1, -1};
int dc[] = {0, -1, 1, 0, -1, 1, -1, 1};


void floodfill(int r, int c, string c1, string c2) {
	if (r < 0 || c < 0 || r >= R || c >= C || visited[r][c]) return;
	if (grid[r][c] != c1) return;
	visited[r][c] = true;
	grid[r][c] = c2;
	F0R(i, 8) {
		if (!visited[r + dr[i]][c + dc[i]]) {
			floodfill(r + dr[i], c + dc[i], c1, c2);
		}
	}
}

inline int calc(int y) {
	return (y < 10) ? 1 : (y < 100) ? 2 : (y < 1000) ? 3 : 4;
}


int main() {

	string line;
	int i = 0;
	int color = 1;
	while (getline(cin, line)) {
		if (line.empty() || line == "%") {
			R = i;
			F0R(a, R) {
				F0R(b, C) {
					if (!visited[a][b]) {
						floodfill(a, b, grid[a][b], to_string(color++));
					}
				}
			}
			int manip[1024];
			F0R(jj, C) {
				int D = 0;
				F0R(ji, R) {
					D = MAX(D, calc(stoi(grid[ji][jj])));
				}
				manip[jj] = D;
			}

			F0R(a, R) {
				F0R(b, C) {
					if (b) cout << " ";
					cout << setw(manip[b]) << grid[a][b];
				}
				cout << endl;
			}
			cout << "%" << endl;

			R = C = i = 0;
			color = 1;
			memset(visited, false, sizeof(visited));
		} else {
			istringstream ss(line);
			string str = "";
			while (!ss.eof()) {
			string temp;
				ss >> temp;
				str += temp;
			}
			F0R(j, str.size()) {
				grid[i][j] = string(1, str[j]);
			}
			C = str.size();
			i++;
		}
	}

			R = i;
			F0R(a, R) {
				F0R(b, C) {
					if (!visited[a][b]) {
						floodfill(a, b, grid[a][b], to_string(color++));
					}
				}
			}
			int manip[1024];
			F0R(jj, C) {
				int D = 0;
				F0R(ji, R) {
					D = MAX(D, calc(stoi(grid[ji][jj])));
				}
				manip[jj] = D;
			}

			F0R(a, R) {
				F0R(b, C) {
					if (b) cout << " ";
					cout << setw(manip[b]) << grid[a][b];
				}
				cout << endl;
			}
			cout << "%" << endl;

			R = C = i = 0;
			color = 1;
			memset(visited, false, sizeof(visited));

	return 0;
}
