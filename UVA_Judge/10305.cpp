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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 35005;
const ld PI = 4 * atan((ld)1);


int color[100];
bool visited[100];
ll N, M;
vector<int> toposort;


void dfs(int src, const vector<vector<int>>& AdjList) {
  visited[src] = true;
  color[src] = 1;

  F0R(i, AdjList[src].size()) {
    int v = AdjList[src][i];
    if (!visited[v]) {
      dfs(v, AdjList);
    }
  }
  color[src] = 2;
  toposort.push_back(src+1);
}


int main(void) {
  while (cin >> N >> M) {
    if (N == 0 && M == 0) break;
    vector<vector<int>> AdjList(100);

    F0R(i, M) {
      ll from, to;
      cin >> from >> to;
      from--;
      to--;
      AdjList[from].pb(to);
    }
    memset(color, 0, sizeof(color));
    memset(visited, false, sizeof(visited));

    F0R(i, N) {
      if (!visited[i]) {
        dfs(i, AdjList);
      }
    }

    F0Rd(i, toposort.size()) {
      cout << toposort[i];
      if (i != 0) cout << " ";
    }
    cout << endl;
    toposort.clear();
  }
  return 0;

}

