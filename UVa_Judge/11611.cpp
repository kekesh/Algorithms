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
	ll L;
	while (cin >> L, L != 0) {
		ll last_seen = 0;
		int flag = -1;
		ll min_dist = INFTY;
		F0R(i, L) {
			char x;
			cin >> x;

			if ((x == 'R' || x == 'D') && (flag == -1)) {
				if (x == 'R') flag = 0;
				else if (x == 'D') flag = 1;
				last_seen = i;
			} else if (x == 'R' && flag == 1) {
				min_dist = MIN(min_dist, (i - last_seen));
				last_seen = i;
				flag = 0;
			} else if (x == 'D' && flag == 0) {
				min_dist = MIN(min_dist, (i - last_seen));
				last_seen = i;
				flag = 1;
			} else if (x == 'Z') {
				min_dist = 0;
			} else if (x == 'R' && flag == 0) {
				last_seen = i;
			} else if (x == 'D' && flag == 1) {
				last_seen = i;
			}

		}
		cout << min_dist << endl;
	}

	return 0;
}
