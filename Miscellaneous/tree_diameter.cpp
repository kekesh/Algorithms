#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

const int INFTY = 10e8;

int bfs(int src, vector<vector<int>>& AdjList, bool second_time) {
  vector<int> d(100);
  for (int i = 0; i < d.size(); i++) {
    d[i] = INFTY;
  }
  d[src] = 0;
  queue<int> q;
  q.push(src);
  int max_dist = -1;
  int max_vertex = src;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < AdjList[u].size(); i++) {
      if (d[AdjList[u][i]] == INFTY) {
        q.push(AdjList[u][i]);
        d[AdjList[u][i]] = d[u] + 1;
        if (d[AdjList[u][i]] > max_dist) {
          max_dist = d[AdjList[u][i]];
          max_vertex = AdjList[u][i];
        }
      }
    }
  }
  return (second_time ? max_dist : bfs(max_vertex, AdjList, true));
}


int main() {
  vector<vector<int>> AdjList;
  AdjList.push_back({1});
  AdjList.push_back({2, 3, 4});
  AdjList.push_back({1});
  AdjList.push_back({1});
  AdjList.push_back({1, 5, 6});
  AdjList.push_back({4});
  AdjList.push_back({4});
  /*
        0
        |
   2 -  1 - 3
        |
        4
      /   \
     5     6 */

  cout << "Diameter: " << bfs(1, AdjList, false) << endl;
}
