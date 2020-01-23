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

bool visited[100];

ll gcd(ll a, ll b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

/* DFSMultiply will multiply the quantity of every item in the same connected component
 * as src by multiplier. We also compute the GCD over all quantities simultaneously. */
void DFSMultiply(vector<vector<int> >& AdjList, int src, unordered_map<ll, ll>& quantities, ll multiplier, ll& g) {
  visited[src] = true;
  quantities[src] *= multiplier;
  g = gcd(g, quantities[src]);

  F0R(i, AdjList[src].size()) {
    int v = AdjList[src][i];
    if (!visited[v]) {
      DFSMultiply(AdjList, v, quantities, multiplier, g);
    }
  }
}

// prevent overflow. this might not be needed.
void DFSReduce(vector<vector<int>>& AdjList, int src, unordered_map<ll, ll>& quantities, ll g) {
    visited[src] = true;
    quantities[src] /= g;
    F0R(i, AdjList[src].size()) {
      int v = AdjList[src][i];
      if (!visited[v]) {
        DFSReduce(AdjList, v, quantities, g);
      }
    }
}

void DFSSearch(vector<vector<int>>& AdjList, int src, int dest, bool& found) {
  visited[src] = true;
  if (src == dest) {
    found = true;
    return;
  }
  F0R(i, AdjList[src].size()) {
    int v = AdjList[src][i];
    if (!found && !visited[v]) {
      DFSSearch(AdjList, v, dest, found);
    }
  }
}


int main(void) {
  string line;

  vector<vector<int>> AdjList;
  unordered_map<string, int> indices;
  unordered_map<ll, ll> quantities; // index -> quantity

  while (getline(cin, line)) {
    if (line == ".") break;

    istringstream iss(line);
    ll q1, q2;
    string from, to, dummy, type;
    iss >> type;

    if (type == "!") {
      iss >> q1 >> from >> dummy >> q2 >> to;
      if (indices.find(from) == indices.end()) {
        // cout << "Adding " << from << endl;
        indices[from] = AdjList.size();
        quantities[indices[from]] = q1;
        AdjList.pb({});
      }

      if (indices.find(to) == indices.end()) {
        indices[to] = AdjList.size();
        quantities[indices[to]] = q2;
        AdjList.pb({});
      }


      /* We need the ratio between from and to to be q1/q2.
       * Let a and b be the old amounts of from and to.
       * DFSMultiply a by q1*b and DFSMultiply b by q2*a since q1*ab/q2*ab = q1/q2. */
      memset(visited, false, sizeof(visited));
      ll multiplier1 = q1 * quantities[indices[to]];
      ll multiplier2 = q2 * quantities[indices[from]]; // q2 * a
      ll g = indices[from];
      DFSMultiply(AdjList, indices[from], quantities, multiplier1, g);
      memset(visited, false, sizeof(visited));
      DFSMultiply(AdjList, indices[to], quantities, multiplier2, g);
      AdjList[indices[from]].pb(indices[to]);
      AdjList[indices[to]].pb(indices[from]);
      memset(visited, false, sizeof(visited));
      DFSReduce(AdjList, indices[to], quantities, g);
    } else if (type == "?") {
      iss >> from >> dummy >> to;

      if (indices.find(from) == indices.end() || indices.find(to) == indices.end()) {
        cout << "? " << from << " = ? " << to << endl;
      } else {
        bool found = false;
        memset(visited, false, sizeof(visited));
        DFSSearch(AdjList, indices[from], indices[to], found);
        if (found) {
          int G = __gcd(quantities[indices[from]], quantities[indices[to]]);
          cout << quantities[indices[from]]/G << " " << from << " = " << quantities[indices[to]]/G << " " << to << endl;
        } else {
          cout << "? " << from << " = ? " << to << endl;
        }
      }
    }
  }

  return 0;
}
