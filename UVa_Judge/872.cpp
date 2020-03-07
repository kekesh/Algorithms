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

int indeg[26];
bool exists[26];
bool visited[26];
bool cycle;
int color[26];
ll sz;


void dfs(int src, const vector<vector<int>>& AdjList) {
  visited[src] = true;
  color[src] = 1;
  F0R(i, AdjList[src].size()) {
    int u = AdjList[src][i];
    if (color[u] == 1) cycle = true;
    else dfs(u, AdjList);
  }
  color[src] = 2;
}

void toposort(string curr, const vector<vector<int>>& AdjList) {
  if (curr.size() == sz) {
      F0R(i, curr.size()) {
        cout << curr[i];
        if (i != curr.size() - 1) cout << " ";
    }
    cout << endl;
  }

  F0R(i, 26) {
    if (exists[i] && indeg[i] == 0) {
      exists[i] = false;
      F0R(j, AdjList[i].size()) {
        int u = AdjList[i][j];
        indeg[u]--;
      }
      char toadd = (char) (i + 'A');
      toposort(curr + toadd, AdjList);

      F0R(j, AdjList[i].size()) {
        int u = AdjList[i][j];
        indeg[u]++;
      }
      exists[i] = true;
    }
  }
}

int main(void) {

  ll T;
  cin >> T;
  getchar();
  getchar();
  while (T--) {
    memset(indeg, 0, sizeof(indeg));
    memset(exists, false, sizeof(exists));
    vector<vector<int>> AdjList(26);
    string line;
    getline(cin, line);
    sz = 0;
    istringstream iss(line);
    char nxt;
    while (iss >> nxt) {
      exists[nxt - 'A'] = true;
    }
    F0R(i, 26) {
      if (exists[i]) sz++;
    }
    getline(cin, line);
    iss.clear();
    iss.str(line);
    string temp;
    while (iss >> temp) {
      int from = temp[0] - 'A';
      int to = temp[2] - 'A';
      AdjList[from].pb(to);
      indeg[to]++;
    }

    // topological sort exists if and only if G is a directed acyclic graph
    // need to check for cycles.
    memset(visited, false, sizeof(visited));
    memset(color, 0, sizeof(color));
    cycle = false;
    F0R(i, 26) {
      if (exists[i] && !visited[i]) {
        dfs(i, AdjList);
      }
    }

    if (cycle) {
      cout << "NO" << endl;
    } else {
      toposort("", AdjList);
    }

    if (T) getchar();
    if (T) cout << endl;
  }

  return 0;
}
