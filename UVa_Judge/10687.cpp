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

// true if lhs < rhs

ll x, y;
bool visited[1001];
int cnt;

bool cmp(pair<pair<int, int>, int> lhs, pair<pair<int, int>, int> rhs) {
	pair<int, int> p1 = lhs.f;
	pair<int, int> p2 = rhs.f;
	long double d1 = (p1.f - x) * (p1.f - x) + (p1.s - y) * (p1.s - y);
	long double d2 = (p2.f - x) * (p2.f - x) + (p2.s - y) * (p2.s - y);

	if (abs(d1 - d2) < 0.0005) {
		if (p1.f != p2.f) {
			return p1.f < p2.f;
		}
		// take minimum y
		return p1.s < p2.s;
	}
	return d1 < d2;
}

void dfs(int src, const vector<vector<int>>& AdjList) {
	visited[src] = true;
	cnt++;
	F0R(i, AdjList[src].size()) {
		int v = AdjList[src][i];
		if (!visited[v]) {
			dfs(v, AdjList);
		}
	}
}

int main() {
	ll N;

	while (cin >> N, N != 0) {
		vector<vector<int>> AdjList(N);
		vector<pair<pair<int, int>, int>> pts;

		F0R(i, N) {
			ll fst, snd;
			cin >> fst >> snd;
			pts.pb(mp(mp(fst, snd), i));
		}

		F0R(i, N) {
			pair<int, int> sorter = pts[i].f;
			x = sorter.f;
			y = sorter.s;
			vector<pair<pair<int, int>, int>> cpy = pts;
			sort(cpy.begin(), cpy.end(), cmp);

			if (cpy.size() > 1) {
				AdjList[i].pb(cpy[1].s);
			}
			if (cpy.size() > 2) {
				AdjList[i].pb(cpy[2].s);
			}
		}
		cnt = 0;
		memset(visited, false, sizeof(visited));
		dfs(0, AdjList);
		if (cnt == N) cout << "All stations are reachable." << endl;
		else cout << "There are stations that are unreachable." << endl;
	}
	return 0;
}
