#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

const string BIPARTITE = "No suspicious bugs found!";
const string NOT_BIPARTITE = "Suspicious bugs found!";

bool check(vector<vector<int>>& AdjList, unordered_set<int>& seen, int source) {
	queue<int> q;
	unordered_map<int, int> color;
	q.push(source);
	color[source] = 0;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		seen.insert(u);
		for (const auto& v : AdjList[u]) {
			if (seen.find(v) == seen.end()) {
				q.push(v);
				color[v] = 1 - color[u];
			} else if (color[v] == color[u]) {
				return false;
			}
		}
	}
	return true;
}


int main() {
	int t;
	cin >> t;
	int case_num = 1;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> AdjList(n + 1);

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		unordered_set<int> seen;
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			if (seen.find(i) == seen.end()) {
				ok &= check(AdjList, seen, i);
			}
		}
		cout << "Scenario #" << case_num++ << ":" << endl;
		cout << (ok ? BIPARTITE : NOT_BIPARTITE) << endl;
	}
}
