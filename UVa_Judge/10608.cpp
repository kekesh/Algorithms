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

struct UnionFind {
vector<int> parent;
vector<int> rank;

  // Constructor
  // Rank = order.
UnionFind(int size) {
parent.assign(size, 0);
rank.assign(size, 1);

F0R(i, size) {
parent[i] = i;
}
}

/* Implementation of findSet() with path compression. */
int findSet(int u) {
return (parent[u] == u) ? u : (parent[u] = findSet(parent[u]));
}

bool inSameSet(int u, int v) {
return findSet(u) == findSet(v);
}

  /* Union by rank heuristic. */
void unionSet(int u, int v) {
int x = findSet(u), y = findSet(v);

if (x == y) return;

if (rank[x] > rank[y]) {
parent[y] = x;
      rank[x] += rank[y];
} else {
parent[x] = y;
rank[y] += rank[x];
}
}

};


int main() {

  ll T;
  cin >> T;
  while (T--) {
    ll N, M;
    cin >> N >> M;
    UnionFind uf(N);
    ll maxi = 1;
    F0R(i, M) {
      ll A, B;
      cin >> A >> B;
      uf.unionSet(A - 1, B - 1);
      maxi = MAX(maxi, uf.rank[uf.findSet(A - 1)]);
    }
    cout << maxi << endl;
  }
return 0;
}
