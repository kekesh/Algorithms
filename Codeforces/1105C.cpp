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
const ld PI = 4 * atan((ld)1);

ll N, L, R, copyL, copyR;
ll res[3];
ll ways[200005][3];

int main() {
		cin >> N >> L >> R;
		copyL = L;
		copyR = R;
		if (L % 3 != 0) {
				L--;

				while (L % 3 != 0) {
						res[L % 3]--;
						L--;
				}
				res[L % 3]--;
		}

		if (R % 3 != 0) {
				R++;
				while (R % 3 != 0) {
						res[R % 3]--;
						R++;
				}
				res[R % 3]--;
		}



		res[0] += (R - L)/3 + 1;
		res[1] += (R - L)/3;
		res[2] += (R - L)/3;
		ways[0][0] = 1;

		for (int i = 1; i <= N; i++) {
				ways[i][0] = (((ways[i - 1][1] * res[2]) % MOD) + (ways[i - 1][0] * res[0]) % MOD + (ways[i - 1][2] * res[1]) % MOD) % MOD;
				ways[i][1] = (((ways[i - 1][0] * res[1]) % MOD) + (ways[i - 1][1] * res[0]) % MOD + (ways[i - 1][2] * res[2]) % MOD) % MOD;
				ways[i][2] = (((ways[i - 1][0] * res[2]) % MOD) + (ways[i - 1][1] * res[1]) % MOD + (ways[i - 1][2] * res[0]) % MOD) % MOD;

		}

		cout << ways[N][0] << endl;

}

