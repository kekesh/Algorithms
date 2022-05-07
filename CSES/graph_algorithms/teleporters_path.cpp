#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool has_eulerian_cycle(const vector<int>& in, const vector<int>& out) {
	const int n = in.size();
	int start = 0, end = 0;
	for (int i = 1; i <= n; ++i) {
		if (abs(in[i] - out[i]) > 1) {
			return false;
		}
		start += in[i] - out[i] == -1;
		end += in[i] - out[i] == 1;
	}
	return (start == 0 && end == 0) || (start == 1 && end == 1);
}

void dfs(const vector<vector<int>>& AdjList, vector<int>& out, vector<int>& euler_path, int u) {
	while (out[u]) {
		int v = AdjList[u][--out[u]];
		dfs(AdjList, out, euler_path, v);
	}
	euler_path.push_back(u);
}


int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> AdjList(n + 1);
	vector<int> indeg(n + 1), outdeg(n + 1);

	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		indeg[v]++;
		outdeg[u]++;
		AdjList[u].push_back(v);
	}

	if (!has_eulerian_cycle(indeg, outdeg)) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	vector<int> eulerian_path;

	dfs(AdjList, outdeg, eulerian_path, 1);

	if (eulerian_path.size() != m + 1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	reverse(eulerian_path.begin(), eulerian_path.end());

	if (eulerian_path.front() != 1 || eulerian_path.back() != n) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	for (const auto& v : eulerian_path) {
		cout << v << " ";
	}
	cout << endl;
}

