#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

bool has_eulerian_path(const vector<long long>& in, const vector<long long>& out) {
	const int n = in.size();
	int start_nodes = 0, end_nodes = 0;
	for (int i = 0; i < n; ++i) {
		if (abs(out[i] - in[i]) > 1) {
			return false;
		}
		start_nodes += (out[i] - in[i] == 1);
		end_nodes += (in[i] - out[i] == 1);
	}
	return (start_nodes == 0 && end_nodes == 0) || (start_nodes == 1 && end_nodes == 1); 
}

int find_start_node(const vector<long long>& in, const vector<long long>& out) {
	const int n = in.size();
	int start = 0;
	for (int i = 0; i < n; ++i) {
		if (out[i] - in[i] == 1) {
			return i;
		}
		if (out[i] > 0) {
			start = i;
		}
	}
	return start;
}

void dfs(int u, vector<long long>& tour, const vector<vector<long long>>& AdjList, vector<long long>& out) {
	while (out[u]) {
		int v = AdjList[u][--out[u]];
		dfs(v, tour, AdjList, out);
	}
	tour.push_back(u);
}

int main() {
	long long n, m;
	while (cin >> n >> m, n + m != 0) {
		vector<vector<long long>> AdjList(n);
		vector<long long> indegree(n), outdegree(n);

		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v;
			AdjList[u].push_back(v);
			indegree[v]++;
			outdegree[u]++;
		}

		if (!has_eulerian_path(indegree, outdegree)) {
			cout << "Impossible" << endl;
			continue;
		}
		vector<long long> eulerian_path;
		dfs(find_start_node(indegree, outdegree), eulerian_path, AdjList, outdegree);
		if (eulerian_path.size() != m + 1) {
			cout << "Impossible" << endl;
			continue;
		}
		reverse(eulerian_path.begin(), eulerian_path.end());
		for (int i = 0; i < m + 1; ++i) {
			cout << eulerian_path[i] << " ";
		}
		cout << endl;
	}
}
