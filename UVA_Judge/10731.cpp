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

ll N;
bool visited[26];
int dfs_num[26], dfs_low[26], dfs_counter;
bool exists[26];
stack<int> s;

// return true if lsh < rhs
bool cmp(const vi & lhs, const vi& rhs) {
  return lhs[0] < rhs[0];
}

void tarjanSCC(int u, const vector<vi>& AdjList, vector<vi>& sccs) {
  dfs_num[u] = dfs_low[u] = ++dfs_counter;
  visited[u] = true;
  s.push(u);

  F0R(i, AdjList[u].size()) {
    int v = AdjList[u][i];
    if (dfs_num[v] == 0) {
      tarjanSCC(v, AdjList, sccs);
    }
    if (visited[v]) {
      dfs_low[u] = MIN(dfs_low[u], dfs_low[v]);
    }
  }

  if (dfs_low[u] == dfs_num[u]) {
    vector<int> tmp;
    int v;
    // cout << "SCC: ";
    do {
      v = s.top(); s.pop(); visited[v] = false;
      tmp.pb(v);
      // cout << v << " ";
    } while (u != v);
    sccs.pb(tmp);
    // cout << endl;
  }
}




int main(void) {
  bool fst = true;
  while (cin >> N, N != 0) {
    if (!fst) cout << endl;
    memset(visited, false, sizeof(visited));
    memset(exists, false, sizeof(exists));
    memset(dfs_num, 0, sizeof(dfs_num));
    memset(dfs_low, 0, sizeof(dfs_low));
    dfs_counter = 0;
    s.empty();
    assert(s.size() == 0);

    fst = false;
    vector<vi> AdjList(26);
    vector<vi> sccs;

    F0R(i, N) {
      char inp[6];
      F0R(i, 6) {
        cin >> inp[i];
        exists[inp[i] - 'A'] = true;
      }

      F0R(i, 5) {
        if (inp[5] - 'A' != inp[i] - 'A') {
          AdjList[inp[5] - 'A'].pb(inp[i] - 'A');
        }
      }
    }
      /* Done constructing graph. */

      F0R(i, 26) {
        if (exists[i] && dfs_num[i] == 0) {
          tarjanSCC(i, AdjList, sccs);
        }
      }

      for (int i = 0; i < sccs.size(); i++) {
        sort(sccs[i].begin(), sccs[i].end());
      }
      sort(sccs.begin(), sccs.end(), cmp);

      F0R(i, sccs.size()) {
        F0R(j, sccs[i].size()) {
          cout << (char) (sccs[i][j] + 'A');
          if (j != sccs[i].size() - 1) {
            cout << " ";
          }
        }
        cout << endl;
      }



  }
  return 0;
}
