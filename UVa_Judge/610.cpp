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

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

/* Start of code. */

ll N, M;

ll dfs_num[1001];
ll dfs_lo[1001];
ll num;
ll parent[1001];
ll color[1001];

// ofstream fout("output.out");

void dfs(ll u, const vector<vector<int>>& AdjList) {
  dfs_num[u] = dfs_lo[u] = num++;
  color[u] = 1;
  // cout << "DFS from " << u << endl;
  F0R(i, AdjList[u].size()) {
    int v = AdjList[u][i];

    if (color[v] != 2 && parent[u] != v) {
        cout << u+1 << " " << v+1 << endl;
    }
    if (color[v] == 0) {
      parent[v] = u;

      dfs(v, AdjList);

      if (dfs_lo[v] > dfs_num[u]) {
        // (u, v) is a bridge.
        cout << v+1 << " " << u+1 << endl;
      }

      dfs_lo[u] = MIN(dfs_lo[u], dfs_lo[v]);
    } else if (v != parent[u]) {
      // back edge
      dfs_lo[u] = min(dfs_lo[u], dfs_num[v]);
    }

  }
  color[u] = 2;
}


ll j=1;
int main(void) {
  while (cin >> N >> M) {
    if (N == 0 && M == 0) break;
    vector<vector<int>> AdjList(N + 1);
    memset(color, 0, sizeof(color));
    memset(parent, 0, sizeof(parent));
    memset(dfs_num, 0, sizeof(dfs_num));
    memset(dfs_lo, 0, sizeof(dfs_lo));
    num = 0;

    F0R(i, M) {
      ll from, to;
      cin >> from >> to;
      from--;
      to--;
      AdjList[from].pb(to);
      AdjList[to].pb(from);
    }
    cout << j++ << "\n" << endl;
    dfs(0, AdjList);
    cout << "#" << endl;
  }
}

