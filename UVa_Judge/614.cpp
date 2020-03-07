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

bool visited[150];
int parent[150];
int num;
bool found;
int j;

void dfs(const vector<vector<int>>& AdjList, int src, int dest) {
	visited[src] = true;
	if (src == dest) {
		found = true;
		return; /* Reached destination. */
	}
	F0R(i, AdjList[src].size()) {
		if (!visited[AdjList[src][i]] && !found) {
			parent[AdjList[src][i]] = src;
			dfs(AdjList, AdjList[src][i], dest);
		}
	}
}

void print_path(int u, int src, unordered_map<int, int>& path) {

	if (u == src) {
	       path[src] = num++;
	       return;
	}

	print_path(parent[u], src, path);
	path[u] = num++;
}

int main() {

	//freopen("output.out","w",stdout);
	ll R, C, ri, ci, rf, cf;
	bool fst = true;
	while (cin >> R >> C >> ri >> ci >> rf >> cf) {
		if (R == 0 && C == 0 && ri == 0 && ci == 0 && rf == 0 && cf == 0) break;
		//if (!fst) fout << "\n";
		fst = false;

		printf("Maze %d\n\n", ++j);

		rf--;
		cf--;
		ri--;
		ci--;
		vector<vector<int>> AdjList(150);
		memset(visited, false, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		num = 0;
		found = false;
		int masks[13][13];
		// (i, j) -> [i * C + j]
		F0R(i, R) {
			F0R(j, C) {
				int idx = i * C + j;
				// order: W N E S
				if (j > 0) {
					int idxp = i * C + (j - 1);
					AdjList[idx].pb(idxp);
				}

				if (i > 0) {
					int idxp = (i - 1) * C + j;
					AdjList[idx].pb(idxp);
				}

				if (j != C - 1) {
					int idxp = i * C + (j + 1);
					AdjList[idx].pb(idxp);
				}

				if (i != R - 1) {
					int idxp = (i + 1) * C + j;
					AdjList[idx].pb(idxp);
				}
			}
		}

		F0R(i, R*C) {
			int mask;
			cin >> mask;
			masks[i / C][i % C] = mask;
			bool east_wall = (mask & (1 << 0));
			bool south_wall = (mask & (1 << 1));
			if (east_wall) {
//				cout << i << " has an east wall." << endl;
				// There is an east wall. Need to remove east neighbor.
				int to_rem = i + 1;
				F0R(j, AdjList[i].size()) {
					if (AdjList[i][j] == to_rem) {
//						cout << "removed " << to_rem <<  " from " << i << endl;
						AdjList[i].erase(AdjList[i].begin() + j);
					}
				}
				// Remove i from the other one.
				F0R(j, AdjList[to_rem].size()) {
					if (AdjList[to_rem][j] == i) {
//						cout << "removed " << i << " from " << to_rem << endl;
						AdjList[to_rem].erase(AdjList[to_rem].begin() + j);
					}
				}
			}

			if (south_wall) {
				// There is a south wall. need to remove south neighbor.
//				cout << i << " has a south wall." << endl;
				int to_rem = i + C;
//				cout << "to_rem = " << to_rem << endl;
				F0R(j, AdjList[i].size()) {
					if (AdjList[i][j] == to_rem) {
//						cout << "removed " << to_rem <<  " from " << i << endl;
						AdjList[i].erase(AdjList[i].begin() + j);
					}
				}
				F0R(j, AdjList[to_rem].size()) {
					if (AdjList[to_rem][j] == i) {
//						cout << "removed " << i << " from " << to_rem << endl;
						AdjList[to_rem].erase(AdjList[to_rem].begin() + j);
					}
				}
			}
		}

		// adjacency list has been constructed.


		/*F0R(i, R*C) {
			cout << "Cell " << i << " neighbors: ";
			F0R(j, AdjList[i].size()) {
				cout << AdjList[i][j] << " ";
			}
			cout << endl;
		}*/

		int src = ri * C + ci;
		int dest = rf * C + cf;
		parent[src] = src;
		dfs(AdjList, src, dest);

		unordered_map<int, int> path;
		print_path(dest, src, path);


		//string ans = "";
		printf("+");
		F0R(i, C) {
			printf("---+");
		}
		puts("");

		F0R(i, R) {
			printf("|");
			F0R(j, C) {
				int c = i*C + j;
				if (found && path.find(c) != path.end()) {
					// part of the path.
					int num = path[c];
					num++;
					if (num >= 100) printf("%d", num);
					else if (num >= 10) printf(" %d", num);
					else printf("  %d", num);
				} else if (visited[c]) {
					printf("???");
				} else {
					printf("   ");
				}
				int m = masks[i][j];
				if (j == C - 1 || (m & (1 << 0))) printf("|");
				else printf(" ");
			}
//			printf("\n");
			puts("");
			// intermediate.
			printf("+");
			F0R(j, C) {
				int m = masks[i][j];
				if (i == R - 1 || (m & (1 << 1))) printf("---");
				else printf("   ");
				printf("+");
			}
//			ans += "\n";
			puts("");
		}

		puts(""); puts("");
	}
	return 0;
}
