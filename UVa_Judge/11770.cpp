#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <cstdio>
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

const int MOD = 1000000007;
const ll INF = 1e18;
const int INFTY = 2147483643;
const ld PI = 4 * atan((ld)1);

ll T, N, M, k;
ll scc[10000], dfs_low[10000], dfs_num[10000], indeg[10000], dfs_count, scc_count;
bool visited[10000];
stack<int> s;

void tarjanSCC(int u, const vector<vi>& AdjList) {
  visited[u] = true;
  dfs_low[u] = dfs_num[u] = ++dfs_count;
  s.push(u);

  F0R(i, AdjList[u].size()) {
    int v = AdjList[u][i];
    if (dfs_num[v] == 0) {
      tarjanSCC(v, AdjList);
    }
    if (visited[v]) {
      dfs_low[u] = MIN(dfs_low[u], dfs_low[v]);
    }
  }

  if (dfs_num[u] == dfs_low[u]) {
    int v;
    do {
      v = s.top(); s.pop(); visited[v] = false;
      scc[v] = scc_count;
    } while (u != v);
    scc_count++;
  }
}


int main(void) {
  cin >> T;
  while (T-- ){
    cin >> N >> M;
    assert(N >= 1 && M >= 0);
    vector<vi> AdjList(N);
    memset(dfs_low, 0, sizeof(dfs_low));
    memset(dfs_num, 0, sizeof(dfs_num));
    dfs_count = scc_count = 0;
    memset(visited, false, sizeof(visited));
    s.empty();
    memset(indeg, 0, sizeof(indeg));
    assert(s.size() == 0);

    F0R(i, M) {
      ll from, to;
      cin >> from >> to;
      AdjList[from-1].pb(to-1);
    }

    F0R(i, N) {
      if (dfs_num[i] == 0) {
        tarjanSCC(i, AdjList);
      }
    }

    F0R(u, N) {
      for (auto v : AdjList[u]) {
        if (scc[u] != scc[v]) {
          // (u, v) leads into scc[v]
          indeg[scc[v]]++;
        }
      }
    }
    ll ans = 0;
    F0R(i, scc_count) {
      if (indeg[i] == 0) {
        ans++;
      }
    }

    cout << "Case " << ++k << ": " << ans << endl;


    /* count the number of SCCs with indegree 0. */

  }
}
