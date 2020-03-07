#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <sstream>
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

bool visited[50];

void dfs(int src, const vector<vector<int>>& AdjList) {
	visited[src] = true;
	for (int n : AdjList[src]) {
		if (!visited[n]) dfs(n, AdjList);
	}
}

int main() {
	ll T;
	cin >> T;
	getchar();
	while (T--) {
		vector<vector<int>> AdjList(50);
		memset(visited, false, sizeof(visited));
		char maxi;
		cin >> maxi;
		getchar();
		ll N = (maxi - 'A' + 1);
		string input;
		while(getline(cin, input)) {
			if (input.empty()) break;
			char from, to;
			istringstream iss(input);
			iss >> from >> to;
			AdjList[from - 'A'].pb(to - 'A');
			AdjList[to - 'A'].pb(from - 'A');
		}
		int numCC = 0;

		F0R(i, N) {
			if (!visited[i]) {
				dfs(i, AdjList);
				numCC++;
			}
		}
		cout << numCC << endl;
		if (T) cout << "\n";

	}
	return 0;
}
