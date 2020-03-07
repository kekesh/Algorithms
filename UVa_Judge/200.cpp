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

vector<string> ind(100000);
int indeg[26];
vector<set<ll>> AdjSet(26);
bool exists[26];

int main(void) {
  string nxt;
  int N = 0;
  while (cin >> nxt, nxt != "#") {
    ind[N++] = nxt;
  }

  F0R(i, N) {
    ll N2 = ind[i].size();
    F0R(j, N2) {
      string pref = ind[i].substr(0, j);
      FOR(k, i + 1, N) {
        if (ind[k].size() > j) {
          string cmpr = ind[k].substr(0, j);
          if (pref == cmpr && ind[i][j] != ind[k][j]) {
            // they're equal. ind[i][j] < ind[k][j];
            // edge from ind[i][j] to ind[k][j].
            int from = ind[i][j] - 'A';
            int to = ind[k][j] - 'A';
            exists[from] = exists[to] = true;
            if (AdjSet[from].find(to) == AdjSet[from].end()) {
              AdjSet[from].insert(to);
              indeg[to]++;
            }
          }
        }
      }
    }
  }

  // topological sort. kahn's algorithm
  priority_queue<int, vector<int>, greater<int>> q;

  F0R(i, 26) {
    if (indeg[i] == 0 && exists[i]) {
      q.push(i);
    }
  }

  string toposort = "";
  while (!q.empty()) {
    int u = q.top(); q.pop();
    char toadd = (char) (u + 'A');
    toposort += toadd;
    for (auto it : AdjSet[u]) {
      indeg[it]--;
      if (indeg[it] == 0) {
        q.push(it);
      }
    }
  }
  cout << toposort << endl;

  return 0;
}

