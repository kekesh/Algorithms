#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, r, m;
		cin >> n >> r >> m;
		vector<vector<int>> AdjList(n + 1);
		vector<pair<int, int>> sources;

		for (int i = 0; i < r; ++i) {
			int u, v;
			cin >> u >> v;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		for (int i = 0; i < m; ++i) {

		}




	}
}
