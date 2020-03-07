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
const int INFTY = 2147483643;

// Start of code.
ll R, C;
bool banned[20000];

ofstream fout("output.out");

inline int idx(int r, int c, int orientation) {
	return (r*4*C + 4*c + orientation);
}

void printPath(const vector<ll>& parent, int c, int src) {

	if (c == src) {
		cout << c;
		return;
	}
	printPath(parent, parent[c], src);
	cout << " " << c;
}


int main() {

	while (cin >> R >> C) {
		memset(banned, false, sizeof(banned));
		if (R == 0 && C == 0) break;
		R++; C++;

		vector<vi> AdjList(R*C*4);
//		cout << "Size: " << R*C*4;
		F0R(i, R) {
			F0R(j, C) {
				F0R(k, 4) {
					int xd = idx(i,j,k);
					if (xd >= R*C*4) {
						cout << "i = " << i << " j = " << j << " and k = " << k << endl;
						assert(false);
					}
					if (k == 0) {
						// N
						FOR(z, 1, 4) if (i >= z) AdjList[idx(i,j,k)].pb(idx(i-z,j,k));
					} else if (k == 1) {
						// E?
						FOR(z, 1, 4) if (j < C-z) AdjList[idx(i,j,k)].pb(idx(i,j+z,k));
					} else if (k == 2) {
						// S
						FOR(z, 1, 4) if (i < R-z) AdjList[idx(i,j,k)].pb(idx(i+z,j,k));
					} else if (k == 3) {
						// W?
						FOR(z, 1, 4) if (j >= z) AdjList[idx(i,j,k)].pb(idx(i,j-z,k));
					}
					AdjList[idx(i,j,k)].pb(idx(i,j,((k-1)%4 + 4)%4)); // positive modulo
					AdjList[idx(i,j,k)].pb(idx(i,j,(k+1)%4));
				}
			}
		}
		FOR(i, 1, R) {
			FOR(j, 1, C) {
				bool isbad;
				cin >> isbad;
				if (isbad) {
					F0R(z, 4) banned[idx(i,j,z)] = true;
					F0R(z, 4) banned[idx(i-1,j,z)] = true;
					F0R(z, 4) banned[idx(i,j-1,z)] = true;
					F0R(z, 4) banned[idx(i-1,j-1,z)] = true;
				}
			}
		}

		F0R(j, C) {
			F0R(z, 4) banned[idx(0, j, z)] = true;
		}

		F0R(i, R) {
			F0R(z, 4) banned[idx(i, 0, z)] = true;
		}


		// ban[i][j] means u can't go to idx(0, 0, z), idx(0, 1, z), idx(1, 0, z), idx(0, 1, z).
		ll R0, C0, Rf, Cf;
	       	string ori;
		cin >> R0 >> C0 >> Rf >> Cf >> ori;
		int src = -1;
		if (ori == "north") {
			src = idx(R0, C0, 0);
		} else if (ori == "east") {
			src = idx(R0, C0, 1);
		} else if (ori == "south") {
			src = idx(R0, C0, 2);
		} else if (ori == "west") {
			src = idx(R0, C0, 3);
		}
		cout << "Source is " << src << endl;

		queue<ll> q;
		q.push(src);
		vector<ll> d(R*C*4, INFTY);
		vector<ll> p(R*C*4, INFTY);
		d[src] = 0;
		p[src] = src;
		while (!q.empty()) {
			ll u = q.front(); q.pop();
			F0R(i, AdjList[u].size()) {
				ll v = AdjList[u][i];
				if (d[v] == INFTY && !banned[v]) {
					// check if the jump is allowed.
					if (v - u == 8 && banned[u+4]) continue;
					else if (v - u == 12 && (banned[u+4] || banned[u+8])) continue;
					else if (v - u == -8 && banned[u-4]) continue;
					else if (v-u == -12 && (banned[u-4] || banned[u-8])) continue;
					else if (v-u == 8*C && banned[u+4*C]) continue; // going down two rows
					else if (v-u == 12*C && (banned[u+4*C] || banned[u+8*C])) continue;
					else if (v-u == -8*C && banned[u-4*C]) continue;
					else if (v-u == -12*C && (banned[u-4*C] || banned[u-8*C])) continue;

					// it's ok
					d[v] = d[u] + 1;
					p[v] = u;
					q.push(v);
				}
			}
		}

		ll ans = INFTY;
		ll zvalue = -1;
		F0R(z, 4) {
			if (d[idx(Rf, Cf, z)] < ans) {
				ans = MIN(ans, d[idx(Rf, Cf, z)]);
				zvalue = z;
			}
		}
		if (ans == INFTY || banned[src]) ans = -1;


		fout << ans << endl;
		cout << "Answer: " << ans << endl;
//		cout << "Here's the path: " << endl;
//		printPath(p, idx(Rf, Cf, zvalue), src);
	}
}
