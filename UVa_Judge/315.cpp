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


/* Count the number of articulation points. */

ll N, M;
int num[100], lo[100], parent[100];
bool articulation[100];
int cnt, root, rootchildren;

void dfs(int u, const vector<vector<int>>& AdjList) {
  num[u] = lo[u] = ++cnt;

  F0R(i, AdjList[u].size()) {
    int v = AdjList[u][i];
    if (num[v] == 0) {
      if (u == root) {
        rootchildren++;
      }
      parent[v] = u;
      dfs(v, AdjList);
      if (lo[v] >= num[u]) {
        articulation[u] = true;
      }
      lo[u] = min(lo[u], lo[v]);
    } else if (parent[u] != v) {
      lo[u] = min(lo[u], num[v]);
    }
  }
}

int main(void) {
  while (cin >> N, N != 0) {
    getchar();
    memset(num, 0, sizeof(num));
    memset(lo, 0, sizeof(lo));
    memset(parent, 0, sizeof(parent));
    memset(articulation, false, sizeof(articulation));
    cnt = 0;
    vector<vector<int>> AdjList(100);

    string line;
    while (getline(cin, line)) {
      istringstream iss(line);
      ll from;
      iss >> from;
      if (from == 0) break;
      from--;
      ll to;
      while (iss >> to) {
        to--;
        AdjList[from].pb(to);
        AdjList[to].pb(from);
      }
    }
    F0R(i, N) {
      if (num[i] == 0) {
        root = i;
        rootchildren = 0;
        parent[root] = root;
        dfs(i, AdjList);
        articulation[root] = (rootchildren > 1);
      }
    }
    int c = 0;
    F0R(i, N) {
      c += articulation[i] ? 1 : 0;
    }
    cout << c << endl;
  }
}

