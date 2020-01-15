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

vector<vector<ll>> AdjList(50);
bool visited[50];

void dfs(int src, int& size, vector<ll>& team) {
	size++;
	visited[src] = true;
	team.pb(src);
	F0R(i, AdjList[src].size()) {
		if (!visited[AdjList[src][i]]) {
			dfs(AdjList[src][i], size, team);
		}
	}

}

int main() {
	ll N, M;
	cin >> N >> M;
	F0R(i, M) {
		ll from, to;
		cin >> from >> to;
		from--;
		to--;
		AdjList[from].pb(to);
		AdjList[to].pb(from);
	}
	bool isok = true;
	vector<vector<ll>> teams;
	queue<int> ones;
	queue<pair<int, int>> twos;
	int residue = 0;
	F0R(i, N) {
		if (!visited[i]) {
			int size = 0;
			vector<ll> team;
			dfs(i, size, team);
			if (size > 3) {
				isok = false;
				break;
			} else if (size == 3) {
//				cout << "Size was " << size << endl;
				teams.pb(team);
			} else if (size == 2) {
				residue += 2;
				twos.push(make_pair(team[0], team[1]));
//				cout << "Inserted." << endl;
			} else if (size == 1) {
				residue += 1;
				ones.push(team[0]);
			}
		}
	}


	if (isok) {

		while (!twos.empty() && !ones.empty()) {
			pair<int, int> p = twos.front(); twos.pop();
			int nxt = ones.front(); ones.pop();
			teams.pb({p.first, p.second, nxt});
		}

		if (ones.size() % 3 != 0) {
			isok = false;
		}

		while (!ones.empty()) {
			int f, s, t;
			f = ones.front(); ones.pop();
			s = ones.front(); ones.pop();
			t = ones.front(); ones.pop();
			teams.pb({f, s, t});
		}

		if (!twos.empty()) isok = false;
		else if (!ones.empty()) isok = false;
	}

	if (isok) {
		F0R(i, teams.size()) {
			F0R(j, teams[i].size()) {
				cout << teams[i][j] + 1;
				if (j != teams[i].size() - 1) cout << " ";
			}
			cout << endl;
		}
	} else {
		cout << "-1" << endl;
	}


	return 0;
}
