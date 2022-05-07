#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

class UF {
	private:
		vector<long long> parent, rank, exp;
	
	public:
		UF(const int n) {
			parent.resize(n + 1);
			rank.resize(n + 1);
			exp.resize(n + 1);
			iota(parent.begin(), parent.end(), 0);
		}
		
		int findSet(const int u) {
			return (parent[u] == u ? u : findSet(parent[u]));
		}

		bool inSameSet(const int u, const int v) {
			return findSet(u) == findSet(v);
		}

		void unionSet(const int u, const int v) {
			int p1 = findSet(u), p2 = findSet(v);
			if (p1 == p2) return;
			if (rank[p1] > rank[p2]) {
				add(p2, -exp[p1]);
				parent[p2] = p1;
			} else {
				add(p1, -exp[p2]);
				parent[p1] = p2;
				rank[p2] += (rank[p1] == rank[p2]);
			}
		}

		void add(long long u, long long delta) {
			long long v = findSet(u);
			exp[v] += delta; 
		}

		void query(int u) {
			long long sum = exp[u];
			while (u != parent[u]) {
				u = parent[u];
				sum += exp[u];
			}
			printf("%lld\n", sum);
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m;
	scanf("%lld %lld", &n, &m);
	char query[10];
	UF a(n);
	for (long long q = 0, u, v; q < m; ++q) {
		scanf("%s", query);
		if (query[0] == 'a') {
			scanf("%lld %lld", &u, &v);
			a.add(u, v);
		} else if (query[0] == 'j') {
			scanf("%lld %lld", &u, &v);
			a.unionSet(u, v);
		} else {
			scanf("%lld", &u);
			a.query(u);
		}
	}
	return 0;
}

