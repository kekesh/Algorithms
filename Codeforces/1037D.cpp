#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9 + 1;


int main() {
	int n;
	cin >> n;
	vector<vector<int>> AdjList(n + 1);
	vector<int> p(n + 1), ind(n + 1);
	for (int i = 0, x, y; i < n - 1; ++i) {
		cin >> x >> y;
		AdjList[x].push_back(y);
		AdjList[y].push_back(x);
	}
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		ind[p[i]] = i;
	}
	const auto cmp = [&ind](int a, int b) {
		return ind[a] < ind[b];
	};
	for (int i = 1; i <= n; ++i) {
		sort(AdjList[i].begin(), AdjList[i].end(), cmp);
	}

	queue<int> q;
	vector<int> d(n + 1, INF);
	q.push(1); d[1] = 0;
	vector<int> seq;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		seq.push_back(u);
		for (const auto& v : AdjList[u]) {
			if (d[v] == INF) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	int maxi = -1;
	for (int i = 0, x; i < n; ++i) {
		if (seq[i] != p[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
