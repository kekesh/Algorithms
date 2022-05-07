#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

class UF {
	private:
		vector<long long> parent, rank;
	
	public:
		UF(const int n) {
			parent.resize(n);
			rank.resize(n);
			iota(parent.begin(), parent.end(), 0);
		}
		
		int findSet(const int u) {
			return (parent[u] == u ? u : parent[u] = findSet(parent[u]));
		}

		bool inSameSet(const int u, const int v) {
			return findSet(u) == findSet(v);
		}

		void unionSet(const int u, const int v) {
			int p1 = findSet(u), p2 = findSet(v);
			if (p1 == p2) return;
			if (rank[p1] > rank[p2]) {
				parent[p2] = p1;
			} else {
				parent[p1] = p2;
				rank[p2] += (rank[p1] == rank[p2]);
			}
		}
};

int main() {
	int n, m;
	cin >> n >> m;
	UF a(n);
	for (int q = 0, u, v; q < m; ++q) {
		string query;
		cin >> query >> u >> v;
		if (query == "union") {
			a.unionSet(u - 1, v - 1);
		} else {
			cout << (a.inSameSet(u - 1, v - 1) ? "YES" : "NO") << endl;
		}
	}
}
