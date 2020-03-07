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


int main() {
	ll T;
	cin >> T;
	int j = 0;
	while (T--) {

		vector<vector<int>> AdjList(1001);
		unordered_map<int, int> units;
		ll N, M;
		cin >> N >> M;
		F0R(i, N) {
			ll nxt;
			cin >> nxt;
			units[i] = nxt;
		}

		F0R(i, M) {
			ll from, to;
			cin >> from >> to;
			AdjList[from].pb(to);
		}


		queue<int> q;
		int src = 0;
		q.push(src);
		ll gain = 0;
		ll endv = -1;
		while (!q.empty()) {
			int u = q.front();
			gain += units[u];
			q.pop();
			int maxivertex, maxigain;
			maxivertex = maxigain = -1;
			F0R(i, AdjList[u].size()) {
				if (units[AdjList[u][i]] > maxigain) {
					maxivertex = AdjList[u][i];
					maxigain = units[AdjList[u][i]];
				}
			}
			if (maxivertex == -1) {
				endv = u;
				break;
			} else {
				q.push(maxivertex);
			}
		}
		cout << "Case " << ++j << ": " << gain << " " << endv << endl;
	}
	return 0;
}
