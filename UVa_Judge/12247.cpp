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

bool taken[53];

int main() {
	vector<int> a(3);
	vector<int> b(3);

	while (cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1]) {
		memset(taken, false, sizeof(taken));
		if (!a[0] && !a[1] && !a[2] && !b[0] && !b[1]) break;
		taken[a[0]] = taken[a[1]] = taken[a[2]] = taken[b[0]] = taken[b[1]] = true;
		sort(a.begin(), a.end());
		b[2] = -1;

		if (b[0] > a[2] && b[1] > a[2]) {
			FOR(i, 1, 53) {
				if (!taken[i]) {
					b[2] = i;
					break;
				}
			}
		} else if (b[0] > a[1] && b[1] > a[1]) {
			for (int i = a[1] + 1; i <= 52; i++) {
				if (!taken[i]) {
					b[2] = i;
					break;
				}
			}
		} else if (b[1] > a[2] || b[0] > a[2]) {
			for (int i = a[2] + 1; i <= 52; i++) {
				if (!taken[i]) {
					b[2] = i;
					break;
				}
			}
		}

		cout << b[2] << endl;



	}

	return 0;
}
