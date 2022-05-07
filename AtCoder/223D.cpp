#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> AdjList(n + 1);
	vector<int> degree(n + 1); // in-degree of a vertex. in-degree of v is # of edges (u, v) for some u.

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		AdjList[u].push_back(v);
		degree[v]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; ++i) {
		if (!degree[i]) {
			pq.push(i);
		}
	}

	vector<int> permutation;
	while (!pq.empty()) {
		int u = pq.top(); pq.pop();
		permutation.push_back(u);
		for (const auto& v : AdjList[u]) {
			degree[v]--;
			m--;
			if (!degree[v]) pq.push(v);
		}
	}

	if (m) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < permutation.size(); ++i) cout << permutation[i] << " ";
	cout << endl;

}
