/* Incomplete. */
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
	ll N, M, P, Q;
	vector<vector<ll>> AdjList(200001);
	vector<ll> G(2001);
	cin >> N >> M >> P;
	F0R(i, M) {
		ll from, to;
		cin >> from >> to;
		AdjList[from].pb(to);
		AdjList[to].pb(from);
	}
	cin >> Q;
	F0R(i, Q) {
		cin >> G[i];
	}

	F0R(i, Q) {
		ll Ko = G[i];
//		cout << "K = " << K << endl;
		int ans = 0;
		F0R(j, N) {
			ll K = Ko;
			// run bfs from each vertex
			int src = j;
			queue<int> q;
			vector<ll> d(N, INFTY);
			q.push(src);
			d[src] = 0;
//			cout << "Running BFS from " << src << endl;
			int count = -1;
			int prev = -1;
			pair<int, int> start_state;
			if (AdjList[q.front()].size() > 0) {
				start_state = {q.front(), AdjList[q.front()][0]};
//				cout << "Start State: (" << start_state.f << "," << start_state.s << ")" << endl;
			}
			int u;
			int cycleLength = 0;
			bool first = true;
			while (!q.empty()) {
				u = q.front(); q.pop();
//				cout << "Now at " << u << endl;
				count++;
				if (count == K) {
//					cout << "Made " << K << " moves. Breaking." << endl;
					break;
				}
				if (AdjList[u].size() == 0) break;
				int v = AdjList[u][0];
				if (prev == v && AdjList[u].size() > 1) {
					v = AdjList[u][1];
				}
				cycleLength++;
				pair<int, int> state = {u, v};
				if (!first && state.first == start_state.first && state.second == start_state.second) {
//					cout << "Cycling with length " << cycleLength << endl;
					cycleLength--;
					K %= cycleLength;
					count = 0;
//					cout << "Num moves is now " << K << endl;
					if (count == K) break;
				}
				q.push(v);
				prev = u;
				first = false;
			}



			if (count == K && u == P) {
//				cout << "Success!" << endl;
				ans++;
			}
		}
//		cout << ans;
		cout << "Answer: " << ans << endl;
		if (i != Q - 1) cout << " ";
	}

	return 0;
}
