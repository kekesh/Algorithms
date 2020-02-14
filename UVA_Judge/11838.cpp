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
bool visited[2000];
int dfs_num[2000], dfs_lo[2000], dfs_counter, num_scc;
stack<int> s;

void tarjanSCC(int u, const vector<vi>& AdjList) {
  visited[u] = true;
  dfs_num[u] = dfs_lo[u] = ++dfs_counter;
  s.push(u);

  F0R(i, AdjList[u].size()) {
    int v = AdjList[u][i];
    if (dfs_num[v] == 0) {
      tarjanSCC(v, AdjList);
    }
    if (visited[v]) {
      dfs_lo[u] = MIN(dfs_lo[u], dfs_lo[v]);
    }
  }

  if (dfs_num[u] == dfs_lo[u] ) {
    int v;
    num_scc++;
    do {
      v = s.top(); s.pop(); visited[v] = false;
    } while (u != v);
  }
}


int main(void) {

  while (cin >> N >> M) {
    if (N == 0 && M == 0) break;
    memset(visited, false, sizeof(visited));
    memset(dfs_lo, 0, sizeof(dfs_lo));
    memset(dfs_num, 0, sizeof(dfs_num));
    s.empty();
    num_scc = dfs_counter = 0;

    vector<vi> AdjList(N);
    F0R(i, M) {
      ll from, to, m;
      cin >> from >> to >> m;
      AdjList[from-1].pb(to-1);
      if (m == 2) {
        AdjList[to-1].pb(from-1);
      }
    }

    F0R(i, N) {
      if (dfs_num[i] == 0) {
        tarjanSCC(i, AdjList);
      }
    }

    int ans = num_scc == 1 ? 1 : 0;
    cout << ans << endl;

  }

}
