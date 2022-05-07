#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> AdjList(n + 1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
	}


	queue<int> q;

}
