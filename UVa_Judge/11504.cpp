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


ll N, M, T;
bool visited[100000];
ll dfs_lo[100000], dfs_num[100000], dfs_counter;
stack<int> s;
int scc_count, scc[100000];


void tarjanSCC(int u, const vector<vector<int>>& AdjList) {
  // cout << "DFS from " << u << endl;
  visited[u] = true;
  dfs_lo[u] = dfs_num[u] = ++dfs_counter;
  s.push(u);
  F0R(i, AdjList[u].size()) {
    ll v = AdjList[u][i];
    if (dfs_num[v] == 0) {
      tarjanSCC(v, AdjList);
    }
    if (visited[v]) {
      // stack invariant
      dfs_lo[u] = MIN(dfs_lo[u], dfs_lo[v]);
    }
  }

  if (dfs_lo[u] == dfs_num[u]) {
    int v;
    // cout << "SCC: ";
    do {
      v = s.top(); s.pop(); visited[v] = false;
      scc[v] = scc_count;
      // cout << v << " ";
    } while (u != v);
    scc_count++;
    // cout << endl;
    // let's check if the SCC we just found is closed.

  }
}

    ofstream fout("output.out");

/*
1
4 5
1 2
2 1
2 3
3 4
4 3
*/

int main() {
  cin >> T;
  while (T--) {
    cin >> N >> M;
    vector<vector<int>> AdjList(N);
    scc_count = 0;
    memset(scc, 0, sizeof(scc));
    memset(dfs_lo, 0, sizeof(dfs_lo));
    memset(dfs_num, 0, sizeof(dfs_num));
    memset(visited, false, sizeof(visited));
    s.empty();
    assert(s.size() == 0);
    dfs_counter = 0;

    F0R(i, M) {
      ll from, to;
      cin >> from >> to;
      from--;
      to--;
      // cout << "(" << from << "," << to << ")" << endl;
      AdjList[from].pb(to);
    }

    // cout << "Done constructing graph." << endl;
    F0R(i,N) {
      // cout << "i = " << i << endl;
      if (dfs_num[i] == 0) {
        // cout << "i = " << i << endl;
        tarjanSCC(i, AdjList);
        // cout << "Ans is now " << ans << endl
      }
    }

    /* Done constructing graph. */


    int indeg[100000];
    memset(indeg, 0, sizeof(indeg));
    F0R(u, N) {
      for (auto v : AdjList[u]) {
        if (scc[u] != scc[v]) {
            indeg[scc[v]]++;
          // (u, v) leads out of the SCC, so we get scc[v] for free.
        }
      }
    }

    int ans = 0;
    F0R(i, scc_count) {
      if (indeg[i] == 0) ans++;
    }

//    cout << ans << endl;
     cout << MAX(ans, 1) << endl;


  }
  return 0;

}
