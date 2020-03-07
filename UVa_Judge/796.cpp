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

ll dfs_num[10000];
ll dfs_lo[10000];
ll cnt;
ll color[10000];
ll parent[10000];
vector<pair<int, int>> bridges;

ofstream fout("output.out");

void dfs(int u, const vector<vector<int>>& AdjList) {
  color[u] = 1;
  dfs_num[u] = dfs_lo[u] = cnt++;

  F0R(i, AdjList[u].size()) {
    int v = AdjList[u][i];
    if (color[v] == 0) {
      // unvisited.
      parent[v] = u;
      dfs(v, AdjList);

      if (dfs_lo[v] > dfs_num[u]) {
        // (u, v) is a bridge.
        bridges.pb(mp(MIN(u, v), MAX(u, v)));
      }
      dfs_lo[u] = MIN(dfs_lo[u], dfs_lo[v]);
    } else if (color[v] == 1 && parent[u] != v) {
      // this is a backedge.
      dfs_lo[u] = min(dfs_lo[u], dfs_num[v]);
    }
  }
  color[u] = 2;
}

ll N;
int main(void) {
  while (cin >> N) {
    memset(dfs_num, 0, sizeof(dfs_num));
    memset(dfs_lo, 0, sizeof(dfs_lo));
    bridges.clear();
    memset(color, 0, sizeof(color));
    cnt = 0;
    getchar();
    vector<vector<int>> AdjList(N+1);
    F0R(i, N) {
      string line;
      getline(cin, line);
      istringstream iss(line);
      ll src, m;
      char dummy;
      iss >> src;
      iss >> dummy;
      iss >> m;
      iss >> dummy;
      F0R(i, m) {
        ll to;
        iss >> to;
        AdjList[src].pb(to);
        AdjList[to].pb(src);
      }

    }

    F0R(i, N) {
      if (color[i] == 0) {
        dfs(i, AdjList);
      }
    }

      cout << bridges.size() << " critical links" << endl;
      sort(bridges.begin(), bridges.end()); // pair<int, int>'s comparison function sorts by first component.
      for (auto p : bridges) {
        cout << p.f << " - " << p.s << endl;
      }
    cout << endl;
  }

  return 0;
}

