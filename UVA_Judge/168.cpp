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
vector<string> split(string s, char delim) {
	vector<string> ret;
	istringstream iss(s);
	string temp;
	while (getline(iss, temp, delim)) {
		ret.pb(temp);
	}
	return ret;
}

int main() {

	while (1) {
		string adjacencies = "";
		char nxt;
		while (cin >> nxt, nxt != '.') {
			if (nxt == '#') exit(0);
			adjacencies += nxt;
		}
		vector<string> adj = split(adjacencies, ';');

		vector<vector<ll>> AdjList(27);
		for (string& s : adj) {
			vector<string> neighbors = split(s, ':');
			string first = neighbors[0];
			char v = first[0];
			if (neighbors.size() > 1) {
				for (char &c : neighbors[1]) {
					AdjList[v - 'A'].pb(c - 'A');
//					cout << "(" << v << "," << c << ")" << endl;
				}
			}
		}
		char minotaur, warrior;
		ll k;
		cin >> minotaur >> warrior >> k;

		int mini = minotaur - 'A';
		int warr = warrior - 'A';
		queue<int> q;
		vector<ll> d(27, INFTY);
		q.push(mini);
		int ctr = 0;
		bool banned[27];
		memset(banned, false, sizeof(banned));
		while (!q.empty()) {
			int u = q.front(); q.pop();
			ctr++;
			F0R(i, AdjList[u].size()) {
				int v = AdjList[u][i];
				if (v != warr && !banned[v]) {
					q.push(v);
					break;
				}
			}
			warr = u;
			if (ctr % k == 0 && !q.empty()) {
				banned[u] = true;
				cout << (char) (u + 'A') << " ";
			}
		}
		cout << "/" << (char) (warr + 'A') << endl;
	}

	return 0;
}
