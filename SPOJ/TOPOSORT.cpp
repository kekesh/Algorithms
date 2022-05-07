#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

struct cmp {
	bool operator()(const int a, const int b) {
		return a > b;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> AdjList(n + 1);
	vector<int> degree(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		AdjList[u].push_back(v);
		degree[v]++;
	}

	priority_queue<int, vector<int>, cmp> pq;
	// O(Vlog(V))
	for (int i = 1; i <= n; ++i) {
		if (!degree[i]) pq.push(i);
	}
	
	vector<int> toposort;
	while (!pq.empty()) {
		int u = pq.top(); pq.pop();
		toposort.push_back(u);
		for (const auto& v : AdjList[u]) {
			m--;
			degree[v]--;
			if (!degree[v]) pq.push(v);
		}
	}
	if (m) {
		cout << "Sandro	fails." << endl;
	} else {
		for (int i = 0; i < n; ++i) {
			cout << toposort[i];
			if (i != n - 1) cout << " ";
		}
		cout << endl;
	}
}
