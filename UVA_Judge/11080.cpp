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
vector<vector<int>> AdjList(201);
vector<int> color(201);

ll bfs(int src) {
  if (AdjList[src].size() == 0) return 1;
  bool isBipartite = true;
  queue<int> q;
  q.push(src);
  color[src] = 0;
  pair<int, int> counter = make_pair(1, 0);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    F0R(i, AdjList[u].size()) {
      if (color[AdjList[u][i]] == INFTY) {
        color[AdjList[u][i]] = 1 - color[u];
        if (color[AdjList[u][i]] == 0) counter.first += 1;
        else counter.second += 1;
        q.push(AdjList[u][i]);
      } else if (color[u] == color[AdjList[u][i]]) {
        isBipartite = false;
      }
    }
  }
  if (isBipartite) {
    return MIN(counter.first, counter.second);

  } else {
    return -INFTY;
  }
}

int main() {
  ll T;
  cin >> T;
  while (T--) {
    ll V, E;
    cin >> V >> E;
    color.assign(V, INFTY);
    AdjList.assign(V, vector<int>());
    F0R(i, E) {
      ll fst, snd;
      cin >> fst >> snd;
      AdjList[fst].pb(snd);
      AdjList[snd].pb(fst);
    }
    ll ans = 0;
    F0R(i, V) {
      if (color[i] == INFTY) {
        ans += bfs(i);
        if (ans < 0) break;
      }
    }
    ans = MAX(ans, -1);
    cout << ans << endl;
  }
return 0;
}
