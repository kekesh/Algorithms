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

ll T, P;
unordered_map<string, int> nametoidx;
unordered_map<int, string> idxtoname;
bool visited[1000];
int dfs_low[1000], dfs_num[1000], dfs_counter, numSCC;
stack<int> s;

void tarjanSCC(int u, const vector<vector<int>>& AdjList) {
  visited[u] = true;
  dfs_low[u] = dfs_num[u] = ++dfs_counter;
  s.push(u);

  F0R(i, AdjList[u].size()) {
    int v = AdjList[u][i];

    if (dfs_low[v] == 0) {
      tarjanSCC(v, AdjList);
    }

    if (visited[v]) {
      dfs_low[u] = MIN(dfs_low[u], dfs_low[v]);
    }
  }

  if (dfs_low[u] == dfs_num[u]) {
    int v;
    numSCC++;
    do {
      v = s.top(); s.pop(); visited[v] = false;
    } while (u != v);
  }
}


int main(void) {
  while (cin >> P >> T) {
    if (T == 0 && P == 0) break;
    nametoidx.clear();
    idxtoname.clear();
    numSCC = dfs_counter = 0;
    memset(dfs_low, 0, sizeof(dfs_low));
    memset(dfs_num, 0, sizeof(dfs_num));
    memset(visited, false, sizeof(visited));
    s.empty();
    assert(s.size() == 0);
    getchar();
    vector<vi> AdjList(1000);
    string line;
    int idx = 0;
    F0R(i, P) {
      getline(cin, line);
      nametoidx[line] = idx;
      idxtoname[idx] = line;
      idx++;
    }


    F0R(i, T) {
      string from, to;
      getline(cin, from);
      getline(cin, to);

      AdjList[nametoidx[from]].pb(nametoidx[to]);
    }

    F0R(i, idx) {
      if (dfs_num[i] == 0) {
        tarjanSCC(i, AdjList);
      }
    }
    cout << numSCC << endl;
  }

  return 0;
}

