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

ll N, M;
int indeg[100];
int j;
const string pre = "Dilbert should drink beverages in this order: ";

int main(void) {
  while (cin >> N) {

    memset(indeg, 0, sizeof(indeg));
    vector<string> drinks(N);
    vector<vector<int>> AdjList(N);
    unordered_map<string, int> m;
    F0R(i, N) {
      string drink;
      cin >> drink;
      m[drink] = i;
      drinks[i] = drink;
    }
    cin >> M;
    F0R(i, M) {
      string s1, s2;
      cin >> s1 >> s2;
      int from = m[s1], to = m[s2];
      AdjList[from].pb(to);
      indeg[to]++;
    }
    // topological sort, kahn's algorithm
    priority_queue<int, vector<int>, greater<int>> q;

    F0R(i, N) {
      if (indeg[i] == 0) {
        q.push(i);
      }
    }

    string toposort = "";
    bool space = false;
    while (!q.empty()) {
      int u = q.top(); q.pop();
      if (space) toposort += " ";
      space = true;
      toposort += drinks[u];

      F0R(i, AdjList[u].size()) {
        int v = AdjList[u][i];
        indeg[v]--;
        if (indeg[v] == 0) q.push(v);
      }
    }
    toposort += ".";
    cout << "Case #" << ++j << ": " << pre << toposort << endl;
    cout << endl;
  }
}
