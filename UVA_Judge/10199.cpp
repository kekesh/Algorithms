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

const int MOD = 1000000007;
const ll INF = 1e18;
const int INFTY = 2147483643;
const ld PI = 4 * atan((ld)1);

struct pair_hash
{
template <class T1, class T2>
std::size_t operator() (const std::pair<T1, T2> &pair) const
{
return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
}
};


unordered_map<string, int> f;
unordered_map<int, string> finv; // inverse

ll dfs_num[100], dfs_lo[100], color[100], parent[100];
ll root, rc, cnt;
bool art[100];

void dfs(int u, const vector<vector<int>>& AdjList) {
  dfs_lo[u] = dfs_num[u] = cnt++;
  color[u] = 1;
  F0R(i, AdjList[u].size()) {
    int v = AdjList[u][i];

    if (color[v] == 0) {
      // (u, v) is a tree edge.

      if (u == root) rc++;

      parent[v] = u;
      dfs(v, AdjList);

      if (dfs_lo[v] >= dfs_num[u]) {
        // vertex u is an articulation point.
        art[u] = true;
      }
      dfs_lo[u] = MIN(dfs_lo[u], dfs_lo[v]);
    } else if (color[v] == 1 && parent[u] != v) {
      /* (u, v) is a back edge in the DFS tree. */
      dfs_lo[u] = MIN(dfs_lo[u], dfs_num[v]);
    }
  }
  color[u] = 2;
}
ll z = 1;

int main(void) {
  ll N;
  bool fst = true;
  while (cin >> N) {
    if (N == 0) break;
    if (!fst) cout << endl;
    memset(art, false, sizeof(art));
    memset(dfs_num, 0, sizeof(dfs_num));
    memset(dfs_lo, 0, sizeof(dfs_lo));
    memset(parent, 0, sizeof(parent));
    memset(color, 0, sizeof(color));
    cnt = 0;
    f.clear();
    finv.clear();
    fst = false;
    int idx = 0;
    F0R(i, N) {
      string city;
      cin >> city;
      f[city] = idx;
      finv[idx++] = city;
    }
    vector<vector<int>> AdjList(N + 1);
    ll M;
    cin >> M;
    F0R(i, M) {
      string from, to;
      cin >> from >> to;
      AdjList[f[from]].pb(f[to]);
      AdjList[f[to]].pb(f[from]);
    }

    // we can have more than one connected component
    F0R(i, N) {
      if (color[i] == 0) {
        root = i;
        rc = 0;
        dfs(i, AdjList);
        art[root] = (rc > 1);
      }
    }
    vector<string> ans;
    F0R(i, N) {
      if (art[i]) ans.pb(finv[i]);
    }
    ll sz = ans.size();
    sort(ans.begin(), ans.end());
    cout << "City map #" << z++ << ": " << sz << " camera(s) found" << endl;

    F0R(i, sz) {
      cout << ans[i] << endl;
    }

  }
  return 0;
}

