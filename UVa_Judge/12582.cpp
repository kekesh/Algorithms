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

int j;
int main() {
	ll T, j = 0;
	cin >> T;
	while (T--) {
		string st;
		cin >> st;

		stack<char> s;
		int vertexdeg[200];
		bool seen[200];
		memset(vertexdeg, 0, sizeof(vertexdeg));
		memset(seen, false, sizeof(seen));
		int ctr = 0;
		F0R(i, st.size()) {
			seen[st[i]] = true;
			if (i == 0) {
				s.push(st[i]);
			} else {
				if (st[i] == s.top()) {
					s.pop();
					continue;
				} else {
					vertexdeg[s.top()]++;
					vertexdeg[st[i]]++;
					s.push(st[i]);
				}
			}
		}
		cout << "Case " << ++j << endl;
		FOR(i, 65, 92) {
			if (seen[i]) {
				cout << (char) i << " = " << vertexdeg[i] << endl;
			}
		}



	}
	return 0;
}
