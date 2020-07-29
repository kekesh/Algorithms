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


class UnionFind {
		private:
				vector<int> parent;
				vector<int> rank;

		public:

				UnionFind(int N) {
						parent.resize(N, 0);
						rank.resize(N, 0);

						for (int i = 0; i < N; i++) parent[i] = i;
				}

				int findSet(int u) {
						return (parent[u] == u ? u : parent[u] = findSet(parent[u]));
				}

				bool inSameSet(int u, int v) {
						return findSet(u) == findSet(v);
				}

				void unionSet(int u, int v) {
						int x = findSet(u), y = findSet(v);
						if (x != y) {
								if (rank[x] > rank[y]) {
										parent[y] = x;
								} else {
										parent[x] = y;
										if (rank[x] == rank[y]) rank[y]++;
								}
						}
				}
						


};

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll N, M;
		cin >> N >> M;

		vector<pi> edges;
		set<int> s;
		unordered_map<int, int> m;

		F0R(i, M) {
				ll u, v;
				cin >> u >> v;
				edges.pb(mp(u - 1, v - 1));
				s.insert(u - 1);
				s.insert(v - 1);
		}

		int asdf = 0;

		for (auto v : s) {
				m[v] = asdf++;
		}
		int sz = (int) s.size();
		UnionFind uf(sz);
		ll ans = N;
		F0R(i, M) {
				ll u = m[edges[i].f], v = m[edges[i].s];
				if (!uf.inSameSet(u, v)) {
						ans--;
						uf.unionSet(u, v);
				}
		}

		cout << ans << endl;


}
