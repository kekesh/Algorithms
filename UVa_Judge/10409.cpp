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
	int num = 1;

	// Unfolded dice:
	/*     2
	 *   4 6 3
	 *     5
	 *     1
	 */

	int moves;
	while (cin >> moves, moves != 0) {

		int a[] = {2, 4, 6, 3, 5, 1};
		F0R(i, moves) {

			string ind;
			cin >> ind;
			if (ind == "north") {
				int t = a[0];
				int tm = a[2];
				int bm = a[4];
				int b = a[5];
				a[0] = b;
				a[2] = t;
				a[4] = tm;
				a[5] = bm;
			} else if (ind == "south") {
				int t = a[0];
				int tm = a[2];
				int bm = a[4];
				int b = a[5];
				a[0] = tm;
				a[2] = bm;
				a[4] = b;
				a[5] = t;
			} else if (ind == "west") {
				int t = a[2];
				int l = a[1];
				int r = a[3];
				int b = a[5];
				a[1] = t;
				a[2] = r;
				a[3] = b;
				a[5] = l;
			} else if (ind == "east") {
				int t = a[2];
				int l = a[1];
				int r = a[3];
				int b = a[5];
				a[1] = b;
				a[2] = l;
				a[3] = t;
				a[5] = r;
			}

		}
		cout << a[5] << endl;
	}

	return 0;
}
