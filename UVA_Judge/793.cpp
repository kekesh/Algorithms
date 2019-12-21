#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>      // std::istringstream
#include <fstream>

using namespace std;

typedef long long ll;

struct UnionFind {
  vector<int> parent;
  vector<int> rank;

  /* A constructor to instantiate the data structure. */
  UnionFind(int size) {
    parent.assign(size, 0);
    rank.assign(size, 0);

    /* Initially, we have N isolated vertices. */
    for (int i = 0; i < size; i++) {
      parent[i] = i;
    }
  }

  /* findSet(u) returns the representative of the set that u belongs to. This method uses path compression so that subsequent calls are sped up.*/
  int findSet(int u) {
    return (parent[u] == u) ? u : (parent[u] = findSet(parent[u]));
  }

  /* inSameSet(u, v) returns true iff u and v are in the same set. */
  bool inSameSet(int u, int v) {
    return findSet(u) == findSet(v);
  }

  /* unionSet(u, v) combines the sets that u and v belong to. This method is optimized with the union by rank heuristic. */
  void unionSet(int u, int v) {
    if (inSameSet(u, v)) return;

    int x = findSet(u), y = findSet(v);

    /* Always add the smaller tree to the larger tree. */
    if (rank[x] > rank[y]) {
      parent[y] = x;
    } else {
      parent[x] = y;
      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }
 }
};


int main() {

  ll T;
  cin >> T;
  while (T--) {
    string line;
    int N;
    scanf("\n%d\n", &N);
    int yes, no;
    yes = no = 0;

    UnionFind uf(N + 1);

    while (getline(cin, line)) {
      if (!line.size()) break;

      istringstream ss(line);
      char query;
      int from, to;
      ss >> query >> from >> to;

      if (query == 'c') {
        uf.unionSet(from, to);
      } else if (query == 'q') {
        bool res = uf.inSameSet(from, to);
        if (res) yes++;
        else no++;
      }
    }
    cout << yes << "," << no << endl;
    if (T != 0) cout << "\n";
  }
}
