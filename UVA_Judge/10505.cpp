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
//
ll N, T;

int bfs(int src, const vector<vector<int>>& AdjList, vector<ll> & color) {
	queue<int> q;
	q.push(src);
	bool isBipartite = true;
	color[src] = 0;
	int ones = 0, zeroes = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		F0R(i, AdjList[u].size()) {
			int v = AdjList[u][i];
			if (color[v] == INFTY) {
				color[v] = 1 - color[u];
				if (color[v] == 1) ones++;
				else zeroes++;
				q.push(v);
			} else if (color[v] == color[u]) {
				isBipartite = false;
			}
		}
	}
	return isBipartite ? MAX(ones, zeroes) : 0;
}



int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		vector<ll> color(N, INFTY);
		vector<vector<int>> AdjList(N, vector<int>());
		F0R(i, N) {
			ll numenemy;
			cin >> numenemy;
			F0R(j, numenemy) {
				ll nxt;
				cin >> nxt;
				nxt--;
				if (nxt < N && find(AdjList[i].begin(), AdjList[i].end(), nxt) == AdjList[i].end())  {
					AdjList[i].pb(nxt);
				}
				if (nxt < N && find(AdjList[nxt].begin(), AdjList[nxt].end(), i) == AdjList[nxt].end()) {
					AdjList[nxt].pb(i);
				}
			}
		}
		ll sum = 0;
		F0R(i, N) {
			if (color[i] == INFTY) {
				sum += bfs(i, AdjList, color);
			}
		}
		cout << sum << endl;


	}
	return 0;
}
