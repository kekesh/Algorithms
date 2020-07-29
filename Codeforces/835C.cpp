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


ll N, M, C, Q;
ll A[101][101][11];
ll orig[101][101];
bool exists[101][101];

map<int, map<int, int>> m;
map<pair<int, int>, int> m2;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> N >> Q >> C;
		F0R(i, N) {
				ll x, y, s;
				cin >> x >> y >> s;
				orig[x][y] += s;
				if (m2.find(mp(x, y)) == m2.end()) {
					m2[mp(x, y)] = i;
					m[i][s]++;
				} else {
						m[m2[mp(x, y)]][s]++;
				}
				exists[x][y] = true;
		}


		for (int z = 0; z <= 10; z++) {
				// first we copy everything over.

				F0R(i, 101) {
						F0R(j, 101) {
								if (exists[i][j]) {
										ll val = 0;
										int idx = m2[mp(i, j)];
										for (auto p : m[idx]) {
												int residue = p.f;
												int frequency = p.s;
												val += frequency * ((residue + z) % (C + 1));
										}
										A[i][j][z] = val;
								}
						}
				}

				F0R(i, 101) {
						F0R(j, 101) {
								if (i - 1 >= 0) A[i][j][z] += A[i - 1][j][z];
								if (j - 1 >= 0) A[i][j][z] += A[i][j - 1][z];
								if (i - 1 >= 0 && j - 1 >= 0) A[i][j][z] -= A[i - 1][j - 1][z];
						}
				}
		}

		F0R(i, Q) {
				ll t;
				cin >> t;
				t = t % (C + 1);

				ll x1, y1, x2, y2;
				cin >> x1 >> y1 >> x2 >> y2;

				ll res = A[x2][y2][t];
				if (x1 - 1 >= 0) res -= A[x1 - 1][y2][t];
				if (y1 - 1 >= 0) res -= A[x2][y1 - 1][t];
				if (x1 - 1 >= 0 && y1 - 1 >= 0) res += A[x1 - 1][y1 - 1][t];
				cout << res << endl;
		}
}
