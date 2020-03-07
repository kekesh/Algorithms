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
typedef vector<int> vi;

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
const int INFTY = 2147483643;

// Start of code.

bool ok(string s1, string s2) {
	bool isok = true;
	isok &= s1.size() == s2.size();
	int cnt = 0;
	F0R(i, s1.size()) {
		if (s1[i] != s2[i]) cnt++;
	}
	isok &= (cnt == 1);
	return isok;
}


int main() {

	ll T;
	cin >> T;
	bool fst = true;
	while (T--) {
		if (!fst) cout << endl;
		fst = false;
		string nxt;
		unordered_map<string, int> idxmap;
		unordered_map<int, string> invidxmap;
		vector<string> allwords;
		int idx = 0;
		while (cin >> nxt, nxt != "*") {
			idxmap[nxt] = idx;
			invidxmap[idx] = nxt;
			idx++;
			allwords.pb(nxt);
		}
		vector<vi> AdjList(idx);

		F0R(i, allwords.size()) {
			FOR(j, i + 1, allwords.size()) {
				if (ok(allwords[i], allwords[j])) {
					AdjList[i].pb(j); AdjList[j].pb(i);
				}
			}
		}

		// graph constructed
		// bfs from spice
		string line;
		getchar();
		while (getline(cin, line)) {
			if (line.empty()) break;
			istringstream iss(line);
			string from, to;
			iss >> from >> to;
//			cout << "SSSP from " << from << " to " << to << endl;
			int src = idxmap[from];
			int dst = idxmap[to];


			queue<int> q;
			vector<int> d(idx, INFTY);
			d[src] = 0;
			q.push(src);
			bool done = false;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				F0R(i, AdjList[u].size()) {
					int v = AdjList[u][i];
					if (d[v] == INFTY) {
						d[v] = d[u] + 1;
						if (v == dst) done = true;
						q.push(v);
					}
				}
				if (done) break;
			}
			cout << from << " " << to << " " << d[dst] << endl;
		}
	}


	return 0;
}
