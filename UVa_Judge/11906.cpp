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

vector<vector<int>> AdjList(10007);
bool banned[10007];
bool visited[10007];
ll R, C, M, N, W;
int ctr[10007];


ofstream fout("output.out");
void process(int r, int c) {
	unordered_set<ll> seen;
	if (r < 0 || c < 0 || r >= R || c >= C) return;
	visited[r * C + c] = true;
	if (r - M >= 0 && c + N < C && !banned[(r - M) * C + (c + N)]) {
		int rp = r - M;
		int cp = c + N;
		AdjList[r * C + c].pb(rp * C + cp);
		seen.insert(rp * C + cp);
		if (!visited[rp * C + cp]) process(rp, cp);
	}

	if (r - M >= 0 && c - N >= 0 && !banned[(r - M) * C + (c - N)]) {
		int rp = r - M;
		int cp = c - N;
		if (seen.find(rp * C + cp) == seen.end()) {
			AdjList[r * C + c].pb(rp * C + cp);
			seen.insert(rp * C + cp);
		}
		if (!visited[rp * C + cp]) process(rp, cp);
	}
	if (r - N >= 0 && c + M < C && !banned[(r - N) * C + (c + M)]) {
		int rp = r - N;
		int cp = c + M;
		if (seen.find(rp * C + cp) == seen.end()) {
			AdjList[r * C + c].pb(rp * C + cp);
			seen.insert(rp * C + cp);
		}
		if (!visited[rp * C + cp]) process(rp, cp);
	}
	if (r - N >= 0 && c - M >= 0 && !banned[(r - N) * C + (c - M)]) {
		int rp = r - N;
		int cp = c - M;
		if (seen.find(rp * C + cp) == seen.end()) {
			AdjList[r * C + c].pb(rp * C + cp);
			seen.insert(rp * C + cp);
		}

		if (!visited[rp * C + cp]) process(rp, cp);
	}
	/* south side. */
	if (r + M < R && c + N < C && !banned[(r + M) * C + (c + N)]) {
		int rp = r + M;
		int cp = c + N;
		if (seen.find(rp * C + cp) == seen.end()) {
			AdjList[r * C + c].pb(rp * C + cp);
			seen.insert(rp * C + cp);
		}

		if (!visited[rp * C + cp]) process(rp, cp);
		//AdjList[rp * C + cp].pb(C * r + c);
//		AdjList[rp * C + cp].pb(C * r + c);
	}
	if (r + M < R && c - N >= 0 && !banned[(r + M) * C + (c - N)]) {
		int rp = r + M;
		int cp = c - N;
		if (seen.find(rp * C + cp) == seen.end()) {
			AdjList[r * C + c].pb(rp * C + cp);
			seen.insert(rp * C + cp);
		}

		if (!visited[rp * C + cp]) process(rp, cp);
		//AdjList[rp * C + cp].pb(C * r + c);
//		AdjList[rp * C + cp].pb(C * r + c);
	}
	if (r + N < R && c + M < C && !banned[(r + N) * C + (c + M)]) {
		int rp = r + N;
		int cp = c + M;
		if (seen.find(rp * C + cp) == seen.end()) {
			AdjList[r * C + c].pb(rp * C + cp);
			seen.insert(rp * C + cp);
		}

		if (!visited[rp * C + cp]) process(rp, cp);
		//AdjList[rp * C + cp].pb(C * r + c);
//		AdjList[rp * C + cp].pb(C * r + c);
	}
	if (r + N < R && c - M >= 0 && !banned[(r + N) * C + (c - M)]) {
		int rp = r + N;
		int cp = c - M;
		if (seen.find(rp * C + cp) == seen.end()) {
			AdjList[r * C + c].pb(rp * C + cp);
			seen.insert(rp * C + cp);
		}

		if (!visited[rp * C + cp]) process(rp, cp);
		//AdjList[rp * C + cp].pb(C * r + c);
//		AdjList[rp * C + cp].pb(C * r + c);
	}
}

int f;


int main() {
	ll T;
	cin >> T;
	while (T--) {
		memset(banned, false, sizeof(banned));
		memset(ctr, 0, sizeof(ctr));
		memset(visited, false, sizeof(visited));
		cin >> R >> C >> M >> N >> W;

		F0R(i, W) {
			ll r, c;
			cin >> r >> c;
			banned[C*r + c] = true;
		}


		/* construct adjlist. */
		process(0, 0);
		F0R(i, R) {
			F0R(j, C) {
				F0R(z, AdjList[C*i + j].size()) {
					ctr[AdjList[C * i + j][z]]++;
				}
			}
		}
		int evens, odds;
		evens = odds = 0;
		F0R(i, R*C) {
			if (i == 0 || ctr[i] != 0) {
				if (ctr[i] & 1) odds++;
				else evens++;
			}
		}
		cout << "Case " << ++f << ": " << evens << " " << odds << endl;
//		if (T) fout << endl;
		F0R(i, R*C) AdjList[i].clear();
	}
	return 0;

}
