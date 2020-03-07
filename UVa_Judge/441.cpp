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

// Start of code.


int main() {
	ll k;
	bool fst = true;
	while (cin >> k, k != 0) {
		if (!fst) cout << endl;
		fst = false;
		vi A(k);
		F0R(i, k) {
			cin >> A[i];
		}

		FOR(i1, 0, k) {
			FOR(i2, i1 + 1, k) {
				FOR(i3, i2 + 1, k) {
					FOR(i4, i3 + 1, k) {
						FOR(i5, i4 + 1, k) {
							FOR(i6, i5 + 1, k) {
								cout << A[i1] << " " << A[i2] << " " << A[i3] << " " << A[i4] << " " << A[i5] << " " << A[i6] << endl;
	}
						}
					}
				}
			}
		}
	}

	return 0;
}
