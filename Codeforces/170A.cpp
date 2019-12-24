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

vector<set<int>> AdjSet(110);
vector<set<int>> languages(110);

bool visited[200];

void dfs(int src) {

	visited[src] = true;

	for (auto neighbor : AdjSet[src]) {
		if (!visited[neighbor]) dfs(neighbor);
	}

}

int main() {
	ll n, m;
	cin >> n >> m;
	int src = -1;
	F0R(i, n) {
		ll ki;
		cin >> ki;
		F0R(j, ki) {
			src = i;
			ll tmp;
			cin >> tmp;
			//cout << "Inserting " << i << " into " << tmp << endl;
			languages[tmp].insert(i);
		}
	}
	/* Construct the graph. */

	FOR(i,1, m+1) {
		//cout << "Printing set " << i << "!" << endl;
		for (auto elem : languages[i]) {
			for (auto elem2 : languages[i]) {
				if (elem != elem2) {
					//cout << elem << " and " << elem2 << " are neighbors." << endl;
					AdjSet[elem].insert(elem2);
					AdjSet[elem2].insert(elem);
				}
			}
		}
	}
	//cout << "Constructed" << endl;

	ll cost = 0;
	if (src == -1) cost = n;
	else {
		dfs(src);

		F0R(i, n) {
			if (!visited[i]) {
				cost++;
				dfs(i);
			}
		}
	}

	cout << cost << endl;

	return 0;
}
